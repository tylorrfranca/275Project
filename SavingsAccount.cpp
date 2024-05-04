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
      Constructs a Savings account with a $0 balance.
   */
   SavingsAccount::SavingsAccount(){
    balance = 1000;
   }

   void SavingsAccount::withdraw(double amount){
    if(amount > balance){
        std::cout << "Not enough Funds\n"; 
    }
    else{
        balance -= amount;
        if(balance < 300){
        std::cout << "Saving Account dropping below $300 \n"; 
        } 
    }
}


private:
    std::string id;
    double balance;
};

#endif