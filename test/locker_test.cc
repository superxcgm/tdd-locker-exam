//
// Created by Yujia Li  on 2020/7/4.
//
#include "gtest/gtest.h"
#include "locker.h"
#include "ticket.h"

TEST(LockerTest, should_store_bag_success_and_return_ticket_when_store_bag_given_locker_has_available_capacity) {
    Locker locker(6);

    std::optional<Ticket> optional = locker.store({});

    ASSERT_TRUE(optional.has_value());
}

TEST(LockerTest, should_throw_LockerFullException_when_store_bag_given_locker_full) {
    Locker locker(1);

    locker.store({});

    ASSERT_THROW(locker.store({}), Locker::LockerFullException);
}
