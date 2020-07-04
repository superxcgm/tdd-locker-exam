//
// Created by Yujia Li  on 2020/7/4.
//

#ifndef TDD_LOCKER_EXAM_LOCKER_ROBOT_H
#define TDD_LOCKER_EXAM_LOCKER_ROBOT_H


#include "locker.h"
#include "vector"
#include "ticket.h"

class Locker;

class LockerRobot {
protected:
    LockerRobot(std::vector<Locker *> lockers, Size size);
    std::vector<Locker *> lockers_;
    const Size size_;
public:
    ~LockerRobot() = default;
    Bag * take(const Ticket & ticket);
};


#endif //TDD_LOCKER_EXAM_LOCKER_ROBOT_H
