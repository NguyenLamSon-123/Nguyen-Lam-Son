#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    int mang[100];  
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> mang[i];
    }

    int newElement;
    cout << "Nhap phan tu muon them vao cuoi mang: ";
    cin >> newElement;

    mang[n] = newElement;
    n++; 
    cout << "Mang sau khi them phan tu: ";
    for (int i = 0; i < n; i++) {
        cout << mang[i] << " ";
    }
    cout << endl;

    return 0;
}
