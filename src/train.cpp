// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    begin = nullptr;
    countOp = 0;
}

int Train::getLength() {
    if (begin == nullptr) {
        return 0;
    }

    int length = 1;
    Сarriage *cur = begin->next;

    while (current != begin) {
        length++;
        cur = cur->next;
    }

    return length;
}

void Train::addCage(bool light) {
    Сarriage *carriage = new Сarriage;
    carriage->light = light;
    carriage->next = nullptr;
    carriage->previous = nullptr;

    if (begin == nullptr) {
        begin = carriage;
        begin->next = begin;
        begin->previous = begin;
    } else {
        carriage->next = begin;
        carriage->previous = begin->previous;
        begin->previous->next = carriage;
        begin->previous = carriage;
    }
}

int Train::getOpCount() {
    return countOp;
}