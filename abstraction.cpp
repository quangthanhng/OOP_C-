#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Woman
{
public:
    void setAge(int a)
    {
        age = a;
    }

    int getAge()
    {
        return age;
    }

    float getweight(){
        return weight;
    }
    float getHeight(){
        return height;
    }

    Woman(string fn, int a, float w, float h){
        fullname = fn;
        age = a;
        weight = w;
        height = h;
    }
private:
    std::string fullname;
    int age;
    float weight;
    float height;
};

class HealthChecker{
    public:

    void check(Woman* woman){
        weight = woman->getweight();
        height = woman->getHeight();
        bloodPressure = 130; // getDevice()
        heartBeat = 80; // getDevice()
    }

    std::string getResult(){
        float bmi = weight / (height * height);
        if(bmi >= 18.5 && bmi <= 24.9
        && bloodPressure >= 120 && bloodPressure < 140 
        && heartBeat >= 60 && heartBeat < 100){
            return "Normal";
        }
        return "Abnormal";
    }

    private:
    float weight;
    float height;
    int bloodPressure;
    int heartBeat;
};

int main()
{
    Woman *hariwon = new Woman("Bella", 20, 60, 1.65);
    HealthChecker* checker = new HealthChecker();
    checker->check(hariwon);
    std::string result = checker->getResult();
    cout << result;
    return 0;
}