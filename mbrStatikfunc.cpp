#include <iostream>
#include <string>
using namespace std;

class mahasiswa{
    private:
        static int nim;
    public:
        int id;
        string nama;

        void setId();
        void printAll();

        static void setNim(int pNim){nim=pNim; /*Definisi Function*/}
        static int getNim(){return nim;}

        mahasiswa(string pnama):nama(pnama){setId();}

    
};
