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
public:
    class LockerFullException : public std::exception {

    };

    class InvalidTicketException : public std::exception {

    };

    class WrongTicketTypeException : public std::exception {

    };

private:
    const int capacity_;
    int available_capacity_;
    const Size size_;
    std::unordered_map<Ticket, Bag *, Ticket::HashFunc> ticket_bag_map;
public:

    Locker(int capacity, Size size);

    std::optional<Ticket> store(Bag *bag);

    Bag *take(Ticket &ticket);
};


#endif //TDD_LOCKER_EXAM_LOCKER_H
