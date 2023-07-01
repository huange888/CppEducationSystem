//#include<iostream>
//#include<string>
//#include <vector>
//#include <algorithm>
//#include"Chancellor.h"
//#include"Person.h"
//#include"Student.h"
//#include"Teacher.h"
//#include"Dean.h"
//#include"Management.h"
//using namespace std;
//bool cmp(Person* a, Person* b) {
//    return a->getAge() < b->getAge();
//}
////class TeacherCompare {
////public:
////    bool operator()(Teacher* t1, Teacher* t2) {
////        return t1->getAge() < t2->getAge();
////    }
////};
//int main() {
//    //用STL中的vector或list管理Person对象指针或引用，管理继承体系中的对象，实现体现多态编程特征。同类对象可以按年龄排序。
//
//    // 创建一个 vector 容器，用于存储 Person 类型的指针
//    vector<Person*> persons;
//   
//    // 循环 5 次，创建 Teacher 对象并输入数据，将其指针存入 vector 容器中
//    for (int i = 0; i < 1; i++) {
//        Teacher* teacher = new Teacher();
//        teacher->inputData();
//        persons.push_back(teacher);
//    }
//    for (auto t:persons )
//    {
//        t->getName();
//    }
//    //增加数据
//    
//
//
//    // 循环 5 次，创建 Student 对象并输入数据，将其指针存入 vector 容器中
//    for (int i = 0; i < 1; i++) {
//        Student* student = new Student();
//        student->inputData();
//        persons.push_back(student);
//    }
//
//    // 创建 Chancellor 对象并输入数据，将其指针存入 vector 容器中
//    Chancellor* chancellor = new Chancellor();
//    chancellor->inputData();
//    persons.push_back(chancellor);
//
//    sort(persons.begin(), persons.end(), cmp);//按年龄由小到大排序
//
//    // 循环遍历 vector 容器中的每个元素，调用 outData() 函数输出数据
//    for (int i = 0; i < persons.size(); i++) {
//        persons[i]->outData();
//    }
//
//    //Teacher类型
//    for (int i = 0; i < persons.size(); i++) {
//        if (dynamic_cast<Teacher*>(persons[i])) {
//            Teacher* teacher = dynamic_cast<Teacher*>(persons[i]);
//            teacher->outData();
//        }
//    }
//
//    // Dean类型
//    for (int i = 0; i < persons.size(); i++) {
//        if (dynamic_cast<Dean*>(persons[i])) {
//            Dean* dean = dynamic_cast<Dean*>(persons[i]);
//            dean->outData();
//        }
//    }
//
//   //Chancellor类型
//    for (int i = 0; i < persons.size(); i++) {
//        if (dynamic_cast<Chancellor*>(persons[i])) {
//            Chancellor* chancellor = dynamic_cast<Chancellor*>(persons[i]);
//            chancellor->outData();
//        }
//    }
//
//    return 0;
//}
