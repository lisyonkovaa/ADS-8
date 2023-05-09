// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCage(bool light) {
    Cage *nCage = new Cage;
    nCage->light = light;
    if (first == nullptr) {
        nCage->next = nCage;
        nCage->prev = nCage;
        first = nCage;
    } else {
        nCage->next = first;
        nCage->prev = first->prev;
        first->prev->next = nCage;
        first->prev = nCage;
    }
}

int Train::getLength() {
    int length = 0;
    Cage *current = first;
    do {
        length++;
        current = current->next;
    } while (current != first);
        return length;
}

int Train::getOpCount() {
    return countOp;
}
