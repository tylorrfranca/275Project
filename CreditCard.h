#include <iostream>
#include <string>
#include <fstream>
#include "BankAccount.h"

#ifndef CREDITCARD_H
#define CREDITCARD_H

using namespace std;

class CreditCard : public BankAccount
{
  public:
  CreditCard();

    double getBalance();
    double getScore();
    double getAvailableCredit();


  private:
    int score;
    int credit; //available credit
    double balance;
    //payment date?
    //transaction history?
    //struct Transaction?
    // Transaction Transactions[]
};

#endif