#include<iostream>
#include<limits>
#include<cmath>
#include<string>
using namespace std;

double add(double a, double b){
    return a + b;
}

double subtract(double a, double b){
    return a - b;
}

double multiply(double a, double b){
    return a * b;
}

double divide(double a, double b){
    return a / b;
}

double power(double a, double b){
    return pow(a, b);
}

void printMenu(){
    cout << endl;
    cout << "===== CALCULATOR =====" << endl;
    cout << "1. Add        (+)" << endl;
    cout << "2. Subtract   (-)" << endl;
    cout << "3. Multiply   (*)" << endl;
    cout << "4. Divide     (/)" << endl;
    cout << "5. Remainder  (%)" << endl;
    cout << "6. Power      (^)" << endl;
    cout << "7. Square root" << endl;
    cout << "0. Exit" << endl;
    cout << "======================" << endl;
    cout << "Choose an option: ";
}

// clears the bad input so the next cin >> does not fail forever
void clearInput(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double readNumber(string label){
    double value;
    while(true){
        cout << label;
        if(cin >> value){
            return value;
        }
        cout << "That is not a number, try again." << endl;
        clearInput();
    }
}

int main(){
    int choice;

    do{
        printMenu();

        if(!(cin >> choice)){
            cout << "Please enter a number from the menu." << endl;
            clearInput();
            continue;
        }

        if(choice == 0){
            cout << "Goodbye!" << endl;
            break;
        }

        if(choice < 0 || choice > 7){
            cout << "Invalid option, pick 0 to 7." << endl;
            continue;
        }

        // option 7 needs only one number
        if(choice == 7){
            double a = readNumber("Enter a number: ");
            if(a < 0){
                cout << "Error: cannot take the square root of a negative number." << endl;
            }
            else{
                cout << "Result: " << sqrt(a) << endl;
            }
            continue;
        }

        double a = readNumber("Enter first number: ");
        double b = readNumber("Enter second number: ");

        switch(choice){
            case 1:
                cout << "Result: " << add(a, b) << endl;
                break;
            case 2:
                cout << "Result: " << subtract(a, b) << endl;
                break;
            case 3:
                cout << "Result: " << multiply(a, b) << endl;
                break;
            case 4:
                if(b == 0){
                    cout << "Error: cannot divide by zero." << endl;
                }
                else{
                    cout << "Result: " << divide(a, b) << endl;
                }
                break;
            case 5:
                if((int)b == 0){
                    cout << "Error: cannot take remainder with zero." << endl;
                }
                else{
                    cout << "Result: " << (int)a % (int)b << endl;
                }
                break;
            case 6:
                cout << "Result: " << power(a, b) << endl;
                break;
        }

    } while(true);

    return 0;
}
