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
    void setLimit(int amount); 
    void setScore(int amount);


  private:
    int score;
    double credit; 
    double balance;
};

#endif