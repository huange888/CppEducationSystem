#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
        for (auto t : persons)
        {
            cout << t->getName() << "导师信息如下：" << endl;
            t->printAdvisor();
        }
    }
   
    void deleteData() {
        StudentManager::outData();
        if(!persons.empty())
        {
            int choice;
            cout << "1->删除学生，2->删除导师" << endl;
            cin >> choice;
            int index;
            cout << "请输入要操作的学生编号：";
            cin >> index;
                for (auto it = persons.begin(); it != persons.end(); it++) {
                    if ((*it)->getSid() == index) {
                        if (choice == 1)
                        {
                            persons.erase(it);
                            cout << "删除成功" << endl;
                        }
                        else if (choice == 2)
                        {
                            int id;
                            cout << "请输入导师的id" << endl;
                            cin >> id;
                            (*it)->deleteAdvisor(id);
                            cout << "删除成功" << endl;
                        }
                        else { cout << "该学生编号不存在" << endl; }
                        break;
                    }
                   
                }
        }
        else
            cout << "删除失败，当前容器为空" << endl;
    }
    void modifyData()
    {
        StudentManager::outData();
        int index;
          if (!persons.empty())
          {
              cout << "1->修改学生，2->修改学生选择的导师" << endl;
              int choice;
              cin >> choice;
              cout << "请输入操作的学生编号：";
              cin >> index;
               auto it = find_if(persons.begin(), persons.end(), [index](Student* s) {return s->getSid() == index; });
                if (it != persons.end())
                {
                    if (choice == 1) {
                        (*it)->inputData();
                    }
                    else if (choice == 2)
                    {
                        int oid,nid;
                        cout << "请输入旧导师编号" << endl;
                        cin >> oid;
                        cout << "请输入新导师编号" << endl;
                        cin >> nid;
                        (*it)->modifyAdvisor(oid,nid);
                    }
                    else
                        cout << "该学生编号不存在" << endl;
                }
          }
          else
              cout << "修改失败，当前容器为空" << endl;
    }
    void findData()
    {
        if (!persons.empty())
        {
            cout << "1->查找学生，2->查找学生的导师" << endl;
            int choice;
            cin >> choice;
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
                        if (choice == 1)
                        {
                            (*it)->outData();

                        }
                        else if (choice == 2)
                        {
                            (*it)->printAdvisor();
                        }
                        else
                            cout << "输入类型错误" << endl;
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

                        if (choice == 1)
                        {
                            (*it)->outData();

                        }
                        else if (choice == 2)
                        {
                            (*it)->printAdvisor();
                        }
                        else
                            cout << "输入类型错误" << endl;
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
            cout << "教师：" << t->getName() << "管理的学生信息如下" << endl;
            t->printStudent();
        }
    }
    void deleteData() {
        TeacherManager::outData();
        if (!persons.empty())
        {
            cout << "1->删除教师，2->删除教师管理的学生" << endl;
            int choice;
            cin >> choice;
            int index;
            cout << "请输入要操作的教师编号：";
            cin >> index;
            for (auto it = persons.begin(); it != persons.end(); it++) {
                if ((*it)->getTid() == index) {
                    if (choice == 1)
                    {
                        persons.erase(it);
                        cout << "删除成功" << endl;
                      
                    }
                    else if (choice == 2)
                    {
                        int id;
                        cout << "请输入要删除学生的编号" << endl;
                        cin >> id;
                        (*it)->deleteStudent(id);
                        cout << "删除成功" << endl;
                    }
                    else
                        cout << "输入类型错误" << endl;
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
            cout << "1->修改教师，2->修改教师管理的学生" << endl;
            int choice;
            cin >> choice;
            int index;
            cout << "请输入要修改的教师编号：";
            cin >> index;
            bool found = false;
            for (auto it = persons.begin(); it != persons.end(); it++)
            {
                if ((*it)->getTid() == index)
                {
                    found = true;
                    if (choice == 1)
                    {
                        (*it)->inputData();
                        break;
                    }
                    else if (choice == 2)
                    {
                        int oid, nid;
                        cout << "请输入旧学生id" << endl;
                        cin >> oid;
                        cout << "请输入新学生id" << endl;
                        cin >> nid;
                        (*it)->modifyStudent(oid, nid);
                        break;
                    }
                    else
                        cout << "输入类型错误" << endl;
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
            int select ;
            promp();
            cin >> select;
            if (select == 1)
            {
                cout << "1->查找教师，2->查找教师管理的学生" << endl;
                int choice;
                cin >> choice;
                int tid;
                cout << "请输入要查找的教师编号：";
                cin >> tid;
                bool found = false;
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    if ((*it)->getTid() == tid)
                    {
                        if (choice == 1)
                        {
                            (*it)->outData();
                        }
                        else if (choice == 2)
                        {
                            int id;
                            cout << "请输入想要查找的学生的id" << endl;
                            cin >> id;
                            (*it)->findStudent(id);
                        }
                        else
                            cout << "输入类型错误" << endl;
                        found = true;
                        return;
                    }
                }
                if (!found)
                    cout << "该教师编号不存在！" << endl;
            }
            else if (select == 2)
            {
                cout << "1->查找教师，2->查找教师管理的学生" << endl;
                int choice;
                cin >> choice;
                string name;
                cout << "请输入姓名：" << endl;
                cin >> name;
                bool found = false;
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    if (choice == 1)
                    {
                        (*it)->outData();
                    }
                    else if (choice == 2)
                    {
                        int id;
                        cout << "请输入想要查找的学生的id" << endl;
                        cin >> id;
                        (*it)->findStudent(id);
                    }
                    else
                        cout << "输入类型错误" << endl;
                    found = true;
                    return;
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
        if(!persons.empty())
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

class DeanManager :public TeacherManager
{
public:
    DeanManager() :TeacherManager() {}
    ~DeanManager() {
        for (auto d : persons){ delete d;}
    }
    void inputData() {
        try {
            int number;
            cout << "请输入系主任的数量:" << endl;
            cin >> number;
            if (cin.fail())
                throw"输入类型错误";
            else {
                for (int i = 0; i < number; i++) {
                    Dean* d = new Dean();
                    d->inputData();
                    persons.push_back(d);
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
    void outData() { PersonManager::outData(); }
    void deleteData() { TeacherManager::deleteData(); }
    void modifyData(){ TeacherManager::modifyData();}
    void findData(){ TeacherManager::findData();}
    void sortData() {TeacherManager::sortData(); }
};
class ChancellorManager :public TeacherManager
{
public:
    ChancellorManager() :TeacherManager() {}
    ~ChancellorManager()
    {for (auto c : persons){ delete c;}}
    void inputData() {
        try {
            int number;
            cout << "请输入院长的数量:" << endl;
            cin >> number;
            if (cin.fail())
                throw"输入类型错误";
            else {
                for (int i = 0; i < number; i++) {
                    Chancellor* t = new Chancellor();
                    t->inputData();
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
    void outData() { PersonManager::outData(); }
    void deleteData() { TeacherManager::deleteData(); }
    void modifyData() { TeacherManager::modifyData(); }
    void findData() { TeacherManager::findData(); }
    void sortData() { TeacherManager::sortData(); }
};
class TeacherStudentManager {
public:
    TeacherStudentManager() {}
    void inputData() {
        string type;
        cout << "请输入要添加的类型（1：教师，2：学生,3：系主任，4：院长）：";
        cin >> type;
        if (type == "1") 
        { teacherManager.inputData(); }
        else if (type == "2") 
        {studentManager.inputData();}
        else if (type == "3")
        { deanManager.inputData(); }
        else if (type == "4")
        { chancellorManager.inputData(); }
        else
            cout << "输入类型错误！" << endl;
    }
    void outData() {
        string type;
        cout << "请输入要输出的类型（1：教师，2：学生,3：系主任，4：院长，5：全部输出）：";
        cin >> type;
        if (type == "1") 
        {teacherManager.outData();}
        else if (type == "2")
        {studentManager.outData();}
        else if (type == "3")
        {deanManager.outData();}
        else if (type == "4")
        {chancellorManager.outData();}
        else if (type == "5")
        {
            teacherManager.outData();
            studentManager.outData();
            deanManager.outData();
            chancellorManager.outData();
        }
        else 
            cout << "输入类型错误！" << endl;
    }
    void deleteData() {
        string type;
        cout << "请输入要删除的类型（1：教师，2：学生,3：系主任，4：院长）：";
        cin >> type;
        if (type == "1") 
        { teacherManager.deleteData();}
        else if (type == "2") 
        {studentManager.deleteData();}
        else if (type == "3")
        {deanManager.deleteData();}
        else if (type == "4")
        { chancellorManager.deleteData(); }
        else
            cout << "输入类型错误！" << endl;
    }
   void findData()
    {
        string type;
        cout << "请输入要查找的类型（1：教师，2：学生,3：系主任，4：院长）：";
        cin >> type;
        if (type == "1") 
        {teacherManager.findData();}
        else if (type == "2") 
        { studentManager.findData(); }
        else if (type == "3")
        {deanManager.findData();  }
        else if (type == "4")
        {chancellorManager.findData();}
        else 
            cout << "输入类型错误！" << endl;
    }

    void modifyData()
    {
        string type;
        cout << "请输入要修改的类型（1：教师，2：学生,3：系主任，4：院长）：";
        cin >> type;
        if (type == "1")
        { teacherManager.modifyData();}
        else if (type == "2") 
        {studentManager.modifyData();}
        else if (type == "3")
        {deanManager.modifyData();}
        else if (type == "4")
        {chancellorManager.modifyData();}
        else 
            cout << "输入类型错误！" << endl;
    }

    void sortData() {
        string type;
        cout << "请输入要排序的类型（1：教师，2：学生,3：系主任，4：院长）：";
        cin >> type;
        if (type == "1")
        {teacherManager.sortData(); }
        else if (type == "2")
        { studentManager.sortData();}
        else if (type == "3")
        { deanManager.sortData();}
        else if (type == "4")
        {chancellorManager.sortData();}
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
    DeanManager deanManager;
    ChancellorManager chancellorManager;
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