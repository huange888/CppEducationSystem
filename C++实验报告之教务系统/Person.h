#ifndef Person_h
#define Person_h
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Person
{
private:
    string name;//姓名
    int age = 0;//年龄
    char sex; //w->女 m->男
public:
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setAge(int a) { age = a; }
    int getAge() { return age; }
    void setSex(char s) { sex = s; }
    string getSex() { if (sex == 'm' || sex == 'M')return"男"; if (sex == 'w' || sex == 'W')return "女"; }
    
    Person() { }
    Person(string n, int a, char s) :name(n), age(a), sex(s) {
       
        cout << "Person constructor..." << endl;
    }
    ~Person()
    {
        cout << "Person destructor..." << endl;
    }
    // 赋值运算符函数
   /* Person& operator =(const Person& p) {
        if (this != &p)
        {
            name = p.name;
            age = p.age;
            sex = p.sex;
        }
        return *this;
    }*/
    Person& operator=(const Person& p)
    {
        if (this != &p)
        {
            memcpy(this, &p, sizeof(Person));
        }
        return *this;
    }
    //拷贝构造函数
    Person(const Person& p) {
      /*  name = p.name;
        age = p.age;
        sex = p.sex;*/
        memcpy(this, &p, sizeof(Person));
    }

    virtual void inputData() {
        cout << "请输入姓名 (string)" << endl;
        cin >> name;
        try {
            cout << "请输入年龄 (int)" << endl;
            cin >> age; // 输入年龄
            if (cin.fail()) {
                throw "输入类型错误，请输入int类型"; // 如果输入类型错误，抛出异常
            }
            cout << "请输入性别 (char：m->男, w->女)" << endl;
            cin >> sex;
            if (sex != 'm' && sex != 'w' && sex != 'M' && sex != 'W')
                throw "性别信息添加失败，请输入规定字符";
        }
        catch (const char* msg) {
            cout << msg << endl; // 捕获异常并输出错误信息
            cout << "程序即将退出" << endl; // 输出提示信息
            exit(1); // 退出程序
        }
            cout << "添加基本信息成功" << endl;
    }
    virtual void outData() {
        cout << "姓名：" << name << " \t年龄：" << age << "\t性别：" << getSex() << endl;
    }
    friend ostream& operator<<(ostream& os, Person& x);
};
ostream& operator<<(ostream& os, Person& x)
{
    cout << "姓名：" << x.name << " \t年龄：" << x.age << "\t性别：" << x.getSex() << endl;
    return os;
}

#endif // !Person_h