//
// Created by Yujia Li  on 2020/7/4.
//

#include <locker.h>
#include "gtest/gtest.h"
#include "primary_locker_robot.h"

TEST(PrimayLockerRobotTest,
     should_return_ticket_and_store_to_first_locker_when_store_bag_given_PrimaryLockerRobot_manage_two_M_size_locker_and_first_locker_not_full) {
    auto first_locker = Locker(2, Size::kMedium);
    auto second_locker = Locker(2, Size::kMedium);
    PrimaryLockerRobot robot({&first_locker, &second_locker});
    Bag bag;

    auto optional_ticket = robot.store(&bag);

    ASSERT_TRUE(optional_ticket.has_value());
    auto got_bag = first_locker.take(optional_ticket.value());
    ASSERT_EQ(got_bag, &bag);
}

TEST(PrimayLockerRobotTest,
     should_return_ticket_and_store_to_second_locker_when_store_bag_given_PrimaryLockerRobot_manage_two_M_size_locker_and_first_locker_full) {
    auto first_locker = Locker(1, Size::kMedium);
    Bag useless_bag;
    first_locker.store(&useless_bag);
    auto second_locker = Locker(2, Size::kMedium);
    PrimaryLockerRobot robot({&first_locker, &second_locker});
    Bag bag;

    auto optional_ticket = robot.store(&bag);

    ASSERT_TRUE(optional_ticket.has_value());
    auto got_bag = second_locker.take(optional_ticket.value());
    ASSERT_EQ(got_bag, &bag);
}

TEST(PrimaryLockerRobotTest,
     should_throw_LockerFullException_when_store_bag_given_PrimaryLockerRobot_manage_two_M_size_locker_and_both_full) {
    auto first_locker = Locker(1, Size::kMedium);
    Bag useless_bag1;
    first_locker.store(&useless_bag1);
    auto second_locker = Locker(1, Size::kMedium);
    Bag useless_bag2;
    second_locker.store(&useless_bag2);
    PrimaryLockerRobot robot({&first_locker, &second_locker});
    Bag bag;

    ASSERT_THROW(robot.store(&bag), Locker::LockerFullException);
}

TEST(PrimaryLockerRobotTest, should_take_correct_bag_when_take_bag_given_valid_ticket) {
    auto locker = Locker(1, Size::kMedium);
    PrimaryLockerRobot robot({&locker});
    Bag bag;
    auto optional_ticket = robot.store(&bag);

    auto got_bag = robot.take(optional_ticket.value());

    ASSERT_EQ(got_bag, &bag);
}

TEST(PrimaryLockerRobotTest, should_throw_InvalidTicketException_when_take_bag_given_fake_ticket) {
    auto locker = Locker(1, Size::kMedium);
    PrimaryLockerRobot robot({&locker});

    auto fake_ticket = Ticket(666, Size::kMedium);

    ASSERT_THROW(robot.take(fake_ticket), Locker::InvalidTicketException);
}

TEST(PrimaryLockerRobotTest, should_throw_WrongTicketTypeException_when_take_bag_given_none_M_Size_Ticket) {
    auto locker = Locker(1, Size::kMedium);
    PrimaryLockerRobot robot({&locker});

    auto fake_ticket = Ticket(666, Size::kLarge);

    ASSERT_THROW(robot.take(fake_ticket), Locker::WrongTicketTypeException);
}

TEST(PrimaryLockerRobotTest, should_throw_WrongConfigException_when_config_PrimaryLockerRobot_given_non_M_Size_Locker) {
    auto locker = Locker(1, Size::kLarge);

    ASSERT_THROW(PrimaryLockerRobot{{&locker}}, PrimaryLockerRobot::WrongConfigException);
}
