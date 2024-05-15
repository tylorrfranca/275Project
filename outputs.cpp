#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

void generateStatement(int items, bool savings){
/*
items: number of items to be generated below header

savings = 1: generate Checking Account statement
Savings = 0: generate credit card statement
*/
    

    std:ofstream out;

    if (savings){
        out.open("Checking Account Statement");
    }
    else{
        out.open("Credit Card Statement");
    };
    

    //formatting header:
    out << "Statement for ";
    if (savings){
        out << "Checking Account";
    }
    else{
        out << "Credit Card";
    };
    out << " May 24: \n" << endl;
    out << "Date" << setw(25) << "Category" << setw(35) << "Withdrawals"<< endl;

    //creating fake dates, categories, and withdrawals
    int month[items], day[items], category[items], withdrawals[items];
    for (int x = 0; x < items ; x++){   //for loop goes for as many items as desired
        month[x] = 5;       //and creates random values for as many registers
        day[x] = rand() % 31+1;         //in the array as items
        category[x] = rand() % 4;
        withdrawals[x] = rand() % 15000;
    }

    //formatting dates, categories & withdrawals for out 
    string ctgry;
    for (int y = 0; y < items; y++) {   //checking category to turn random 
        if (category[y] == 0) {         //number in array into an actual value
            ctgry = "Grocery";
        }
        else if (category[y] == 1) {
            ctgry = "Utilities";
        }
        else if (category[y] == 2) {
            ctgry = "Insurance";
        } 
        else if (category[y] == 3) {
            ctgry = "Travel";
        }   
        else {
            ctgry = "Mortgage";
        }

        int year = 2024;
        
        //formatting dollar amount
        int cost = withdrawals[y];
        string price = to_string(cost / 100);
        price += ".";
        if (cost % 100 < 10){
            price = price + '0' + to_string(cost %100);
        }
        else{
            price += to_string(cost %100);
        }

        //outputting values formatted in columns
        out << month[y]<< "-" << day[y] << "-"<< year << setw(20) << ctgry;
        out << setw(30)  <<"$"<< price<< endl;
    }

    out.close();    //close the file

}
