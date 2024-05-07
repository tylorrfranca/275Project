/*
Savings Account class 
Author: Tylor Franca
Version: 1.0.0
*/

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "BankAccount.h"
#include <string> 
#include <fstream>
#include <iostream>

class SavingsAccount : public BankAccount {
public:
   /**
      Constructs a bank account with a $2000 balance.
   */
   SavingsAccount();


   void withdraw(double amount) override;


private:
    std::string id;
    double balance;
};


#endif