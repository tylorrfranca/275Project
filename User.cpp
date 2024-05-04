#include "User.h"
#include <iostream> 
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std; 

User::User(std::string i, std::string n, double s, BankAccount *BankAcc) {
    this->id = i; 
    name = n; 
    salary = s; 
    account = BankAcc;
}

void User::deposit_monthly_salary(){
    account -> deposit(salary/12);
}

void User::print(std::ostream &outputFile) const {
    int space = name.find(' ');
    string fname = name.substr(0, space); // string before a space is the first name
    string lname = name.substr(space + 1); 

    outputFile << left << "|" << std::setw(16)<< id << "\t"
        << std::left << "|" << std::setw(14) << lname << "\t"
        << std::left << "|" << std::setw(14) << fname << "\t"
        << std::left << "|" << std::setw(18) << std::fixed << std::setprecision(2) << salary << "\t"
        << std::left << "|" << std::setw(16) << std::fixed << std::setprecision(2) <<salary/12 << "\t"
        << std::left << "|" << std::setw(12) << std::fixed << std::setprecision(2) << account->get_balance() <<  " | " <<"\n";
    
}