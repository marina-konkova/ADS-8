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
    first->next = first;
    first->prev = first;
  } else {
    Cage *last = first->prev;
    last->next = newCage;
    newCage->prev = last;
    newCage->next = first;
    first->prev = newCage;
  }
}

int Train::getLength() {
  if (first == nullptr)
    return 0;

  int length = 1;
  Cage *current = first->next;

  while (current != first) {
    length++;
    current = current->next;
  }

  return length;
}

int Train::getOpCount() {
  return countOp;
}
