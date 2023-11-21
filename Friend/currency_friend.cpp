#include<iostream>
using namespace std;

class Currency;

class Converter {
public:
    static void convertToUSD(Currency& currency);
    static void convertToDinar(Currency& currency);
    static void convertToEuro(Currency& currency);
    static void convertToSingaporeDollar(Currency& currency);
    static void convertToGBP(Currency& currency);
    static void convertToCustomCurrency(Currency& currency, float exchangeRate, const string& currencyName);
};

class Currency {
private:
    float inr;
public:
    float p;

    void getINR() {
        cout << "Enter the INR: ";
        cin >> inr;
        cout << endl;
    }

    friend class Converter;

    void displayResult(const string& currencyName) {
        cout << inr << " INR = " << p << " " << currencyName << endl;
    }
};

void Converter::convertToUSD(Currency& currency) {
    currency.p = 0.013 * currency.inr;
    currency.displayResult("USD");
}

void Converter::convertToDinar(Currency& currency) {
    currency.p = currency.inr / 26;
    currency.displayResult("Dinar");
}

void Converter::convertToEuro(Currency& currency) {
    currency.p = currency.inr / 83.85;
    currency.displayResult("EURO");
}

void Converter::convertToSingaporeDollar(Currency& currency) {
    currency.p = currency.inr / 56;
    currency.displayResult("Singapore Dollar");
}

void Converter::convertToGBP(Currency& currency) {
    currency.p = currency.inr / 99.42;
    currency.displayResult("GBP");
}

void Converter::convertToCustomCurrency(Currency& currency, float exchangeRate, const string& currencyName) {
    currency.p = currency.inr / exchangeRate;
    currency.displayResult(currencyName);
}

int main() {
    while (1) {
        Currency converter;
        converter.getINR(); // Entering INR

        int choice;
        cout << "Select the currency conversion type:" << endl;
        cout << "1. USD" << endl;
        cout << "2. Dinar" << endl;
        cout << "3. EURO" << endl;
        cout << "4. Singapore Dollar" << endl;
        cout << "5. GBP" << endl;
        cout << "6. Custom Currency" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        float customExchangeRate;
        string customCurrencyName;  // Move the declaration outside the switch statement

        switch (choice) {
        case 1:
            Converter::convertToUSD(converter);
            break;
        case 2:
            Converter::convertToDinar(converter);
            break;
        case 3:
            Converter::convertToEuro(converter);
            break;
        case 4:
            Converter::convertToSingaporeDollar(converter);
            break;
        case 5:
            Converter::convertToGBP(converter);
            break;
        case 6:
            cout << "Enter the custom exchange rate: ";
            cin >> customExchangeRate;
            cout << "Enter the custom currency name: ";
            cin >> customCurrencyName;
            Converter::convertToCustomCurrency(converter, customExchangeRate, customCurrencyName);
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
