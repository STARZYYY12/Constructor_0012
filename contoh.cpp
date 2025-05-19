#include <iostream>
using namespace std;

class mahasiswa{
    private:
        static int jumlahMhs;
    public:
        string nama;

        mahasiswa(string pNama){
            nama=pNama;
            ++jumlahMhs;
            cout << "mahasiwa dibuat" << nama << endl;
        }
        ~mahasiswa(){
            cout << "jumlah mahasiswa" << jumlahMhs << endl;
        }
        static void setjumlah(int pJumlah){
            jumlahMhs = pJumlah;
        }
        static int getjumlahMhs(){
            return jumlahMhs;
        }

};

int mahasiswa::jumlahMhs = 0;

int main(){
    cout << "jumlah mahasiswa:;" << mahasiswa::getjumlahMhs << endl;

    mahasiswa mhs1("Andi");
    mahasiswa mhs2("Lulu");
    cout << "jumlah mahsiswa: " << mahasiswa::getjumlahMhs() << endl;
    mahasiswa::setjumlah(5);
    
    {
        mahasiswa mhs3("Husna");
        cout << "jumlah mahsiswa: " << mahasiswa::getjumlahMhs << endl;
    }

    cout << "jumlah mahasiwa: " << mahasiswa::getjumlahMhs << endl;
    return 0;
}