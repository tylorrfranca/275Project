/*
Savings Account class 
Author: Tylor Franca
Version: 1.0.0
*/

#ifndef CHECKINGS_ACCOUNT_H
#define CHECKINGS_ACCOUNT_H

#include "BankAccount.h"
#include <string> 
#include <fstream>
#include <iostream>

class CheckingAccount : public BankAccount {
public:
   /**
      Constructs a checking account with a $0 balance.
   */
   CheckingAccount();
   



private:
    std::string id;
    double balance;
};

#endif