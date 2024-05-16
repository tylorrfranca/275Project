#include "User.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std; 

// Default constructor for User class
User::User(){
};

// Parameterized constructor for User class
User::User(std::string UserN, std::string UserP, std::string n, CheckingAccount* CkAcc, SavingsAccount* SvAcc, CreditCard* cc) {
    this->UserName = UserN;
    passWord = UserP; 
    name = n; 
    CkAccount = CkAcc;
    SvAccount = SvAcc;
    CreditAcc = cc; 
}

// Transfers funds from savings to checking account
void User::transerSavingsToCheckings(double amount){
    if(amount < 0){
        cout << "Please enter a real amount of money (i.e. no negatives)\n";
    }
    else{
        if((SvAccount->get_balance()) >= amount){
            SvAccount->withdraw(amount); 
            CkAccount->deposit(amount);
        } else {
            cout << "Not enough funds\n";
        }
    }
}

// Transfers funds from savings account to credit card account
void User::transerSavingsToCreditCard(double amount){
    if(amount < 0){
        cout << "Please enter a real amount of money (i.e. no negatives)\n";
    }
    else{
        if((SvAccount->get_balance()) >= amount){
            SvAccount->withdraw(amount); 
            CreditAcc->withdraw(amount);
        } else {
            cout << "Not enough funds\n";
        } 
    }       
}

// Transfers funds from checking account to savings account
void User::transerCheckingToSavings(double amount){
    if(amount < 0){
        cout << "Please enter a real amount of money (i.e. no negatives)\n";
    }
    else{
        if((CkAccount->get_balance()) >= amount){
            CkAccount->withdraw(amount);
            SvAccount->deposit(amount);
        } else {
            cout << "Not enough funds\n";
        }  
    }       
}

// Returns credit limit
int User::getCreditLimit(){
    return CreditAcc->getAvailableCredit();
}

// Returns credit score 
int User::getCreditScore(){
    return CreditAcc->getScore();
}

// Transfers funds from checking account to credit card
void User::transerCheckingToCreditCard(double amount){
    if(amount < 0){
        cout << "Please enter a real amount of money (i.e. no negatives)\n";
    }
    else{
        if((CkAccount->get_balance()) >= amount){
            CkAccount->withdraw(amount);
            CreditAcc->withdraw(amount);
        } else {
            cout << "Not enough funds\n";
        }  
    }  
}

// Transfers credit money to checking account with fee
void User::creditToChecking(double amount){
    if(amount < 0){
        cout << "Please enter a real amount of money (i.e. no negatives)\n";
    }
    else{
        if((CreditAcc->get_balance()) >= amount){
            CkAccount->deposit(amount * 0.98); // Applying 2% fee
            CreditAcc->deposit(amount);
        } else {
            cout << "Not enough funds\n";
        } 
    }
}

// Transfers credit money to savings with a 2% fee 
void User::creditToSaving(double amount){
    if(amount < 0){
        cout << "Please enter a real amount of money (i.e. no negatives)\n";
    }
    else{
        if((CreditAcc->get_balance()) >= amount){
            SvAccount->deposit(amount * 0.98); // Applying 2% fee
            CreditAcc->deposit(amount);
        } else {
            cout << "Not enough funds\n";
        } 
    }
}

// Returns userName 
std::string User::get_UserName() const{
    return UserName;
}

// Returns name of user 
std::string User::get_name() const{
    return name;
}

// Returns password of user
std::string User::get_password() const{
    return passWord;
}

// Returns checking account balance 
double User::getCheckingBalance(){
    return CkAccount->get_balance(); 
}

// Returns savings account balance
double User::getSavingBalance(){
    return SvAccount->get_balance(); 
}

// Returns credit card balance
double User::getCreditBalance(){
    return CreditAcc->get_balance(); 
}

// Deposits amount into checking account
void User::Ckdeposit(double amount){
    CkAccount->deposit(amount);
}

// Withdraws amount from checking account
void User::Ckwithdraw(double amount){
    CkAccount->withdraw(amount);
}

// Deposits amount into savings account
void User::Svdeposit(double amount){
    SvAccount->deposit(amount);
}

// Withdraws amount from savings account
void User::Svwithdraw(double amount){
    SvAccount->withdraw(amount);
}

// Prints user information
void User::print(std::ostream &outputFile) const {
    int space = name.find(' ');
    string fname = name.substr(0, space); // String before a space is the first name
    string lname = name.substr(space + 1); 

    outputFile << left << "|" << std::setw(16)<< UserName << "\t"
        << std::left << "|" << std::setw(14) << lname << "\t"
        << std::left << "|" << std::setw(14) << fname << "\t"
        << std::left << "|" << std::setw(18) << std::fixed << std::setprecision(2) << salary << "\t"
        << std::left << "|" << std::setw(16) << std::fixed << std::setprecision(2) << salary/12 << "\t"
        << std::left << "|" << std::setw(12) << std::fixed << std::setprecision(2) << CkAccount->get_balance() << " | " <<"\n";
}