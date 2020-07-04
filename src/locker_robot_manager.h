//
// Created by Yujia Li  on 2020/7/4.
//

#ifndef TDD_LOCKER_EXAM_LOCKER_ROBOT_MANAGER_H
#define TDD_LOCKER_EXAM_LOCKER_ROBOT_MANAGER_H

#include "locker.h"
#include "optional"
#include "primary_locker_robot.h"
#include "super_locker_robot.h"

class LockerRobotManager {
    Locker *const locker_;
    PrimaryLockerRobot *const primary_locker_robot_;
    SuperLockerRobot *const super_locker_robot_;
public:
    LockerRobotManager(Locker *locker, PrimaryLockerRobot *primary_locker_robot, SuperLockerRobot *super_locker_robot);

    std::optional<Ticket> store(Bag *bag);

    Bag *take(const Ticket &ticket);
};


#endif //TDD_LOCKER_EXAM_LOCKER_ROBOT_MANAGER_H
