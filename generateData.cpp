#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int generateRandomNumber(int min, int max) {
  return rand() % (max - min + 1) + min;
}

double generateRandomSalary(double minSalary, double maxSalary) {
  return minSalary + static_cast<double>(rand()) / (RAND_MAX) * (maxSalary - minSalary);
}

string generateRandomLastName() {
  // Replace with an array of last names if you want a specific list
  string lastNames[] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Franca", "Keroles", "Mitubishi", "Amberg", "Nguyen"};
  int randomIndex = generateRandomNumber(0, sizeof(lastNames) / sizeof(lastNames[0]) - 1);
  return lastNames[randomIndex];
}

string generateRandomFirstName() {
  // Replace with an array of first names if you want a specific list
  string firstNames[] = {"John", "Jane", "David", "Mary", "Elizabeth", "Lucas", "Tylor", "Anthony", "Stephen", "Adrian", "James"};
  int randomIndex = generateRandomNumber(0, sizeof(firstNames) / sizeof(firstNames[0]) - 1);
  return firstNames[randomIndex];
}

void generateFile() {
  srand(time(0));  // Seed the random number generator

  int numEmployees = 100; // Adjust this value to change the number of employees

  ofstream salaryFile("Salary.txt");
  if (salaryFile.is_open()) {
    salaryFile << "EmployeeID LastName FirstName Salary\n";
    for (int i = 0; i < numEmployees; ++i) {
      long long employeeId = generateRandomNumber(100000000, 999999999);
      string lastName = generateRandomLastName();
      string firstName = generateRandomFirstName();
      double salary = generateRandomSalary(300.0, 70000.0);

      // Find the maximum length among all first names for consistent alignment
      int maxLength = 0;
      for (int j = 0; j < numEmployees; ++j) {
        maxLength = max(maxLength, int(generateRandomFirstName().length()));
      }

      salaryFile << employeeId << " " << lastName << " " << setw(maxLength) << right << firstName << " " << fixed << setprecision(2) << salary << endl;

     // for(long i = 0; i < 10000; i++){}; //busy wait
    }
    salaryFile.close();
  } else {
    cout << "Error: Could not open file." << endl;
  }

}