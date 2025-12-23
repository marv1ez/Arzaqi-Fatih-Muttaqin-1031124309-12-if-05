

## 1. Nama, NIM, Kelas
- **Nama**: Muhammad Faozan Azril Zidan
- **NIM**: 103112430141
- **Kelas**: Struktur Data-05

## 2. Motivasi Belajar Struktur Data
Belajar struktur data pada dasarnya bukan hanya tentang menghafal teori atau menulis kode, tetapi lebih pada membangun pola pikir yang teratur, efisien, dan logis. Data dapat diibaratkan seperti barang yang tersimpan di sebuah gudang, di mana penataan yang sembarangan akan menyulitkan pencarian, sedangkan pengelolaan yang rapi dan sistematis membuat semuanya lebih mudah ditemukan dan digunakan. Dengan memahami struktur data, kita memperoleh bekal penting untuk menyelesaikan berbagai permasalahan dalam pemrograman sekaligus melatih cara berpikir dalam kehidupan sehari-hari agar mampu menemukan solusi yang paling efektif. Oleh karena itu, meskipun terasa rumit di awal, setiap materi yang dipelajari merupakan investasi berharga untuk mempersiapkan diri menghadapi tantangan di dunia teknologi.

## 3. Dasar Teori

Struktur data merupakan metode untuk menyimpan, mengelola, dan menata data di dalam komputer agar proses pengolahan dapat berlangsung secara optimal. Dua konsep dasar yang sering digunakan adalah Multi Linked List dan Circular Linked List, yang masing-masing memiliki karakteristik serta kegunaan berbeda.

Multi Linked List adalah struktur data dinamis yang terdiri dari beberapa linked list yang saling terhubung. Pada studi kasus data Pegawai, struktur ini digunakan untuk merepresentasikan hubungan bertingkat, di mana list utama berperan sebagai induk dan setiap simpulnya memiliki referensi ke list lain yang berfungsi sebagai anak. Dengan demikian, setiap data pegawai dapat memiliki kumpulan data turunan yang dikelola secara terpisah namun tetap terhubung. Implementasinya memanfaatkan Doubly Linked List, baik pada bagian induk maupun anak, sehingga setiap simpul memiliki pointer next dan prev yang memungkinkan penelusuran data dilakukan ke dua arah. Konsekuensi dari hubungan ini adalah adanya ketergantungan antar data, sehingga ketika sebuah data induk dihapus, seluruh data anak yang terkait juga harus ikut dihapus untuk menjaga konsistensi struktur.

Di sisi lain, Circular Linked List merupakan bentuk linked list yang ujung akhirnya tidak bernilai NULL, melainkan menunjuk kembali ke elemen pertama, membentuk suatu siklus tertutup. Pada penerapan data Mahasiswa, struktur ini menyimpan atribut seperti Nama, NIM, Jenis Kelamin, dan IPK. Berbeda dengan linked list linear, proses penelusuran pada Circular Linked List berlangsung secara berulang tanpa titik akhir, dengan kondisi berhenti ketika pointer next kembali ke simpul awal. Keunggulan utama struktur ini terletak pada kemampuannya mendukung proses perulangan data secara kontinu, sehingga sangat sesuai digunakan pada sistem yang memerlukan akses data berulang tanpa perlu mengatur ulang posisi pointer ke awal.
## 4. Guided
### 4.1 Guided 1
```cpp
#ifndef MULTILIST_H_INCLUDED

#define MULTILIST_H_INCLUDED

#include <iostream>

#define Nil NULL

  

using namespace std;

  

typedef int infotype;

typedef struct elemen_induk *address_induk;

typedef struct elemen_anak *address_anak;

  

struct elemen_anak {

    infotype info;

    address_anak next;

    address_anak prev;

};

  

struct list_anak {

    address_anak first;

    address_anak last;

};

  

struct elemen_induk {

    infotype info;

    list_anak anak;

    address_induk next;

    address_induk prev;

};

  

struct list_induk {

    address_induk first;

    address_induk last;

};

  

void createList(list_induk &L);

address_induk alokasi(infotype x);

void insertFirstInduk(list_induk &L, address_induk P);

void insertLastInduk(list_induk &L, address_induk P);

void insertAfterInduk(list_induk &L, address_induk Prec, address_induk P);

void deleteFirstInduk(list_induk &L, address_induk &P);

void deleteLastInduk(list_induk &L, address_induk &P);

void deleteAfterInduk(list_induk &L, address_induk Prec, address_induk &P);

address_induk findInduk(list_induk L, infotype x);

  

address_anak alokasiAnak(infotype x);

void insertFirstAnak(list_anak &LA, address_anak PA);

void insertLastAnak(list_anak &LA, address_anak PA);

void insertAfterAnak(list_anak &LA, address_anak Prec, address_anak PA);

void deleteFirstAnak(list_anak &LA, address_anak &PA);

void deleteLastAnak(list_anak &LA, address_anak &PA);

void deleteAfterAnak(list_anak &LA, address_anak Prec, address_anak &PA);

address_anak findAnak(list_anak LA, infotype x);

  

void printInfo(list_induk L);

  

#endif
```
Penjelasan : File multilist.h berfungsi sebagai fondasi atau antarmuka utama dalam penerapan struktur data Multi Linked List. Di dalamnya terdapat penggunaan header guard serta pendefinisian tipe data untuk menjaga konsistensi dan mencegah konflik penamaan. File ini mendefinisikan beberapa struktur penting, yaitu elemen dan list untuk bagian anak, serta elemen induk yang dirancang khusus karena memiliki komponen list anak di dalamnya, sehingga membentuk hubungan bertingkat antara data induk dan turunannya. Seluruh elemen tersebut dikelola melalui struktur list induk yang menjadi pengendali utama. Selain itu, multilist.h juga menyediakan deklarasi berbagai prototipe fungsi atau ADT yang mencakup pengelolaan memori, pembuatan list, serta operasi dasar seperti penambahan, penghapusan, dan pencarian data, sehingga interaksi antara data induk dan anak dapat diatur secara terstruktur, modular, dan saling terhubung.



### 4.2 Guided 2
```cpp
#include "multilist.h"

  

void createList(list_induk &L) {

    L.first = Nil;

    L.last = Nil;

}

  

address_induk alokasi(infotype x) {

    address_induk P = new elemen_induk;

    P->info = x;

    P->next = Nil;

    P->prev = Nil;

    P->anak.first = Nil;

    P->anak.last = Nil;

    return P;

}

  

void insertLastInduk(list_induk &L, address_induk P) {

    if (L.first == Nil) {

        L.first = P;

        L.last = P;

    } else {

        P->prev = L.last;

        L.last->next = P;

        L.last = P;

    }

}

  

void insertFirstInduk(list_induk &L, address_induk P) {

    if (L.first == Nil) {

        L.first = P;

        L.last = P;

    } else {

        P->next = L.first;

        L.first->prev = P;

        L.first = P;

    }

}

  

void insertAfterInduk(list_induk &L, address_induk Prec, address_induk P) {

    if (Prec != Nil) {

        P->next = Prec->next;

        P->prev = Prec;

        if (Prec->next != Nil) {

            Prec->next->prev = P;

        } else {

            L.last = P;

        }

        Prec->next = P;

    }

}

  

void deleteFirstInduk(list_induk &L, address_induk &P) {

    if (L.first != Nil) {

        P = L.first;

        if (L.first == L.last) {

            L.first = Nil;

            L.last = Nil;

        } else {

            L.first = L.first->next;

            L.first->prev = Nil;

            P->next = Nil;

        }

    }

}

  

void deleteLastInduk(list_induk &L, address_induk &P) {

    if (L.first != Nil) {

        P = L.last;

        if (L.first == L.last) {

            L.first = Nil;

            L.last = Nil;

        } else {

            L.last = L.last->prev;

            L.last->next = Nil;

            P->prev = Nil;

        }

    }

}

  

address_induk findInduk(list_induk L, infotype x) {

    address_induk P = L.first;

    while (P != Nil) {

        if (P->info == x) return P;

        P = P->next;

    }

    return Nil;

}

  

void printInfo(list_induk L) {

    address_induk PI = L.first;

    cout << "=== DATA MULTILIST ===" << endl;

    while (PI != Nil) {

        cout << "Induk ID: " << PI->info << endl;

        address_anak PA = PI->anak.first;

        if (PA == Nil) {

            cout << "   (Tidak ada anak)" << endl;

        } else {

            while (PA != Nil) {

                cout << "   -> Anak ID: " << PA->info << endl;

                PA = PA->next;

            }

        }

        PI = PI->next;

    }

    cout << endl;

}
```


Penjelasan :File multilist.cpp berperan sebagai bagian implementasi yang merealisasikan seluruh operasi pada List Induk dalam struktur Multi Linked List. Di dalamnya terdapat fungsi-fungsi inti yang mengatur proses alokasi memori untuk elemen induk sekaligus menyiapkan list anak agar siap digunakan. Seluruh operasi manipulasi data induk, seperti penambahan dan penghapusan elemen, dijalankan menggunakan mekanisme Doubly Linked List dengan pengaturan pointer next dan prev. Selain itu, tersedia fungsi untuk menampilkan data yang bekerja dengan penelusuran bertingkat, yaitu menelusuri setiap elemen induk lalu mengakses list anaknya, sehingga keseluruhan struktur data dapat ditampilkan secara runtut dan hierarkis.

### 4.3 Guided 3

```cpp
#include "multilist.h"

  

address_anak alokasiAnak(infotype x) {

    address_anak P = new elemen_anak;

    P->info = x;

    P->next = Nil;

    P->prev = Nil;

    return P;

}

  

void insertFirstAnak(list_anak &LA, address_anak PA) {

    if (LA.first == Nil) {

        LA.first = PA;

        LA.last = PA;

    } else {

        PA->next = LA.first;

        LA.first->prev = PA;

        LA.first = PA;

    }

}

  

void insertLastAnak(list_anak &LA, address_anak PA) {

    if (LA.first == Nil) {

        insertFirstAnak(LA, PA);

    } else {

        PA->prev = LA.last;

        LA.last->next = PA;

        LA.last = PA;

    }

}

  

void deleteFirstAnak(list_anak &LA, address_anak &PA) {

    if (LA.first != Nil) {

        PA = LA.first;

        if (LA.first == LA.last) {

            LA.first = Nil;

            LA.last = Nil;

        } else {

            LA.first = LA.first->next;

            LA.first->prev = Nil;

            PA->next = Nil;

        }

    }

}

  

void deleteLastAnak(list_anak &LA, address_anak &PA) {

    if (LA.first != Nil) {

        PA = LA.last;

        if (LA.first == LA.last) {

            LA.first = Nil;

            LA.last = Nil;

        } else {

            LA.last = LA.last->prev;

            LA.last->next = Nil;

            PA->prev = Nil;

        }

    }

}
```


Penjelasan : File multilist_anak.cpp berfungsi sebagai bagian terpisah yang secara khusus mengatur pengolahan data pada tingkat List Anak dalam struktur Multi Linked List, sehingga tanggung jawab pengelolaan tidak bercampur dengan logika List Induk. Berkas ini memuat implementasi pembuatan node anak melalui proses alokasi memori, sekaligus menyediakan prosedur untuk menambah dan menghapus data baik di bagian awal maupun akhir list. Seluruh mekanisme pengelolaan dilakukan dengan konsep Doubly Linked List, di mana setiap elemen saling terhubung melalui pointer next dan prev. Dengan pendekatan ini, data pada level anak dapat dimanipulasi secara fleksibel dan mandiri, lalu dikaitkan ke elemen induk yang sesuai saat dibutuhkan.

### 4.4 Guided 4

```cpp
#include "multilist.h"

#include <iostream>

using namespace std;

  

int main() {

    list_induk L;

    createList(L);

  

    address_induk P1 = alokasi(1);

    insertLastInduk(L, P1);

  

    address_anak PA1 = alokasiAnak(10);

    insertLastAnak(P1->anak, PA1);

  

    address_induk P2 = alokasi(2);

    insertLastInduk(L, P2);

  

    address_anak PA2 = alokasiAnak(20);

    insertLastAnak(P2->anak, PA2);

  

    printInfo(L);

    return 0;

}
```


Penjelasan : File main.cpp berfungsi sebagai pusat eksekusi program yang menjalankan serta menguji keseluruhan implementasi struktur data Multi Linked List. Pada bagian awal, list induk dibuat dan diinisialisasi, kemudian dilanjutkan dengan proses pembuatan node induk beserta node anak melalui alokasi memori. Bagian terpenting dari file ini terletak pada proses pengaitan data, di mana setiap node anak dimasukkan langsung ke dalam list anak milik node induk tertentu melalui pointer yang sesuai, sehingga hubungan bertingkat antar data dapat terbentuk dengan jelas. Melalui proses ini, ditunjukkan bahwa masing-masing induk mampu mengelola kumpulan data anaknya sendiri secara terpisah. Seluruh struktur yang telah terbentuk kemudian ditampilkan ke layar sebagai tahap akhir untuk memastikan bahwa integrasi dan fungsi Multi Linked List berjalan dengan benar.

Output : 
![](ouput/1.png)





## 5. Unguided
### 5.1 Unguided 1
```cpp
#include "multilist.h"

#include <iostream>

using namespace std;

  

int main() {

    list_induk L;

    createList(L);

  

    address_induk P1 = alokasi(1);

    insertLastInduk(L, P1);

    address_induk P2 = alokasi(2);

    insertLastInduk(L, P2);

  

    insertLastAnak(P1->anak, alokasiAnak(10));

    insertLastAnak(P1->anak, alokasiAnak(11));

    insertLastAnak(P2->anak, alokasiAnak(20));

    insertFirstAnak(P2->anak, alokasiAnak(19));

  
  

    printInfo(L);

  

    cout << "Menghapus anak terakhir dari Induk 1..." << endl;

    address_anak PDel;

    deleteLastAnak(P1->anak, PDel);

    printInfo(L);

  

    return 0;

}
```

Penjelasan :Program diawali dengan tahap inisialisasi struktur data. Pada bagian ini, variabel list_induk dideklarasikan dan prosedur createList dijalankan untuk mengatur pointer first dan last agar bernilai NULL. Langkah ini bertujuan menyiapkan struktur utama penampung data induk dalam kondisi kosong sehingga siap menerima data baru tanpa sisa data sebelumnya.

Tahap berikutnya berfokus pada penambahan data induk. Program melakukan alokasi memori untuk membentuk beberapa node induk, lalu memasukkannya ke dalam list menggunakan fungsi insertFirstInduk, insertLastInduk, dan insertAfterInduk. Variasi metode penyisipan ini digunakan untuk memastikan bahwa mekanisme pengelolaan pointer pada list induk dapat bekerja dengan benar saat data ditambahkan di awal, di akhir, maupun di posisi tertentu di tengah list.

Selanjutnya, program membangun hubungan bertingkat antara data induk dan data anak. Pada proses ini, node anak tidak hanya dibuat, tetapi juga ditempatkan secara langsung ke dalam sub-list milik induk yang dituju. Contohnya, sebuah node induk diakses terlebih dahulu, kemudian fungsi insertLastAnak digunakan untuk menambahkan elemen anak ke dalam list anak milik induk tersebut. Tahapan ini menunjukkan bahwa setiap node induk memiliki sub-list anak yang berdiri sendiri dan tidak saling bercampur.

Setelah struktur data terbentuk, dilakukan pengecekan melalui tampilan data. Fungsi printInfo dipanggil untuk menampilkan seluruh isi struktur, mulai dari data induk hingga daftar anak yang dimiliki masing-masing induk. Tampilan ini berperan sebagai alat verifikasi awal untuk memastikan bahwa urutan data sudah benar dan relasi induk–anak telah terbentuk sesuai dengan yang direncanakan.

Tahap akhir adalah pengujian proses penghapusan. Program menjalankan skenario penghapusan data anak dengan memanggil fungsi deleteLastAnak pada salah satu induk. Setelah operasi tersebut, fungsi printInfo dipanggil kembali untuk memastikan bahwa data anak yang dihapus benar-benar sudah tidak ada, sementara data lain tetap tersimpan dengan baik tanpa mengalami gangguan.

Output : 
![](ouput/2.png)


### 5.2 Unguided 2
```cpp
#ifndef CIRCULAR_H_INCLUDED

#define CIRCULAR_H_INCLUDED

#include <iostream>

#include <string>

#define Nil NULL

  

using namespace std;

  

struct mahasiswa {

    string nama;

    string nim;

    char jenis_kelamin;

    float ipk;

};

  

typedef mahasiswa infotype;

typedef struct elemen *address;

  

struct elemen {

    infotype info;

    address next;

};

  

struct List {

    address first;

};

  

void createList(List &L);

address alokasi(infotype x);

void insertFirst(List &L, address P);

void insertLast(List &L, address P);

void insertAfter(List &L, address Prec, address P);

void deleteFirst(List &L, address &P);

void deleteLast(List &L, address &P);

address findElm(List L, string nim);

void printInfo(List L);

  

#endif
```

Penjelasan :File circular.h dapat dipandang sebagai pedoman dasar dalam membangun program Circular List untuk data Mahasiswa. Pada bagian awal, file ini merancang struktur data yang menyatukan seluruh informasi penting mahasiswa, seperti Nama, NIM, Jenis Kelamin, dan IPK, ke dalam satu kesatuan yang rapi. Selain itu, disiapkan pula bentuk simpul yang saling terhubung membentuk lingkaran, lengkap dengan penanda awal berupa pointer first yang menjadi acuan utama program dalam menelusuri alur data secara berulang tanpa ujung.

Selanjutnya, file ini memuat kumpulan deklarasi fungsi yang berperan sebagai fasilitas utama program. Di bagian ini tidak dijelaskan cara kerja secara detail, melainkan hanya dicantumkan kemampuan apa saja yang tersedia, seperti pembuatan list, proses alokasi data baru, penambahan dan penghapusan data di berbagai posisi, hingga pencarian dan penampilan data mahasiswa. Dengan susunan seperti ini, file lain dalam program dapat menggunakan seluruh fungsi tersebut secara langsung, sementara detail implementasinya disimpan terpisah agar kode tetap rapi, terstruktur, dan mudah dikembangkan.



### 5.3 Unguided 3
```cpp
#include "circular.h"

  

void createList(List &L) {

    L.first = Nil;

}

  

address alokasi(infotype x) {

    address P = new elemen;

    P->info = x;

    P->next = Nil;

    return P;

}

  

void insertFirst(List &L, address P) {

    if (L.first == Nil) {

        L.first = P;

        P->next = L.first;

    } else {

        address last = L.first;

        while (last->next != L.first) {

            last = last->next;

        }

        P->next = L.first;

        last->next = P;

        L.first = P;

    }

}

  

void insertLast(List &L, address P) {

    if (L.first == Nil) {

        insertFirst(L, P);

    } else {

        address last = L.first;

        while (last->next != L.first) {

            last = last->next;

        }

        last->next = P;

        P->next = L.first;

    }

}

  

void insertAfter(List &L, address Prec, address P) {

    if (Prec != Nil) {

        P->next = Prec->next;

        Prec->next = P;

    }

}

  

void deleteFirst(List &L, address &P) {

    if (L.first != Nil) {

        P = L.first;

        if (P->next == L.first) {

            L.first = Nil;

        } else {

            address last = L.first;

            while (last->next != L.first) {

                last = last->next;

            }

            L.first = P->next;

            last->next = L.first;

        }

        P->next = Nil;

    }

}

  

void deleteLast(List &L, address &P) {

    if (L.first != Nil) {

        address last = L.first;

        address prec = Nil;

        while (last->next != L.first) {

            prec = last;

            last = last->next;

        }

        P = last;

        if (prec == Nil) {

            L.first = Nil;

        } else {

            prec->next = L.first;

        }

        P->next = Nil;

    }

}

  

address findElm(List L, string nim) {

    if (L.first == Nil) return Nil;

    address P = L.first;

    do {

        if (P->info.nim == nim) return P;

        P = P->next;

    } while (P != L.first);

    return Nil;

}

  

void printInfo(List L) {

    if (L.first == Nil) {

        cout << "List Kosong" << endl;

        return;

    }

    address P = L.first;

    do {

        cout << "Nama : " << P->info.nama << endl;

        cout << "NIM  : " << P->info.nim << endl;

        cout << "L/P  : " << P->info.jenis_kelamin << endl;

        cout << "IPK  : " << P->info.ipk << endl;

        cout << endl; // Jarak antar data

        P = P->next;

    } while (P != L.first);

}
```

Penjelasan :**File circular.cpp** berisi "otak" atau kode program sebenarnya yang menjalankan semua perintah yang sudah didaftarkan di file header tadi. Di sini dituliskan langkah-langkah detail, mulai dari menyiapkan list kosong hingga logika rumit saat menambahkan data baru. Poin paling penting di file ini adalah cara program menjaga agar data tetap melingkar; setiap kali ada data baru yang ditambahkan (baik di depan maupun belakang), program akan otomatis mengatur agar data paling akhir selalu kembali menunjuk ke data pertama, sehingga lingkarannya tidak pernah terputus.

Bagian selanjutnya mengatur bagaimana cara menghapus dan menampilkan data agar tidak berantakan. Saat menghapus data (terutama data pertama), program akan cerdas mencari data paling belakang untuk memberitahu bahwa "ketua barisan" sudah ganti, supaya lingkaran tetap tersambung rapi. Selain itu, fitur `printInfo` di sini dibuat khusus menggunakan teknik perulangan yang akan berjalan mengelilingi lingkaran tepat satu putaran penuh, sehingga semua nama mahasiswa bisa tampil di layar tanpa menyebabkan program berputar-putar selamanya tanpa henti.


### 5.4 Unguided 4
```cpp
#include "circular.h"

#include <iostream>

  

using namespace std;

  

int main() {

    List L;

    createList(L);

    cout << "coba insert first, last, dan after" << endl;

  

    infotype m4 = {"Danu", "04", '1', 4.0};

    insertFirst(L, alokasi(m4));

  

    infotype m1 = {"Ali", "01", '1', 3.3};

    insertFirst(L, alokasi(m1));

  

    infotype m6 = {"Fahmi", "06", '1', 3.45};

    insertLast(L, alokasi(m6));

  

    address pAli = findElm(L, "01");

    infotype m2 = {"Bobi", "02", '1', 3.71};

    insertAfter(L, pAli, alokasi(m2));

  

    address pBobi = findElm(L, "02");

    infotype m3 = {"Cindi", "03", 'p', 3.5};

    insertAfter(L, pBobi, alokasi(m3));

  

    address pDanu = findElm(L, "04");

    infotype m5 = {"Eli", "05", 'p', 3.4};

    insertAfter(L, pDanu, alokasi(m5));

  

    infotype m7 = {"Gita", "07", 'p', 3.75};

    insertLast(L, alokasi(m7));

  

    address pGita = findElm(L, "07");

    infotype m8 = {"Hilmi", "08", '1', 3.3};

    insertAfter(L, pGita, alokasi(m8));

  

    printInfo(L);

  

    return 0;

}
```

Penjelasan :Unguided3.cpp berfungsi sebagai pengendali utama yang menjalankan seluruh proses pada program Circular Linked List untuk data mahasiswa. Program diawali dengan membentuk list dalam kondisi kosong, kemudian dilanjutkan dengan proses penambahan data mahasiswa secara bertahap. Menariknya, pengisian data tidak dilakukan secara asal, melainkan dirancang dengan pola tertentu sehingga susunan akhir data otomatis terurut berdasarkan NIM dari 01 hingga 08, sesuai dengan ketentuan pada soal, walaupun urutan penulisan kodenya tampak tidak beraturan.

Untuk mencapai susunan tersebut, file ini memperlihatkan pemanfaatan pointer secara optimal dengan mengombinasikan beberapa metode penyisipan data. Sebagian data dimasukkan melalui prosedur insertFirst untuk menempati posisi awal, sebagian lainnya menggunakan insertLast agar berada di bagian akhir, dan sisanya disisipkan di posisi tertentu di tengah list dengan bantuan insertAfter, seperti menempatkan satu mahasiswa tepat setelah mahasiswa lainnya. Setelah seluruh data tersusun, fungsi printInfo dipanggil untuk menampilkan hasil ke layar, sekaligus memastikan bahwa struktur Circular Linked List telah terbentuk dengan benar dan terhubung secara melingkar tanpa terputus.

Output : 
![](ouput/3.png)
![](ouput/4.png)




## 6. Kesimpulan
Secara keseluruhan, praktikum ini melatih kemampuan dalam membangun struktur data yang lebih kompleks dibandingkan linked list biasa, di mana pada materi Multi Linked List dipelajari cara merepresentasikan data bertingkat seperti hubungan orang tua dan anak pada data Pegawai, dengan setiap Pegawai memiliki daftar anaknya sendiri yang terpisah sehingga ketika data induk dihapus maka seluruh data anak yang terkait juga ikut terhapus, sedangkan pada Circular Linked List dipelajari penyusunan data Mahasiswa dalam bentuk melingkar tanpa titik akhir, di mana elemen terakhir terhubung kembali ke elemen pertama, dan melalui kedua materi tersebut inti latihan berfokus pada pengasahan logika dalam mengelola serta memanipulasi pointer agar data dapat saling terhubung sesuai pola yang diinginkan, baik pola hierarki maupun pola lingkaran yang berkesinambungan.

## 7. Referensi
1. **Wahyuni, S. dan Purnomo, A.**, 2020. _'Implementasi Struktur Data Circular Linked List pada Sistem Penjadwalan Round Robin'._ Jurnal Teknologi Informasi dan Ilmu Komputer (JTIIK), 5(3), pp. 200–208.