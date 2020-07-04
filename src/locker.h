//
// Created by Yujia Li  on 2020/7/4.
//

#ifndef TDD_LOCKER_EXAM_LOCKER_H
#define TDD_LOCKER_EXAM_LOCKER_H

#include <optional>
#include "ticket.h"
#include "bag.h"

class Locker {

public:
    Locker(int capacity);
    std::optional<Ticket> store(Bag *bag);
};


#endif //TDD_LOCKER_EXAM_LOCKER_H
