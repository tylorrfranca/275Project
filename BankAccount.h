
/*
BankAccount class 
Author: Tylor Franca
Version: 1.0.0
*/

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string> 
#include <fstream>
#include <iostream>


class BankAccount {
public:
   /**
      Constructs a bank account with a $2000 balance.
   */
   BankAccount();

   /**
      Deposits money into this account.
      @param amount the amount to deposit.
   */
   void deposit(double amount);


   /**
      Withdraws money from this account.
      @param amount the amount to withdraw.
   */
   void withdraw(double amount);

   /**
      Gets the balance of this account.
      @return the balance
   */
   double get_balance() const;

   /**
     Gets the id of this account.
     @return the balance
  */
    std::string get_id() const;
   /**
     Set id for bank account.
  */
    void set_id(std::string id);
private:
    std::string id;
    double balance;
};

#endif