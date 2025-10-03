# Template Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Arzaqi Fatih Muttaqin
- **NIM**: 103112430092
- **Kelas**: 12-IF-05

## 2. Motivasi Belajar Struktur Data
Belajar Struktur Data adalah investasi terbaik karena ia adalah kunci untuk merancang program yang sangat cepat dan efisien, sekaligus pondasi utama yang wajib dikuasai untuk lolos wawancara kerja di perusahaan teknologi top.

## 3. Dasar Teori
stuktur data itu ibaratnya buat mengatur dan menyipan supaya bisa di cari, diproses, dan juga di ubah . Nah dari pemilihann stuktur data yang bagus dapat membuat program nya bisa berjalan lebih bagus , lebih efisien dll

- **Array** Array adalah struktur data linear yang menyimpan elemen dengan tipe data yang sama dalam blok memori yang berdekatan. Elemen dalam array diakses menggunakan indeks numerik.
- **Linked List** Linked List adalah struktur data linear di mana setiap elemen (disebut node) berisi data dan pointer yang menunjuk ke node berikutnya. Tidak seperti array, linked list tidak menyimpan elemen secara berurutan di memori.
- **Stack**  
    Stack (tumpukan) adalah struktur data linear yang menerapkan prinsip **Last In, First Out (LIFO)**. Elemen terakhir yang ditambahkan akan menjadi yang pertama diambil.
- **Queue**  
    Queue (antrian) adalah struktur data linear yang menerapkan prinsip **First In, First Out (FIFO)**. Elemen pertama yang masuk akan menjadi yang pertama keluar.
- **Tree**  
    Tidak seperti array, linked list, stack dan queue, yang merupakan struktur data linier, tree adalah struktur data hierarkis. Binary tree adalah jenis struktur tree di mana setiap node memiliki paling banyak dua child, yang disebut sebagai left child dan right child. Binary tree seringkali diimplementasikan menggunakan link.
- **Graph**  
    Graph adalah struktur data yang terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling keterkaitan. Graph merepresentasikan kumpulan object dimana pasangan dari objek terhubung oleh sebuah link.
## 4. Guided
### 4.1 Guided 1
```cpp
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
```

Penjelasan : Program di atas dibuat untuk menghitung diskon dari total belanja yang dimasukkan oleh pengguna. Pertama, program meminta input berupa nilai total pembelian, lalu menyimpannya ke dalam variabel `total_pembelian`. Setelah itu dilakukan pengecekan dengan struktur `if-else`, yaitu jika nilai pembelian lebih besar atau sama dengan Rp30.000, maka pengguna berhak mendapat diskon sebesar 10% dari total belanja. Nilai diskon ini dihitung menggunakan rumus `diskon = 0.1 * total_pembelian` dan hasilnya langsung ditampilkan. Namun, jika pembelian kurang dari Rp30.000, program akan menampilkan pesan bahwa belanjanya masih kurang untuk mendapatkan diskon.

Output :
![[1.png]]
### 4.2 Guided 2
```cpp
#include <iostream>

  

  

using namespace std;

  

int main(){

  

    float celcius, fahrenheit;

  

    cout << "dingin kamu berapa derajat:";

  

    cin >> celcius;

  

    fahrenheit = (9.0/5.0) * celcius + 32;

  

    cout << "setara dinginnya : " << fahrenheit << " derajat fahrenheit" << endl;

  

    cout << "terlalu dingin";

  

    return 0;

  

}
```

Penjelasan : Program diatas berfungsi untuk mengubah suhu dari Celcius ke Fahrenheit. Pertama, dibuat dua variabel `float`: `celcius` untuk menampung input pengguna dan `fahrenheit` untuk hasil konversi. Setelah pengguna memasukkan suhu dalam Celcius lewat `cin`, program menghitungnya dengan rumus `(9.0/5.0) * celcius + 32`. Nilai yang diperoleh kemudian disimpan ke variabel `fahrenheit` dan ditampilkan ke layar dalam bentuk derajat Fahrenheit.

Output : ![[2.png]]

### 4.3 Guided 3
```cpp
#include <iostream>

  

  

using namespace std;

  

int main() {

  

    int a = 20;

  

    int b;

  

  

    b = 20 + ++a;

  

    cout << "Nilai a: " << a << endl;

  

    cout << "Nilai b: " << b << endl;

  

    return 0;

  

}
```

Penjelasan :  Program diatas memperlihatkan cara kerja operator **prefix increment (++r)**. Awalnya, variabel `r` diberi nilai 20, lalu `s` dideklarasikan tanpa nilai awal. Saat baris `s = 20 + ++r;` dijalankan, `r` dinaikkan dulu menjadi 21, lalu dipakai dalam perhitungan. Hasilnya, `s` bernilai 41 dan `r` bernilai 21. Kedua nilai tersebut kemudian ditampilkan ke layar dengan `cout`.

Output : ![[3.png]]
## 5. Unguided
### 5.1 Unguided 1
```cpp
#include <iostream>

  

using namespace std;

  

  

int main(){

  

    float x, y;

  

    cin >> x >> y;

  

    cout << x + y << endl;

  

    cout << x - y << endl;

  

    cout << x * y << endl;

  

    if(y != 0)

  

        cout << x / y << endl;

  

    else

  

        cout << "Error" << endl;

  

    return 0;

  

}
```


Penjelasan : Program diatas menunjukkan cara melakukan operasi aritmatika dasar dengan dua bilangan bertipe float. Pertama, variabel **a** dan **b** dideklarasikan, lalu pengguna diminta memasukkan nilainya melalui **cin**. Setelah itu, program menampilkan hasil penjumlahan, pengurangan, serta perkalian. Untuk pembagian, digunakan kondisi **if-else** agar tidak terjadi pembagian dengan nol. Jika **b ≠ 0**, maka hasil **a/b** ditampilkan, sedangkan jika **b = 0**, program akan menampilkan pesan **"Error"**.

Output : ![[4.png]]
### 5.2 Unguided 2
```cpp
#include <iostream>

  

using namespace std;

  

  

int main(){

  

    string satuan[]={"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};

  

    string belasan[]={"sepuluh","sebelas","dua belas","tiga belas","empat belas","lima belas","enam belas","tujuh belas","delapan belas","sembilan belas"};

  

    string puluhan[]={"","", "dua puluh","tiga puluh","empat puluh","lima puluh","enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};

  

  

    int n;

  

    cin >> n;

  

    if(n<0 || n>100)

  

        cout << "error";

  

    else if(n < 10)

  

        cout << satuan[n];

  

    else if(n < 20)

  

        cout << belasan[n-10];

  

    else if(n < 100){

  

        cout << puluhan[n/10];

  

        if(n % 10 != 0)

  

            cout << " " << satuan[n%10];

  

    }else

  

        cout << "seratus";

  

  

    return 0;

  

}
```

Penjelasan : Program diatas digunakan untuk mengubah angka menjadi tulisan dalam bahasa Indonesia. Ada tiga array string yang disiapkan: **satuan** (0–9), **belasan** (10–19), dan **puluhan** (20–90). Setelah pengguna memasukkan sebuah angka `n`, program akan memeriksa kondisinya. Jika `n` kurang dari 0 atau lebih dari 100, akan muncul pesan “error”. Angka 0–9 langsung diambil dari array satuan, angka 10–19 dari array belasan, sedangkan angka 20–99 diambil dari array puluhan dengan tambahan satuan jika tidak habis dibagi 10. Khusus angka 100, program langsung menampilkan kata “seratus”.

Output : ![[5.png]]
### 5.3 Unguided 3
```cpp
#include <iostream>

using namespace std;

  

int main(){

    int n;

    cin >> n;

  

    for(int i=n; i>=1; i--){

        for(int s=0; s<n-i; s++) cout<<" ";

        for(int j=i; j>=1; j--) cout<<j<<" ";

        cout<<"* ";

        for(int j=1; j<=i; j++) cout<<j<<" ";

        cout<<endl;

    }

    for(int s=0; s<n; s++) cout<<" ";

    cout<<"*"<<endl;

  

    return 0;

}
```

Penjelasan : Program diatas berfungsi menampilkan pola segitiga simetris dengan angka dan tanda bintang (_). Pertama, pengguna diminta memasukkan sebuah bilangan bulat n sebagai tinggi segitiga. Proses utama dilakukan dengan perulangan bersarang. Perulangan luar mengatur jumlah baris dari n hingga 1. Di dalamnya, ada tiga langkah: mencetak spasi untuk menjaga kerapihan, menampilkan angka menurun dari i ke 1, mencetak simbol * di tengah, lalu melanjutkan dengan angka naik dari 1 ke i. Setelah itu, baris ditutup dengan endl. Sebagai penutup, program menambahkan satu baris terakhir berupa spasi sebanyak n dan sebuah bintang (_) di bagian bawah sebagai alas segitiga.

Output : ![[6.png]]
## 6. Kesimpulan
Dari berbagai program yang sudah dibuat, saya jadi lebih paham bagaimana dasar-dasar C++ bisa dipakai untuk menyelesaikan masalah sederhana. Mulai dari menghitung diskon, mengonversi suhu, operasi aritmatika, penggunaan increment, sampai mengubah angka jadi teks atau pola bintang, semuanya menunjukkan bahwa logika pemrograman saling berkaitan. Konsep seperti input-output, percabangan, perulangan, dan array menjadi pondasi utama dalam membangun solusi. Melalui latihan-latihan ini, saya semakin yakin bahwa menguasai dasar sangat penting sebelum masuk ke materi yang lebih rumit seperti struktur data atau algoritma. Selain itu, saya juga menyadari bahwa logika yang kreatif bisa membuat program lebih menarik dan mudah dipahami. Jadi, pembelajaran ini bukan hanya soal menulis kode, tapi juga melatih cara berpikir sistematis untuk menyelesaikan masalah.

## 7. Referensi
1. [https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/](https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/)
2. [https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html](https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html)