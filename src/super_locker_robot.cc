//
// Created by Yujia Li  on 2020/7/4.
//

#include "super_locker_robot.h"

SuperLockerRobot::SuperLockerRobot(std::vector<Locker *> lockers) : lockers_(std::move(lockers)) {

}

std::optional<Ticket> SuperLockerRobot::store(Bag *bag) {
    Locker *highest_empty_ratio_locker = nullptr;
    for (auto &locker: lockers_) {
        if (highest_empty_ratio_locker == nullptr) {
            highest_empty_ratio_locker = locker;
            continue;
        }
        if (locker->getEmptyRatio() > highest_empty_ratio_locker->getEmptyRatio()) {
            highest_empty_ratio_locker = locker;
        }
    }
    return highest_empty_ratio_locker->store(bag);
}

Bag *SuperLockerRobot::take(const Ticket &ticket) {
    if (ticket.size_ != Size::kLarge) {
        throw Locker::WrongTicketTypeException();
    }
    for (auto &locker : lockers_) {
        if (locker->isReleasedAndNotUsedTicket(ticket)) {
            return locker->take(ticket);
        }
    }
    throw Locker::InvalidTicketException();
}
