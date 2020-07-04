//
// Created by Yujia Li  on 2020/7/4.
//

#include "primary_locker_robot.h"

#include <utility>

PrimaryLockerRobot::PrimaryLockerRobot(std::vector<Locker *> lockers) : lockers_(std::move(lockers)) {

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
    for (auto &locker : lockers_) {
        if (locker->isReleasedAndNotUsedTicket(ticket)) {
            return locker->take(ticket);
        }
    }
    throw Locker::InvalidTicketException();
}
