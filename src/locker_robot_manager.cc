//
// Created by Yujia Li  on 2020/7/4.
//

#include "locker_robot_manager.h"

LockerRobotManager::LockerRobotManager(Locker *locker, PrimaryLockerRobot *primary_locker_robot,
                                       SuperLockerRobot *super_locker_robot) : locker_(locker), primary_locker_robot_(
        primary_locker_robot), super_locker_robot_(super_locker_robot) {

}

std::optional<Ticket> LockerRobotManager::store(Bag *bag) {
    return locker_->store(bag);
}
