#ifndef Dean_h
#define Dean_h
#include "Teacher.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Dean :public Teacher
{
private:
	double performance[12];
	double result = 0;
public:
	Dean() :Teacher(), performance{} {
		cout << "Dean constructor..." << endl;
	}
	Dean(string n, int a, char s, int t, string p, string d, int wh, double hp, double sa) : Teacher(n, a, s, t, p, d, wh, hp, sa), performance{} {
		cout << "Dean constructor..." << endl;
	}
	~Dean()
	{
		cout << "Dean destructor..." << endl;
	}
	// 赋值运算符函数
	Dean& operator =(const Dean& t) {
		if (this != &t)
		{
			Teacher::operator=(t);
			for (int i = 0; i < 12; i++) {
				performance[i] = t.performance[i];
			}
			result = t.result;
		}
		return *this;
	}
	//拷贝构造函数
	Dean(const Dean& t) : Teacher(t) {
		for (int i = 0; i < 12; i++) {
			performance[i] = t.performance[i];
		}
		result = t.result;
	}
	virtual double getIncome() { return Teacher::getIncome() + getPerformance(); }
	double getPerformance() { for (int i = 0; i < 12; i++) { result += performance[i]; } return result; }
	virtual void inputData() {
		Teacher::inputData();
		setPerformance();
		cout << "添加系主任信息成功" << endl;
	}
	void setPerformance() {
		cout << "接下来请输入每月绩效工资 (double)" << endl;
		try {
			for (int i = 0; i < 12; i++)
			{
				cout << "请输入第" << i + 1 << "月的绩效工资" << endl;
				cin >> performance[i];
				if (cin.fail())
					throw "输入类型错误，请输入double类型";
			}	
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "程序即将退出" << endl;
			exit(1);
		}
		cout << "添加每月绩效信息成功" << endl;
	}
	virtual void outData() {
		Teacher::outData();
		cout << "以下为系主任每月绩效工资：" << endl;
		for (int i = 0; i < 12; i++) {
			cout << i + 1 << "月绩效工资：" << performance[i] << "\t";
			if ((i+1) % 3 == 0)
				cout << endl;
		}
	}
	friend ostream& operator<<(ostream& os, Dean& x);
};
ostream& operator<<(ostream& os, Dean& x)
{
	os << static_cast<Teacher&>(x); //为Teacher类调用输出操作符重载
	os << "以下为系主任每月绩效工资：" << endl;
	for (int i = 0; i < 12; i++) {
		os << i + 1 << "月绩效工资：" << x.performance[i] <<"\t";
		if ((i+1) % 3 == 0)
			os << endl;
	}
	return os;
}
#endif // !Dean_h
