#include <iostream>
#include <stdexcept>
using namespace std;


/**
* Melakukan pencarian NIM menggunakan algoritma Sequential Search.
*
* Pencarian dilakukan dengan membandingkan NIM target terhadap
* setiap elemen array mulai dari indeks pertama.
*
* @param arr Array yang berisi daftar NIM mahasiswa yang hadir.
* @param n Jumlah elemen dalam array
* @param target NIM mahasiswa yang ingin dicari
* @return Indeks array jika NIM ditemukan, atau -1 jika tidak ditemukan.
* @throws invalid_argument Jika NIM yang dimasukkan kurang dari atau sama dengan nol
*/
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


/**
* Program menyimpan daftar NIM mahasiswa, menerima input NIM
* dari pengguna, kemudian memanggil fungsi search() untuk
* memeriksa keberadaan NIM dalam daftar hadir
*
* Hasil pencarian akan menampilkan indeks dan urutan kedatangan
* jika NIM ditemukan. Jika tidak ditemukan, program menampilkan
* pesan bahwa NIM tidak ada di daftar hadir
*/
int main() {
   /**
    * Array untuk menyimpan daftar NIM mahasiswa yang hadir
    */
   int hadir[] = {578857, 585479, 579462,
                  578837, 581203, 577914};


   /**
    * Menghitung jumlah elemen array
    */
   int n = sizeof(hadir) / sizeof(hadir[0]);


   /**
    * Variabel untuk menyimpan NIM yang dimasukkan pengguna
    */
   int nim;


   try {
       cout << "Masukkan NIM: ";


       /**
        * Memeriksa apakah input berhasil dibaca sebagai int
        * Jika salah, program akan melemparkan exception
        */
       if (!(cin >> nim))
           throw invalid_argument("input salah");


       /**
        * Memanggil fungsi search() untuk mencari NIM
        * dalam array hadir
        */
       int posisi = search(hadir, n, nim);


       /**
        * Menampilkan hasil pencarian berdasarkan nilai posisi
        */
       if (posisi == -1)
           cout << "Tidak ada di daftar hadir" << endl;
       else
           cout << "Ditemukan di indeks " << posisi
                << " (kedatangan ke-" << posisi + 1
                << ")" << endl;


   /**
    * Menangkap dan menampilkan pesan kesalahan
    * jika terjadi invalid_argument
    */
   } catch (const invalid_argument& e) {
       cout << "Error: " << e.what() << endl;
       return 1;
   }


   return 0;
}
