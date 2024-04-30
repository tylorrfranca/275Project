#include <iostream>
#include <string>
#include <fstream>

#ifndef CREDITCARD_H
#define CREDITCARD_H

using namespace std;

class CreditCard
{
  private:
    int number[];
    int score;
    int credit; //available credit
    double balance;
    //payment date?
    //transaction history?
    //struct Transaction?
    // Transaction Transactions[]
  public:
    double getBalance();
    double getScore();
    double getAvailableCredit();
}
