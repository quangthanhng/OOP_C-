#include <iostream>
#include <string>
using namespace std;

struct Message
{
public:
    std::string content;
    std::string sender;
};

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

    Message introduce(std::string language, bool isFull = true)
    {
        Message msg;
        if (language == "Vietnam")
        {
            msg.content = "Xin chao! Toi la phu nu.\n";
            if (isFull)
            {
                msg.content += "Toi rat xinh dep.\n";
            }
        }
        else
        {
            msg.content = "Hi! I am woman\n";
            if (isFull)
            {
                msg.content += "I am very beautiful";
            }
        }
        return msg;
    }

private:
    float weight;
    std::string fullname;
    int age;
};

int main()
{
    Woman *hariwon = new Woman();
    Message msg = hariwon->introduce("Vietnam");
    cout << msg.content;
    return 0;
}