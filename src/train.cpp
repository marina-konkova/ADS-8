// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
  Cage *newCage = new Cage;
  newCage->light = light;
  newCage->next = nullptr;
  newCage->prev = nullptr;
  if (first == nullptr) {
    first = newCage;
    first->next = newCage;
    first->prev = first;
  } else {
    newCage->next = first->next;
    newCage->prev = first;
    first->next->prev = newCage;
    first->prev = newCage;
  }
}

int Train::getLength() {
  if (first == nullptr)
    return 0;
  Cage *current = first;
  current->light = true;
  int length = 1;
  while (true) {
        current = current->next;
        if (current->light == false) {
            length++;
            countOp++;
        }  else {
            countOp++;
            current->light = false;
            for (int i = length; i > 0; i--) {
                current = current->prev;
                countOp++;
            }
            if (current->light == false)
                return length;
            length = 1;
        }
    }
}

int Train::getOpCount() {
  return countOp;
}
