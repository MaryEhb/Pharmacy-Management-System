# Pharmacy Management System
Done by: Mariem Ehab & Mariam Hossini (4th year computer engineering students)
for: Data Structure Project
Date: April 2023

This is a pharmacy management system based on the doubly linked list data structure. It consists of three main parts, the pharmacy database, the inventory management of the pharmacy, the customer cart management.
these parts are constructed by the LinkedList and its nodes called Products.

## Pharmacy DataBase
This function represents a database of the available products in the pharmacy. It creates a linked list and adds all the products, and then returns that list. The list contains the following products:

"Aspirin" , "Ibuprofen", "Amoxicillin", "Loratadine", "Omeprazole", "Metformin", "Lisinopril", "Atorvastatin", "Sertraline", "Acetaminophen", "Simvastatin", "Prednisone", "Albuterol".

## Inventory Management

The inventory management part is responsible for managing the products available in the pharmacy. It has the following features:

- Displaying the list of available products with their prices and quantities.
- Adding new products to the inventory.
- Removing products from the inventory.
- Modifying the price and quantity of existing products.
- Check if the product is in the pharmacy
- Displaying the total sales made by the pharmacy on the current day
- Displaying the details needed of a product

## Customer Cart Management

The customer cart management part is responsible for managing the customer's order. It has the following features:

- Displaying the list of available products with their prices and quantities in the cart.
- Adding products to the cart.
- Removing products from the cart.
- Modifing the quantity of a product in the cart
- checking out and creating the bill to the customer (plus removing the products purchsed from the pharmacy database)

## Product Class
It is a class that represents a product with the following attributes:

- `name` (string): the name of the product
- `price` (double): the price of the product
- `quantity` (int): the quantity of the product
- `details` (string): additional details about the product

In addition, the `Product` class has two pointers:

- `next` (Product*): a pointer to the next product in a linked list
- `previous` (Product*): a pointer to the previous product in a linked list

### Constructors

The `Product` class has two constructors:

- `Product()`: a default constructor that sets the `name` to "unknown", `price` to 0, `details` to "no details" and `quantity` to 1.
- `Product(string n, double p, string d, int q)`: a constructor that takes in four parameters `n`, `p`, `d`, `q` which respectively represent the name, price, details and quantity of the product.

## LinkedList Class 

it is a class for storing `Product` objects. The class provides functionality for adding, removing, and finding products in the list.

### Class Members

#### `private` Members

- `Product* head`: pointer to the first node of the linked list
- `Product* tail`: pointer to the last node of the linked list

#### `public` Members

- `LinkedList()`: default constructor that initializes the `head` and `tail` pointers to `nullptr`.
- `Product* getHead()`: a function that returns the head of the list.
- `Product* getTail()`: a function that returns the tail of the list.
- `bool isempty()`: a function that returns true if the linked list is empty, otherwise returns false.
- `void makeEmpty()`: a function that removes all the products from the list.
- `Product* isfound(string name)`: a function that searches for a product by its name and returns its pointer if found, otherwise returns `nullptr`.
- `void insertFirst(string name, double price, string details, int quantity)`: a function that adds a new product to the beginning of the list.
- `void insert(string name, double price, string details, int quantity)`: a function that adds a new product to the end of the list.
- `void insertAfter(string name, double price, string details, int quantity, string existingProductName)`: a function that adds a new product after an existing product in the list.
- `void insertBefore(string name, double price, string details, int quantity, string existingProductName)`: a function that adds a new product before an existing product in the list.
- `removeFirst()`: a function that removes/delete the first product in the list
- `removeLast()`: a function that removes/delete the last product in the list
- `remove(string name)`: a function that removes/delete a product by its name from the list
- `modifyname(string oldName, string newName)`: a function that modifies the name of a product in the list
- `modifyprice(string name, double newPrice)`: a function that modifies the price of a product in the list
- `modifydetails(string name, string newDetails)`: a function that modifies the details of a product in the list
- `modifyquantity(string name, int newquantity)`: a function that modifies the quantity of a product in the list
- `modify(string oldName, string newName, double newPrice, string newDetails, int newquantity)`: a function that modifies all of the name, price, details and quantity of a product in the list
- `find_location(string product)`: a function that finds the location of the product returning its count in the list
- `display()`: a function that displays all the products and its details in the list
- `calc_bill()`: a function that generates bill for the products contained in the list
