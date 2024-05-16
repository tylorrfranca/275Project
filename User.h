/*
Employee class 
Author: Tylor Franca
Version: 1.0.0
*/


#ifndef USER_H
#define USER_H

#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditCard.h"

#include <iostream> 

class User {
    public:
          // Default constructor
          User();

          // Parameterized constructor
          User(std::string UserN, std::string UserP, std::string n, CheckingAccount* CkAcc, SavingsAccount* SvAcc, CreditCard* cc);

          /**
           * Prints this employee's information to outputFile.
           */
          void print(std::ostream &outputFile) const;

          // Transfers funds from savings account to checking account
          void transerSavingsToCheckings(double amount);

          // Transfers funds from savings account to credit card account
          void transerSavingsToCreditCard(double amount);

          // Transfers funds from checking account to savings account
          void transerCheckingToSavings(double amount);

          // Transfers funds from checking account to credit card account
          void transerCheckingToCreditCard(double amount);

          // Returns the credit limit
          int getCreditLimit();

          // Returns the credit score
          int getCreditScore();

          // Transfers credit money to checking account with fee
          void creditToChecking(double amount);

          // Transfers credit money to savings account with fee
          void creditToSaving(double amount);

          // Returns the balance of checking account
          double getCheckingBalance();

          // Returns the balance of savings account
          double getSavingBalance();

          // Returns the balance of credit card account
          double getCreditBalance();

          // Deposits amount into checking account
          void Ckdeposit(double amount);

          // Withdraws amount from checking account
          void Ckwithdraw(double amount);

          // Deposits amount into savings account
          void Svdeposit(double amount);

          // Withdraws amount from savings account
          void Svwithdraw(double amount);

          // Returns the user name
          std::string get_UserName() const;

          // Returns the password
          std::string get_password() const;

          // Returns the name
          std::string get_name() const; 

    private:
          std::string UserName; // User name
          std::string passWord; // Password
          std::string name; // Name
          double salary; // Salary
          CheckingAccount* CkAccount; // Pointer to checking account
          SavingsAccount* SvAccount; // Pointer to savings account
          CreditCard* CreditAcc; // Pointer to credit card account
};

#endif