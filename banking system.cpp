#include <iostream>
#include <vector>
#include <string>
using namespace std;

//==================== CUSTOMER CLASS ====================

class Customer
{
private:
    int customerID;
    string name;
    string phone;

public:
    Customer()
    {
        customerID = 0;
        name = "";
        phone = "";
    }

    Customer(int id, string n, string p)
    {
        customerID = id;
        name = n;
        phone = p;
    }

    int getCustomerID()
    {
        return customerID;
    }

    string getName()
    {
        return name;
    }

    string getPhone()
    {
        return phone;
    }

    void displayCustomer()
    {
        cout << "\nCustomer ID : " << customerID;
        cout << "\nName        : " << name;
        cout << "\nPhone       : " << phone << endl;
    }
};

//==================== TRANSACTION CLASS ====================

class Transaction
{
private:
    string type;
    double amount;

public:
    Transaction()
    {
        type = "";
        amount = 0;
    }

    Transaction(string t, double a)
    {
        type = t;
        amount = a;
    }

    void displayTransaction()
    {
        cout << type << " : Rs. " << amount << endl;
    }
};
//==================== ACCOUNT CLASS ====================

class Account
{
private:
    int accountNumber;
    Customer customer;
    double balance;
    vector<Transaction> transactions;

public:
    Account()
    {
        accountNumber = 0;
        balance = 0;
    }

    Account(int accNo, Customer c, double bal = 0)
    {
        accountNumber = accNo;
        customer = c;
        balance = bal;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }

    Customer getCustomer()
    {
        return customer;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            transactions.push_back(Transaction("Deposit", amount));
            cout << "\nRs. " << amount << " Deposited Successfully.\n";
        }
        else
        {
            cout << "\nInvalid Amount!\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount <= balance && amount > 0)
        {
            balance -= amount;
            transactions.push_back(Transaction("Withdrawal", amount));
            cout << "\nRs. " << amount << " Withdrawn Successfully.\n";
        }
        else
        {
            cout << "\nInsufficient Balance or Invalid Amount!\n";
        }
    }

    bool transfer(Account &receiver, double amount)
    {
        if (amount <= balance && amount > 0)
        {
            balance -= amount;
            receiver.balance += amount;

            transactions.push_back(Transaction("Transfer Sent", amount));
            receiver.transactions.push_back(Transaction("Transfer Received", amount));

            cout << "\nTransfer Successful.\n";
            return true;
        }

        cout << "\nTransfer Failed!\n";
        return false;
    }

    void showTransactions()
    {
        cout << "\n----- Transaction History -----\n";

        if (transactions.empty())
        {
            cout << "No Transactions Yet.\n";
            return;
        }

        for (int i = 0; i < transactions.size(); i++)
        {
            transactions[i].displayTransaction();
        }
    }

    void displayAccount()
    {
        cout << "\n========== Account Details ==========\n";
        customer.displayCustomer();
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance        : Rs. " << balance << endl;
    }
};
//==================== BANKING SYSTEM CLASS ====================

class BankingSystem
{
private:
    vector<Account> accounts;

public:

    void createAccount()
    {
        int customerID, accountNumber;
        string name, phone;
        double initialBalance;

        cout << "\nEnter Customer ID: ";
        cin >> customerID;
        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Initial Balance: ";
        cin >> initialBalance;

        Customer customer(customerID, name, phone);
        Account account(accountNumber, customer, initialBalance);

        accounts.push_back(account);

        cout << "\nAccount Created Successfully!\n";
    }

    int findAccount(int accountNumber)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNumber() == accountNumber)
            {
                return i;
            }
        }

        return -1;
    }

    void depositMoney()
    {
        int accountNumber;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        int index = findAccount(accountNumber);

        if (index == -1)
        {
            cout << "Account Not Found!\n";
            return;
        }

        cout << "Enter Amount: ";
        cin >> amount;

        accounts[index].deposit(amount);
    }

    void withdrawMoney()
    {
        int accountNumber;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        int index = findAccount(accountNumber);

        if (index == -1)
        {
            cout << "Account Not Found!\n";
            return;
        }

        cout << "Enter Amount: ";
        cin >> amount;

        accounts[index].withdraw(amount);
    }

    void transferMoney()
    {
        int sender, receiver;
        double amount;

        cout << "\nSender Account Number: ";
        cin >> sender;

        cout << "Receiver Account Number: ";
        cin >> receiver;

        int senderIndex = findAccount(sender);
        int receiverIndex = findAccount(receiver);

        if (senderIndex == -1 || receiverIndex == -1)
        {
            cout << "Invalid Account Number!\n";
            return;
        }

        cout << "Enter Amount: ";
        cin >> amount;

        accounts[senderIndex].transfer(accounts[receiverIndex], amount);
    }

    void displayAccount()
    {
        int accountNumber;

        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        int index = findAccount(accountNumber);

        if (index == -1)
        {
            cout << "Account Not Found!\n";
            return;
        }

        accounts[index].displayAccount();
    }

    void transactionHistory()
    {
        int accountNumber;

        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        int index = findAccount(accountNumber);

        if (index == -1)
        {
            cout << "Account Not Found!\n";
            return;
        }

        accounts[index].showTransactions();
    }
};
//==================== MAIN FUNCTION ====================

int main()
{
    BankingSystem bank;

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "        BANKING SYSTEM MENU\n";
        cout << "=====================================\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Money\n";
        cout << "5. Display Account Details\n";
        cout << "6. Transaction History\n";
        cout << "7. Exit\n";
        cout << "=====================================\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;

        case 2:
            bank.depositMoney();
            break;

        case 3:
            bank.withdrawMoney();
            break;

        case 4:
            bank.transferMoney();
            break;

        case 5:
            bank.displayAccount();
            break;

        case 6:
            bank.transactionHistory();
            break;

        case 7:
            cout << "\nThank You For Using Banking System.\n";
            break;

        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 7);

    return 0;
}