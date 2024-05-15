#include <iostream>
#include <string>
#include <fstream>
#include "User.h"

#include <vector>


using namespace std; 

int main(); 
void MainMenu(User &user);

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
    double ckBalance, svBalance, ccBalance; 

   
    CheckingAccount *checking; 
    SavingsAccount *saving; 
    CreditCard *credit; 


    goToLine(1,inputFile);
    while ((!inputFile.eof())) {
        inputFile >> username >> password>> lName >> fName >> ckBalance >> svBalance >> ccBalance; 
        checking = new CheckingAccount;
        saving = new SavingsAccount; 
        credit = new CreditCard; 

        string fullName = fName + " " + lName; 
        checking->deposit(ckBalance); 
        saving->deposit(svBalance);
        credit->deposit(ccBalance);

        User user(username, password, fullName, checking, saving, credit); 

        listOfUsers.push_back(user); 
    }
    inputFile.close();

    return listOfUsers;
}

void CreditMenu(User &user){
    char choice;
    cout << "____________________________________________ \n";
    cout << "|          Credit Card Account Menu         |\n"; 
    cout << "|              Balance: $" << user.getCreditBalance() << "               |\n"; 
    cout << "____________________________________________\n";
    cout << "Please select an option\n";
    cout << "A) Pay off Card" << endl; 
    cout << "B) Transfer to Checking with 2% fee" << endl; 
    cout << "C) Transfer To Saving with 2% fee" << endl;
    cout << "D) View FICO Credit Score" << endl;
    cout << "E) View Monthly Statement" << endl;
    cout << "X) Main Menu" << endl;
    cin >> choice;

    choice = tolower(choice);

    switch(choice){
        case 'a' :
           CreditMenu(user);
           break; 
        
        case 'b' :
           double transferToCkAmount; 
           cout << "How much would you like to transfer to  your Checkings Account?" << endl; 
           cout << "$"; 
           cin >> transferToCkAmount; 
           user.creditToChecking(transferToCkAmount);
           CreditMenu(user);
           break; 

        case 'c' :
           double transferToSvAmount; 
           cout << "How much would you like to transfer to your Savings Account?" << endl; 
           cout << "$"; 
           cin >> transferToSvAmount; 
           user.creditToSaving(transferToSvAmount);
           CreditMenu(user);
           break; 
            
        case 'd' : 
            cout << "705" << endl; //need random data here
            CreditMenu(user);
            break; 

        case 'e' : 
            //need random data to be output here
            break; 

        case 'x' :
            MainMenu(user);
            break; 
    }
}

void SavingMenu(User &user){
    char choice;
    cout << "____________________________________________ \n";
    cout << "|           Savings Account Menu           |\n"; 
    cout << "|              Balance: $" << user.getSavingBalance() << "               |\n"; 
    cout << "____________________________________________\n";
    cout << "Please select an option\n";
    cout << "A) Deposit" << endl; 
    cout << "B) Withdrawl" << endl; 
    cout << "C) Transfer To Checking" << endl;
    cout << "D) View Last Statement" << endl;
    cout << "X) Main Menu" << endl;
    cin >> choice;

    choice = tolower(choice);

    switch(choice){
        case 'a' :
           double depositAmount; 
           cout << "How much would you like to deposit?" << endl; 
           cout << "$"; 
           cin >> depositAmount; 
           user.Svdeposit(depositAmount);
           SavingMenu(user);
           break; 
        
        case 'b' :
           double withdrawAmount; 
           cout << "How much would you like to withdraw?" << endl; 
           cout << "$"; 
           cin >> withdrawAmount; 
           user.Svwithdraw(withdrawAmount);
           SavingMenu(user);
           break; 

        case 'c' : 
           double transferAmount; 
           cout << "How much would you like to transfer to your checking account?" << endl; 
           cout << "$"; 
           cin >> transferAmount; 
           user.transerSavingsToCheckings(transferAmount);
           SavingMenu(user);
           break; 
            
        case 'd' : 
            //need Someone to add a random file that generates this data 
            break; 

        case 'x' :
            MainMenu(user);
            break; 
    }
}


void CheckingMenu(User &user){
    char choice;
    cout << "____________________________________________ \n";
    cout << "|           Checking Account Menu          |\n"; 
    cout << "|              Balance: $" << user.getCheckingBalance() << "               |\n"; 
    cout << "____________________________________________\n";
    cout << "Please select an option\n";
    cout << "A) Deposit" << endl; 
    cout << "B) Withdrawl" << endl; 
    cout << "C) Transfer To Savings" << endl;
    cout << "D) View Last Statement" << endl;
    cout << "X) Main Menu" << endl;
    cin >> choice;

    choice = tolower(choice);

    switch(choice){
        case 'a' :
           double depositAmount; 
           cout << "How much would you like to deposit?" << endl; 
           cout << "$"; 
           cin >> depositAmount; 
           user.Ckdeposit(depositAmount);
           CheckingMenu(user);
           break; 
        
        case 'b' :
           double withdrawAmount; 
           cout << "How much would you like to withdraw?" << endl; 
           cout << "$"; 
           cin >> withdrawAmount; 
           user.Ckwithdraw(withdrawAmount);
           CheckingMenu(user);
           break; 

        case 'c' : 
           double transferAmount; 
           cout << "How much would you like to transfer to your savings account?" << endl; 
           cout << "$"; 
           cin >> transferAmount; 
           user.transerCheckingToSavings(transferAmount);
           CheckingMenu(user);
           break; 
            
        case 'd' : 
            //need Someone to add a random file that generates this data 
            break; 

        case 'x' :
            MainMenu(user);
            break; 
    }
}


void MainMenu(User &user){

    char choice;
    cout << "____________________________________________ \n";
    cout << "|Welcome to the Franca Finance Application |\n"; 
    cout << "____________________________________________\n";
    cout << "Please select an option\n";
    cout << endl; 

    cout << "A) Checking Account" << endl; 
    cout << "B) Savings Account" << endl; 
    cout << "C) Credit Card" << endl;
    cout << "X) Log Out" << endl;
    cin >> choice;

    choice = tolower(choice);

    switch(choice){
        case 'a' :
           CheckingMenu(user);
            break; 
        
        case 'b' :
            SavingMenu(user);
            break;

        case 'c' : 
            CreditMenu(user);
            break; 

        case 'x' :
            main();
            break; 
    }

        
}

bool LogInPage(vector<User>& users){
    bool access = false;
    User passUser;  
    string userName, password, userCompare, passCompare;
    cout << "____________________________________________\n";
    cout << "|Welcome to the Franca Finance Application |\n"; 
    cout << "|              Please Log In               |\n";
    cout << "____________________________________________\n";
    cout << "" << endl; 
    
    while(!access){
        cout << "UserName: " << endl; 
        cin >> userName; 

        cout << "Password: " << endl; 
        cin >> password;



        for (const auto& user : users){
            userCompare = user.get_UserName();
            passCompare = user.get_password(); 

            if(userCompare == userName && passCompare == password){
                access = true; 
                passUser = user; 
            }
        }

        if(!access){
            cout << "Incorrect UserName or Password, please try again" << endl; 
         }
         else{
            cout << "____________________________________________\n";
            cout << "" << endl;
            cout << "Logging In";
            for(long long i = 0; i < 1000000000; i++);
            cout << ".";
            for(long long i = 0; i < 1000000000; i++);
            cout << ".";
            for(long long i = 0; i < 1000000000; i++);
            cout << ".";
            cout << "" << endl;
            

            MainMenu(passUser);
         }
    }   

}

int main(){

    vector<User> UserDataBase = ReadandStoreData();
    LogInPage(UserDataBase);     
    return 0; 
}



