#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int main() {
    // Hardcoded stock prices
    map<string, double> stockPrices = {
        {"AAPL", 180.0},
        {"TSLA", 250.0},
        {"GOOGL", 135.0},
        {"MSFT", 330.0},
        {"AMZN", 140.0}
    };

    int n;
    cout << "Enter number of stocks you own: ";
    cin >> n;

    double totalInvestment = 0.0;
    string stockName;
    int quantity;

    ofstream file("portfolio.txt"); // optional file output
    file << "Stock Portfolio Summary\n";
    file << "-----------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "Enter stock symbol (AAPL/TSLA/GOOGL/MSFT/AMZN): ";
        cin >> stockName;
        cout << "Enter quantity: ";
        cin >> quantity;

        if (stockPrices.find(stockName) != stockPrices.end()) {
            double value = stockPrices[stockName] * quantity;
            totalInvestment += value;

            cout << stockName << " -> " << quantity << " shares, Value: $" << value << endl;
            file << stockName << " -> " << quantity << " shares, Value: $" << value << "\n";
        } else {
            cout << "Invalid stock symbol!" << endl;
        }
    }

    cout << "\nTotal Investment Value: $" << totalInvestment << endl;
    file << "\nTotal Investment Value: $" << totalInvestment << endl;

    file.close();
    return 0;
}
