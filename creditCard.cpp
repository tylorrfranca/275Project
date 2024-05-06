#include <iostream>
#include <string>
#include <fstream>
#include "creditCard.h"



using namespace std;

CreditCard::CreditCard() {}

double CreditCard::getBalance(){
    return balance;
}

double CreditCard::getScore(){
    return score;
}

double CreditCard::getAvailableCredit(){
    return credit; 
}


