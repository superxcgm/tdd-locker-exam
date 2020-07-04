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
    const Size size_;
    std::unordered_map<Ticket, Bag *, Ticket::HashFunc> ticket_bag_map;
public:

    Locker(int capacity, Size size);

    std::optional<Ticket> store(Bag *bag);

    Bag *take(const Ticket &ticket);

    bool isNotFull() {
        return capacity_ != ticket_bag_map.size();
    }

    bool isFull() {
        return !isNotFull();
    }

    bool isReleasedAndNotUsedTicket(const Ticket &ticket) {
        return ticket_bag_map.find(ticket) != ticket_bag_map.end();
    }

    Size getSize() {
        return size_;
    }
};


#endif //TDD_LOCKER_EXAM_LOCKER_H
