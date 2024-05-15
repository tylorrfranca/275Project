#include "User.h"
#include <iostream> 
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std; 

User::User(){

};

User::User(std::string UserN, std::string UserP, std::string n, CheckingAccount* CkAcc, SavingsAccount* SvAcc, CreditCard* cc)
 {
    this->UserName = UserN;
    passWord = UserP; 
    name = n; 
    CkAccount = CkAcc;
    SvAccount = SvAcc;
    CreditAcc = cc; 
}

void User::transerSavingsToCheckings(double amount){
    SvAccount->withdraw(amount); 
    CkAccount->deposit(amount);
}

      //transfers funds from savings account to credit card account
void User::transerSavingsToCreditCard(double amount){
    SvAccount->withdraw(amount); 
    CreditAcc->withdraw(amount);
}


      //transfers funds from checkings account to savings account
void User:: transerCheckingToSavings(double amount){
    CkAccount->withdraw(amount);
    SvAccount->deposit(amount);
}

int User::getCreditLimit(){
    return CreditAcc->getAvailableCredit();
}

int User::getCreditScore(){
    return CreditAcc->getScore();
}


      
void User::transerCheckingToCreditCard(double amount){
    CkAccount->withdraw(amount);
    CreditAcc->withdraw(amount);
}

void User::creditToChecking(double amount){
    CkAccount->deposit(amount* 0.98);
    CreditAcc->deposit(amount);
}

void User::creditToSaving(double amount){
    SvAccount->deposit(amount * 0.98);
    CreditAcc->deposit(amount);
}


std::string User::get_UserName() const{
    return UserName;
}

std::string User::get_password() const{
    return passWord;
}

double User::getCheckingBalance(){
    return CkAccount->get_balance(); 
 }

double User::getSavingBalance(){
    return SvAccount->get_balance(); 
 }

double User::getCreditBalance(){
    return CreditAcc->get_balance(); 
 }

void User::Ckdeposit(double amount){
    CkAccount->deposit(amount);
 }

 void User::Ckwithdraw(double amount){
    CkAccount->withdraw(amount);
 }

 void User::Svdeposit(double amount){
    SvAccount->deposit(amount);
 }

 void User::Svwithdraw(double amount){
    SvAccount->withdraw(amount);
 }



void User::print(std::ostream &outputFile) const {
    int space = name.find(' ');
    string fname = name.substr(0, space); // string before a space is the first name
    string lname = name.substr(space + 1); 

    outputFile << left << "|" << std::setw(16)<< UserName << "\t"
        << std::left << "|" << std::setw(14) << lname << "\t"
        << std::left << "|" << std::setw(14) << fname << "\t"
        << std::left << "|" << std::setw(18) << std::fixed << std::setprecision(2) << salary << "\t"
        << std::left << "|" << std::setw(16) << std::fixed << std::setprecision(2) <<salary/12 << "\t"
        << std::left << "|" << std::setw(12) << std::fixed << std::setprecision(2) << CkAccount->get_balance() <<  " | " <<"\n";
    
}