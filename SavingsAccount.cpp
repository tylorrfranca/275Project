/*
Savings Account class 
Author: Tylor Franca
Version: 1.0.0
*/


#include "SavingsAccount.h"
#include <string> 
#include <fstream>
#include <iostream>

   /**
      Constructs a Savings account with a $1000 balance.
   */

  // balance not being initialized correctly, needs fix
SavingsAccount::SavingsAccount() : balance(1000){
    balance = 200;
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

