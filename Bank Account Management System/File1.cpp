 #include <iostream>
#include <vector>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit of $" << amount << " successful.\n";
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal of $" << amount << " successful.\n";
        } else {
            std::cout << "Insufficient funds!\n";
        }
    }

    void displayBalance() {
        std::cout << "Account Balance: $" << balance << std::endl;
    }
};

int main() {
    std::string accNum;
    double initialBalance;

    std::cout << "Enter account number: ";
    std::cin >> accNum;

    std::cout << "Enter initial balance: ";
    std::cin >> initialBalance;

    BankAccount account(accNum, initialBalance);

    int choice;
    double amount;

    do {
        std::cout << "\n1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Display Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.displayBalance();
                break;
            case 4:
                std::cout << "Exiting program...";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

