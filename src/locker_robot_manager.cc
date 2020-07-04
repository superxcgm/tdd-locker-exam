//
// Created by Yujia Li  on 2020/7/4.
//

#include "locker_robot_manager.h"

LockerRobotManager::LockerRobotManager(Locker *locker, PrimaryLockerRobot *primary_locker_robot,
                                       SuperLockerRobot *super_locker_robot) : locker_(locker), primary_locker_robot_(
        primary_locker_robot), super_locker_robot_(super_locker_robot) {

}

std::optional<Ticket> LockerRobotManager::store(Bag *bag) {
    switch (bag->size_) {
        case Size::kSmall:
            return locker_->store(bag);
        case Size::kMedium:
            return primary_locker_robot_->store(bag);
        case Size::kLarge:
            return super_locker_robot_->store(bag);
    }
    return {};
}

Bag *LockerRobotManager::take(const Ticket &ticket) {
    switch (ticket.size_) {
        case Size::kSmall:
            return locker_->take(ticket);
        case Size::kMedium:
            return primary_locker_robot_->take(ticket);
        case Size::kLarge:
            return super_locker_robot_->take(ticket);
    }
    return nullptr;
}
