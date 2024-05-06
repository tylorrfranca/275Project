#include <iostream>
#include <string>
#include <fstream>
#include "User.h"



using namespace std; 

int main(){
   CheckingAccount *CkAccount = new CheckingAccount;
   SavingsAccount *SvAccount = new SavingsAccount; 
   CreditCard *CcAccount = new CreditCard;

   User Tylor("0123", "Tylor", CkAccount, SvAccount, CcAccount);

   cout << CkAccount -> get_balance() << endl;
   CkAccount -> deposit(200);
   cout << CkAccount -> get_balance() << endl;

   cout << SvAccount -> get_balance() << endl;
   SvAccount -> deposit(200);
   cout << SvAccount -> get_balance() << endl;
     
    return 0; 
}