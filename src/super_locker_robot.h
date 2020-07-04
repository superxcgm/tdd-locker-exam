//
// Created by Yujia Li  on 2020/7/4.
//

#ifndef TDD_LOCKER_EXAM_SUPER_LOCKER_ROBOT_H
#define TDD_LOCKER_EXAM_SUPER_LOCKER_ROBOT_H

#include "vector"
#include "ticket.h"
#include "locker.h"

class SuperLockerRobot {
    std::vector<Locker *> lockers_;
public:
    explicit SuperLockerRobot(std::vector<Locker *> lockers);

    std::optional<Ticket> store(Bag *bag);
};


#endif //TDD_LOCKER_EXAM_SUPER_LOCKER_ROBOT_H

