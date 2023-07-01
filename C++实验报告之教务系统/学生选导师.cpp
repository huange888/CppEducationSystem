//// 完善代码，添加析构函数
//#include <iostream>
//#include <vector>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//class Person {
//public:
//    string name;
//    string id;
//    string gender;
//    int age;
//    Person(string name, string id, string gender, int age) : name(name), id(id), gender(gender), age(age) {}
//    virtual ~Person() {}
//};
//
//class Teacher : public Person {
//public:
//    string title;
//    Teacher(string name, string id, string gender, int age, string title) : Person(name, id, gender, age), title(title) {}
//    ~Teacher() {}
//};
//
//class Student : public Person {
//public:
//    string major;
//    Teacher* advisor;
//    Student(string name, string id, string gender, int age, string major) : Person(name, id, gender, age), major(major) {}
//    ~Student() {}
//};
//
//class DepartmentChair : public Teacher {
//public:
//    DepartmentChair(string name, string id, string gender, int age, string title) : Teacher(name, id, gender, age, title) {}
//    ~DepartmentChair() {}
//};
//
//class Dean : public Teacher {
//public:
//    Dean(string name, string id, string gender, int age, string title) : Teacher(name, id, gender, age, title) {}
//    ~Dean() {}
//};
//
//class Management {
//public:
//    vector<Teacher*> teachers;
//    vector<Student*> students;
//    map<Teacher*, set<Student*>> advisorToStudents;
//    map<Student*, Teacher*> studentToAdvisor;
//    void addTeacher(Teacher* teacher) {
//        teachers.push_back(teacher);
//    }
//    void addStudent(Student* student) {
//        students.push_back(student);
//    }
//    void addAdvisorToStudent(Teacher* advisor, Student* student) {
//        advisorToStudents[advisor].insert(student);
//        studentToAdvisor[student] = advisor;
//    }
//    void removeAdvisorToStudent(Teacher* advisor, Student* student) {
//        advisorToStudents[advisor].erase(student);
//        studentToAdvisor.erase(student);
//    }
//    void printTeachers() {
//        for (auto teacher : teachers) {
//            cout << "Name: " << teacher->name << endl;
//            cout << "ID: " << teacher->id << endl;
//            cout << "Gender: " << teacher->gender << endl;
//            cout << "Age: " << teacher->age << endl;
//            cout << "Title: " << teacher->title << endl;
//            cout << endl;
//        }
//    }
//    void printStudents() {
//        for (auto student : students) {
//            cout << "Name: " << student->name << endl;
//            cout << "ID: " << student->id << endl;
//            cout << "Gender: " << student->gender << endl;
//            cout << "Age: " << student->age << endl;
//            cout << "Major: " << student->major << endl;
//            cout << "Advisor: " << student->advisor->name << endl;
//            cout << endl;
//        }
//    }
//    void printAdvisorToStudents(Teacher* advisor) {
//        cout << "Advisor: " << advisor->name << endl;
//        for (auto student : advisorToStudents[advisor]) {
//            cout << "Name: " << student->name << endl;
//            cout << "ID: " << student->id << endl;
//            cout << "Gender: " << student->gender << endl;
//            cout << "Age: " << student->age << endl;
//            cout << "Major: " << student->major << endl;
//            cout << endl;
//        }
//    }
//    void printStudentToAdvisor(Student* student) {
//        cout << "Student: " << student->name << endl;
//        cout << "Advisor: " << studentToAdvisor[student]->name << endl;
//    }
//    void removeTeacher(Teacher* teacher) {
//        teachers.erase(remove(teachers.begin(), teachers.end(), teacher), teachers.end());
//        for (auto student : advisorToStudents[teacher]) {
//            studentToAdvisor.erase(student);
//        }
//        advisorToStudents.erase(teacher);
//    }
//    void removeStudent(Student* student) {
//        students.erase(remove(students.begin(), students.end(), student), students.end());
//        advisorToStudents[studentToAdvisor[student]].erase(student);
//        studentToAdvisor.erase(student);
//    }
//    ~Management() {
//        for (auto teacher : teachers) {
//            delete teacher;
//        }
//        for (auto student : students) {
//            delete student;
//        }
//    }
//};
//
//
//int main() {
//    Management management;
//    Teacher* teacher1 = new Teacher("John", "001", "Male", 35, "Professor");
//    Teacher* teacher2 = new Teacher("Mary", "002", "Female", 40, "Associate Professor");
//    Teacher* teacher3 = new Teacher("David", "003", "Male", 45, "Assistant Professor");
//    Teacher* teacher4 = new Teacher("Sarah", "004", "Female", 50, "Lecturer");
//    Teacher* teacher5 = new Teacher("Tom", "005", "Male", 55, "Adjunct Professor");
//    management.addTeacher(teacher1);
//    management.addTeacher(teacher2);
//    management.addTeacher(teacher3);
//    management.addTeacher(teacher4);
//    management.addTeacher(teacher5);
//
//    Student* student1 = new Student("Alice", "101", "Female", 20, "Computer Science");
//    Student* student2 = new Student("Bob", "102", "Male", 21, "Mathematics");
//    Student* student3 = new Student("Cathy", "103", "Female", 22, "Physics");
//    Student* student4 = new Student("David", "104", "Male", 23, "Chemistry");
//    Student* student5 = new Student("Emily", "105", "Female", 24, "Biology");
//    management.addStudent(student1);
//    management.addStudent(student2);
//    management.addStudent(student3);
//    management.addStudent(student4);
//    management.addStudent(student5);
//
//    management.addAdvisorToStudent(teacher1, student1);
//    management.addAdvisorToStudent(teacher2, student2);
//    management.addAdvisorToStudent(teacher3, student3);
//    management.addAdvisorToStudent(teacher4, student4);
//    management.addAdvisorToStudent(teacher5, student5);
//
//    management.printTeachers();
//    management.printStudents();
//    management.printAdvisorToStudents(teacher1);
//    management.printStudentToAdvisor(student1);
//    management.printAdvisorToStudents(teacher2);
//    management.printStudentToAdvisor(student2);
//    management.printAdvisorToStudents(teacher3);
//    management.printStudentToAdvisor(student3);
//    management.printAdvisorToStudents(teacher4);
//    management.printStudentToAdvisor(student4);
//    management.printAdvisorToStudents(teacher5);
//    management.printStudentToAdvisor(student5);
//    management.removeAdvisorToStudent(teacher1, student1);
//    management.removeTeacher(teacher1);
//    management.removeStudent(student1);
//
//    return 0;
//}
//
