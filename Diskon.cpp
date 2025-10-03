#include <iostream>

  

using namespace std;

int main(){

 double total_pembelian,diskon;

cout << "Total belanja: Rp. ";

cin >> total_pembelian;

if (total_pembelian >= 30000){

diskon = 0.1 * total_pembelian;

cout << "Kamu dapat diskon sebesar " << diskon << "";

 } else {

cout << "total belanja kamu belum memenuhi syarat mendapatkan diskon";

 }

return 0;

}