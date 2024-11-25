#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Product {
    int id;
    int quantity;
};

int main() {

    map<string, Product> inventory = {
        {"Product A", {101, 50}},
        {"Product B", {102, 30}},
        {"Product C", {103, 20}}
    };

    // Sales data
    vector<pair<int, int>> sales = {
        {101, 10},
        {102, 5},
        {103, 15}
    };


    int total_sales = 0;
    for (auto& sale : sales) {
        for (auto& product : inventory) {
            if (product.second.id == sale.first) {
                product.second.quantity -= sale.second;
                total_sales += sale.second * 10;  // Assume each product costs $10
            }
        }
    }


    cout << "Inventory Status:\n";
    for (const auto& product : inventory) {
        cout << product.first << ": ID " << product.second.id << ", Remaining Stock = " << product.second.quantity << endl;
    }

    cout << "Total Sales: $" << total_sales << endl;

    return 0;
}

