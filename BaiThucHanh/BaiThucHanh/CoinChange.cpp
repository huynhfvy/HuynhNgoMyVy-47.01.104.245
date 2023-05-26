#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void coinChange(int amount, vector<int>& coins) {
    sort(coins.begin(), coins.end(), greater<int>());

    vector<int> change(coins.size(), 0);

    for (int i = 0; i < coins.size(); i++) {
        if (amount >= coins[i]) {
            change[i] = amount / coins[i];
            amount -= change[i] * coins[i];
        }
    }

    if (amount == 0) {
        cout << "So luong dong tien can it nhat de doi:" << endl;
        for (int i = 0; i < coins.size(); i++) {
            cout << coins[i] << ": " << change[i] << " to" << endl;
        }
    }
    else {
        cout << "Khong the doi." << endl;
    }
}

int main() {
    int amount;
    cout << "Nhap so tien can doi: ";
    cin >> amount;
    cout << "\n";


    int numCoins;
    cout << "Nhap so luong dong tien: ";
    cin >> numCoins;
    cout << "\n";

    vector<int> coins(numCoins);
    cout << "Nhap menh gia cua tung dong tien: ";
    for (int i = 0; i < numCoins; i++) {
        cin >> coins[i];
    }
    cout << "\n";

    coinChange(amount, coins);

    return 0;
}
