//
// Created by Yujia Li  on 2020/7/4.
//
#include "gtest/gtest.h"
#include "locker.h"
#include "ticket.h"
#include "optional"

TEST(LockerTest, should_store_bag_success_and_return_ticket_when_store_bag_given_locker_has_available_capacity) {
    Locker locker(6, Size::kSmall);

    std::optional<Ticket> optional = locker.store({});

    ASSERT_TRUE(optional.has_value());
}

TEST(LockerTest, should_throw_LockerFullException_when_store_bag_given_locker_full) {
    Locker locker(1, Size::kSmall);

    locker.store({});

    ASSERT_THROW(locker.store({}), Locker::LockerFullException);
}

TEST(LockerTest, should_take_correct_bag_when_take_bag_given_valid_ticket) {
    Locker locker(1, Size::kSmall);
    Bag bag;
    auto optional_ticket = locker.store(&bag);

    Bag *got_bag = locker.take(optional_ticket.value());

    ASSERT_EQ(got_bag, &bag);
}

TEST(LockerTest, should_throw_InvalidTicketException_when_take_bag_given_fake_ticket) {
    Locker locker(1, Size::kSmall);
    auto fake_ticket = Ticket{666, Size::kSmall};

    ASSERT_THROW(locker.take(fake_ticket), Locker::InvalidTicketException);
}

TEST(LockerTest, should_throw_WrongTicketTypeException_when_take_bag_given_ticket_type_not_same_with_locker_type) {
    Locker locker(1, Size::kSmall);
    auto ticket = Ticket{66, Size::kLarge};

    ASSERT_THROW(locker.take(ticket), Locker::WrongTicketTypeException);
}
