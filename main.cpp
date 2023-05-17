/*
Done by: Mariem Ehab & Mariam Hossini (4th year computer engineering students)
for: Data Structure Project
Date: April 2023
*/

#include <iostream>
#include <string>
#include"LinkedList.h"
#include <cstdlib> // for system function

using namespace std;

// Simulation of customer cart in pharmacy
// allows customers to add, remove, modify, 
// and display products in their cart, and then checkout and calculate the total bill. 
// takes a linkedlist of pharmacy available products and output the total bills from customers
double customer(LinkedList list) {
  
    double tot_bills = 0.00;
    
    bool anotherCustomer = true;  // if true then there is a customer to order otherwise false indicates the end of the function
    bool sameCustomer;           // if true then we continue the operations of the customer
    bool emptyTheCart;          //if false the cart will stay the same. if true all the cart products will be deleted
    char c;
    int customerChoice;

    // Start a loop to handle multiple customers
    while (anotherCustomer) {

        // Initialize the customer's cart
        LinkedList cart;
        emptyTheCart = false; 
        sameCustomer = true;

        // Start a loop to handle a single customer
        do {

            // Initialize the customer's bill
            double customerBill = 0.00;
            

            // Print a menu of options for the customer to choose from
            cout << "\nCustomer Options Menu:\n"
                << "1. Add Product to cart\n"
                << "2. Remove Product from cart\n"
                << "3. Modify Product quantity in cart\n"
                << "4. Display Products in cart\n"
                << "5. Bill and Checkout\n"
                << "6. Cancel\n\n"
                << "Enter a valid option number from the list above: ";
               
            // Get the customer's choice
            cin >> customerChoice;

            // Based on the customer's choice, perform the appropriate action
            if (customerChoice == 1) {
                int num_of_products = 0;
                string product_name;
                int product_quantity;
                
                // Ask the customer how many products they want to add
                cout << "How many products you want to add? ";
                cin >> num_of_products;

                for (int i = 1; i <= num_of_products; i++) {

                    // ask for the name and quantity of each product
                    cout << "Enter the name of product (" << i << ") you want to add : ";
                    cin >> product_name;
                    cout << "Enter the quantity of product (" << i << ") you want to add: ";
                    cin >> product_quantity;

                    Product* productNeeded = list.isfound(product_name);

                    // If the product is available, add it to the cart
                    if (productNeeded != nullptr && productNeeded-> quantity > 0) {

                        if (product_quantity > productNeeded->quantity) {
                            product_quantity = productNeeded->quantity;
                            cout << "We only found quantity of " << product_quantity << " from " << product_name << " and were added to the cart.\n";
                        }

                        cart.insert(productNeeded->name, productNeeded->price, productNeeded->details, product_quantity);
            
                    }
                    // Otherwise, inform the customer that the product is not available
                    else {
                        cout << "\nThis Product is not available right now in our Pharmacy\n";
                    }

                }

            }

            else if (customerChoice == 2) {
                string product_name;

                // Ask the customer for the name of the product they want to remove
                cout << "Enter the name of the product you want to remove: ";
                cin >> product_name;

                // Remove the product from the cart if found
                cart.remove(product_name);
            }

            else if (customerChoice == 3) {
                string product_name;
                int product_quantity;

                // Ask the customer for the name of the product they want to modify
                // and the new quantity they want to set
                cout << "Enter the name of the product you want to modify: ";
                cin >> product_name;
                cout << "Enter the new quantity you want to modify to: ";
                cin >> product_quantity;

                // Modify the quantity of the product in the cart
                cart.modifyquantity(product_name, product_quantity);

            }

            else if (customerChoice == 4) {
                // Display the products currently in the cart
                cart.display();
            }

            else if (customerChoice == 5) {

                customerBill = cart.calc_bill();
                tot_bills += customerBill;

                Product* cartProduct = cart.getHead();

                while (cartProduct != nullptr) {
                    Product* pharmProduct = list.isfound(cartProduct->name);
                    pharmProduct->quantity -= cartProduct->quantity;
                    cartProduct = cartProduct->next;
                }

                emptyTheCart = true;
            }
            
            else if (customerChoice == 6) {

                emptyTheCart = true;
            }
                
            else{
                // Inform the customer that they entered an invalid option
                cout << "Sorry you entered an invalid option\n";
            }

            // If the customer chose to cancel or checkout, empty the cart and move on to the next customer
            if (emptyTheCart) {
                cart.makeEmpty();
                sameCustomer = false;
            }

        } while (sameCustomer);

        // Ask if there is another customer
        cout << "Is there another customer?(Y/N):  ";
        cin >> c;

        // Validate the input
        // If the input is invalid, ask again
        while (c != 'y' && c != 'Y' && c != 'n' && c != 'N') {

            cout << "Sorry You entered an invalid value please insert [Y] for yes or [N] for no: ";
            cin >> c;

        }
        
        // If the input is no exit the loop
        if (c == 'N' || c == 'n') {
            anotherCustomer = false;
        }
    }

    return tot_bills;
}

// Simulation of inventory of a pharmacy and its managment
// it takes the list of all available products and the savings 
// The operations include adding, removing, and modifying products, as well as checking
// out the pharmacy, finding product location, and displaying sales and all products
void inventory(LinkedList list, double savings) {
    
    int  choice3;
    char choice4;
    do {
        cout << "1- Add product.\n"
            << "2- Remove product.\n" 
            << "3- Modify product.\n"
            << "4 - Check out the pharamcy.\n"
            << "5 - Find product location.\n"
            << "6 - Today's sales.\n"
            << "7- Display all products\n"
            << "8- Display a product's details\n"
            << "9-Exit.\n";

        cout << "Choose what do you want to do : ";
        cin >> choice3;
        ////////add list///////////
        if (choice3 == 1) {
            int choose_add1;
            char choose_add2;
            string new_name_add;
            double new_price_add;
            int new_quantity_add;
            string new_details_add;
            string old_name;
            do {
                cout << "1-Add in the first of the list.\n"
                    << "2-Add in the last of the list.\n"
                    << "3-Add product before another product in the list.\n"
                    << "4-Add product after another product in the list.\n"
                    << "5- Exit.\n"
                    << "Choose which add operation do you want to do : ";

                cin >> choose_add1;
                //insert first
                if (choose_add1 == 1) {
                    cout << "Enter the name of the product you want to add : ";
                    cin >> new_name_add;
                    cout << "Enter the price of the product you want to add : ";
                    cin >> new_price_add;
                    cout << "Enter the quantity of the product you want to add : ";
                    cin >> new_quantity_add;
                    cout << "Enter details about the the product you want to add : ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, new_details_add);
                 
                    list.insertFirst(new_name_add, new_price_add, new_details_add, new_quantity_add);
                    list.display();
                }
                //insert last
                else if (choose_add1 == 2) {
                    cout << "Enter the name of the product you want to add : ";
                    cin >> new_name_add;
                    cout << "Enter the price of the product you want to add : ";
                    cin >> new_price_add;
                    cout << "Enter the quantity of the product you want to add : ";
                    cin >> new_quantity_add;
                    cout << "Enter details about the the product you want to add : ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, new_details_add);

                    list.insert(new_name_add, new_price_add, new_details_add, new_quantity_add);
                    cout << "The product added successfully.\n";
                }
                //insert before
                else if (choose_add1 == 3)
                {
                    cout << "Enter the name of the product you want to add before it :";
                    cin >> old_name;
                    cout << "Enter the name of the product you want to add : ";
                    cin >> new_name_add;
                    cout << "Enter the price of the product you want to add : ";
                    cin >> new_price_add;
                    cout << "Enter the quantity of the product you want to add : ";
                    cin >> new_quantity_add;
                    cout << "Enter details about the the product you want to add : ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, new_details_add);

                    list.insertBefore(new_name_add, new_price_add, new_details_add, new_quantity_add, old_name);
                }
                //insert after
                else if (choose_add1 == 4) {

                    cout << "Enter the name of the product you want to add after it :";
                    cin >> old_name;
                    cout << "Enter the name of the product you want to add : ";
                    cin >> new_name_add;
                    cout << "Enter the price of the product you want to add : ";
                    cin >> new_price_add;
                    cout << "Enter the quantity of the product you want to add : ";
                    cin >> new_quantity_add;
                    cout << "Enter details about the the product you want to add : ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, new_details_add);
                    
                    list.insertAfter(new_name_add, new_price_add, new_details_add, new_quantity_add, old_name);
                }

                //exit
                else if (choose_add1 == 5)
                {
                    cout << "\t\t\t\t\tEnd of add operations!\n";
                }
                else {
                    cout << "OOPS!, you entered incorrect choice.\n";
                }
                if (choose_add1 == 5)
                {
                    break;
                }
                else {
                    cout << "Do you want to make any other add operation? PRESS [(Y) or (N)]: ";
                    cin >> choose_add2;
                }
            } while (choose_add2 == 'Y' || choose_add2 == 'y');

        }
        ////////remove list///////////
        else if (choice3 == 2) {
            int choose_rem1;
            char choose_rem2;
            string old_name_rem;
            do {
                cout << "1- Remove the first product in the list.\n"
                    << "2- Remove the last product in the list.\n"
                    << "3 - Remove by product name\n4 - Exit.\n"
                    << "Choose which remove operation do you want to do : ";

                cin >> choose_rem1;
                //remove first
                if (choose_rem1 == 1) {
                    list.removeFirst();
                }
                //remove last
                else if (choose_rem1 == 2) {
                    list.removeLast();
                }
                //remove
                else if (choose_rem1 == 3)
                {
                    cout << "Enter the name of the product you want to remove :";
                    cin >> old_name_rem;
                    list.remove(old_name_rem);
                }
                //exit
                else if (choose_rem1 == 4)
                {
                    cout << "\t\t\t\t\tEnd of remove operations!\n";
                }
                else {
                    cout << "OOPS!, you entered incorrect choice.\n";
                }
                if (choose_rem1 == 4)
                {
                    break;
                }
                else {
                    cout << "Do you want to make any other remove operation? PRESS [(Y) or (N)]: ";
                    cin >> choose_rem2;
                }
            } while (choose_rem2 == 'Y' || choose_rem2 == 'y');
        }
        ///  /  /  ////////////////modification////////////////////////
        else if (choice3 == 3) {

            int choose_mod1;
            char choose_mod2;
            string old_name_mod;
            string new_name_mod;
            double new_price_mod;
            int new_quantity_mod;
            string new_details_mod;
            
            do {
                cout << "1- Modify name of product.\n"
                    << "2- Modify price of product.\n"
                    << "3- Modify quantity of product\n"
                    << "4- Modify details of product.\n"
                    << "5- Modify all data about the product.\n"
                    << "6-Exit.\n"
                    << "Choose which modificatin operation do you want to do : ";

                cin >> choose_mod1;
                //modify name
                if (choose_mod1 == 1) {
                    cout << "Enter the name of the product you want to modify: ";
                    cin >> old_name_mod;
                    cout << "Enter the new name of the product: ";
                    cin >> new_name_mod;
                    list.modifyname(old_name_mod, new_name_mod);

                }
                //modify price
                else if (choose_mod1 == 2) {
                    cout << "Enter the name of the product you want to modify: ";
                    cin >> old_name_mod;
                    cout << "Enter the new price of the product: ";
                    cin >> new_price_mod;
                    list.modifyprice(old_name_mod, new_price_mod);
                }
                //modify quantity
                else if (choose_mod1 == 3)
                {
                    cout << "Enter the name of the product you want to modify: ";
                    cin >> old_name_mod;
                    cout << "Enter the new quantity of the product: ";
                    cin >> new_quantity_mod;
                    list.modifyquantity(old_name_mod, new_quantity_mod);

                }
                //modify dtails
                else if (choose_mod1 == 4)
                {
                    cout << "Enter the name of the product you want to modify: ";
                    cin >> old_name_mod;
                    cout << "Enter the new details of the product: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, new_details_mod);

                    list.modifydetails(old_name_mod, new_details_mod);
                }
                //modify all
                else if (choose_mod1 == 5)
                {
                    cout << "Enter the name of the product you want to modify: ";
                    cin >> old_name_mod;
                    cout << "Enter the new name of the product: ";
                    cin >> new_name_mod;
                    cout << "Enter the new price of the product: ";
                    cin >> new_price_mod;
                    cout << "Enter the new quantity of the product: ";
                    cin >> new_quantity_mod;
                    cout << "Enter the new details of the product: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, new_details_mod);

                    list.modify(old_name_mod, new_details_mod, new_price_mod, new_details_mod, new_quantity_mod);
                }
                //exit
                else if (choose_mod1 == 6)
                {
                    cout << "\t\t\t\t\tEnd of modify operations!\n";
                }
                else {
                    cout << "OOPS!, you entered incorrect choice.\n";
                }
                if (choose_mod1 == 6)
                {
                    break;
                }
                else {
                    cout << "Do you want to make any other remove operation? PRESS [(Y) or (N)]: ";
                    cin >> choose_mod2;
                }
            } while (choose_mod2 == 'Y' || choose_mod2 == 'y');
        }
        /// check out the pharmacy
        else if (choice3 == 4) {
            string old_name_check;
            cout << "Enter the name of the product you want to check if found in the pharmacy or not :";
            cin >> old_name_check;
            if (list.isfound(old_name_check) != nullptr) {
                cout << "This product exist in the pharmacy.\n";
            }
            else {
                cout << "This product isn't exist in the pharmacy.\n";
            }
        }
        ////////////////////find location///////////
        else if (choice3 == 5) {
            string old_name_loc;
            cout << "Enter the name of the product for which you want to find the location : ";
            cin >> old_name_loc;
            list.find_location(old_name_loc);
        }
        ///////////////Today's sales////////////
        else if (choice3 == 6)
        {
        cout << "Total Today's savings is: " << savings << "$\n";
        }
        else if (choice3 == 7) {
        list.display();
        }
        else if (choice3 == 8) {

            string prod_name;
            cout << "Enter the name of the product that you need its details: ";
            cin >> prod_name;

            Product* prod = list.isfound(prod_name);
            if(prod != nullptr){
                cout << prod_name << " is a " << prod->details << '\n';
            }
            else {
                cout << "sorry we couldn't find this product\n";
            }

        }
        else if (choice3 == 9) {
            cout << "\t\t\t\t\tEnd of pharmacy system!\n";
        }
        else {
            cout << "OOPS!, you entered incorrect  choice.\n";
        }
        if (choice3 == 9) {
            break;
        }
        else {
            cout << "Do you want to make any other operation in the pharmacy system? PRESS [(Y) or (N)]: ";
            cin >> choice4;
        }
    } while (choice4 == 'Y' || choice4 == 'y');

}

// This function act as the database of the products available in the pharmacy 
// it creates a list and add all the products then returns that list
LinkedList Pharmacy_Database() {

    LinkedList l;

    l.insert("Aspirin", 10, "Pain reliever and anti-inflammatory medication", 100);
    l.insert("Ibuprofen", 15, "Nonsteroidal anti-inflammatory drug (NSAID) used to treat pain and fever", 100);
    l.insert("Amoxicillin", 20, "Antibiotic used to treat bacterial infections", 100);
    l.insert("Loratadine", 12, "Antihistamine used to treat allergy symptoms such as sneezing, runny nose, and itching", 100);
    l.insert("Omeprazole", 18, "Proton pump inhibitor (PPI) used to reduce stomach acid and treat conditions such as GERD and ulcers", 100);
    l.insert("Metformin", 8, "Oral diabetes medication that helps control blood sugar levels", 100);
    l.insert("Lisinopril", 10, "ACE inhibitor used to treat high blood pressure and heart failure", 100);
    l.insert("Atorvastatin", 25, "Statin used to lower cholesterol and reduce the risk of heart disease", 100);
    l.insert("Sertraline", 20, "Selective serotonin reuptake inhibitor (SSRI) used to treat depression, anxiety, and OCD", 100);
    l.insert("Acetaminophen", 5, "Pain reliever and fever reducer available over-the-counter", 100);
    l.insert("Simvastatin", 22, "Statin used to lower cholesterol and reduce the risk of heart disease", 100);
    l.insert("Prednisone", 15, "Corticosteroid used to treat inflammation, allergic reactions, and autoimmune disorders", 100);
    l.insert("Albuterol", 12, "Bronchodilator used to treat asthma and COPD", 100);
    l.insert("Losartan", 16, "Angiotensin II receptor blocker (ARB) used to treat high blood pressure and heart failure", 100);
    l.insert("Cetirizine", 8, "Antihistamine used to treat allergy symptoms such as sneezing, runny nose, and itching", 100);

    return l;
}

int main() 
{
    int choice1;
    char choice2;
    LinkedList Pharmacy_list = Pharmacy_Database(); //pharmacy inventory database
    double savings = 0.00;
    
    //this system function clears the terminal before start
    system("cls");

    cout << "\t\t\t\t\t\tWelcome to our pharmacy\n";
    do {
        cout << "\n1- Access Pharmacy Inventory\n"
            << "2- Customer Cart\n"
            << "3- Exit\n"
            << "Choose what system you want to access : ";

        cin >> choice1;
        cout << "\n";

        if (choice1 == 1){

            cout << "\t\t\t\t\tWelcome to the pharmacy inventory\n";
            inventory(Pharmacy_list, savings);

        }else if (choice1 == 2){

            cout << "\t\t\t\t\tWelcome to the customer system\n";
            savings += customer(Pharmacy_list);

        }
        else if (choice1 == 3){
            cout << "\t\t\t\t\tThank you! for using our system\n"
                << "Done by Mariem Ehab & Mariem Hossini fourth year computer engineering students\n"
                << "\t\t\t\t\t<<<For Data Structure Project>>>\n\n";
        }
        else {
            cout << "OOPS!, you entered incorrect  choice.\n";
        }
        if (choice1 == 3)
        {
            break;
        }
        else {
            cout << "Do you want to access another operation? PRESS [(Y) or (N)]: ";
            cin >> choice2;
        }
    } while (choice2 == 'Y' || choice2 == 'y');

    return 0;
}