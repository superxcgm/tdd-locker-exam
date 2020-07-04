//
// Created by Yujia Li  on 2020/7/4.
//

#ifndef TDD_LOCKER_EXAM_LOCKER_H
#define TDD_LOCKER_EXAM_LOCKER_H

#include <optional>
#include <unordered_map>
#include "ticket.h"
#include "bag.h"

class Locker {
    const int capacity_;
    int available_capacity_;
    std::unordered_map<Ticket, Bag *, Ticket::HashFunc> ticket_bag_map;
public:
    Locker(int capacity);

    std::optional<Ticket> store(Bag *bag);

    class LockerFullException : public std::exception {

    };

    Bag *take(Ticket &ticket);
};


#endif //TDD_LOCKER_EXAM_LOCKER_H
