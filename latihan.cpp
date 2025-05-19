#include <iostream>
#include <string>
using namespace std;

class Petugas;
class Admin;

class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    void tampilkanInfo() {
        cout << "Judul: " << judul << ", Penulis: " << penulis << ", Status: " 
             << (dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    friend class Petugas;
    friend void lihatStatistik(Admin a, Buku b);
};

class Peminjam {
private:
    string nama;
    int ID;
    int totalPinjaman;

public:
    Peminjam(string n, int id) : nama(n), ID(id), totalPinjaman(0) {}

    void tampilkanInfo() {
        cout << "Nama: " << nama << ", ID: " << ID << ", Total Pinjaman: " << totalPinjaman << endl;
    }

    friend class Petugas;
    friend void lihatStatistik(Admin a, Peminjam p);
};

class Petugas {
private:
    string nama;
    int IDPetugas;
    string levelAkses;

public:
    Petugas(string n, int id, string akses) : nama(n), IDPetugas(id), levelAkses(akses) {}

    void prosesPinjam(Buku &b, Peminjam &p) {
        if (!b.dipinjam) {
            b.dipinjam = true;
            p.totalPinjaman++;
            cout << "Buku dipinjam oleh: " << p.nama << endl;
        } else {
            cout << "Buku sedang dipinjam." << endl;
        }
    }

    void prosesKembali(Buku &b, Peminjam &p) {
        if (b.dipinjam) {
            b.dipinjam = false;
            p.totalPinjaman--;
            cout << "Buku dikembalikan oleh: " << p.nama << endl;
        } else {
            cout << "Buku tidak sedang dipinjam." << endl;
        }
    }

    friend class Admin;
};

class Admin {
public:
    void ubahLevelAkses(Petugas &p, string levelBaru) {
        p.levelAkses = levelBaru;
        cout << "Level akses petugas diubah menjadi: " << levelBaru << endl;
    }

    friend void lihatStatistik(Admin a, Buku b);
    friend void lihatStatistik(Admin a, Peminjam p);
};

// Fungsi friend terbatas untuk Admin
void lihatStatistik(Admin a, Buku b) {
    cout << "[Statistik Buku] Status: " << (b.dipinjam ? "Dipinjam" : "Tersedia") << endl;
}

void lihatStatistik(Admin a, Peminjam p) {
    cout << "[Statistik Peminjam] Total buku dipinjam: " << p.totalPinjaman << endl;
}

// --- Program utama untuk uji coba ---
int main() {
    Buku buku1("Pemrograman C++", "Budi");
    Peminjam peminjam1("Andi", 101);
    Petugas petugas1("Siti", 201, "normal");
    Admin admin1;

    buku1.tampilkanInfo();
    peminjam1.tampilkanInfo();

    petugas1.prosesPinjam(buku1, peminjam1);
    admin1.ubahLevelAkses(petugas1, "admin");

    lihatStatistik(admin1, buku1);
    lihatStatistik(admin1, peminjam1);

    petugas1.prosesKembali(buku1, peminjam1);

    return 0;
}
