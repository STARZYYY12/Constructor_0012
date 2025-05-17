#include <iostream>
using namespace std;

class angka {
private:
    int *arr;
    int panjang;
public:
    angka(int);  
    ~angka();    
    void cetakData();
    void isiData();
};

angka::angka(int i) { 
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::~angka() {  
    cout << endl;
    cetakData();
    delete[] arr;
    cout << "Alamat Array Sudah Dilepaskan" << endl;
