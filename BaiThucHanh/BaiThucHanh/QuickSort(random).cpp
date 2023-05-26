#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[low], arr[i - 1]);
    return i - 1;
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIdx = partition(arr, low, high);
        quicksort(arr, low, pivotIdx - 1);
        quicksort(arr, pivotIdx + 1, high);
    }
}

void shiftArray(vector<int>& arr, int startIdx) {
    vector<int> temp(arr.begin() + startIdx, arr.end());
    temp.insert(temp.end(), arr.begin(), arr.begin() + startIdx);
    arr = temp;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    cout << endl;

    vector<int> arr(n);
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;

    int startIdx;
    cout << "Nhap vi tri bat dau: ";
    cin >> startIdx;
    cout << endl;

    shiftArray(arr, startIdx);
    quicksort(arr, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
