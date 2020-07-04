//
// Created by Yujia Li  on 2020/7/4.
//

#include "primary_locker_robot.h"

PrimaryLockerRobot::PrimaryLockerRobot(std::vector<Locker *> lockers) : lockers_(lockers) {

}

std::optional<Ticket> PrimaryLockerRobot::store(Bag *bag) {
    for (auto &locker : lockers_) {
        if (locker->isNotFull()) {
            return locker->store(bag);
        }
    }
    return {};
}
