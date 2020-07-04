//
// Created by Yujia Li  on 2020/7/4.
//

#include <vector>
#include "locker_robot.h"

LockerRobot::LockerRobot(std::vector<Locker *> lockers, Size size) : lockers_(std::move(lockers)), size_(size) {
    for (auto &locker : lockers_) {
        if (locker->getSize() != size_) {
            throw WrongConfigException();
        }
        if (locker->hasManager()) {
            throw WrongConfigException();
        }
        locker->setManager(this);
    }
}

Bag *LockerRobot::take(const Ticket &ticket) {
    if (ticket.size_ != size_) {
        throw Locker::WrongTicketTypeException();
    }
    for (auto &locker : lockers_) {
        if (locker->isReleasedAndNotUsedTicket(ticket)) {
            return locker->take(ticket);
        }
    }
    throw Locker::InvalidTicketException();
}
