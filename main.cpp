#include <iostream>
#include <string>
#include <fstream>
#include "User.h"

#include <vector>


using namespace std; 


void goToLine(int n, std::ifstream& input){
    input.seekg(0);
    std::string line; 
    for(int i = 0; i < n; i++){
        input.ignore(100,'\n');
    }
}

vector<User> ReadandStoreData(){
    ifstream inputFile("Salary.txt");
    vector<User> listOfUsers; 
    string username, password, fName, lName; 
   
    CheckingAccount *checking; 
    SavingsAccount *saving; 
    CreditCard *credit; 


    goToLine(1,inputFile);
    while ((!inputFile.eof())) {
        inputFile >> username >> lName >> fName;
        checking = new CheckingAccount;

        string fullName = fName + " " + lName; 

        User user(username, password, fullName, checking, saving, credit); 

        listOfUsers.push_back(user); 
    }
    inputFile.close();

    return listOfUsers;
}


void MainMenu(const User* user){
    char choice;
    cout << "____________________________________________";
    cout << "|Welcome to the Franca Finance Application |\n"; 
    cout << "____________________________________________";
    cout << "Please select an option";
    cin >> choice;

    choice = tolower(choice);

    switch(choice){
        case 'a' :
            cout << " A) Checking Account" << endl; 
            break; 
        
        case 'b' :
            cout << "B) Savings Account" << endl; 
            break;

        case 'c' : 
            cout << "C) Credit Card" << endl; 
            break; 

        case 'x' :
            cout << "X) Exit" << endl;
            break; 
    }

        
}

bool LogInPage(vector<User>& users){
    bool access = false; 
    string userName, password, userCompare, passCompare;
    cout << "____________________________________________\n";
    cout << "|Welcome to the Franca Finance Application |\n"; 
    cout << "|              Please Log In               |\n";
    cout << "____________________________________________\n";
    cout << "" << endl; 
    
    while(!false){
        cout << "UserName: " << endl; 
        cin >> userName; 

        cout << "Password: " << endl; 
        cin >> password;



        for (const auto& user : users){
            userCompare = user.get_UserName();
            passCompare = user.get_password(); 

            if(userCompare == userName && passCompare == password){
                access = true;
                break;  
            }
        }
        cout << "Incorrect UserName or Password, please try again" << endl; 
    }

}

int main(){











//    CheckingAccount *CkAccount = new CheckingAccount;
//    SavingsAccount *SvAccount = new SavingsAccount; 
//    CreditCard *CcAccount = new CreditCard;

//    User Tylor("0123", "456" "Tylor", CkAccount, SvAccount, CcAccount);

//    cout << CkAccount -> get_balance() << endl;
//    CkAccount -> deposit(200);
//    cout << CkAccount -> get_balance() << endl;

//    cout << SvAccount -> get_balance() << endl;
//    SvAccount -> deposit(200);
//    cout << SvAccount -> get_balance() << endl;
     
    return 0; 
}



