#include "Employee.h"
#include <iostream> 
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std; 

// creates an employee with 4 parameters
Employee::Employee(std::string i, std::string n, double s, BankAccount *BankAcc) {
    this->id = i; 
    name = n; 
    salary = s; 
    account = BankAcc;
}

// deposits the monthly salary of employee to bank balance
void Employee::deposit_monthly_salary(){
    account -> deposit(salary/12);
}

// function that takes double variable and returns a string with commas and no extra zeros 
string Employee::format(double income) const{
        string incomeStr; 
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(2) << income;  // Set decimal precision
        incomeStr = stream.str();
        
        int pos = incomeStr.find('.');   // finds position of decimal and starts adding commas from there
        int n = pos - 3;
        
        while (n > 0) {         // while n is not the last index we add a comma every 3 numbers
        incomeStr.insert(n, ",");
        n -= 3;
        }
        return incomeStr;   // returns amount as a formated string
}
void Employee::print(std::ostream &outputFile) const {
    //String Variables to be able to print out amounts formattes
    double monthlySal = salary/12; 
    string salaryStr = format(salary); 
    string monthlySalStr = format(monthlySal); 
    string accountStr = format(account->get_balance());



    int space = name.find(' ');
    string fname = name.substr(0, space); // string before a space is the first name
    string lname = name.substr(space + 1); 

    //output table
    outputFile << left << "|" << " " << std::setw(16)<< id << "\t"
        << std::left << "|" << " " << std::setw(12) << lname << "\t"
        << std::left << "|" << " " << std::setw(12) << fname << "\t"
        << std::left << "|" << " $" << std::setw(14) << std::fixed << std::left << std::setprecision(5) << salaryStr << "\t"
        << std::left << "|" << " $" << std::setw(14) << std::fixed << std::setprecision(2) << monthlySalStr << "\t"
        << std::left << "|" << " $" << std::setw(10) << std::fixed << std::setprecision(2) << accountStr <<  " | " <<"\n";
    
}

