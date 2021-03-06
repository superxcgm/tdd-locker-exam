//
// Created by Yujia Li  on 2020/7/4.
//

#ifndef TDD_LOCKER_EXAM_PRIMARY_LOCKER_ROBOT_H
#define TDD_LOCKER_EXAM_PRIMARY_LOCKER_ROBOT_H


#include <vector>
#include "locker.h"

class PrimaryLockerRobot : public LockerRobot {
public:

    explicit PrimaryLockerRobot(std::vector<Locker *> lockers);

    std::optional<Ticket> store(Bag *bag);
};


#endif //TDD_LOCKER_EXAM_PRIMARY_LOCKER_ROBOT_H
