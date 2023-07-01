#include "Person.h"
#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;
#ifndef Teacher_h
#define Teacher_h
class Teacher :public Person
{
private:
    int tid = 0;
    string protitle;
    string dept;
    double hourPrice = 0;
    double salary = 0;
    int workHour = 0;
    map<int, string> students;
    string name;
    int id;
    int num;

public:
    virtual double getSalary() { return salary; }
    virtual double getIncome() { return salary + (hourPrice * double(workHour)); }
    virtual void setSalary(double s) { salary = s; }
    void setWorkHour(int wh) { workHour = wh; }
    void setHourPrice(double hp) { hourPrice = hp; }
    int getTid() { return tid; }
    string getTitle() { return protitle; }
   
    Teacher() {  }
    Teacher(string n, int a, char s, int t, string p, string d, int wh, double hp, double sa) :Person(n, a, s), tid(t), protitle(p), dept(d), workHour(wh), hourPrice(hp), salary(sa) { cout << "Teacher constructor..." << endl; }
    ~Teacher()
    {
        cout << "Teacher destructor..." << endl;
    }
    // 赋值运算符函数
    Teacher& operator =(const Teacher& t) {
        Person::operator=(t);
        tid = t.tid;
        protitle = t.protitle;
        dept = t.dept;
        workHour = t.workHour;
        hourPrice = t.hourPrice;
        salary = t.salary;
        return *this;
    }
    //拷贝构造函数
    Teacher(const Teacher& t) :Person(t) {
        tid = t.tid;
        protitle = t.protitle;
        dept = t.dept;
        workHour = t.workHour;
        hourPrice = t.hourPrice;
        salary = t.salary;
       
    }
    virtual void inputData() {
        Person::inputData();
        try {
            cout << "请输入教师编号 (int)" << endl;
            cin >> tid;
            if (cin.fail())
                throw  "输入类型错误，请输入int类型"; // 如果输入类型错误，抛出异常
            cout << "请输入职称 (string)" << endl;
            cin >> protitle;
            cout << "请输入所属院系 (string)" << endl;
            cin >> dept;
            cout << "请输入用工作时长 (double)" << endl;
            cin >> workHour;
            if (cin.fail())
                throw  "输入类型错误，请输入double类型"; // 如果输入类型错误，抛出异常
            cout << "请输入工作时薪 (double)" << endl;
            cin >> hourPrice;
            if (cin.fail())
                throw  "输入类型错误，请输入double类型"; // 如果输入类型错误，抛出异常
            cout << "请输入基本工资 (double)" << endl;
            cin >> salary;
            if (cin.fail())
                throw  "输入类型错误，请输入double类型"; // 如果输入类型错误，抛出异常
        }
        catch (const char* msg)
        {
                cout << msg << endl; // 捕获异常并输出错误信息
                cout << "程序即将退出" << endl; // 输出提示信息
                exit(1); // 退出程序
        }
        cout << "添加教师个人信息成功" << endl;
    }
    void setStudent() {
        cout << "请输入管理学生的个数" << endl;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int id;
            string name;
            cout << "请输入管理的学生的id" << endl;
            cin >> id;
            cout << "请输入管理的学生的姓名" << endl;
            cin >> name;
            students.insert(make_pair(id, name));
        }
    }
    void printStudent()
    {
        int i = 1;
        for (auto it = students.begin(); it != students.end(); it++)
        {
            cout << "管理的学生" << i << "\tid:" << it->first << "\t姓名:" << it->second << endl;
            i++;
        }
    }
    void findStudent(int tid)
    {
            cout << "该导师选择的学生信息如下：" << endl;
            if (!students.empty()) {
                cout << "学生姓名：" << students[tid] << endl; // 输出具有给定 ID 的学生的姓名
            }
            else {
                cout << "输出失败，该映射为空" << endl;
            }
    }
    void deleteStudent(int id) {
        auto it = students.find(id); // 找到给定id的学生
        if (it != students.end()) { // 如果找到该学生
            students.erase(it); // 将这个学生从map映射中删除
            cout << "学生 " << id << " 已被删除" << endl;
        }
        else { //如果学生没找到
            cout << "学生 " << id << " 不存在" << endl;
        }
    }
    void modifyStudent(int oldId, int newId) {
        auto it = students.find(oldId); // 找到旧id
        if (it != students.end()) { // 如果该学生存在
            string name = it->second; // 获得该学生的姓名
            students.erase(it); // 将该学生从map映射中去掉
            students.insert(make_pair(newId, name)); // 给学生插入新的id
            cout << "管理的学生 " << oldId << " 的编号已修改为 " << newId << endl;
        }
        else { // 如果学生没找到
            cout << "管理的学生 " << oldId << " 不存在" << endl;
        }
    }
    virtual void outData()
    {
        Person::outData();
        cout << "教师编号：" << tid << "\t职称：" << protitle << "\t所属院系：" << dept << "\t工作时长：" << workHour << "\t工作时薪：" << hourPrice << "\t基本工资：" << salary << "\t教师总收入：" << getIncome() << endl;
       
    }
    friend ostream& operator<<(ostream& os, Teacher& x);

};
ostream& operator<<(ostream& os, Teacher& x)
{
    os << static_cast<Person&>(x); //为Person类调用输出操作符重载
    cout << "教师编号：" << x.tid << "\t职称：" << x.protitle << "\t所属院系：" << x.dept << "\t工作时长：" << x.workHour << "\t工作时薪：" << x.hourPrice << "\t基本工资：" << x.salary << "\t总收入：" << x.getIncome() << endl;
    return os;
}
#endif // !Teacher_h
