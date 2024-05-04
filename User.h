/*
Employee class 
Author: Tylor Franca
Version: 1.0.0
*/


#ifndef USER_H
#define USER_H

#include "BankAccount.h"
#include <iostream> 

class User {
    public:

    /**
         Constructs an employee with a id, given name, salary, and
        bank account.
        @param i the id
        @param n the name
        @param s the annual salary
        @param BankAcc a pointer to the bank account
    */
          User(std::string i, std::string n, double s, BankAccount* BankAcc);
    /**
         Deposits one month's salary into the bank account.
    */
          void deposit_monthly_salary();


    /**
         Prints this employee's information to cout.
    */

          void print(std::ostream &outputFile) const;

    private:
          std::string id;
          std::string name;
          double salary;
          BankAccount* account;
};


#endif