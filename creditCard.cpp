#include <iostream>
#include <string>
#include <fstream>
#include "creditCard.h"



using namespace std;
//Constructor
CreditCard::CreditCard() {}

//returns balance
double CreditCard::getBalance(){
    return balance;
}

//returns  credit score
double CreditCard::getScore(){
    return score;
}

//returns credit limit
double CreditCard::getAvailableCredit(){
    return credit; 
}

//sets credit limit
 void CreditCard::setLimit(int amount){
    credit = amount; 
} 

//sets credit score
void CreditCard::setScore(int amount){
    score = amount; 
}



