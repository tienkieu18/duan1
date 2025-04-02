#include "CauhoiTN.h"

int main() 
{
    cout << "075206004927 - Kieu Minh Tien" << endl;
    int choice;
    string filename = "dethi.TTN";
    do 
    {
        cout << "\n1. Tao de thi";
        cout << "\n2. Cho thi";
        cout << "\n3. Chuan hoa file";
        cout << "\n4. Thoat";
        cout << "\nLua chon: ";
        cin >> choice;
        switch (choice) 
        {
            case 1: 
            {
                ofstream f(filename);
                int n;
                cout << "Nhap so luong cau hoi: ";
                cin >> n;
                vector<CauhoiTN> dsCauhoi;
                for (int i = 0; i < n; i++) 
                {
                    CauhoiTN ch;
                    cout << "Nhap cau hoi thu " << i + 1 << ":\n";
                    ch.nhap();
                    dsCauhoi.push_back(ch);
                }
                for (const auto &ch : dsCauhoi) 
                {
                    ch.ghifile(f);
                }
                f.close();
                break;
            }
            case 2: 
            {
                ifstream f(filename);
                if (!f) {
                    cout << "Khong the mo file!" << endl;
                    break;
                }
                int diem = 0, tong = 0;
                CauhoiTN ch;
                while (f.peek() != EOF) 
                { // Kiểm tra còn dữ liệu không
                    ch.docfile(f);
                    if (f.fail()) break; // Kiểm tra lỗi đọc file
                    ch.xuat(); // Hiển thị câu hỏi
                    char traloi;
                    cout << "Nhap dap an cua ban (A/B): ";
                    cin >> traloi;
                    if (ch.kiemtra(traloi)) diem++;
                    tong++;
                }
                f.close();
                cout << "Diem cua ban: " << diem << "/" << tong << endl;
                break;
            }
            case 3: 
            {
                ifstream f(filename);
                if (!f) 
                {
                    cout << "Khong the mo file!" << endl;
                    break;
                }
                vector<CauhoiTN> dsCauhoi;
                CauhoiTN ch;
                while (!f.eof()) 
                {
                    ch.docfile(f);
                    ch.chuanhoa();
                    dsCauhoi.push_back(ch);
                }
                f.close();
                ofstream out(filename);
                for (const auto &ch : dsCauhoi) 
                {
                    ch.ghifile(out);
                }
                out.close();
                cout << "Da chuan hoa file thanh cong!" << endl;
                break;
            }
            case 4:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 4);
    return 0;
}
