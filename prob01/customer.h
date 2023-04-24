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

#include <memory>
#include <string>

class Customer {
 public:
  // ====================== YOUR CODE HERE ======================
  // 1. Define a constructor using member initializer list syntax
  //    according to the README.
  // 2. Define the accessor functions (i.e. the getter functions)
  //    `GetName`, `GetProductCount`, and `GetNextCustomer`.
  //    You do not need to create mutator functions (setters).
  // 3. Define the recursive functions specified in the README.
  // ============================================================
  Customer(const std::string& name, int product_count,
           std::shared_ptr<Customer> next_customer);
  std::string GetName() const;
  int GetProductCount() const;
  std::shared_ptr<Customer> GetNextCustomer() const;
  int TotalCustomersInLine();
  int TotalProductsInLine();
  std::string FirstAlphabeticalCustomerInLine();

 private:
  std::string name_;
  int product_count_;
  std::shared_ptr<Customer> next_customer_;
};
