#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Employee
{
protected:
    string hoTen;
    int luongCoBan;
    int namKinhNghiem;

public:
    Employee(string hoTen, int luongCoBan, int namKinhNghiem)
        : hoTen(hoTen), luongCoBan(luongCoBan), namKinhNghiem(namKinhNghiem) {}

    virtual int salary_Statistics() { return luongCoBan; }
    virtual void xuatThongTin(int i)
    {
        cout << left << setw(5) << i
             << setw(25) << hoTen
             << setw(15) << salary_Statistics()
             << setw(10) << namKinhNghiem << endl;
    }

    string getHoTen() { return hoTen; }
    void setHoTen(string tenMoi) { hoTen = tenMoi; }
    void setLuongCoBan(int luong) { luongCoBan = luong; }
    void setNamKinhNghiem(int nam) { namKinhNghiem = nam; }

    virtual ~Employee() {}
};

class HR : public Employee
{
public:
    HR(string hoTen, int luongCoBan, int namKinhNghiem)
        : Employee(hoTen, luongCoBan, namKinhNghiem) {}

    int salary_Statistics() override { return luongCoBan; }
};

class it_Engineer : public Employee
{
public:
    it_Engineer(string hoTen, int luongCoBan, int namKinhNghiem)
        : Employee(hoTen, luongCoBan, namKinhNghiem) {}

    int salary_Statistics() override { return luongCoBan * 1.15; }
};

class sale_Employee : public Employee
{
private:
    int number_Of_Contract;

public:
    sale_Employee(string hoTen, int luongCoBan, int namKinhNghiem, int number_Of_Contract)
        : Employee(hoTen, luongCoBan, namKinhNghiem), number_Of_Contract(number_Of_Contract) {}

    int salary_Statistics() override
    {
        return luongCoBan + ((float)number_Of_Contract / 100) * luongCoBan;
    }
};

// Danh sách nhân viên
vector<Employee *> danhSachNhanVien;

void themNhanVien()
{
    int loai;
    cout << "Chon loai nhan vien: \n";
    cout << "1. HR\n2. IT Engineer\n3. Sale Employee\n";
    cin >> loai;
    cin.ignore();

    string hoTen;
    int luongCoBan, namKinhNghiem, soHopDong = 0;

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
    cout << "Nhap so nam kinh nghiem: ";
    cin >> namKinhNghiem;

    if (loai == 3)
    {
        cout << "Nhap so hop dong ky trong thang: ";
        cin >> soHopDong;
    }

    switch (loai)
    {
    case 1:
        danhSachNhanVien.push_back(new HR(hoTen, luongCoBan, namKinhNghiem));
        break;
    case 2:
        danhSachNhanVien.push_back(new it_Engineer(hoTen, luongCoBan, namKinhNghiem));
        break;
    case 3:
        danhSachNhanVien.push_back(new sale_Employee(hoTen, luongCoBan, namKinhNghiem, soHopDong));
        break;
    default:
        cout << "Lua chon khong hop le!\n";
    }
}

void hienThiDanhSach()
{
    if (danhSachNhanVien.empty())
    {
        cout << "Danh sach nhan vien trong!\n";
        return;
    }

    cout << "\n===================== DANH SACH NHAN VIEN =====================\n";
    cout << left << setw(5) << "STT"
         << setw(25) << "Ho Ten"
         << setw(15) << "Luong Thuc Te"
         << setw(10) << "Kinh Nghiem" << endl;
    cout << "-----------------------------------------------------------------\n";

    for (size_t i = 0; i < danhSachNhanVien.size(); i++)
    {
        danhSachNhanVien[i]->xuatThongTin(i + 1);
    }
}

void suaNhanVien()
{
    int index;
    hienThiDanhSach();
    cout << "Nhap STT nhan vien can sua: ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > danhSachNhanVien.size())
    {
        cout << "STT khong hop le!\n";
        return;
    }

    Employee *nv = danhSachNhanVien[index - 1];
    string hoTen;
    int luongCoBan, namKinhNghiem;

    cout << "Nhap ho ten moi: ";
    getline(cin, hoTen);
    cout << "Nhap luong co ban moi: ";
    cin >> luongCoBan;
    cout << "Nhap so nam kinh nghiem moi: ";
    cin >> namKinhNghiem;

    nv->setHoTen(hoTen);
    nv->setLuongCoBan(luongCoBan);
    nv->setNamKinhNghiem(namKinhNghiem);
}

void xoaNhanVien()
{
    int index;
    hienThiDanhSach();
    cout << "Nhap STT nhan vien can xoa: ";
    cin >> index;

    if (index < 1 || index > danhSachNhanVien.size())
    {
        cout << "STT khong hop le!\n";
        return;
    }

    delete danhSachNhanVien[index - 1];
    danhSachNhanVien.erase(danhSachNhanVien.begin() + index - 1);
    cout << "Nhan vien da duoc xoa!\n";
}

void tinhTongLuong()
{
    int tongLuong = 0;
    for (Employee *nv : danhSachNhanVien)
    {
        tongLuong += nv->salary_Statistics();
    }
    cout << "Tong tien luong cua cong ty: " << tongLuong << endl;
}

void menu()
{
    int choice;
    do
    {
        cout << "\033[1;33m" << "===== QUAN LY NHAN VIEN =====\n";
        cout << "1. Them nhan vien\n";
        cout << "2. Hien thi danh sach nhan vien\n";
        cout << "3. Sua thong tin nhan vien\n";
        cout << "4. Xoa nhan vien\n";
        cout << "5. Tinh tong tien luong\n";
        cout << "6. Thoat\n";
        cout << "Lua chon cua ban: \033[0m";
        cin >> choice;
        switch (choice)
        {
        case 1:
            themNhanVien();
            break;
        case 2:
            hienThiDanhSach();
            break;
        case 3:
            suaNhanVien();
            break;
        case 4:
            xoaNhanVien();
            break;
        case 5:
            tinhTongLuong();
            break;
        case 6:
            cout << "Thoat chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 6);
}

int main()
{
    menu();
    for (Employee *nv : danhSachNhanVien)
        delete nv;
}
