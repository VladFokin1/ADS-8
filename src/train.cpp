// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), current(nullptr), countOp(0) {}

Train::Cage* Train::create(bool light) {
  Cage* newCage = new Cage;
  newCage->light = light;
  newCage->next = nullptr;
  newCage->prev = nullptr;
  return newCage;
}

void Train::addCage(bool light) {
  if (first && last) {
    last->next = create(light);
    last->next->prev = last;
    last = last->next;
    last->next = first;
    first->prev = last;
  } else {
    first = last = create(light);
  }
}

int Train::getLength() {
  
}

int Train::getOpCount() {
  return countOp;
}
