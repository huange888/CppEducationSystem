//#include<iostream>
//#include<string>
//#include<vector>
//#include<tuple>
//#include<list>
//using namespace std;
//struct Grade
//{
//	string courseName;
//	double grade;
//	Grade(string s,double g):courseName(s),grade(g){}
//};
//typedef tuple<string, int, string, vector<Grade>> Student;
////inputData()函数返回的Student是一种复杂的元组数据类型，该元组保存学生的姓名、学号、专业，以及任意多门课程的成绩
//Student inputData()
//{
//	Student stu;
//	cout << "输入学生数据：姓名，学号，专业" << endl;
//	cin >> get<0>(stu) >> get<1>(stu) >> get<2>(stu);//元组简单元素的访问方法
//	string cName;
//	double score = 0;
//	int i = 1;
//	while (cName!="exit")
//	{
//		cout << "输入第" << i++ << " 科目名称，输入exit结束：\t";
//		cin >> cName;
//		if (cName == "exit")
//			break;
//		cout << "成绩：\t";
//		cin >> score;
//		get<3>(stu).push_back(Grade(cName, score));//向元组向量元素中添加对象
//	}
//	return stu;
//}
//void display(Student student)
//{
//	cout << get<0>(student) << "\t" << get<1>(student) << "\t" << get<2>(student) << "\t" << endl;
//	//for循环示范了访问元组中具有不确定个数的向量元素的访问方法
//	for (int i = 0; i < get<3>(student).size(); i++)
//	{
//		cout << get<3>(student)[i].courseName << "\t" << get<3>(student)[i].grade << endl;
//	}
//}
//int main()
//{
//	auto t = make_tuple("string", 3, 20.01);
//	tuple<const char*, int, double>tt("string", 3, 20.01);
//	tuple<int, int, int>t5{ 1,2,3 };
//	tuple<int, string, const char*>t1, t2{ 1,"数据结构","3.5学分" };
//	t1 = t2;
//	cout << get<0>(t1) << "\t" << get<1>(t1) << "\t" << get<2>(t1) << endl;//元组的访问方法
//	//下面的代码段示例了具用继表、向量元素的元组定义方法，以及元组中的链表访问方法
//	tuple < string, vector<double>, int, list<int>> vtable ("tomoto", { 3,12,2.34 }, 42, { 1,8,9 });
//	list<int>::iterator iter;//访问链表的迭代器
//	for (iter = get<3>(vtable).begin(); iter != get<3>(vtable).end(); iter++)
//	{
//		cout << *iter << "\t";
//
//	}
//	cout << endl;
//	//student对象实例了向元组中的对象赋值的方法
//	Student student{ "李四",1001,"计算机专业",{{"英语",76.4},{"高数",87},{"c++语言",89}} };
//	display(student);
//	student = inputData();
//	cout << endl;
//	display(student);
//	system("pause");
//	return 0;
//}