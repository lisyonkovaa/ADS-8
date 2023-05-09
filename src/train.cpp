// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train(): first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    Cage *nCage = new Cage;
    nCage->next = nullptr;
    nCage->prev = nullptr;
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
    int length = 1;
    Cage* current = first;
    if (!current->light) {
        current->light = true;
    }
    current = current->next;
    countOp++;
    while (true) {
        if (!current->light) {
        length++;
        current = current->next;
        countOp++;
        } else {
            current->light = false;
            int temporary_length = length;
            while (length) {
                current = current->prev;
                length--;
                countOp++;
            }
            if (!current->light) {
                return temporary_length;
            } else {
                while (temporary_length) {
                    current = current->next;
                    temporary_length--;
                    length++;
                    countOp++;
                }
            }
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
