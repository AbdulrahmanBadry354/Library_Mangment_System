﻿// main.cpp
#include <iostream>
#include <string>
#include "Customer.h"
#include "LinkedList.h"
using namespace std;

bool isValied(string str, string btr) { // valied sentence
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            continue;
        else {
            str = "unknown";
            break;
        }
    }
    if (str == "unknown") {
        cout << "not valied " + btr + "\n";
        return false;
    }
    else {
        return true;
    }
}

bool isValiedNum(string str, string btr) { // valied any number
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == '.')
            continue;
        else {
            str = "unknown";
            break;
        }
    }
    if (str == "unknown") {
        cout << "not valied " + btr + "\n";
        return false;
    }
    else {
        return true;
    }
}

int main() {
    LinkedList customerList;
   
    while (true) { // main menu
        cout << "########################";
        cout << "\nMenu:\n"
            << "1. Create account\n"
            << "2. Delete account\n"
            << "3. Withdraw\n"
            << "4. Deposit\n"
            << "5. Check balance\n"
            << "6. count\n"
            << "7. Exit\n";
        cout << "########################\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, username, password;
            string age, id;
            string balance;

            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter initial balance: ";
            cin >> balance;
            // check name valied
            if (isValied(name, "name")) {}
            else { break; }
            // check age valied
            if (isValiedNum(age, "age")) {}
            else { break; }
            // check id valied
            if (isValiedNum(id, "id")) {}
            else { break; }
            // check balanc valied
            if (isValiedNum(balance, "balance")) {}
            else { break; }
            if (stoi(age) > 120 && stoi(age) <= 12 && id.length() > 6) {
                cout << "Not valied age or ID\n";
                break;
            }
            Customer newCustomer(name, stoi(age), username, password, stoi(id), stod(balance));
            bool checker = false;
            customerList.insert(newCustomer, checker);
            if (checker) {}
            else
                cout << "Account created successfully\n";
            break;
        }
        case 2: {
            string id;
            cout << "Enter ID to delete: ";
            cin >> id;
            // check id valied
            if (isValiedNum(id, "id")) {}
            else
                break;
            bool checker = false;
            customerList.deleteCustomerById(stoi(id), checker);
            if (checker) {}
            else
                cout << "Account deleted successfully\n";
            break;
        }
        case 3: {
            string id;
            string amount;
            cout << "Enter ID to withdraw from: ";
            cin >> id;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            // is valied id
            if (isValiedNum(id, "id")) {}
            else
                break;
            // is valied amount
            if (isValiedNum(amount, "amount")) {}
            else
                break;
            customerList.withdrawFromAccount(stoi(id), stod(amount));
            break;
        }
        case 4: {
            string id;
            string amount;
            cout << "Enter ID to deposit to: ";
            cin >> id;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            // is valied id
            if (isValiedNum(id, "id")) {}
            else
                break;
            // is valied amount
            if (isValiedNum(amount, "amount")) {}
            else
                break;
            Customer* customer = customerList.findCustomerById(stoi(id));
            if (customer != nullptr) {
                customer->deposit(stod(amount));
            }
            else {
                cout << "Customer with ID " << id << " not found" << endl;
            }
            break;
        }
        case 5: {
            string id;
            cout << "Enter ID to check balance: ";
            cin >> id;
            // is valied id
            if (isValiedNum(id, "id")) {}
            else
                break;
            customerList.displayAccountBalance(stoi(id));
            break;
        }
        case 6: {
            cout << customerList.Count() <<"\n";
            break;
        }
        case 7: {
            cout << "Exiting program\n";
            return 0;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}




//  full project in one file
/*#include <iostream>
#include <string>
using namespace std;
class Customer {
private:
    string name;
    int age;
    string username;
    string password;
    int id;
    double balance;

public:
    Customer(string name, int age, string username, string password, int id, double balance)
        : name(name), age(age), username(username), password(password), id(id), balance(balance) {}

    string getName() const { return name; }
    int getAge() const { return age; }
    string getUsername() const { return username; }
    string getPassword() const { return password; }
    int getId() const { return id; }
    double getBalance() const { return balance; }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account " << id << endl;
        }
        else {
            cout << "Insufficient funds in account " << id << endl;
        }
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " to account " << id << endl;
    }

    void displayAccountInfo() {
        cout << "Name: " << name << ", "
            << "Age: " << age << ", "
            << "Username: " << username << ", "
            << "ID: " << id << ", "
            << "Balance: $" << balance << endl;
    }
};

class Node {
public:
    Customer customer;
    Node* next;

    Node(Customer customer) : customer(customer), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(Customer customer, bool&check) {
        if (head == nullptr)
        {
            Node* newNode = new Node(customer);
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Customer* Customer = findCustomerById(customer.getId());
            if (Customer == nullptr)
            {
                Node* newNode = new Node(customer);
                newNode->next = head;
                head = newNode;
            }
            else
            {
                cout << "Please check the ID you recived from customer services as there is exists one \n";
                cout << "Enter the right one as there isn't two id equall\n";
                check = true;
            }
        }
      
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            temp->customer.displayAccountInfo();
            temp = temp->next;
        }
    }

    Customer *findCustomerById(int id) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->customer.getId() == id) {
                return &(temp->customer);
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void deleteCustomerById(int id ,bool&check) {
        Node* temp = head;
        Node* prev = nullptr;
        Customer* Customer = findCustomerById(id);
        if (Customer == nullptr)
        {
            cout << "There isn't account with this ID " << id <<"\n";
            check = true;
        }
        else
        {
        while (temp != nullptr) {
            if (temp->customer.getId() == id) {
                if (prev == nullptr) {
                    head = temp->next;
                }
                else {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        }
    }

    void withdrawFromAccount(int id, double amount) {
        Customer* customer = findCustomerById(id);
        if (customer != nullptr) {
            customer->withdraw(amount);
        }
        else {
            cout << "Customer with ID " << id << " not found" << endl;
        }
    }

    void displayAccountBalance(int id) {
        Customer* customer = findCustomerById(id);
        if (customer != nullptr) {
            cout << "Account " << id << " balance: $" << customer->getBalance() << endl;
        }
        else {
            cout << "Customer with ID " << id << " not found" << endl;
        }
    }
};
bool isValied(string str ,string btr )
{
    
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            continue;
        else

        {
            str = "unknown";
            break;
        }
    }
    if (str == "unknown")
    {
        cout << "not valied " + btr + "\n";
        return false;
    }
    else
    {
        return true;
    }
 }

bool isValiedNum(string str ,string btr)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == '.')
            continue;
        else

        {
            str = "unknown";
            break;
        }
    }
    if (str == "unknown")
    {
        cout << "not valied " + btr + "\n";
        return false;
    }
    else
    {
        return true;
    }
}
int main() {
    LinkedList customerList;

    while (true) {
        cout << "########################";
        cout << "\nMenu:\n"
            << "1. Create account\n"
            << "2. Delete account\n"
            << "3. Withdraw\n"
            << "4. Deposit\n"
            << "5. Check balance\n"
            << "6. Exit\n";
        cout << "########################\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, username, password;
            string age, id;
            string balance;

            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter initial balance: ";
            cin >> balance;
            //check name valied
            if (isValied(name,"name")) {}
            else { break; }
            //check age valied
            if (isValiedNum(age,"age")) {}
            else { break; }
            //check id valied
            if (isValiedNum(id, "id")) {}
            else { break; }
            //check balanc valied
            if (isValiedNum(balance ,"balance")) {}
            else { break; }
            if (stoi(age) > 120 && stoi(age) <= 12 && id.length() > 6)
            {
                cout << "Not valied age or ID\n";
                break;
            }
            Customer newCustomer(name, stoi(age), username, password, stoi(id), stod(balance));
            bool checker = false;
            customerList.insert(newCustomer,checker);
            if (checker) {}
            else
            cout << "Account created successfully\n";
            break;
        }
        case 2: {
            string id;
            cout << "Enter ID to delete: ";
            cin >> id;
            //check id valied
            if (isValiedNum(id,"id")) {}
            else
                break;
            bool checker = false;
            customerList.deleteCustomerById(stoi(id), checker);
            if (checker) {}
            else
            cout << "Account deleted successfully\n";
            break;
        }
        case 3: {
            string id;
            string amount;
            cout << "Enter ID to withdraw from: ";
            cin >> id;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            //is valied id
            if (isValiedNum(id,"id")) {}
            else
                break;
            //is valied amount
            if (isValiedNum(amount,"amount")) {}
            else
                break;
            customerList.withdrawFromAccount(stoi(id), stod(amount));
            break;
        }
        case 4: {
            string id;
            string amount;
            cout << "Enter ID to deposit to: ";
            cin >> id;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            //is valied id
            if (isValiedNum(id,"id")) {}
            else
                break;
            //is valied amount
            if (isValiedNum(amount,"amount")) {}
            else
                break;
            Customer* customer = customerList.findCustomerById(stoi(id));
            if (customer != nullptr) {
                customer->deposit(stod(amount));
            }
            else {
                cout << "Customer with ID " << id << " not found" << endl;
            }
            break;
        }
        case 5: {
            string id;
            cout << "Enter ID to check balance: ";
            cin >> id;
            //is valied id
            if (isValiedNum(id,"id")) {}
            else
                break;
            customerList.displayAccountBalance(stoi(id));
            break;
        }
        case 6: {
            cout << "Exiting program\n";
            return 0;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}*/
