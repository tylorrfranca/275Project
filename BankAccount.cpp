#include "BankAccount.h"
#include <iostream> 

//creates a balance of $2000
BankAccount::BankAccount(){
    balance = 0; 
}

// adds an amount to bank balance
void BankAccount::deposit(double amount){
    if(amount < 0){
     std::cout << "Please enter a real amount a money(i.e. no negatives)\n";
    }else{
        balance += amount; 
    }
}

//takes away an amount from bank balnce 
void BankAccount::withdraw(double amount){
    if(amount > balance || amount < 0){
        std::cout << "Not enough Funds\n"; 
    }
    else{
        balance -= amount; 
    }
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

