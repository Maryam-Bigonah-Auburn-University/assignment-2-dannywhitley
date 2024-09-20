#include <iostream>
#include <string>
using namespace std;

// Function declarations; more detailed annotations are done in the function definitions
bool isLeapYear(int year);  // Determines if the year entered is a leap year
int getCenturyValue(int year); // Determines the centrury value from the first two digits of the year entered
int getYearValue(int year); // Determines the year value based on the last two digits of the year entered
int getMonthValue(int month, int year); // Determines the month value depending on the month entered and if it is a leap year

// Can handle months entered outside of the range (1-12) and days outside of the range of the month entered, tested with dates as far back as 1990
int main()
{
    // Variable declarations for the inputs
    int inputMonth, inputDay, inputYear, sumValuesRemainder;
    string dayOfWeek;

    // Initializes dayOfWeek as a blank string
    dayOfWeek = "";

    // Variable declarations for the declared functions
    int yearValue, centuryValue, monthValue;
    bool leapYear;

    // Displays messge to the terminal and prompts the user to enter a date
    cout << "Enter a date as numeric values.\n" << "Month: ";
    cin  >> inputMonth;

    // Ensures a valid month is entered
    if ((inputMonth < 1) || (inputMonth > 12))
    {
        do
        {
            cout << "Enter a valid month: ";
            cin >> inputMonth;
        } while ((inputMonth < 1) || (inputMonth > 12));
    }

    // Prompts the user to enter the day of the month
    cout << "Day: ";
    cin >> inputDay;

    // Makes sure a valid day is entered for months with 31 days
    if (((inputMonth == 1) || (inputMonth == 3) || (inputMonth == 5) || (inputMonth == 7) || (inputMonth == 8) || (inputMonth == 10) || (inputMonth == 12)) && ((inputDay < 1) || (inputDay > 31)))
    {
        // Continues to prompt the user until a valid day is entered
        do
        {
            cout << "Enter a valid day (1-31): ";
            cin >> inputDay;
        } while ((inputDay < 1) || (inputDay > 31));
    }

    // Makes sure a valid day is entered for months with 30 days
    if (((inputMonth == 4) || (inputMonth == 6) || (inputMonth == 9) || (inputMonth == 11)) && ((inputDay < 1) || (inputDay > 30)))
    {
        // Continues to prompt the user until a valid day is entered
        do
        {
            cout << "Enter a valid day (1-30): ";
            cin >> inputDay;
        } while ((inputDay < 1) || (inputDay > 30));
    }

    if (inputMonth == 2)
    {
        // Prompts the user to enter the year
        cout << "Year: ";
        cin >> inputYear;

        // Makes sure the user enters a valid day for February if it is a leap year
        if (isLeapYear(inputYear) && ((inputDay < 1) || (inputDay > 29)))
        {
            // Continues to prompt the user until a valid day is entered
            do
            {
                cout << "Enter a valid day (1-29): ";
                cin >> inputDay;
            } while ((inputDay < 1) || (inputDay > 29));
        }

        // Makes sure the user enters a valid day for February if it is not a leap year
        if (!isLeapYear(inputYear) && ((inputDay < 1) || (inputDay > 28)))
        {   
            // Continues to prompt the user until a valid day is entered
            do 
            {
                cout << "Enter a valid day (1-28): ";
                cin >> inputDay;
            } while ((inputDay < 1) || (inputDay > 28));
        }
    }

    if (inputMonth != 2)
    {
        cout << "Year: ";
        cin >> inputYear;
    }

    // Calls functions to find values
    centuryValue = getCenturyValue(inputYear);
    yearValue = getYearValue(inputYear);
    monthValue = getMonthValue(inputMonth,inputYear);

    // Determines a value between 0 to 6, from the entered day and the values produced by the defined functions
    sumValuesRemainder = (inputDay + monthValue + yearValue + centuryValue) % 7;
    
    // Switch statement is used to determine what day of the week it is 
    switch (sumValuesRemainder)
    {
        case (0): // Sunday
            dayOfWeek =  "Sunday";
            break;
        case (1): // Monday
            dayOfWeek = "Monday";
            break;
        case (2): // Tuesday
            dayOfWeek = "Tuesday";
            break;
        case (3): // Wednesday
            dayOfWeek = "Wednesday";
            break;
        case (4): // Thursday
            dayOfWeek = "Thursday";
            break;
        case (5): // Friday
            dayOfWeek = "Friday";
            break;
        case (6): // Saturday
            dayOfWeek = "Saturday";
            break;
    }
    // Displays the entered date in MM/DD/YYYY format and tells the user what day that corresponds to 
    cout << inputMonth << "/" << inputDay << "/" << inputYear << " corresponds to a " << dayOfWeek << endl;

    // Terminates the code
    return 0;
}

// Function definition for isLeapYear; returns a bool value
bool isLeapYear(int year)
{
    // Detects if the year is a leap year
    // Returns 0 for false and 1 for true and is passed through getMonthValue
    return(((year % 400) == 0) || (((year % 4) == 0) && (year % 100 != 0)));
}

// Function definition for getCenturyValue; returns an int value
int getCenturyValue(int year)
{
    // Declares century and centuryValue as type integer
    int century, centuryValue;

    // Uses static type cast to ensure that the variable is type int no matter what
    // centuryis computed by using integer division
    century = year / 100;
    
    // Determines the centuryValue by subtracting the remainder of the century divided by 4 from 3
    // then multiplying by 2
    centuryValue = 2 * (3 - (century % 4));

    // Returns the century value to the function call in the main section of ther code
    return(centuryValue);
}

// Function definition for getYearValue; returns an int value
int getYearValue(int year)
{
    // Declares the variables yearsThisCentury and numberLeapYears as type int
    int yearsThisCentury, numberLeapYears;

    // Calculates the number of years passed in this century using the remainder of integer division
    yearsThisCentury = year % 100;

    // Calculates the number of leap years passed so far this century
    numberLeapYears = yearsThisCentury / 4;

    // Returns a value based on the sum of the number of years and the leaps years passed this century 
    return(yearsThisCentury + numberLeapYears);
}

// Function definition for getMonthValue; returns an int value
int getMonthValue(int month, int year)
{
    // Declares the variable monthValue as type int
    int monthValue;

    // Switch-case is used to determine the monthValue depending on what month is entered
    switch (month)
    {
        case (1): // January
            // If statement is used to determine which value to use if the year is a leap year
            if (isLeapYear(year)) {
                monthValue = 6;
            }
            else { // When it's not a leap year
                monthValue = 0;
            }
            break;
        case (2): // February
            // If statement is used to determine which value to use if the year is a leap year
            if (isLeapYear(year)) {
                monthValue = 2;
            }
            else { // When it's not a leap year
                monthValue = 3;
            }
            break;
        case (3): // March
            monthValue = 3;
            break;
        case (4): // April
            monthValue = 6;
            break;
        case (5): // May
            monthValue = 1;
            break;
        case (6): // June
            monthValue = 4;
            break;
        case (7): // July
            monthValue = 6;
            break;
        case (8): // August
            monthValue = 2;
            break;
        case (9): // September
            monthValue = 5;
            break;
        case (10): // October
            monthValue = 0;
            break;
        case (11): // November
            monthValue = 3;
            break;
        case (12): // December
            monthValue = 5;
            break;   
    }
    // Returns a value based on the month and weither the year is a leap year or not
    return(monthValue);
}
