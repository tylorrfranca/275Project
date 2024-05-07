
/*
Employee class 
Author: Tylor Franca
Version: 1.0.0
*/


#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "BankAccount.h"
#include <iostream> 

class Employee {
    public:

    /**
         Constructs an employee with a id, given name, salary, and
        bank account.
        @param i the id
        @param n the name
        @param s the annual salary
        @param BankAcc a pointer to the bank account
    */
          Employee(std::string i, std::string n, double s, BankAccount* BankAcc);
    /**
         Deposits one month's salary into the bank account.
    */
          void deposit_monthly_salary();


      /**
         Formats double to string with commas and no extra zeros.
    */
          std::string format(double income) const;


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