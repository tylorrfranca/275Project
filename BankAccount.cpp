#include "BankAccount.h"
#include <iostream> 

//creates a balance of $2000
BankAccount::BankAccount(){}

// adds an amount to bank balance
void BankAccount::deposit(double amount){
    balance += amount; 
}

//takes away an amount from bank balnce 
void BankAccount::withdraw(double amount){
    if(amount > balance){
        std::cout << "Not enough Funds\n"; 
    }
    balance -= amount; 
}

//returns balance amount
double BankAccount::get_balance() const{
    return balance;
}

//returns ID number
std::string BankAccount::get_id() const{
    return id;
}

// creates an ID for Bank Account that matches Employee ID
void BankAccount::set_id(std::string id){
    this->id = id; 
}
