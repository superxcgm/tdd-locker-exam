//
// Created by Yujia Li  on 2020/7/4.
//

#include "primary_locker_robot.h"

PrimaryLockerRobot::PrimaryLockerRobot(std::vector<Locker *> lockers) : lockers_(lockers) {

}

std::optional<Ticket> PrimaryLockerRobot::store(Bag *bag) {
    return lockers_[0]->store(bag);
}
