#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm> // for find_if

using namespace std;

struct Product {
    int code;
    string name;
    float price;
    int quantity;
};

vector<Product> inventory;

void addProduct() {
    Product p;
    cout << "\nEnter Product Code: ";
    cin >> p.code;

    for (const auto& prod : inventory) {
        if (prod.code == p.code) {
            cout << "Product code already exists!\n";
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
    cout << "Enter Product Name: ";
    getline(cin, p.name);

    cout << "Enter Price: ";
    cin >> p.price;

    cout << "Enter Quantity: ";
    cin >> p.quantity;

    inventory.push_back(p);
    cout << "Product added successfully!\n";
}

void displayProducts() {
    if (inventory.empty()) {
        cout << "No products in inventory.\n";
        return;
    }

    cout << "\n=== Product List ===\n";
    cout << left << setw(10) << "Code" 
         << setw(20) << "Name" 
         << setw(10) << "Price" 
         << setw(10) << "Qty" << endl;

    for (const auto& p : inventory) {
        cout << left << setw(10) << p.code 
             << setw(20) << p.name 
             << setw(10) << p.price 
             << setw(10) << p.quantity << endl;
    }
}

void searchProduct() {
    int code;
    cout << "Enter Product Code to search: ";
    cin >> code;

    for (const auto& p : inventory) {
        if (p.code == code) {
            cout << "Product Found:\n";
            cout << "Name: " << p.name << ", Price: " << p.price << ", Quantity: " << p.quantity << endl;
            return;
        }
    }
    cout << "Product not found!\n";
}

void updateProduct() {
    int code;
    cout << "Enter Product Code to update: ";
    cin >> code;

    for (auto& p : inventory) {
        if (p.code == code) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter new name (current: " << p.name << "): ";
            getline(cin, p.name);

            cout << "Enter new price (current: " << p.price << "): ";
            cin >> p.price;

            cout << "Enter new quantity (current: " << p.quantity << "): ";
            cin >> p.quantity;

            cout << "Product updated!\n";
            return;
        }
    }
    cout << "Product not found!\n";
}

void deleteProduct() {
    int code;
    cout << "Enter Product Code to delete: ";
    cin >> code;

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->code == code) {
            inventory.erase(it);
            cout << "Product deleted!\n";
            return;
        }
    }
    cout << "Product not found!\n";
}

void createBill() {
    vector<pair<Product, int>> cart;
    char more;
    float total = 0;

    do {
        int code, qty;
        cout << "Enter Product Code: ";
        cin >> code;

        auto it = find_if(inventory.begin(), inventory.end(), [code](const Product& p) {
            return p.code == code;
        });

        if (it == inventory.end()) {
            cout << "Product not found!\n";
        } else {
            cout << "Enter quantity: ";
            cin >> qty;

            if (qty > it->quantity) {
                cout << "Not enough stock!\n";
            } else {
                cart.push_back({*it, qty});
                it->quantity -= qty;
                cout << "Added to cart.\n";
            }
        }

        cout << "Add more items? (y/n): ";
        cin >> more;
    } while (tolower(more) == 'y');

    cout << "\n===== BILL =====\n";
    cout << left << setw(20) << "Product" 
         << setw(10) << "Qty" 
         << setw(10) << "Price" 
         << setw(10) << "Total" << endl;

    for (const auto& item : cart) {
        float itemTotal = item.first.price * item.second;
        total += itemTotal;
        cout << left << setw(20) << item.first.name 
             << setw(10) << item.second 
             << setw(10) << item.first.price 
             << setw(10) << itemTotal << endl;
    }

    cout << "-----------------------------\n";
    cout << "Grand Total: " << total << endl;
}

int main() {
    int choice;

    do {
        cout << "\n==== Supermarket Billing System ====\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Product\n";
        cout << "5. Delete Product\n";
        cout << "6. Create Bill\n";
        cout << "7. Exit\n";
        cout << "---->> Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;
            case 6: createBill(); break;
            case 7: cout << "Thank you for using the system!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}

