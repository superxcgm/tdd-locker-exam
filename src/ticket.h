//
// Created by Yujia Li  on 2020/7/4.
//

#ifndef TDD_LOCKER_EXAM_TICKET_H
#define TDD_LOCKER_EXAM_TICKET_H


#include <cstdlib>
#include <functional>
#include "size.h"

struct Ticket {
private:
    static int id_count_;
public:
    int id_;
    Size size_;

    Ticket(int id, Size size) : id_(id), size_(size) {}

    static Ticket GenerateTicket(Size size) {
        return Ticket{++id_count_, size};
    }

    bool operator==(const Ticket &rhs) const {
        return id_ == rhs.id_;
    }

    bool operator!=(const Ticket &rhs) const {
        return !(rhs == *this);
    }

    struct HashFunc {
        std::size_t operator()(const Ticket &ticket) const {
            return std::hash<int>()(ticket.id_);
        }
    };
};


#endif //TDD_LOCKER_EXAM_TICKET_H
