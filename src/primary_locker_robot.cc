//
// Created by Yujia Li  on 2020/7/4.
//

#include "primary_locker_robot.h"

#include <utility>

PrimaryLockerRobot::PrimaryLockerRobot(std::vector<Locker *> lockers) : lockers_(std::move(lockers)) {
    for (auto &locker : lockers_) {
        if (locker->getSize() != Size::kMedium) {
            throw WrongConfigException();
        }
    }
}

std::optional<Ticket> PrimaryLockerRobot::store(Bag *bag) {
    for (auto &locker : lockers_) {
        if (locker->isNotFull()) {
            return locker->store(bag);
        }
    }
    throw Locker::LockerFullException();
}

Bag *PrimaryLockerRobot::take(const Ticket &ticket) {
    if (ticket.size_ != Size::kMedium) {
        throw Locker::WrongTicketTypeException();
    }
    for (auto &locker : lockers_) {
        if (locker->isReleasedAndNotUsedTicket(ticket)) {
            return locker->take(ticket);
        }
    }
    throw Locker::InvalidTicketException();
}
