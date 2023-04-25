// Brian Milian
// CPSC 121L-01
// 2023-04-17
// brianmilian@csu.fullerton.edu
// @brian-250
//
// Lab 12-1
// If it is a pair programming lab please specify partner below.
// Partner: @peteranteater
//
// This program performs recursion to retrieve and change information
// from a train and it's carriages
//

#include "train.h"

// ========================= YOUR CODE HERE =========================
// This implementation file (train.cc) is where you should implement
// the member functions declared in the header (train.h), only
// if you didn't implement them inline within train.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the Train class.
// ===================================================================
int Train::TotalTrainPassengers() {
  if (next_carriage_ == nullptr) {
    return passenger_count_;
  } else {
    return passenger_count_ + next_carriage_->TotalTrainPassengers();
  }
}
int Train::MaxCarriagePassengers() {
  if (next_carriage_ == nullptr) {
    return passenger_count_;
  } else {
    if (next_carriage_->MaxCarriagePassengers() < passenger_count_) {
      return passenger_count_;
    } else {
      return next_carriage_->MaxCarriagePassengers();
    }
  }
}
bool Train::IsTrainFull() {
  if (next_carriage_ == nullptr) {
    return passenger_count_ == seat_count_;
  } else {
    return next_carriage_->IsTrainFull();
  }
}
void Train::AddCarriageToEnd(std::shared_ptr<Train> train) {
  if (next_carriage_ == nullptr) {
    next_carriage_ = train;
  } else {
    next_carriage_->AddCarriageToEnd(train);
  }
}
