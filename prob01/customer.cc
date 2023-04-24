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
// This program performs recursion to retrieve information from customers in
// a market line
//

#include "customer.h"

// ========================= YOUR CODE HERE =========================
// This implementation file (customer.cc) is where you should implement
// the member functions declared in the header (customer.h), only
// if you didn't implement them inline within customer.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the Customer class.
// ===================================================================
Customer::Customer(const std::string& name, int product_count,
                   std::shared_ptr<Customer> next_customer)
    : name_(name),
      product_count_(product_count),
      next_customer_(next_customer) {}
std::string Customer::GetName() const {
  return name_;
}
int Customer::GetProductCount() const {
  return product_count_;
}
std::shared_ptr<Customer> Customer::GetNextCustomer() const {
  return next_customer_;
}
int Customer::TotalCustomersInLine() {
  if (next_customer_ == nullptr) {
    return 1;
  } else {
    return 1 + next_customer_->TotalCustomersInLine();
  }
}
int Customer::TotalProductsInLine() {
  if (next_customer_ == nullptr) {
    return product_count_;
  } else {
    return product_count_ + next_customer_->TotalProductsInLine();
  }
}
std::string Customer::FirstAlphabeticalCustomerInLine() {
  if (next_customer_ == nullptr) {
    return name_;
  } else {
    if (next_customer_->FirstAlphabeticalCustomerInLine() > name_) {
      return name_;
    } else {
      return next_customer_->FirstAlphabeticalCustomerInLine();
    }
  }
}
