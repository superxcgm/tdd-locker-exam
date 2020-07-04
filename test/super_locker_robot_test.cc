//
// Created by Yujia Li  on 2020/7/4.
//

#include <locker.h>
#include "gtest/gtest.h"
#include "super_locker_robot.h"

TEST(SuperLockerRobot,
     should_return_ticket_and_store_to_first_locker_when_store_bag_given_SuperLockerRobot_manager_two_L_size_locker_and_first_locker_has_higher_empty_ratio) {
    auto first_locker = Locker(2, Size::kLarge);
    auto second_locker = Locker(2, Size::kLarge);
    Bag useless_bag;
    second_locker.store(&useless_bag);
    SuperLockerRobot robot({&first_locker, &second_locker});
    Bag bag;

    auto optional_ticket = robot.store(&bag);

    ASSERT_TRUE(optional_ticket.has_value());
    auto got_bag = first_locker.take(optional_ticket.value());
    ASSERT_EQ(got_bag, &bag);
}

TEST(SuperLockerRobot,
     should_return_ticket_and_store_to_second_locker_when_store_bag_given_SuperLockerRobot_manager_two_L_size_locker_and_second_locker_has_higher_empty_ratio) {
    auto first_locker = Locker(2, Size::kLarge);
    auto second_locker = Locker(2, Size::kLarge);
    Bag useless_bag;
    first_locker.store(&useless_bag);
    SuperLockerRobot robot({&first_locker, &second_locker});
    Bag bag;

    auto optional_ticket = robot.store(&bag);

    ASSERT_TRUE(optional_ticket.has_value());
    auto got_bag = second_locker.take(optional_ticket.value());
    ASSERT_EQ(got_bag, &bag);
}

TEST(SuperLockerRobot,
     should_return_ticket_and_store_to_first_locker_when_store_bag_given_SuperLockerRobot_manager_two_L_size_locker_and_has_same_empty_ratio) {
    auto first_locker = Locker(2, Size::kLarge);
    auto second_locker = Locker(2, Size::kLarge);
    SuperLockerRobot robot({&first_locker, &second_locker});
    Bag bag;

    auto optional_ticket = robot.store(&bag);

    ASSERT_TRUE(optional_ticket.has_value());
    auto got_bag = first_locker.take(optional_ticket.value());
    ASSERT_EQ(got_bag, &bag);
}

TEST(SuperLockerRobot,
     should_throw_LockerFullException_when_store_bag_given_SuperLockerRobot_manager_two_L_size_locker_and_both_full) {
    auto first_locker = Locker(1, Size::kLarge);
    Bag useless_bag1;
    first_locker.store(&useless_bag1);
    auto second_locker = Locker(1, Size::kLarge);
    Bag useless_bag2;
    second_locker.store(&useless_bag2);
    SuperLockerRobot robot({&first_locker, &second_locker});
    Bag bag;

    ASSERT_THROW(robot.store(&bag), Locker::LockerFullException);
}

TEST(SuperLockerRobot, should_take_correct_bag_when_take_bag_given_a_valid_ticket) {
    auto locker = Locker(2, Size::kLarge);
    SuperLockerRobot robot({&locker});
    Bag bag;
    auto optional_ticket = robot.store(&bag);

    auto got_bag = robot.take(optional_ticket.value());

    ASSERT_EQ(got_bag, &bag);
}

TEST(SuperLockerRobot, should_take_correct_bag_when_take_bag_given_a_fake_ticket) {
    auto locker = Locker(2, Size::kLarge);
    SuperLockerRobot robot({&locker});
    auto fake_ticket = Ticket(666, Size::kLarge);

    ASSERT_THROW(robot.take(fake_ticket), Locker::InvalidTicketException);
}

TEST(SuperLockerRobot, should_throw_WrongTicketTypeException_when_take_bag_given_a_non_L_size_ticket) {
    auto locker = Locker(2, Size::kLarge);
    SuperLockerRobot robot({&locker});
    auto non_L_size_ticket = Ticket(666, Size::kMedium);

    ASSERT_THROW(robot.take(non_L_size_ticket), Locker::WrongTicketTypeException);
}

TEST(SuperLockerRobot, should_throw_WrongConfigException_when_config_SuperLockerRobot_given_non_L_size_locker) {
    auto non_L_size_locker = Locker(2, Size::kMedium);

    ASSERT_THROW(SuperLockerRobot{{&non_L_size_locker}}, WrongConfigException);
}
