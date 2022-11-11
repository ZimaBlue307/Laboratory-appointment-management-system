#include "Manager.h"

Manager::Manager()
{
	init_vector();
}
Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;
	init_vector();
	//print();

}
void print_student(student_info &s)
{
	cout << " 学号  " << s.s_id << "  姓名  " << s.m_name << "  密码  " << s.m_pwd << endl;
}
void print_teacher(teacher_info &t)
{
	cout << " 职工号  " << t.t_id << "  姓名  " << t.m_name << "  密码  " << t.m_pwd << endl;
}
void Manager::sub_menu()//子菜单
{	
	cout << endl;
	cout << "\t\t\t ---------------------------------- " << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            1、添加账号           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            2、查看账号           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            3、添加实验室         |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            4、查看实验室         |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            5、清空预约           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            0、注销登录           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t----------------------------------- " << endl;
	cout << endl;
}
void Manager::add_account()//添加账号
{

	cout << "当前学生人数：" << vs.size() << endl;
	cout << "当前老师人数：" << vt.size() << endl;

	cout << "1、学生账号" << endl;
	cout << "2、教师账号" << endl;
	int opt = -1;
	cout << "请输入选项：";
	cin >> opt;
	string filename;
	string temp;
	if (opt == 1)
	{
		filename = STUDENT_FILE;
		temp = "请输入学号：";
	}
	else {
		filename = TEACHER_FILE;
		temp = "请输入职工号：";
	}
	int id;
	string name;
	string pwd;
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	while (1)
	{
		cout << temp;
		cin >> id;
		if (!check(id, opt))
		{
			break;
		}
	}
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;
	ofs << id << "\t" << name << "\t" << pwd << endl;
	ofs.close();
	cout << "添加成功" << endl;
	if (opt == 1)
	{
		student_info ns;
		ns.s_id = id;
		ns.m_name = name;
		ns.m_pwd = pwd;
		vs.push_back(ns);
	}
	else
	{
		teacher_info nt;
		nt.t_id = id;
		nt.m_name = name;
		nt.m_pwd = pwd;
		vt.push_back(nt);
	}
}
void Manager::show_account()//查看所有账户
{
	cout << "1、查看所有学生账号" << endl;
	cout << "2、查看所有老师账号" << endl;
	int opt = -1;
	cout << "请输入选项：" << endl;
	cin >> opt;

	if (opt == 1)
	{
		cout << "所有学生信息如下：" << endl<<endl;
		for_each(vs.begin(), vs.end(), print_student);
	}
	else
	{
		cout << "所有教师信息如下：" << endl << endl;;
		for_each(vt.begin(), vt.end(), print_teacher);
	}

}
void Manager::show_lab()//查看实验室
{
	cout << "实验室信息如下：" << endl << endl;
	cout << "实验室编号 " << "\t" << "实验室名称" << endl;
	for (vector<lab_info>::iterator it = vl.begin(); it != vl.end(); it++)
	{
		cout << "   " << it->id << "\t\t" << it->name << endl;
	}
	cout << endl;

}

void Manager::add_lab()//添加实验室
{
	string filename;
	string temp;
	filename = LAB_FILE;
	int id;
	string name;
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	while (1)
	{
		cout << "请输入实验室编号：";
		cin >> id;
		if (!check(id, 3))
		{
			break;
		}
	}
	cout << "请输入实验室名称：";
	cin >> name;
	ofs << id << "\t" << name  << endl;
	ofs.close();
	cout << "添加成功" << endl;
	lab_info l;
	l.id = id;
	l.name = name;
	vl.push_back(l);
}

void Manager::clear_order()//清空预约
{
	cout << "确定清空所有预约吗？" << endl;
	cout << "清空之后不可恢复！" << endl;
	cout << "    1、是      2、否      " << endl;
	int opt = 0;
	cin >> opt;
	if (opt == 1)
	{
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::trunc);
		ofs.close();
		cout << "清空完成" << endl << endl;
	}

}
Manager::~Manager()
{
}
void Manager::init_vector()
{
	this->vs.clear();//学生
	this->vt.clear();//老师
	
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！！！" << endl;
		return;
	}


	student_info s;
	
	while (ifs >> s.s_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{	
		vs.push_back(s);
	}
	ifs.close();
	
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！！！" << endl;
		return;
	}
	teacher_info t;

	while (ifs >> t.t_id && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vt.push_back(t);
	}
	ifs.close();

	ifs.open(LAB_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！！！" << endl;
		return;
	}

	lab_info l;

	while (ifs >> l.id && ifs >> l.name)
	{
		vl.push_back(l);
	}
	ifs.close();

}
bool Manager::check(int id,int flag)
{
	if (flag == 1)
	{
		for (vector<student_info>::iterator it = vs.begin(); it != vs.end(); it++)
		{
			if (it->s_id == id)
			{
				cout << "学号重复,请重新输入" << endl;
				return true;
			}
		}
	}
	else if (flag == 2)
	{
		for (vector<teacher_info>::iterator it = vt.begin(); it != vt.end(); it++)
		{
			if (it->t_id == id)
			{
				cout << "职工号重复，请重新输入" << endl;
				return true;
			}
		}
	}
	else {
		for (vector<lab_info>::iterator it = vl.begin(); it != vl.end(); it++)
		{
			if (it->id == to_string(id))
			{
				cout << "实验室编号重复，请重新输入" << endl;
				return true;
			}
		}
	}
	return false;
}