#include <iostream>
#include <string>
#include <map>

class AccountHolder {
public:
    AccountHolder() : name(""), balance(0.0) {}

    AccountHolder(const std::string& name, double initialBalance = 0.0)
        : name(name), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited $" << amount << " into " << name << "'s account.\n";
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from " << name << "'s account.\n";
        } else {
            std::cout << "Insufficient funds for withdrawal from " << name << "'s account.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
    double balance;
};

class Bank {
public:
    void createAccount(const std::string& accountHolderName, double initialBalance = 0.0) {
        int accountId = nextAccountId++;
        accounts[accountId] = AccountHolder(accountHolderName, initialBalance);
        std::cout << "Account created for " << accountHolderName << " with ID " << accountId << ".\n";
    }

    AccountHolder* getAccountById(int accountId) {
        auto it = accounts.find(accountId);
        return (it != accounts.end()) ? &it->second : nullptr;
    }

private:
    int nextAccountId = 1;
    std::map<int, AccountHolder> accounts;
};

int main() {
    std::cout << "Welcome to the Bank Account Management System!\n";

    Bank bank;

    int choice;
    do {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Perform Transaction\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string accountHolderName;
                double initialBalance;
                std::cout << "Enter account holder's name: ";
                std::cin >> accountHolderName;
                std::cout << "Enter initial balance: $";
                std::cin >> initialBalance;
                bank.createAccount(accountHolderName, initialBalance);
                break;
            }
            case 2: {
                int accountId;
                std::cout << "Enter account ID: ";
                std::cin >> accountId;

                AccountHolder* account = bank.getAccountById(accountId);
                if (account == nullptr) {
                    std::cout << "Account not found. Please enter a valid account ID.\n";
                    break;
                }

                int transactionChoice;
                std::cout << "\nChoose a transaction:\n";
                std::cout << "1. Deposit\n";
                std::cout << "2. Withdraw\n";
                std::cout << "3. Balance Inquiry\n";
                std::cout << "Enter your choice: ";
                std::cin >> transactionChoice;

                switch (transactionChoice) {
                    case 1: {
                        double amount;
                        std::cout << "Enter deposit amount: $";
                        std::cin >> amount;
                        account->deposit(amount);
                        break;
                    }
                    case 2: {
                        double amount;
                        std::cout << "Enter withdrawal amount: $";
                        std::cin >> amount;
                        account->withdraw(amount);
                        break;
                    }
                    case 3:
                        std::cout << "Balance for " << account->getName() << "'s account: $"
                                  << account->getBalance() << "\n";
                        break;
                    default:
                        std::cout << "Invalid transaction choice. Please enter a valid option.\n";
                }
                break;
            }
            case 3:
                std::cout << "Exiting the Bank Account Management System. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 3);

    return 0;
}

