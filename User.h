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
          User(std::string UserN, std::string UserP, std::string n, CheckingAccount* CkAcc, SavingsAccount* SvAcc, CreditCard* cc);



    /**
         Prints this employee's information to cout.
    */

          void print(std::ostream &outputFile) const;

      // transfers funds from savings account to checkings account
          void transerSavingsToCheckings(double amount);


      //transfers funds from savings account to credit card account
          void transerSavingsToCreditCard(double amount);


      //transfers funds from checkings account to savings account
          void transerCheckingToSavings(double amount);


      //transfers funds from checkings account to credit card account
          void transerCheckingToCreditCard(double amount);

          std::string get_UserName() const;

          std::string get_password() const;

    private:
          std::string UserName;
          std::string passWord; 
          std::string name;
          double salary;
          CheckingAccount* CkAccount;
          SavingsAccount* SvAccount; 
          CreditCard* CreditAcc;
};


#endif