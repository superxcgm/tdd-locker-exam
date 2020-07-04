//
// Created by Yujia Li  on 2020/7/4.
//

#include "locker.h"

Locker::Locker(int capacity) : capacity_(capacity), available_capacity_(capacity) {}

std::optional<Ticket> Locker::store(Bag *bag) {
    if (available_capacity_ <= 0) {
        throw LockerFullException();
    }
    --available_capacity_;
    Ticket ticket = Ticket::GenerateTicket();
    ticket_bag_map[ticket] = bag;
    return ticket;
}

Bag *Locker::take(Ticket &ticket) {
    if (ticket_bag_map.find(ticket) != ticket_bag_map.end()) {
        return ticket_bag_map[ticket];
    }
    return nullptr;
}
