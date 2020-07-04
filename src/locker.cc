//
// Created by Yujia Li  on 2020/7/4.
//

#include "locker.h"

Locker::Locker(int capacity, Size size) : capacity_(capacity), size_(size) {}

std::optional<Ticket> Locker::store(Bag *bag) {
    if (isFull()) {
        throw LockerFullException();
    }
    Ticket ticket = Ticket::GenerateTicket(size_);
    ticket_bag_map[ticket] = bag;
    return ticket;
}

Bag *Locker::take(Ticket &ticket) {
    if (ticket.size_ != size_) {
        throw WrongTicketTypeException();
    }
    if (ticket_bag_map.find(ticket) != ticket_bag_map.end()) {
        auto bag = ticket_bag_map[ticket];
        ticket_bag_map.erase(ticket);
        return bag;
    }
    throw InvalidTicketException();
}
