//
// Created by Yujia Li  on 2020/7/4.
//

#include "gtest/gtest.h"
#include "locker.h"
#include "primary_locker_robot.h"
#include "super_locker_robot.h"
#include "size.h"
#include "locker_robot_manager.h"

TEST(LockerRobotManager,
     should_return_ticket_and_store_bag_to_S_size_locker_when_store_bag_given_S_size_locker_not_full) {
    auto s_size_locker = Locker{1, Size::kSmall};
    auto m_size_locker = Locker{1, Size::kMedium};
    auto primary_locker_robot = PrimaryLockerRobot({&m_size_locker});
    auto l_size_locker = Locker{1, Size::kLarge};
    auto super_locker_robot = SuperLockerRobot({&l_size_locker});
    LockerRobotManager manager(&s_size_locker, &primary_locker_robot, &super_locker_robot);
    Bag bag{Size::kSmall};

    auto optional_ticket = manager.store(&bag);
    ASSERT_TRUE(optional_ticket.has_value());
    auto got_bag = s_size_locker.take(optional_ticket.value());
    ASSERT_EQ(got_bag, &bag);
}

TEST(LockerRobotManager,
     should_throw_LockerFullException_when_store_bag_given_S_size_locker_full) {
    auto s_size_locker = Locker{1, Size::kSmall};
    Bag useless_bag;
    s_size_locker.store(&useless_bag);
    auto m_size_locker = Locker{1, Size::kMedium};
    auto primary_locker_robot = PrimaryLockerRobot({&m_size_locker});
    auto l_size_locker = Locker{1, Size::kLarge};
    auto super_locker_robot = SuperLockerRobot({&l_size_locker});
    LockerRobotManager manager(&s_size_locker, &primary_locker_robot, &super_locker_robot);
    Bag bag{Size::kSmall};

    ASSERT_THROW(manager.store(&bag), Locker::LockerFullException);
}

TEST(LockerRobotManager,
     should_return_ticket_and_store_bag_to_PrimaryLockerRobot_when_store_bag_given_PrimaryLockerRobot_not_full) {
    auto s_size_locker = Locker{1, Size::kSmall};
    auto m_size_locker = Locker{1, Size::kMedium};
    auto primary_locker_robot = PrimaryLockerRobot({&m_size_locker});
    auto l_size_locker = Locker{1, Size::kLarge};
    auto super_locker_robot = SuperLockerRobot({&l_size_locker});
    LockerRobotManager manager(&s_size_locker, &primary_locker_robot, &super_locker_robot);
    Bag bag{Size::kMedium};

    auto optional_ticket = manager.store(&bag);
    ASSERT_TRUE(optional_ticket.has_value());
    auto got_bag = primary_locker_robot.take(optional_ticket.value());
    ASSERT_EQ(got_bag, &bag);
}

TEST(LockerRobotManager,
     should_throw_LockerFullException_when_store_bag_given_M_size_locker_full) {
    auto s_size_locker = Locker{1, Size::kSmall};
    auto m_size_locker = Locker{1, Size::kMedium};
    Bag useless_bag;
    m_size_locker.store(&useless_bag);
    auto primary_locker_robot = PrimaryLockerRobot({&m_size_locker});
    auto l_size_locker = Locker{1, Size::kLarge};
    auto super_locker_robot = SuperLockerRobot({&l_size_locker});
    LockerRobotManager manager(&s_size_locker, &primary_locker_robot, &super_locker_robot);
    Bag bag{Size::kMedium};

    ASSERT_THROW(manager.store(&bag), Locker::LockerFullException);
}
