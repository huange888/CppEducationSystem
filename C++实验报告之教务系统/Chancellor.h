#ifndef Chancellor_h
#define Chancellor_h
#include "Teacher.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Chancellor :public Teacher
{
private:
    double yearsalary = 0;
    double salary = 0;
public:
    Chancellor() {}
    Chancellor(string n, int a, char s, int t, string p, string d, int wh, double hp, double sa, double ys) :Teacher(n,a,s,t,p,d,wh,hp,sa), yearsalary(ys) { cout << "Chancelllor constructor..." << endl; }
    ~Chancellor()
    {
        cout << "Chancellor destructor..." << endl;
    }
    //赋值运算符函数
    Chancellor& operator=(const Chancellor& t)
    {
        if (this != &t)
        {
            Teacher::operator=(t);
            yearsalary = t.yearsalary;

        }
        return *this;
    }
    virtual double getIncome() { return Teacher::getIncome() + yearsalary; }
    virtual void setSalary(double s) { salary = s; }
    virtual double getSalary() { return salary; }
    //拷贝构造函数
    Chancellor(const Chancellor& t)
    {
        Teacher::operator=(t);
        yearsalary = t.yearsalary;
    }
    virtual void inputData()
    {
        Teacher::inputData();
        try
        {
            cout << "请输入院长年薪 (double)" << endl;
            cin >> yearsalary;
            if(cin.fail())
                throw "输入类型错误，请输入double类型"; // 如果输入类型错误，抛出异常
        }
        catch (const char* msg)
        {
            cout << msg << endl;
            cout << "程序即将退出" << endl;
            exit(1);
        }
         cout << "添加院长年薪信息成功" << endl;
    }
    virtual void outData()
    {
        Teacher::outData();
        cout << "院长年薪：" << yearsalary << endl;
      
    }
    friend ostream& operator<<(ostream& os, Chancellor& x);
};
ostream& operator<<(ostream& os, Chancellor& x)
{
	os << static_cast<Teacher&>(x); //为Teacher类调用输出操作符重载
	os << "院长年薪：" << x.yearsalary << endl;
	return os;
}
#endif
