#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
    // Vehicle(){
    //     cout << "Created a vehicle\n";
    // }
    Vehicle(std::string name)
    {
        modelName = name;
        cout << "Created a vehicle with name " << modelName << ".\n";
    }
    ~Vehicle(){
        cout << "Deleted a vehicle.\n";
    }
    string get_modelName()
    {
        return modelName;
    }

    void set_modelName(std::string mName)
    {
        modelName = mName;
    }

    void set_version(int v)
    {
        version = v;
    }

    int get_version()
    {
        return version;
    }

protected:
    void run()
    {
        cout << "A vehicle is running\n";
    }

private:
    std::string modelName;
    int version;
};

class Taxi : public Vehicle
{
public:
    Taxi(std::string name) : Vehicle(name)
    {
        cout << "Created a taxi.\n";
    }
    ~Taxi(){
        cout << "Deleted a taxi.\n";
    }

    void start()
    {
        std::cout << "Started! Ready to run.\n";
        run();
    }
    void run()
    {
        Vehicle::run();
        cout << "It's a taxi\n";
    }

    void run(int km)
    {
        kmCounter = km;
    }

    int CalculateFee()
    {
        return kmCounter * 10000;
    }

private:
    int kmCounter;
};

int main()
{
    Taxi* taxi = new Taxi("Kia Morning");
    Taxi* taxi2 = new Taxi("Vinfast Fadil");
    // taxi->set_modelName("Kia Morning");
    // std::cout << taxi->get_modelName() << endl;
    // taxi->start();
    delete taxi;
    return 0;
}
