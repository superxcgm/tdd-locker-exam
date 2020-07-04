//
// Created by Yujia Li  on 2020/7/4.
//

#include "super_locker_robot.h"

#include <utility>

SuperLockerRobot::SuperLockerRobot(std::vector<Locker *> lockers) : LockerRobot(std::move(lockers), Size::kLarge) {
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
