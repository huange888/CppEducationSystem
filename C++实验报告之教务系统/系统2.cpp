//#include<iostream>
//#include<string>
//#include <vector>
//#include <algorithm>
//#include"Student_Teacher.h"
//using namespace std;
//
//int main()
//{
//    TeacherStudentManager t3;
//    try
//    {
//
//        while (true)
//        {
//            int choice;
//            t3.Show_Menu();
//            cout << "请输入您的选择：" << endl;
//            cin >> choice;
//            if (cin.fail())
//                throw "程序即将退出";
//            switch (choice)
//            {
//            case 0:
//                t3.ExitSystem();
//                break;
//            case 1:
//                t3.inputData();
//                break;
//            case 2:
//                t3.outData();
//                break;
//            case 3:
//                t3.deleteData();
//                break;
//            case 4:
//                t3.modifyData();
//                break;
//            case 5:
//                t3.findData();
//                break;
//            case 6:
//                t3.sortData();
//                break;
//            default:
//                system("cls");//清屏
//                break;
//            }
//        }
//    }
//    catch (const char* msg)
//    {
//        cout << msg << endl;
//        system("pause");
//        exit(1);
//    }
//
//}