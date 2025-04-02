#ifndef CAUHOITN_H
#define CAUHOITN_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CauhoiTN 
{
    private:
        string noidung;
        string daA;
        string daB;
        char dapan;
    
    public:
        //ham nhap tu ban phim
        void nhap();

        //xuat cau hoi va dap an dung
        void xuat() const;

        //doc cau hoi tu file
        void docfile(ifstream &f);

        //ghi cau hoi vao file
        void ghifile(ofstream &f) const;

        //kiem tra cau tra loi
        bool kiemtra(char traloi) const;

        //chuan hoa noi dung cau hoi va dap an
        void chuanhoa();

        //kiem tra hai cau hoi co giong nhau khong
        friend bool giongnhau(const CauhoiTN &cau1, const CauhoiTN &cau2);
};

#endif 