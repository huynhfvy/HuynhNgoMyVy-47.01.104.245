#include <iostream>
#include <vector>
#include <string>

using namespace std;


string findLCS(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int> > table(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            i--;
            j--;
        }
        else if (table[i - 1][j] > table[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string str1, str2;
    cout << "Nhap chuoi dau tien: ";
    getline(cin, str1);
    cout << "\n";

    cout << "Nhap chuoi thu hai: ";
    getline(cin, str2);
    cout << "\n";

    string lcs = findLCS(str1, str2);
    cout << "Chuoi chung dai nhat la: " << lcs << "\n";

    return 0;
}
