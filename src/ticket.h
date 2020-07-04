//
// Created by Yujia Li  on 2020/7/4.
//

#ifndef TDD_LOCKER_EXAM_TICKET_H
#define TDD_LOCKER_EXAM_TICKET_H


#include <cstdlib>
#include <functional>

struct Ticket {
private:
    Ticket(int id) : id_(id) {}

    static int id_count_;
public:
    int id_;

    static Ticket GenerateTicket() {
        return Ticket{++id_count_};
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
