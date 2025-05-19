#include <iostream>
using namespace std;

    class Mahasiswa {
        private:
            static int jumlahMhs;
        public:
            string nama;
            Mahasiswa(string pNama) {
                nama = pNama;
                ++jumlahMhs;
                cout << "Mahasiswa dibuat" << nama << endl;
            }
            ~Mahasiswa(){
                cout << "Destuctor terpanggil" << endl;
            }
            static int getJumlahMhs(){
                return jumlahMhs;
            }
    };

            int Mahasiswa::jumlahMhs = 0;
 
        int main () {

            cout << "Jumlah Mahasiswa:" << Mahasiswa::jumlahMhs << endl;
            
            Mahasiswa mhs1("Nafis");
            Mahasiswa mhs1("Donan");
            Mahasiswa mhs1("Upi");

            cout <<   


        }
