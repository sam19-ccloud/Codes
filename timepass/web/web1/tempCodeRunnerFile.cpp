#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class PizzaParlor {
private:
    map<string, double> menu;
    vector<string> order;

public:
    PizzaParlor() {
        // Initialize the menu with pizza types and prices
        menu["Margherita"] = 8.99;
        menu["Pepperoni"] = 9.99;
        menu["Vegetarian"] = 10.99;
        menu["BBQ Chicken"] = 11.99;
        menu["Hawaiian"] = 10.49;
    }

    // Show the pizza menu
    void showMenu() {
        cout << "\nWelcome to the Pizza Parlor!\n";
        cout << "Here's the menu:\n";
        for (const auto& pizza : menu) {
            cout << pizza.first << ": $" << pizza.second << endl;
        }
    }

    // Take a pizza order
    void orderPizza() {
        showMenu();
        cout << "\nEnter the pizza you want to order (type the name exactly): ";
        string pizzaChoice;
        cin.ignore();  // To ignore any leftover newline characters
        getline(cin, pizzaChoice);

        if (menu.find(pizzaChoice) != menu.end()) {
            order.push_back(pizzaChoice);
            cout << pizzaChoice << " has been added to your order!\n";
        } else {
            cout << "Sorry, we don't have that pizza on the menu. Please try again.\n";
        }
    }

    // View current order
    void viewOrder() {
        if (!order.empty()) {
            cout << "\nYour current order:\n";
            double totalCost = 0.0;
            for (const string& pizza : order) {
                cout << "- " << pizza << " ($" << menu[pizza] << ")\n";
                totalCost += menu[pizza];
            }
            cout << "\nTotal cost: $" << totalCost << endl;
        } else {
            cout << "\nYour order is empty.\n";
        }
    }

    // Cancel a pizza from the order
    void cancelOrder() {
        if (order.empty()) {
            cout << "\nYou have no orders to cancel.\n";
            return;
        }

        viewOrder();
        cout << "\nEnter the pizza you want to cancel (type the name exactly): ";
        string pizzaToCancel;
        cin.ignore();
        getline(cin, pizzaToCancel);

        auto it = find(order.begin(), order.end(), pizzaToCancel);
        if (it != order.end()) {
            order.erase(it);
            cout << pizzaToCancel << " has been canceled from your order.\n";
        } else {
            cout << "Sorry, that pizza is not in your current order.\n";
        }
    }
};

int main() {
    PizzaParlor pizzaParlor;

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Order Pizza\n";
        cout << "2. View Order\n";
        cout << "3. Cancel Pizza\n";
        cout << "4. Exit\n";
        cout << "Please enter the number of your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                pizzaParlor.orderPizza();
                break;
            case 2:
                pizzaParlor.viewOrder();
                break;
            case 3:
                pizzaParlor.cancelOrder();
                break;
            case 4:
                cout << "Thank you for visiting the Pizza Parlor! Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}

