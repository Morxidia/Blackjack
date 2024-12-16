#include <iostream>

using namespace std;

int Nilai[10];

void Tampil(int Maxnilai, int BanyakSiswa);

main()
{
    int Maxnilai=0,BanyakSiswa=0,i;
    for(i=0;i<10;i++)
    {
        cout << "Nilai SIswa - " << i+1 << " : ";
        cin >> Nilai[i];
        if(Maxnilai < Nilai[i]) Maxnilai=Nilai[i];
    }
    for (i=0;i<10;i++) if(Maxnilai == Nilai[i]) BanyakSiswa ++;
    Tampil(Maxnilai,BanyakSiswa);
}

void Tampil(int Maxnilai, int BanyakSiswa)
{
    system("cls");
    cout << "Nilai Yang di input :" << endl;
    for(int i=0;i<10;i++) cout << Nilai[i] << "  ";
    cout << endl;
    cout << "Nilai Tertinggi : " << Maxnilai << endl;
    cout << "Banyak Siswa yang memiliki nilai tertinggi : " << BanyakSiswa << endl;
}