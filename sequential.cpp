// Sequential Search - Cek Presensi dengan NIM
#include <iostream>
#include <stdexcept>
using namespace std;

int search(int arr[], int n, int target) {
    if (target <= 0)
        throw invalid_argument("NIM harus > 0");

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int hadir[] = {578857, 585479, 579462,
                   578837, 581203, 577914};
    int n = sizeof(hadir) / sizeof(hadir[0]);
    int nim;
    try {
        cout << "Masukkan NIM: ";
        if (!(cin >> nim))
            throw invalid_argument("input salah");
        int pos = search(hadir, n, nim);
        if (pos == -1)
            cout << "Tidak ada di daftar hadir" << endl;
        else
            cout << "Ditemukan di indeks " << pos
                 << " (kedatangan ke-" << pos + 1
                 << ")" << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}