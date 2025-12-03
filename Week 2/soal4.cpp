#include <iostream>
using namespace std;

void cetakStok(int arr[], int size) {
    cout <<"[";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i < size - 1 ? " " : ",");
}
    cout << "]" << endl;
}

int hitungTotalStok(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int* cariStokPalingSedikit(int arr[], int size) {
    int* ptrPalingSedikit = &arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *ptrPalingSedikit) {
            ptrPalingSedikit = &arr[i];
        }
    }
    return ptrPalingSedikit;
}

void tambahStokBonus(int* ptrStok){
    *ptrStok += 10;
}
int main() {
    int stokBuku[] = {20,25,40,15,10};
    int jumlahJenisBuku = 5;
    
    cout <<"Stok Awal: " <<endl;
    cetakStok(stokBuku, jumlahJenisBuku);

    int total = hitungTotalStok(stokBuku, jumlahJenisBuku);
    cout <<"Total semua Stok: " << total << endl;

    int* ptrStokRendah = cariStokPalingSedikit(stokBuku, jumlahJenisBuku);
    tambahStokBonus(ptrStokRendah);

    cout << "\nStok Buku Setelah Penambahan Bonus:" << endl;
    cetakStok(stokBuku, jumlahJenisBuku);

    return 0;
}