#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Diemtrungbinh
{
public:
    float toan, ly, hoa, van, anh, sinh, su, dia;

    // Hàm tính điểm trung bình
    float tinhTrungBinh()
    {
        return (toan + ly + hoa + van + anh + sinh + su + dia) / 8;
    }
};

class ThongtinHocSinh
{
public:
    int mssv;
    string name;
    int age;
    string hometown;
    float height;
    float weight;
    Diemtrungbinh dtb;
    ThongtinHocSinh *pNext;

    // Hàm dựng mặc định
    ThongtinHocSinh() : mssv(0), age(0), height(0), weight(0), pNext(NULL) {}

    // Hàm dựng có tham số
    ThongtinHocSinh(
        int mssv_hs, string name_hs, int age_hs, string hometown_hs,
        float height_hs, float weight_hs, float diemtoan, float diemly,
        float diemhoa, float diemvan, float diemanh, float diemsinh,
        float diemsu, float diemdia)
    {
        mssv = mssv_hs;
        name = name_hs;
        age = age_hs;
        hometown = hometown_hs;
        height = height_hs;
        weight = weight_hs;
        dtb.toan = diemtoan;
        dtb.ly = diemly;
        dtb.hoa = diemhoa;
        dtb.van = diemvan;
        dtb.anh = diemanh;
        dtb.sinh = diemsinh;
        dtb.su = diemsu;
        dtb.dia = diemdia;
        pNext = NULL;
    }
};

class Hocsinh
{
public:
    ThongtinHocSinh *pHead;
    ThongtinHocSinh *pTail;

    // Hàm dựng
    Hocsinh() : pHead(NULL), pTail(NULL) {}

    // Hàm hủy giải phóng bộ nhớ
    ~Hocsinh()
    {
        ThongtinHocSinh *temp;
        while (pHead != NULL)
        {
            temp = pHead;
            pHead = pHead->pNext;
            delete temp;
        }
    }

    // Hàm nhập thông tin học sinh
    void nhapthongtin(ThongtinHocSinh *newstudent)
    {
        if (pHead == NULL)
        {
            pHead = newstudent;
            pTail = newstudent;
        }
        else
        {
            pTail->pNext = newstudent;
            pTail = newstudent;
        }
    }

    // Hàm giới thiệu bản thân
    void gioithieubanthan(ThongtinHocSinh *p)
    {
        cout << "Ten cua hoc sinh la: " << p->name << endl;
        cout << "Tuoi cua hoc sinh la: " << p->age << endl;
        cout << "Que quan cua hoc sinh la: " << p->hometown << "\n\n";
    }

// Hàm hiển thị bảng điểm
#include <iomanip> // Thư viện hỗ trợ căn chỉnh định dạng

    void showbangdiem(ThongtinHocSinh *p)
    {
        cout << "========== BANG DIEM MON HOC ==========" << endl;
        cout << "+-------+--------------------+--------+" << endl;
        cout << "|  STT  |      Ten Mon       |  Diem  |" << endl;
        cout << "+-------+--------------------+--------+" << endl;

        cout << "|   1   | " << setw(18) << left << "Toan" << " | "
             << setw(6) << right << fixed << setprecision(1) << p->dtb.toan << " |" << endl;

        cout << "|   2   | " << setw(18) << left << "Ly" << " | "
             << setw(6) << right << fixed << setprecision(1) << p->dtb.ly << " |" << endl;

        cout << "|   3   | " << setw(18) << left << "Hoa" << " | "
             << setw(6) << right << fixed << setprecision(1) << p->dtb.hoa << " |" << endl;

        cout << "|   4   | " << setw(18) << left << "Van" << " | "
             << setw(6) << right << fixed << setprecision(1) << p->dtb.van << " |" << endl;

        cout << "|   5   | " << setw(18) << left << "Anh" << " | "
             << setw(6) << right << fixed << setprecision(1) << p->dtb.anh << " |" << endl;

        cout << "|   6   | " << setw(18) << left << "Sinh" << " | "
             << setw(6) << right << fixed << setprecision(1) << p->dtb.sinh << " |" << endl;

        cout << "|   7   | " << setw(18) << left << "Su" << " | "
             << setw(6) << right << fixed << setprecision(1) << p->dtb.su << " |" << endl;

        cout << "|   8   | " << setw(18) << left << "Dia" << " | "
             << setw(6) << right << fixed << setprecision(1) << p->dtb.dia << " |" << endl;

        cout << "+-------+--------------------+--------+" << endl;
    }

    // Hàm xếp loại học lực
    void xeploai(ThongtinHocSinh *p)
    {
        float dtb = p->dtb.tinhTrungBinh();
        cout << "Diem trung binh cua hoc sinh " << p->name << " la: " << dtb << endl;
        if (dtb >= 8)
            cout << "Xep loai hoc luc gioi.\n";
        else if (dtb >= 5 && dtb < 8)
            cout << "Xep loai hoc luc kha.\n";
        else
            cout << "Xep loai hoc luc trung binh.\n";
    }

    // Hàm duyệt danh sách và hiển thị thông tin
    void duyet()
    {
        for (ThongtinHocSinh *p = pHead; p != NULL; p = p->pNext)
        {
            gioithieubanthan(p);
            showbangdiem(p);
            xeploai(p);
        }
    }
};

// Hàm nhập thông tin học sinh
ThongtinHocSinh *nhapThongTin()
{
    int mssv_hs, age_hs;
    string name_hs, hometown_hs;
    float height_hs, weight_hs;
    float diemtoan, diemly, diemhoa, diemvan, diemanh, diemsinh, diemsu, diemdia;

    cout << "Nhap MSSV: ";
    cin >> mssv_hs;
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, name_hs);
    cout << "Nhap tuoi: ";
    cin >> age_hs;
    cin.ignore();
    cout << "Nhap que quan: ";
    getline(cin, hometown_hs);
    cout << "Nhap chieu cao: ";
    cin >> height_hs;
    cout << "Nhap can nang: ";
    cin >> weight_hs;
    cout << "Nhap diem cac mon: ";
    cin >> diemtoan >> diemly >> diemhoa >> diemvan >> diemanh >> diemsinh >> diemsu >> diemdia;

    return new ThongtinHocSinh(mssv_hs, name_hs, age_hs, hometown_hs, height_hs, weight_hs, diemtoan, diemly, diemhoa, diemvan, diemanh, diemsinh, diemsu, diemdia);
}

int main()
{
    Hocsinh hocsinh;
    int n;

    cout << "Hay nhap so luong hoc sinh can nhap thong tin: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ThongtinHocSinh *newstudent = nhapThongTin();
        hocsinh.nhapthongtin(newstudent);
    }

    hocsinh.duyet();
    return 0;
}
