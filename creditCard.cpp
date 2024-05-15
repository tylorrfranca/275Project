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

 void CreditCard::setLimit(int amount){
    credit = amount; 
} 


void CreditCard::setScore(int amount){
    score = amount; 
}



