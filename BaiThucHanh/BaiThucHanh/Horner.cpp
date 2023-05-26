#include <iostream>
#include <vector>

using namespace std;

double horner(const vector<double>& dathuc, double x) {
    double result = 0;
    for (int i = dathuc.size() - 1; i >= 0; i--) {
        result = result * x + dathuc[i];
    }

    return result;
}

int main() {
    int bac;
    cout << "Nhap bac cua da thuc: ";
    cin >> bac;
    cout << "\n";

    vector<double> dathuc(bac + 1);
    for (int i = bac; i >= 0; i--) {
        cout << "Nhap he so cua x^" << i << ": " << "\n";
        cin >> dathuc[i];
    }

    double x;
    cout << "Nhap diem x can tinh gia tri da thuc: ";
    cin >> x;
    cout << "\n";

    double result = horner(dathuc, x);

    cout << "Gia tri cua da thuc tai diem " << x << " la: " << result << "\n";

    return 0;
}
