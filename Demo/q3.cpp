#include <iostream>
using namespace std;

// Function declarations
double convertToMPH(int minutes, int seconds); // User enters the time it takes them to run 1 mile and the rate is determined
double convertToMPH(double kilometersPerHour); // User enters their running rate in KPH and it is converted to MPH

int main()
{
    // Declares input variables
    int inputMinutes, inputSeconds;
    double inputKPH;

    // Displays messages prompting the user to input values
    cout << "Enter the time spent running one mile in minutes and seconds: \n" << "Minutes: ";
    cin >> inputMinutes; 
    cout << "Seconds: ";
    cin >> inputSeconds;
    cout << "Enter a running pace in kilometers per hour: "; 
    cin >> inputKPH;

    // Sets the precision to 2 decimal points, see pg 31-32
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // Caculates the running rate in MPH from the first definition of convertToMPH
    cout << "The running rate in MPH based on the time entered (First definition of convertToMPH) is: ";
    cout << convertToMPH(inputMinutes, inputSeconds) << " MPH." << endl;

    // Calculates the running rate in MPH from the second definition of convertToMPH
    cout << "The running rate in MPH based on the rate in KPH entered (Second definition of convertToMPH) is: ";
    cout << convertToMPH(inputKPH) << " MPH." << endl;
}

// First definition of convertToMPH using minutes and seconds 
double convertToMPH(int minutes, int seconds)
{
    // Declares the hours spent running 1 mile and MPH
    double hours;
    double mph;

    // Converts the minutes and seconds to hours
    hours = ((minutes / 60.0) + (seconds / 3600.0));

    // Calculates the mph
    mph = 1 / hours;

    // Returns a value for the runners speed in MPH and type double
    return(mph);
}

// Second definition using kilometers per hour
double convertToMPH(double kilometersPerHour)
{
    // Declares a constant variable of type double for the conversion factor KPH to MPH
    const double KMPERMILE = 1.61;

    // Returns a value of MPH when the function is called 
    return(kilometersPerHour / KMPERMILE);
}
