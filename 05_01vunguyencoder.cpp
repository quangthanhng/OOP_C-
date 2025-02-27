#include <iostream>
#include <string>

using namespace std;

class MobilePhone {
public:
    ~MobilePhone() {
        cout << "Deleted a device.\n";
        cout << "===============================================================\n";
    }

    void trigger() {
        cout << "The device has been activated in " << HSX << endl;
    }

    void callFunction() {
        cout << "The " << HSX << " is calling.\n";
    }

    void powerOn() {
        cout << "Powering on the phone..." << endl;
    }

    void makeCall() {
        cout << "Making a call..." << endl;
    }

    MobilePhone(string HSX_dth, string version_dth, float size_dth, int number) {
        cout << "Starting to analyze the device........\n";
        cout << "Here are the information: \n";
        HSX = HSX_dth;
        version = version_dth;
        size = size_dth;
        number_of_insurance_in_year = number;
    }

    string get_HSX() {
        return HSX;
    }

    string get_version() {
        return version;
    }

    float get_size() {
        return size;
    }

    int get_insurance() {
        return number_of_insurance_in_year;
    }

private:
    string HSX;
    string version;
    float size;
    int number_of_insurance_in_year;
};

class Iphone : public MobilePhone {
public:
    Iphone(string HSX_dth, string version_dth, float size_dth, int number)
        : MobilePhone(HSX_dth, version_dth, size_dth, number) {
        trigger();
        callFunction();
        cout << "Phone name: " << get_HSX() << endl;
        cout << "Operating system: " << get_version() << endl;
        cout << "Size: " << get_size() << " inch." << endl;
        cout << "Number of insurance in year: " << get_insurance() << endl;
        FaceID();
        AirDrop();
        AppStore();
    }

    ~Iphone() {
        cout << "Turning off the phone.\n";
    }

private:
    void FaceID() {
        cout << "Please enter your face in front of the screen\n";
    }

    void AirDrop() {
        cout << "AirDrop is opening\n";
    }

    void AppStore() {
        cout << "Appstore is ready for you.\n";
    }
};

class GalaxyS : public MobilePhone {
public:
    GalaxyS(string HSX_dth, string version_dth, float size_dth, int number)
        : MobilePhone(HSX_dth, version_dth, size_dth, number) {
        trigger();
        callFunction();
        cout << "Phone name: " << get_HSX() << endl;
        cout << "Operating system: " << get_version() << endl;
        cout << "Size: " << get_size() << " inch." << endl;
        cout << "Number of insurance in year: " << get_insurance() << endl;
        S_pen();
        GooglePlay();
    }

    ~GalaxyS() {
        cout << "Turning off the phone.\n";
    }

private:
    void S_pen() {
        cout << "Lifting up your S_pen to use.\n";
    }

    void GooglePlay() {
        cout << "GooglePlay is ready for you.\n";
    }
};

class RedmiNote : public MobilePhone {
public:
    RedmiNote(string HSX_dth, string version_dth, float size_dth, int number)
        : MobilePhone(HSX_dth, version_dth, size_dth, number) {
        trigger();
        callFunction();
        cout << "Phone name: " << get_HSX() << endl;
        cout << "Operating system: " << get_version() << endl;
        cout << "Size: " << get_size() << " inch." << endl;
        cout << "Number of insurance in year: " << get_insurance() << endl;
    }

    ~RedmiNote() {
        cout << "Turning off the phone.\n";
    }
};

class Xperia : public MobilePhone {
public:
    Xperia(string HSX_dth, string version_dth, float size_dth, int number)
        : MobilePhone(HSX_dth, version_dth, size_dth, number) {
        trigger();
        callFunction();
        cout << "Phone name: " << get_HSX() << endl;
        cout << "Operating system: " << get_version() << endl;
        cout << "Size: " << get_size() << " inch." << endl;
        cout << "Number of insurance in year: " << get_insurance() << endl;
    }

    ~Xperia() {
        cout << "Turning off the phone.\n";
    }
};

int main() {
    Iphone* phone = new Iphone("Apple", "Iphone 13 IOS 18.3.1", 16, 3);
    delete phone;
    GalaxyS* phone2 = new GalaxyS("Samsung", "SamSung galaxy S23 ultra Android 15", 17, 2);
    delete phone2;
    RedmiNote* phone3 = new RedmiNote("Xiaomi", "Redmi Note 10 Android 15", 16.5, 3);
    delete phone3;
    Xperia* phone4 = new Xperia("Sony", "Xperia version 2 Android 15", 17.5, 3);
    delete phone4;

    return 0;
}