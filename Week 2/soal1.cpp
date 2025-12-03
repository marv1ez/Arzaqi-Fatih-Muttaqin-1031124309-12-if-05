#include <iostream>
using namespace std;

int main() {
    int bukuPerHari[7] = {4,3,5,6,2,4,2};
    int totalBuku = 0;

    cout<<"Laporan Baca Buku Mingguan"<<endl;

    for (int i = 0; i < 7; i++) {
        cout<<"Hari ke-"<<i+1<<":"<<bukuPerHari[i]
        <<"buku"<<endl;
        totalBuku += bukuPerHari[i];
    }
}