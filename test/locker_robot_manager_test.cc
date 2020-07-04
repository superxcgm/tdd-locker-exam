//
// Created by Yujia Li  on 2020/7/4.
//

#include "gtest/gtest.h"
#include "locker.h"
#include "primary_locker_robot.h"
#include "super_locker_robot.h"
#include "size.h"
#include "locker_robot_manager.h"

class ALockerRobotManager : public testing::Test {

protected:
    virtual void SetUp() {
        s_size_locker_ = std::make_shared<Locker>(1, Size::kSmall);
        m_size_locker_ = std::make_shared<Locker>(1, Size::kMedium);
        l_size_locker_ = std::make_shared<Locker>(1, Size::kLarge);
        std::vector<Locker *> m_size_lockers = {m_size_locker_.get()};
        primary_locker_robot_ = std::make_shared<PrimaryLockerRobot>(m_size_lockers);
        std::vector<Locker *> l_size_lockers = {l_size_locker_.get()};
        super_locker_robot_ = std::make_shared<SuperLockerRobot>(l_size_lockers);
        manager_ = std::make_shared<LockerRobotManager>(s_size_locker_.get(), primary_locker_robot_.get(),
                                                        super_locker_robot_.get());
    }

public:
    std::shared_ptr<Locker> s_size_locker_;
    std::shared_ptr<Locker> m_size_locker_;
    std::shared_ptr<Locker> l_size_locker_;
    std::shared_ptr<PrimaryLockerRobot> primary_locker_robot_;
    std::shared_ptr<SuperLockerRobot> super_locker_robot_;
    std::shared_ptr<LockerRobotManager> manager_;
};

TEST_F(ALockerRobotManager,
       should_return_ticket_and_store_bag_to_S_size_locker_when_store_bag_given_S_size_locker_not_full) {
    Bag bag{Size::kSmall};

    auto optional_ticket = manager_->store(&bag);

    ASSERT_TRUE(optional_ticket.has_value());
    auto got_bag = s_size_locker_->take(optional_ticket.value());
    ASSERT_EQ(got_bag, &bag);
}

TEST_F(ALockerRobotManager,
       should_throw_LockerFullException_when_store_bag_given_S_size_locker_full) {
    Bag useless_bag;
    s_size_locker_->store(&useless_bag);
    Bag bag{Size::kSmall};

    ASSERT_THROW(manager_->store(&bag), Locker::LockerFullException);
}

TEST_F(ALockerRobotManager,
       should_return_ticket_and_store_bag_to_PrimaryLockerRobot_when_store_bag_given_PrimaryLockerRobot_not_full) {
    Bag bag{Size::kMedium};

    auto optional_ticket = manager_->store(&bag);

    ASSERT_TRUE(optional_ticket.has_value());
    auto got_bag = primary_locker_robot_->take(optional_ticket.value());
    ASSERT_EQ(got_bag, &bag);
}

TEST_F(ALockerRobotManager,
       should_throw_LockerFullException_when_store_bag_given_M_size_locker_full) {
    Bag useless_bag;
    m_size_locker_->store(&useless_bag);
    Bag bag{Size::kMedium};

    ASSERT_THROW(manager_->store(&bag), Locker::LockerFullException);
}

TEST_F(ALockerRobotManager,
       should_return_ticket_and_store_bag_to_SuperLockerRobot_when_store_bag_given_SuperLockerRobot_not_full) {
    Bag bag{Size::kLarge};

    auto optional_ticket = manager_->store(&bag);

    ASSERT_TRUE(optional_ticket.has_value());
    auto got_bag = super_locker_robot_->take(optional_ticket.value());
    ASSERT_EQ(got_bag, &bag);
}

TEST_F(ALockerRobotManager,
       should_throw_LockerFullException_when_store_bag_given_L_size_locker_full) {
    Bag useless_bag;
    l_size_locker_->store(&useless_bag);
    Bag bag{Size::kLarge};

    ASSERT_THROW(manager_->store(&bag), Locker::LockerFullException);
}

TEST_F(ALockerRobotManager, should_take_correct_bag_when_take_bag_given_a_valid_S_size_ticket) {
    Bag bag{Size::kSmall};
    auto optional_ticket = manager_->store(&bag);

    auto got_bag = manager_->take(optional_ticket.value());

    ASSERT_EQ(got_bag, &bag);
}
