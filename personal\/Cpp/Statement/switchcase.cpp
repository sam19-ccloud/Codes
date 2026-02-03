

#include <iostream>
#include <string> 
using namespace std;

int main() {
    int dayNumber;
    
    cout << "Enter a number (1-7) to represent the day of the week (1=Monday, 7=Sunday): ";
    cin >> dayNumber;
    
    string dayName; 
    
    switch (dayNumber) {
        case 1:
            dayName = "Monday";
            break;
        case 2:
            dayName = "Tuesday";
            break;
        case 3:
            dayName = "Wednesday";
            break;
        case 4:
            dayName = "Thursday";
            break;
        case 5:
            dayName = "Friday";
            break;
        case 6:
            dayName = "Saturday";
            break;
        case 7:
            dayName = "Sunday";
            break;
        default:
            dayName = "Invalid day number";
            break;
    }

    cout<< "The day is: " << dayName <<endl;
}
   