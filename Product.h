/*
Done by: Mariem Ehab & Mariam Hossini (4th year computer engineering students)
for: Data Structure Project
Date: April 2023
*/

#include <iostream>
using namespace std;

class Product {

public:
    //products details
    string name;
    double price;
    int quantity;
    string details;

    //pointers for the previous and next products
    Product* next;
    Product* previous;

    Product() {
        price = 0;
        name = "unknown";
        details = "no details";
        quantity = 1;
    }

    Product(string n, double p, string d, int q) {
        price = p;
        name = n;
        details = d;
        quantity = q;
    }
};