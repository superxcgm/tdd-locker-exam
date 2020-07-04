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