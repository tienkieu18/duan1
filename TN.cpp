#include "CauhoiTN.h"
using namespace std; 

//ham chuan hoa chuoi
void trim(string &s)
{
    s.erase(0, s.find_first_not_of(" \t\r\n"));
    s.erase(s.find_last_not_of(" \t\r\n") + 1);
}

//nhap cau hoi tu ban phim
void CauhoiTN::nhap()
{
    cin.ignore();
    cout << "Nhap noi dung cau hoi: ";
    getline(cin, noidung);
    cout << "Nhap dap an A: ";
    getline(cin, daA);
    cout << "Nhap dap an B: ";
    getline(cin, daB);
    do
    {
        cout << "Nhap dap an dung (A/B): ";
        cin >> dapan;
        dapan = toupper(dapan);
    } while (dapan != 'A' && dapan != 'B');
}

//xuat cau hoi va dap an dung 
void CauhoiTN::xuat() const 
{
    cout << "Cau hoi: " << noidung << endl;
    cout << "A. " << daA << endl;
    cout << "B. " << daB << endl;
    cout << "Dap an dung: " << dapan << endl;
}

//doc cau hoi tu file 
void CauhoiTN::docfile(ifstream &f) 
{
    getline(f, noidung);
    getline(f, daA);
    getline(f, daB);
    f >> dapan;
    f.ignore();
}

//ghi cau hoi vao file
void CauhoiTN::ghifile(ofstream &f) const 
{
    f << noidung << endl;
    f << daA << endl;
    f << daB << endl;
    f << dapan << endl;
    f << "---" << endl;
}

//kiem tra dap an 
bool CauhoiTN::kiemtra(char traloi) const 
{
    return toupper(traloi) == dapan;
}

//chuan hoa noi dung cau hoi
void CauhoiTN::chuanhoa() 
{
    trim(noidung);
    trim(daA);
    trim(daB);
}

//kiem tra hai cau hoi co giong nhau khong
bool giongnhau(const CauhoiTN &cau1, const CauhoiTN &cau2) 
{
    return cau1.noidung == cau2.noidung;
}