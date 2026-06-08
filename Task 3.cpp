#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
};

class Account {
private:
    int accountNumber;
    string customerName;
    double balance;
    vector<Transaction> history;

public:
    Account(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        customerName = name;
        balance = initialBalance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getCustomerName() {
        return customerName;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "?" << amount << " deposited successfully.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
            return;
        }

        balance -= amount;
        history.push_back(Transaction("Withdrawal", amount));
        cout << "?" << amount << " withdrawn successfully.\n";
    }

    void transfer(Account &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
            return;
        }

        balance -= amount;
        receiver.balance += amount;

        history.push_back(Transaction("Transfer Sent", amount));
        receiver.history.push_back(Transaction("Transfer Received", amount));

        cout << "?" << amount << " transferred successfully.\n";
    }

    void displayAccountInfo() {
        cout << "\n----- Account Details -----\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Balance        : ?" << balance << endl;
    }

    void showTransactionHistory() {
        cout << "\n----- Transaction History -----\n";

        if (history.empty()) {
            cout << "No transactions found.\n";
            return;
        }
    }
};

int main() {
    int accNo1, accNo2;
    string name1, name2;
    double balance1, balance2;

    cout << "Create Account 1\n";
    cout << "Enter Account Number: ";
    cin >> accNo1;

    cin.ignore();
    cout << "Enter Customer Name: ";
    getline(cin, name1);

    cout << "Enter Initial Balance: ";
    cin >> balance1;

    Account acc1(accNo1, name1, balance1);

    cout << "\nCreate Account 2\n";
    cout << "Enter Account Number: ";
    cin >> accNo2;

    cin.ignore();
    cout << "Enter Customer Name: ";
    getline(cin, name2);

    cout << "Enter Initial Balance: ";
    cin >> balance2;

    Account acc2(accNo2, name2, balance2);

    int choice;
    double amount;

    do {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Fund Transfer\n";
        cout << "4. View Account Details\n";
        cout << "5. Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            acc1.deposit(amount);
            break;

        case 2:
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            acc1.withdraw(amount);
            break;

        case 3:
            cout << "Enter Transfer Amount: ";
            cin >> amount;
            acc1.transfer(acc2, amount);
            break;

        case 4:
            acc1.displayAccountInfo();
            break;

        case 5:
            acc1.showTransactionHistory();
            break;

        case 6:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
