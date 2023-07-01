#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include"Chancellor.h"
#include"Person.h"
#include"Student.h"
#include"Teacher.h"
#include"Dean.h"
#include<fstream>
using namespace std;
template<typename T>
class PersonManager {
public:
    PersonManager() {}
    virtual void inputData() = 0;
    virtual void outData() {
        if (!persons.empty())
        {
            for (auto t : persons) {
                t->outData();
            }
        }
        else
            cout << "输出失败，当前容器为空" << endl;
    }
    virtual void deleteData() = 0;
    virtual void sortData() = 0;
    virtual  void findData() = 0;
    virtual void modifyData() = 0;
    virtual ~PersonManager() {}
    void promp()
    {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按人员编号查找" << endl;
        cout << "2、按人员姓名查找" << endl;
    }
public:
    vector<T*> persons;
};
class StudentManager : public PersonManager<Student> {
public:
    StudentManager() :PersonManager() {}
    void inputData() {
        try {
            int number;
            cout << "请输入学生的数量:" << endl;
            cin >> number;
            if (cin.fail())
                throw"输入类型错误";
            else {
                for (int i = 0; i < number; i++) {
                    Student* s = new  Student;
                    s->inputData();
                    cout << "请输入导师id" << endl;
                    int tid;
                    cin >> tid;
                    cout << "请输入导师姓名" << endl;
                    string name;
                    cin >> name;
                    s->addAdvisor();
                    persons.push_back(s);
                }
            }
        }
        catch (const char* msg) {
            cout << msg << endl;
            cout << "请重新输入！" << endl;
            cin.clear(); // 清除cin上的错误标志
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入缓冲区中的任何剩余字符
        }
    }
    void outData() {
        PersonManager::outData();
        for (auto t:persons)
        {
            cout << t->getName() << "导师信息如下：" << endl;
            t->printAdvisor();
        }
    }
    void deleteData() {
        StudentManager::outData();
        if (!persons.empty())
        {
            int index;
            cout << "请输入要删除导师的学生编号：";
            cin >> index;
            for (auto it = persons.begin(); it != persons.end(); it++) {
                if ((*it)->getSid() == index) {
                    (*it)->setAdvisorId(0);
                    (*it)->setAdvisorName("0");
                    cout << "删除成功" << endl;
                    break;
                }
                else { cout << "该学生编号不存在" << endl; }
            }
        }
        else
            cout << "删除失败，当前容器为空" << endl;
    }
    void modifyData()
    {
        PersonManager::outData();
        int index;
        if (!persons.empty())
        {
            cout << "请输入要修改的学生编号：";
            cin >> index;
            auto it = find_if(persons.begin(), persons.end(), [index](Student* s) {return s->getSid() == index; });
            int id;
            cout << "请输入要修改的导师的编号" << endl;
            cin >> id;
            string name;
            cout << "请输入要修改的导师的姓名" << endl;
            cin >> name;
            if (it != persons.end())
            {
                (*it)->inputData();
                (*it)->addAdvisor();

            }
            else
                cout << "该学生编号不存在" << endl;
        }
        else
            cout << "修改失败，当前容器为空" << endl;
    }
    void findData()
    {
        if (!persons.empty())
        {
            promp();
            int select = 0;
            cin >> select;
            if (select == 1)
            {
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    int sid;
                    cout << "请输入要查找的学生编号：";
                    cin >> sid;
                    if ((*it)->getSid() == sid)
                    {
                        (*it)->outData();
                       // (*it)->getAdvisor((*it)->getAdvisorId());
                        break;
                    }
                    else
                        cout << "该学生编号不存在" << endl;
                }
            }
            else if (select == 2)
            {
                string name;
                cout << "请输入姓名：" << name;
                cin >> name;
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    if ((*it)->getName() == name)
                    {
                        (*it)->outData();
                       // (*it)->getAdvisor((*it)->getAdvisorId());
                        break;
                    }
                    else
                        cout << "抱歉，查无此人！" << endl;
                }
            }
            else
            {
                cout << "输入选项有误" << endl;
            }
        }
        else
            cout << "查找失败，当前容器为空" << endl;
    }
    void sortData() {
        if (!persons.empty())
        {
            sort(persons.begin(), persons.end(), [](Student* s1, Student* s2) {return s1->getAge() < s2->getAge(); });
            cout << "排序成功" << endl;
        }
        else
            cout << "排序失败，当前容器为空" << endl;
    }
    ~StudentManager() {
        for (auto s : persons) {
            delete s;
        }
    }

   
};
class TeacherManager : public PersonManager<Teacher> {
public:
    TeacherManager() :PersonManager() {}
    void inputData() {
        try {
            int number;
            cout << "请输入教师的数量:" << endl;
            cin >> number;
            if (cin.fail())
                throw"输入类型错误";
            else {
                for (int i = 0; i < number; i++) {
                    Teacher* t = new Teacher();
                    t->inputData();
                    t->setStudent();
                    persons.push_back(t);

                }
            }
        }
        catch (const char* msg) {
            cout << msg << endl;
            cout << "请重新输入！" << endl;
            cin.clear(); // 清除cin上的错误标志
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入缓冲区中的任何剩余字符
        }
    }
    void outData() {
        PersonManager::outData();
        for (auto t : persons)
        {
            t->printStudent();
        }
    }

    void deleteData() {
        PersonManager::outData();
        if (!persons.empty())
        {
            int index;
            cout << "请输入要删除学生的教师编号：";
            cin >> index;
            for (auto it = persons.begin(); it != persons.end(); it++) {
                if ((*it)->getTid() == index) {
                    int id;
                    cout << "请输入要删除学生的编号" << endl;
                    cin >> id;
                    (*it)->deleteStudent(id);
                    persons.erase(it);
                    cout << "删除成功" << endl;
                    break;
                }
                else
                    cout << "抱歉，查无此人！" << endl;
            }
        }
        else
            cout << "删除失败，当前容器为空" << endl;
    }
    void modifyData()
    {
        TeacherManager::outData();
        if (persons.empty()) {
            cout << "修改失败，当前容器为空" << endl;
            return;
        }
        while (true)
        {
            int index;
            cout << "请输入要修改的教师编号：";
            cin >> index;
            bool found = false;
            for (auto it = persons.begin(); it != persons.end(); it++)
            {
                if ((*it)->getTid() == index)
                {
                    found = true;
                    int oid,nid;
                    cout << "请输入旧学生id" << endl;
                    cin >> oid;
                    cout << "请输入新学生id" << endl;
                    cin >> nid;
                    (*it)->modifyStudent(oid,nid);
                    break;
                }
            }
            if (!found)
                cout << "该教师编号不存在！" << endl;
            else
                break;
        }
    }
    void findData()
    {
        if (!persons.empty())
        {
            int select;
            promp();
            cin >> select;
            if (select == 1)
            {
                int tid;
                cout << "请输入要查找的教师编号：";
                cin >> tid;
                bool found = false;
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    if ((*it)->getTid() == tid)
                    {
                        int id;
                        cout << "请输入想要查找的学生的id" << endl;
                        cin >> id;
                        (*it)->findStudent(id);
                        found = true;
                        return;
                    }
                }
                if (!found)
                    cout << "该教师编号不存在！" << endl;
            }
            else if (select == 2)
            {
                string name;
                cout << "请输入姓名：" << endl;
                cin >> name;
                bool found = false;
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    if ((*it)->getName() == name)
                    {
                        int id;
                        cout << "请输入想要查找的学生的id" << endl;
                        cin >> id;
                        (*it)->findStudent(id);
                        found = true;
                        return;
                    }
                }
                if (!found)
                    cout << "抱歉，查无此人！" << endl;
            }
            else
            {
                cout << "输入选项有误" << endl;
            }
        }
        else
            cout << "查找失败，当前容器为空" << endl;
    }

    void sortData() {
        if (!persons.empty())
        {
            sort(persons.begin(), persons.end(), [](Teacher* t1, Teacher* t2) {
                return t1->getAge() < t2->getAge();
                });
            cout << "排序成功" << endl;
        }
        else
            cout << "排序失败，当前容器为空" << endl;
    }
    ~TeacherManager() {
        for (auto t : persons) {
            delete t;
        }
    }
};


class TeacherStudentManager {
public:
    TeacherStudentManager() {}
    void inputData() {
        string type;
        cout << "请输入要增加的类型（1：教师，2：学生）：";
        cin >> type;
        if (type == "1")
        {
            teacherManager.inputData();
        }
        else if (type == "2")
        {
            studentManager.inputData();
        }

        else
            cout << "输入类型错误！" << endl;
    }
    void outData() {
        string type;
        cout << "请输入要输出的类型（1：教师，2：学生,3：全部输出）：";
        cin >> type;
        if (type == "1")
        {
            teacherManager.outData();
        }
        else if (type == "2")
        {
            studentManager.outData();
        }
       
        else if (type == "3")
        {
            teacherManager.outData();
            studentManager.outData();
          
        }
        else
            cout << "输入类型错误！" << endl;
    }
    void deleteData() {
        string type;
        cout << "请输入要删除的类型（1：教师，2：学生）：";
        cin >> type;
        if (type == "1")
        {
            teacherManager.deleteData();
        }
        else if (type == "2")
        {
            studentManager.deleteData();
        }
      
        else
            cout << "输入类型错误！" << endl;
    }
    void findData()
    {
        string type;
        cout << "请输入要查找的类型（1：教师，2：学生）：";
        cin >> type;
        if (type == "1")
        {
            teacherManager.findData();
        }
        else if (type == "2")
        {
            studentManager.findData();
        }
       
        else
            cout << "输入类型错误！" << endl;
    }

    void modifyData()
    {
        string type;
        cout << "请输入要修改的类型（1：教师，2：学生）：";
        cin >> type;
        if (type == "1")
        {
            teacherManager.modifyData();
        }
        else if (type == "2")
        {
            studentManager.modifyData();
        }
     
        else
            cout << "输入类型错误！" << endl;
    }

    void sortData() {
        string type;
        cout << "请输入要排序的类型（1：教师，2：学生）：";
        cin >> type;
        if (type == "1")
        {
            teacherManager.sortData();
        }
        else if (type == "2")
        {
            studentManager.sortData();
        }
      
        else
            cout << "输入类型错误！" << endl;
    }
    void ExitSystem()
    {
        string index;
        cout << "确定是否退出(1->是，2->否)" << endl;
        cin >> index;
        if (index == "1")
        {
            cout << "欢迎下次使用" << endl;
            exit(0);//退出程序
        }
        else if (index == "2")
            cout << "欢迎继续使用！" << endl;
        else
            cout << "输入类型错误!" << endl;
    }
    void Show_Menu();
private:
    TeacherManager teacherManager;
    StudentManager studentManager;
};
void TeacherStudentManager::Show_Menu()
{
    cout << "*************************************" << endl;
    cout << "**********欢迎使用教务管理系统*******" << endl;
    cout << "***********0.退出管理程序************" << endl;
    cout << "***********1.增加人员信息************" << endl;
    cout << "***********2.显示人员信息************" << endl;
    cout << "***********3.删除人员信息************" << endl;
    cout << "***********4.修改人员信息************" << endl;
    cout << "***********5.查找人员信息************" << endl;
    cout << "***********6.按照年龄排序************" << endl;
    cout << "*************************************" << endl;
    cout << endl;
}