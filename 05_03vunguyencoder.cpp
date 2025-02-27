#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Flight_Ticket
{
private:
    string name_flight;
    string day_flight;
    int price;

public:
    Flight_Ticket() {} // Constructor mặc định
    Flight_Ticket(string name_f, string day_f, int p)
    {
        name_flight = name_f;
        day_flight = day_f;
        price = p;
    }

    string get_name_flight() { return name_flight; }
    string get_day_flight() { return day_flight; }
    int get_price() { return price; }

    void set_flight_info()
    {
        cout << "Nhap ten chuyen bay: ";
        cin.ignore();
        getline(cin, name_flight);
        cout << "Nhap ngay bay: ";
        getline(cin, day_flight);
        cout << "Nhap gia ve: ";
        cin >> price;
    }
};

class People
{
protected:
    string name;
    string gender;
    int age;

public:
    People() {} // Constructor mặc định
    People(string n, string g, int a)
    {
        name = n;
        gender = g;
        age = a;
    }

    void set_personal_info()
    {
        cout << "Nhap ten khach hang: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap gioi tinh: ";
        getline(cin, gender);
        cout << "Nhap tuoi: ";
        cin >> age;
    }

    string get_name() { return name; }
    string get_gender() { return gender; }
    int get_age() { return age; }
};

class Customer : public People
{
private:
    Flight_Ticket ticket;
    int number_of_ticket_to_buy;

public:
    Customer() {}

    void set_customer_info()
    {
        set_personal_info();
        ticket.set_flight_info();
        cout << "Nhap so luong ve can mua: ";
        cin >> number_of_ticket_to_buy;
    }

    void show_information()
    {
        cout << "=============== Thong Tin Hanh Khach ===============\n";
        cout << "Ten chuyen bay: " << ticket.get_name_flight() << endl;
        cout << "Ngay bay: " << ticket.get_day_flight() << endl;
        cout << "Gia ve: " << ticket.get_price() << " VND" << endl;
        cout << "Khach hang: " << get_name() << endl;
        cout << "Gioi tinh: " << get_gender() << endl;
        cout << "Tuoi: " << get_age() << endl;
        cout << "So ve da mua: " << number_of_ticket_to_buy << endl;
        cout << "Tong tien: " << (ticket.get_price() * number_of_ticket_to_buy) << " VND\n";
        cout << "===================================================\n\n";
    }
};

int main()
{
    int n;
    cout << "Vui long nhap so luong khach hang muon dang ky ve: ";
    cin >> n;

    vector<Customer> guests(n);
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin khach hang " << i + 1 << ":\n";
        guests[i].set_customer_info();
    }

    cout << "\n======= Danh Sach Hanh Khach =======\n";
    for (int i = 0; i < n; i++)
    {
        guests[i].show_information();
    }

    return 0;
}
