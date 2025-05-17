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

