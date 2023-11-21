#include<iostream>
using namespace std;

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

    void convertToUSD() {
        p = 0.013 * inr;
        cout << inr << " INR = " << p << " USD" << endl;
    }

    void convertToDinar() {
        p = inr / 26;
        cout << inr << " INR = " << p << " Dinar" << endl;
    }

    void convertToEuro() {
        p = inr / 83.85;
        cout << inr << " INR = " << p << " EURO" << endl;
    }

    void convertToSingaporeDollar() {
        p = inr / 56;
        cout << inr << " INR = " << p << " Singapore Dollar" << endl;
    }

    void convertToGBP() {
        // Conversion to British Pound
        p = inr / 99.42;
        cout << inr << " INR = " << p << " GBP" << endl;
    }

    void convertToCustomCurrency(float exchangeRate, const string& currencyName) {
        p = inr / exchangeRate;
        cout << inr << " INR = " << p << " " << currencyName << endl;
    }
};

int main()
{
    while (1)
    {
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
            converter.convertToUSD();
            break;
        case 2:
            converter.convertToDinar();
            break;
        case 3:
            converter.convertToEuro();
            break;
        case 4:
            converter.convertToSingaporeDollar();
            break;
        case 5:
            converter.convertToGBP();
            break;
        case 6:
            cout << "Enter the custom exchange rate: ";
            cin >> customExchangeRate;
            cout << "Enter the custom currency name: ";
            cin >> customCurrencyName;
            converter.Currency::convertToCustomCurrency(customExchangeRate, customCurrencyName);
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

