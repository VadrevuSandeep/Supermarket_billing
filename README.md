🛒 Supermarket Billing System (C++)

This is a simple and interactive Supermarket Billing System developed in C++, designed to handle basic inventory management and billing operations. The program is entirely terminal-based and suitable for beginners looking to understand structures, vectors, conditionals, and user input handling in C++.

🔧 Features

✅ Add a new product with a unique product code

📋 Display all available products in a formatted table

🔍 Search for a product by code

✏️ Update product details like name, price, and quantity

❌ Delete a product from inventory

🧾 Create bills by selecting multiple products and quantities

📦 Automatically adjust inventory after billing

💻 How It Works
The system stores product data using a vector of struct:

struct Product {
    int code;
    string name;
    float price;
    int quantity;
};

Each feature is implemented using menu-driven logic inside a loop in the main() function, making it modular and beginner-friendly.

🧠 Concepts Covered

struct and vector usage for dynamic data handling

Input validation using cin.fail() and cin.ignore()

Searching and modifying records using iterators and find_if

Simple billing logic with inventory management

Formatted output using iomanip

📌 Prerequisites

To run and compile this project, make sure you have the following installed on your system:

✅ Required:

C++ Compiler (e.g., g++, clang++)

Windows: MinGW

Linux: Pre-installed or install via sudo apt install g++

macOS: Install Xcode command line tools using xcode-select --install

Command-line terminal or any IDE that supports C++:

Code::Blocks

Dev C++

Visual Studio

VS Code with C++ extension

🔣 Basic Knowledge:

Familiarity with:

C++ syntax (input/output, loops, conditionals)

struct and vector usage

File handling (optional for future improvements)
