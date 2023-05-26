#include <iostream>

using namespace std;

void chuyen_dia(int n, char nguon, char trung_gian, char dich) {
    if (n == 1) {
        cout << "1 " << nguon << " " << dich << "\n";
    }
    else {
        chuyen_dia(n - 1, nguon, dich, trung_gian);
        cout << n << " " << nguon << " " << dich << "\n";
        chuyen_dia(n - 1, trung_gian, nguon, dich);
    }
}

int main() {

    int n;
    cin >> n;
    chuyen_dia(n, 'A', 'B', 'C');

    return 0;
}