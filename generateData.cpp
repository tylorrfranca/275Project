#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

struct Credit {
    int creditBalance;
    int creditLimit;
    int creditScore;
};

// Function prototypes
int generateRandomCreditBalance();
int generateRandomCreditLimit();
int generateRandomCreditScore();
Credit generateRandomCredit();
void generateCreditFile(const std::string &fileName, int numberOfEntries);

int generateRandomCreditBalance() {
    return rand() % 1001; // Random balance between 0 and 1000
}

int generateRandomCreditLimit() {
    return (rand() % 4501) + 500; // Random limit between 500 and 5000
}

int generateRandomCreditScore() {
    return (rand() % 326) + 500; // Random score between 300 and 750
}

Credit generateRandomCredit() {
    Credit credit;
    credit.creditBalance = generateRandomCreditBalance();
    credit.creditLimit = generateRandomCreditLimit();
    credit.creditScore = generateRandomCreditScore();
    return credit;
}

void generateCreditFile(const std::string &fileName, int numberOfEntries) {
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }

    outFile << "Credit Balance\tCredit Limit\tCredit Score\n";

    for (int i = 0; i < numberOfEntries; ++i) {
        Credit credit = generateRandomCredit();
        outFile << credit.creditBalance << "           \t"
                << credit.creditLimit << "           \t"
                << credit.creditScore << "\n";
    }

    outFile.close();
    
}


struct Employee {
    std::string userName;
    std::string password;
    std::string lastName;
    std::string firstName;
    int checkingAccount;
    int savingsAccount;
};

std::vector<std::string> userNames = {"tylor", "Anthony", "Nick", "james", "sarah", "michael", "jessica", "john", "emily", "daniel", "SunnyDaze", "DragonRider", "ButterflyWings", "RainbowChaser", "StarGazer", "MoonWalker", "ThunderStruck", "OceanDreamer", "MountainClimber", "FireFlyer", "RiverRunner", "SandCastleKing", "MeadowLark", "BlueberryPie", "SnowFlake", "WhisperWind", "AutumnLeaves", "SpringBlossom", "SummerBreeze", "WinterChill"};
std::vector<std::string> passwords = {"hola", "hola2", "yoyo", "pass123", "hello", "world", "abc123", "qwerty", "password", "letmein", "Sunflower8", "Dragonfly3!", "Butterfly#12", "Rainbow$7", "Starlight9", "Moonbeam#5", "Thunder$2storm", "Oceanwave6", "Mountain#peak4", "Firefly!3", "Riverbank9", "Sandcastle$8", "Meadowlark5", "Blueberry#7", "Snowflake$4", "Whispering3", "Autumnleaf9!", "Springtime#2", "Summerbreeze7", "Winterstorm$1"};
std::vector<std::string> lastNames = {"Keroles", "Nguyen", "Johnson", "Smith", "Brown", "Wilson", "Moore", "Taylor", "Anderson", "Thomas", "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez", "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", "Thomas", "Taylor", "Moore", "Jackson", "Martin"};
std::vector<std::string> firstNames = {"John", "David", "John", "Michael", "Sarah", "Jessica", "Emily", "Daniel", "Matthew", "Laura", "Emily", "James", "Olivia", "Liam", "Sophia", "Benjamin", "Ava", "Mason", "Isabella", "Ethan", "Mia", "Alexander", "Amelia", "Jacob", "Charlotte", "Michael", "Harper", "Daniel", "Evelyn", "Matthew"};

int generateRandomAmount() {
    return rand() % 1000 + 1; // Random amount between 1 and 1000
}

Employee generateRandomEmployee() {
    Employee emp;
    emp.userName = userNames[rand() % userNames.size()];
    emp.password = passwords[rand() % passwords.size()];
    emp.lastName = lastNames[rand() % lastNames.size()];
    emp.firstName = firstNames[rand() % firstNames.size()];
    emp.checkingAccount = generateRandomAmount();
    emp.savingsAccount = generateRandomAmount();
    return emp;
}

void generateSalaryFile(const std::string &fileName, int numberOfEmployees) {
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }

    outFile << "userName\tPassword\tLastName\tFirstName\tChecking Account\tSavings Account\n";

    for (int i = 0; i < numberOfEmployees; ++i) {
        Employee emp = generateRandomEmployee();
        outFile << emp.userName << "    \t"
                << emp.password << "    \t"
                << emp.lastName << "   \t"
                << emp.firstName << "    \t"
                << emp.checkingAccount << "                   \t"
                << emp.savingsAccount <<"\n";
    }

    outFile.close();
  
}


