/*
Done by: Mariem Ehab & Mariam Hossini (4th year computer engineering students)
for: Data Structure Project
Date: April 2023
*/

#include <iostream>
#include"Product.h"

using namespace std;

class LinkedList {
private:
	Product* head;  // pointer to the first node of the linked list
	Product* tail;  // pointer to the last node of the linked list

public:
	//default constructor
	LinkedList() {
		head = nullptr;  
		tail = nullptr;
	}

	// function that returns the head of the list
	Product* getHead() {
		return head;
	}

	// function that returns the tail of the list
	Product* getTail() {
		return tail;
	}

	//check if the linked list is empty
	bool isempty(){
		if (head == nullptr){
			return true;
		}
		else{
			return false;
		}
	}

	//remove all list products
	void makeEmpty() {
		while (head != nullptr) {
			removeFirst();
		}
	}

	// find a product by its name and return its pointer, or nullptr if not found
	Product* isfound(string name) {
		Product* p = head;
		while (p != nullptr) {
			if (p->name == name) {
				return p;
			}

			p = p->next;
		}
		return nullptr;
	}

	// add a new product to the beginning of the list 
	void insertFirst(string name, double price, string details, int quantity) {

		Product* newProductPtr = new Product(name, price, details, quantity);

		if (isempty()) {
			// If the list is empty, make the new product the head and tail of the list
			newProductPtr->next = nullptr;
			newProductPtr->previous = nullptr;
			head = newProductPtr;
			tail = newProductPtr;
			cout << "The product added successfully in the beginning of the list.\n";
		}
		else {

			// Check if the product already exists in the list
			if (isfound(name) == nullptr) {
				// Insert the new product at the beginning of the list
				newProductPtr->next = head;
				newProductPtr->previous = nullptr;

				head->previous = newProductPtr;
				head = newProductPtr;
				cout << "The product added successfully in the beginning of the list.\n";
			}
			else {
				cout << "This product has been added before.\n";
			}

		}
	}

	//1.Insertion of new Item in the list (at the end)
	void insert(string name, double price, string details, int quantity)
	{
		Product* newnode = new Product(name, price, details, quantity);

		//if the linked list is empty
		if (isempty()) {
			// If the list is empty, make the new product the head and tail of the list
			newnode->next = nullptr;
			newnode->previous = nullptr;
			head = newnode;
			tail = newnode;
			cout << "The Product has been added to the cart successfully\n";
		}
		// Check if the product already exists in the list
		else if (isfound(name) == nullptr) {
			// Insert the new product at the end of the list
			newnode->next = nullptr;
			newnode->previous = tail;
			tail->next = newnode;
			tail = newnode;
			cout << "The Product has been added to the cart successfully\n";
		}
		else {
			cout << "This product has been added before.\n";
		}
	}


	// add a new product after an existing product
	void insertAfter(string name, double price, string details, int quantity, string existingProductName) {

		Product* newProductPtr = new Product(name, price, details, quantity);
		Product* existProductPtr = isfound(existingProductName);

		if (existProductPtr != nullptr) {

			//Check wether the product is found or not
			if (isfound(name) == nullptr) {
				newProductPtr->next = existProductPtr->next;
				newProductPtr->previous = existProductPtr;

				if (tail == existProductPtr) {
					tail = newProductPtr;
				}
				else {
					existProductPtr->next->previous = newProductPtr;
				}

				existProductPtr->next = newProductPtr;
				cout << "The product has been added successfully.\n";
			}
			else {
				cout << "This product has been added before.\n";
			}


		}
		else {
			cout << "Sorry! Your product named " << name << " couldn't be added because " << existingProductName
				<< " doesn't exist in the list\n";
		}
	}

	//Add Product at the middle (before an existing product)
	void insertBefore(string name, double price, string details, int quantity, string existingProductName) {
		Product* newProductPtr = new Product(name, price, details, quantity);
		Product* existProductPtr = isfound(existingProductName);

		if (existProductPtr != nullptr) {



			//Check wether the product is found or not
			if (isfound(name) == nullptr) {

				if (head == existProductPtr) {
					head = newProductPtr;
				}
				else {
					existProductPtr->previous->next = newProductPtr;
				}

				newProductPtr->previous = existProductPtr->previous;
				newProductPtr->next = existProductPtr;
				existProductPtr->previous = newProductPtr;
				cout << "The product added successfully.\n";
			}
			else {
				cout << "This product has been added before.\n";
			}

		}
		else {
			cout << "Sorry! Your product named " << name << " couldn't be added because " << existingProductName
				<< " doesn't exist in the list\n";
		}
	}

	//remove item from the first
	void removeFirst() {
		if (head != nullptr) {

			Product* temp = head;
			head = head->next;

			if (head != nullptr) {
				head->previous = nullptr;
			}

			delete temp;
			cout << "The first product deletd successfully.\n";

		}
		else {
			cout << "This element doesn't exist.\n";
		}
	}
	//remove from the last
	void removeLast() {

		if (tail != nullptr) {
			Product* temp = tail;

			tail = tail->previous;

			if (head != nullptr) {
				tail->next = nullptr;
			}

			delete temp;

			cout << "The last product deletd successfully.\n";

		}
		else {
			cout << "This element doesn't exist.\n";
		}
	}
	//remove
	void remove(string name) {

		Product* existProductPtr = isfound(name);

		if (existProductPtr != nullptr) {

			if (existProductPtr == head) {
				removeFirst();
			}
			else if (existProductPtr == tail) {
				removeLast();
			}
			else {
				Product* previousProduct = existProductPtr->previous;
				Product* nextProduct = existProductPtr->next;

				previousProduct->next = nextProduct;
				nextProduct->previous = previousProduct;

				delete existProductPtr;
				cout << "The product deletd successfully.\n";
			}

		}
		else {
			cout << "Sorry! Your product named " << name
				<< " couldn't be removed because it doesn't exist in the list\n";
		}
	}

	//modify name
	void modifyname(string oldName, string newName) {
		Product* productPtr = isfound(oldName);
		if (productPtr != nullptr) {

			productPtr->name = newName;
			cout << "The name has been modified successfully.\n";

		}
		else {
			cout << "Sorry! Your product named " << oldName
				<< " couldn't be modified because it doesn't exist in the list\n";
		}
	}

	//modify price
	void modifyprice(string name, double newPrice) {
		Product* productPtr = isfound(name);
		if (productPtr != nullptr) {

			productPtr->price = newPrice;
			cout << "The price has been modified successfully.\n";

		}
		else {
			cout << "Sorry! Your product named " << name
				<< " couldn't be modified because it doesn't exist in the list\n";
		}
	}

	//modify details
	void modifydetails(string name, string newDetails) {
		Product* productPtr = isfound(name);

		if (productPtr != nullptr) {

			productPtr->details = newDetails;
			cout << "The details have been modified successfully.\n";

		}
		else {
			cout << "Sorry! Your product named " << name
				<< " couldn't be modified because it doesn't exist in the list\n";
		}
	}

	//modify quantity
	void modifyquantity(string name, int newquantity) {
		Product* productPtr = isfound(name);

		if (productPtr != nullptr) {

			productPtr->quantity = newquantity;
			cout << "The quantity has been modified successfully.\n";

		}
		else {
			cout << "Sorry! Your product named " << name
				<< " couldn't be modified because it doesn't exist in the list\n";
		}
	}

	//Modification Functions
	void modify(string oldName, string newName, double newPrice, string newDetails, int newquantity) {
		Product* productPtr = isfound(oldName);
		if (productPtr != nullptr) {
			productPtr->name = newName;
			productPtr->price = newPrice;
			productPtr->details = newDetails;
			productPtr->quantity = newquantity;
			cout << "All data have been modified successfully.\n";
		}
		else {
			cout << "Sorry! Your product named " << oldName
				<< " couldn't be modified because it doesn't exist in the list\n";
		}
	}

	//5.Find the location of the product
	void find_location(string product)
	{
		Product* current = head;
		int count = 0;
		bool check = false;
		while (check == false && current != NULL)
		{
			if (current->name == product)
			{
				check = true;
			}
			count++;
			if (check == false)
			{
				current = current->next;
			}

		}
		if (check == false)
		{
			cout << "This product doesn't exist in the pharmacy.\n";
		}
		else
		{
			cout << "The product is number " << count << " of the products.\n";
		}
	}

	//Display list of products and its details in the list
	void display() {
		int count = 0;
		Product* current = head;
		Product* temp = head;

		while (current != nullptr) {
			current = current->next;
			count++;
		}

		cout << "\nThe List has " << count << " products.\n";
		while (current != nullptr) {
			cout << "Product number\t\t\t" << "Name of product\t\t" << "Price of the product\t\t" << "Quantity of the product\t" << endl;
		}

		for (int i = 0; i < count; i++) {
			cout << "(" << i + 1 << ")\t\t\t\t" << temp->name << "\t\t\t" << temp->price << "\t\t\t\t" << temp->quantity << endl;
			temp = temp->next;
		}
		cout << "\n";
	}

	//6. Generate bill for a customer
	double calc_bill() {
		Product* p = head;
		double bill = 0;

		display();

		while (p != nullptr) {
			bill += (p->price * p->quantity);
			p = p->next;
		}

		cout << "The total bill is: " << bill << "LE\n\n";

		return bill;
	}

};