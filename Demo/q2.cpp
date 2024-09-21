#include <iostream>
#include <string>
using namespace std;

void computeCoin(int coinValue, int& number, int& amountLeft); 
// The amount entered will be be between 1 and 99 cents
// The coin denomination will be entered in the form of cents (i.e. quarters = 25) while only accepting quarters, dimes, and pennies
// It will return the number of coins of the selected denomination 

void printChange(int coinValue, int number);
// Prints out the number of coins of the selected denomination needed

int main()
{
    // Declares variables
    char continuePrompt;
    int userValue, userNumber, userAmountLeft; 

    // Initialized variables
    continuePrompt = 'Y';
    userNumber = 0;

    // Will continue to run the void function as long as the user responds to the prompt affirmatively 
    do
    {
        // Prompts the user to enter an amount between 1 and 99 cents
        cout << "Enter an amount of change between 1-99 cents: ";
        cin >> userAmountLeft;
        
        // If statement is triggered when the change entered is between 1 and 99 cents
        if ((userAmountLeft > 0) && (userAmountLeft < 100))
        {
            // Calls the void functions to find and print how many quarters are used
            computeCoin(25, userNumber, userAmountLeft);
            printChange(25, userNumber);

            // Calls the void functions to find and print how many quarters are used
            computeCoin(10, userNumber, userAmountLeft);
            printChange(10, userNumber);

            // Calls the void functions to find and print how many quarters are used
            computeCoin(1, userNumber, userAmountLeft);
            printChange(1, userNumber);

            // Prompts the user to see if they want to go again
            cout << "Do you want to make change again?\n" << "(press Y or y to continue and any other key to exit): ";
            cin >> continuePrompt;
        }

        // This statement is triggered when a value outsode of the accepted range is entered and will as the user if they want to try again
        else
        {
            // Will continue the loop if the user decides to enter an amount within the accepted range
            cout << "Your value was out of the accepted range. Try again?\n" << "(press Y or y to continue and any other key to exit): ";
            cin >> continuePrompt;
        }
    } while ((continuePrompt == 'Y') || (continuePrompt == 'y'));

    // Terminates the code
    return 0;
}

// Function definition for computeCoin
void computeCoin(int coinValue, int& number, int& amountLeft)
{
    // Determines the number of coins it will take of the denomination selected using integer division, uses call by reference to edit the value in the memory
    number = amountLeft / coinValue;

    // Determines the amount left over after the number of coins is used and since it is call by reference it will directly edit the value in the memory
    amountLeft -= (number * coinValue);
}

// Function definition for printChange doesnt use call by reference because it does not need to change any of the values in the memory
void printChange(int coinValue, int number)
{
    // Prints the number of coins and the type (quarters, dimes, pennies) used
    switch (coinValue)
    {
        case (25): // quarters
        cout << number << " " << "quarters" << endl;
        break;

        case (10): // dimes
        cout << number << " " << "dimes" << endl;
        break;

        case (1): // pennies
        cout << number << " " << "pennies" << endl;
    }
}
