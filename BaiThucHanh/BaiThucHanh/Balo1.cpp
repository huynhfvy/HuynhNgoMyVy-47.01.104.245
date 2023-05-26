#include <iostream>
#include <vector>

using namespace std;

void solveBalo(int n, int w, vector<int>& items) {
    vector<int> selectedItems;
    vector<vector<int> > tab(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (items[i - 1] <= j) {
                tab[i][j] = max(tab[i - 1][j], items[i - 1] + tab[i - 1][j - items[i - 1]]);
            }
            else {
                tab[i][j] = tab[i - 1][j];
            }
        }
    }

    int optimalWeight = tab[n][w];

    int i = n, j = w;
    while (i > 0 && j > 0) {
        if (tab[i][j] != tab[i - 1][j]) {
            selectedItems.push_back(i - 1);
            j -= items[i - 1];
        }
        i--;
    }

    cout << optimalWeight << endl;
    for (int i = selectedItems.size() - 1; i >= 0; i--) {
        cout << selectedItems[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }

    solveBalo(n, w, items);

    return 0;
}
