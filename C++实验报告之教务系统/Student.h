#include "Person.h"
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include"Teacher.h"
#ifndef Student_h
#define Student_h
using namespace std;
class Student :public Person
{
private:
	int sid = 0;
	int classX = 0;
	double chinese = 0;
	double english = 0;
	double math = 0;
	map<int, string> advisors;
	int advisorId;
	string advisorName;

public:
	int getSid() { return sid; }
	void setAdvisorId(int id) { advisorId = id; }
	void setAdvisorName(string name) { advisorName = name; }
	Student() {  }
	Student(string n, int a, char s, int si, int c, double ch, double m, double e) :Person(n, a, s), sid(si), classX(c), chinese(ch), math(m), english(e) {cout << "Student constructor..." << endl; }
	~Student()
	{
		cout << "Student destructor..." << endl;
		
	}
	// 赋值运算符函数
	Student& operator =(const Student& s) {
		if (this != &s)
		{
			Person::operator=(s);
			sid = s.sid;
			classX = s.classX;
			chinese = s.chinese;
			math = s.math;
			english = s.english;

		}
		return *this;
	}
	//拷贝构造函数
	Student(const Student& s) :Person(s) {
		sid = s.sid;
		classX = s.classX;
		chinese = s.chinese;
		math = s.math;
		english = s.english;
	}
	virtual void inputData() {
		Person::inputData();
		try {
			cout << "请输入学生编号 (int)" << endl;
			cin >> sid;
			if (cin.fail()) {
				throw  "输入类型错误，请输入int类型"; // 如果输入类型错误，抛出异常
			}
			cout << "请输入班级编号 (int)" << endl;
			cin >> classX;
			if (cin.fail()) {
				throw  "输入类型错误，请输入int类型"; // 如果输入类型错误，抛出异常
			}
			cout << "请输入语文成绩 (double)" << endl;
			cin >> chinese;
			if (cin.fail()) {
				throw "输入类型错误，请输入double类型"; // 如果输入类型错误，抛出异常
			}
			cout << "请输入数学成绩 (double)" << endl;
			cin >> math;
			if (cin.fail()) {
				throw "输入类型错误，请输入double类型"; // 如果输入类型错误，抛出异常
			}
			cout << "请输入英语成绩 (double)" << endl;
			cin >> english;
			if (cin.fail()) {
				throw "输入类型错误，请输入double类型"; // 如果输入类型错误，抛出异常
			}
			
		}
		catch (const char* msg) {
			cout << msg << endl; // 捕获异常并输出错误信息
			cout << "程序即将退出" << endl; // 输出提示信息
			exit(1); // 退出程序
		}
		cout << "添加个人信息成功" << endl;
	}
	void addAdvisor() {
		int id;
		string name;
		cout << "请输入导师的id" << endl;
		cin >> id;
		cout << "请输入导师的姓名" << endl;
		cin >> name;
		if (advisors.empty()) {
			advisors.insert(make_pair(id, name)); // 输出具有给定 ID 的教师的信息
			cout << "添加导师信息成功" << endl;
		}
		else {
			cout << "添加失败，一个学生只能选择一个导师" << endl;
		}
	}
	void printAdvisor() {
		cout << "该学生选择的导师信息如下：" << endl;
		for (auto it = advisors.begin(); it != advisors.end(); it++)
		{
			cout << "导师id:" << it->first << "\t导师姓名：" << it->second<< endl;
		}
	}
	void findAdvisor(int tid)
	{
		cout << "该导师选择的学生信息如下：" << endl;
		if (!advisors.empty()) {
			cout << "导师姓名：" << advisors[tid] << endl; // 输出具有给定 ID 的学生的姓名
		}
		else {
			cout << "输出失败，该映射为空" << endl;
		}
	}
	void deleteAdvisor(int id) {
		auto it = advisors.find(id); // 找到给定id的导师
		if (it != advisors.end()) { // 如果找到该导师
			advisors.erase(it); // 将这个导师从map映射中删除
			cout << "导师 " << id << " 已被删除" << endl;
		}
		else { //如果学生没找到
			cout << "导师 " << id << " 不存在" << endl;
		}
	}
	void modifyAdvisor(int oldId, int newId) {
		auto it = advisors.find(oldId); // 找到旧id
		if (it != advisors.end()) { // 如果该学生存在
			string name = it->second; // 获得该学生的姓名
			advisors.erase(it); // 将该学生从map映射中去掉
			advisors.insert(make_pair(newId, name)); // 给学生插入新的id
			cout << "导师 " << oldId << " 的编号已修改为 " << newId << endl;
		}
		else { // 如果学生没找到
			cout << "导师 " << oldId << " 不存在" << endl;
		}
	}
	virtual void outData()
	{
		Person::outData();
		cout << "学号：" <<sid << "\t班级编号：" << classX << "\t语文成绩：" << chinese << "\t数学成绩：" << math << "\t英语成绩：" << english << endl;		
		//cout << "导师id：" << advisorId << "\t导师姓名：" << advisorName<<endl;
	}
	friend ostream& operator<<(ostream& os, Student& x);

};
ostream& operator<<(ostream& os, Student& x)
{
	os << static_cast<Person&>(x); //为Person类调用输出操作符重载
	os << "学号：" << x.sid << "\t班级编号：" << x.classX << "\t语文成绩：" << x.chinese << "\t数学成绩：" << x.math << "\t英语成绩：" << x.english << endl;
	return os;
}
#endif // !Student_h