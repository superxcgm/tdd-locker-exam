//
// Created by Yujia Li  on 2020/7/4.
//

#include "super_locker_robot.h"

SuperLockerRobot::SuperLockerRobot(std::vector<Locker *> lockers) : lockers_(std::move(lockers)) {

}

std::optional<Ticket> SuperLockerRobot::store(Bag *bag) {
    return lockers_[0]->store(bag);
}
