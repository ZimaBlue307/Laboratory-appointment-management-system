#include "work.h"

void Work::show_root_menu()
{
	cout << "==================================欢迎使用实验室预约系统==================================" << endl;
	cout << endl;
	cout << "\t\t\t ---------------------------------- " << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            1、学生登录           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            2、教师登录           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            3、管理员登录         |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            0、退出系统           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t----------------------------------- " << endl;
	cout << endl;
}

void Work::login(string filename, int flag)
{
	Identity * father = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//保存登录输入的信息
	int id = 0;
	string name;
	string pwd;
	if (flag == 1)
	{
		cout << "请输入学号：";
		cin >> id;
	}
	else if (flag == 2)
	{
		cout << "请输入职工号：";
		cin >> id;
	}
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;

	int fid;
	string fname;
	string fpwd;
	if (flag == 1)
	{
		//学生
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{

			//cout << fid << "  " << fname << "  " << fpwd << endl;
			if (fid == id && fname == name && fpwd == pwd)
			{

				father = new Student(id, name, pwd);
				cout << "登录成功" << endl;
				ifs.close();
				
				
				
				this->student_work(father);
				return;
			}
		}
	}
	else if (flag == 2)
	{
		//老师
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				father = new Teacher(id, name, pwd);
				cout << "登录成功" << endl;
				ifs.close();
				
				
				
				this->teacher_work(father);
				return;
			}
		}
	}
	else {
		//管理员
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				father = new Manager(name, pwd);
				cout << "登录成功" << endl;
				ifs.close();
				
				
				this->manager_work(father);				
				return;
			}
		}
	}

	cout << "登录失败！" << endl;

	return;

}
void Work::dowork()
{
	int opt = -1;
	while (true)
	{
		show_root_menu();
		cout << "请输入您的选择：";
		cin >> opt;
		switch (opt)
		{
		case 1://学生
		{
			login(STUDENT_FILE, 1);
			break;
		}
		case 2://教师
		{
			login(TEACHER_FILE, 2);
			break;
		}
		case 3://管理员
		{
			login(ADMIN_FILE, 3);
			break;
		}
		case 0://退出
		{
			cout << "感谢您的使用" << endl;
			
			
			exit(0);
			break;
		}
		default:
			cout << "输入有误，请重新输入" << endl;
			
			
			break;
		}
	}
}

void Work::manager_work(Identity*manager)
{
	Manager*m = (Manager*)manager;
	//m->init_vector();
	cout << "==================================欢迎管理员 " << m->m_name << " 登录==================================" << endl;
	int opt = -1;
	while (1)
	{
		m->sub_menu();
		cout << "请输入选项：";
		cin >> opt;
		switch (opt)
		{
		case 1://添加账号
		{
			m->add_account();
			break;
		}
		case 2://查看账号
		{
			m->show_account();
			break;
		}
		case 3://添加实验室信息
		{
			m->add_lab();
			break;
		}
		case 4://查看实验室信息
		{
			m->show_lab();
			break;
		}
		case 5://清空预约
		{
			m->clear_order();
			break;
		}
		case 0:
		{
			cout << "注销成功" << endl;
			delete m;
			
			
			return;
		}
		default:
			cout << "请重新输入" << endl;
			
			
			break;
		}

	}
	
}

void Work::student_work(Identity*student)
{
	Student*s = (Student*)student;
	cout << "==================================欢迎学生 " << s->m_name << " 登录==================================" << endl;
	int opt = -1;
	while (1)
	{
		s->sub_menu();
		cout << "请输入选项：";
		cin >> opt;
		switch (opt)
		{
		case 1://申请预约
		{
			s->apply_order();
			break;
		}
		case 2://查看自身预约
		{
			s->self_order();
			break;
		}
		case 3://取消预约
		{
			s->cancel_order();
			break;
		}
		case 0:
		{
			cout << "注销成功" << endl;
			delete s;
			
			
			return;
		}
		default:
			cout << "请重新输入" << endl;
			
			
			break;
		}

	}

}
void Work::teacher_work(Identity*teacher)
{
	Teacher* t =(Teacher *)teacher;
	cout << "==================================欢迎老师 " << t->m_name << " 登录==================================" << endl;
	int opt = -1;
	while (1)
	{
		t->sub_menu();
		cout << "请输入选项：";
		cin >> opt;
		switch (opt)
		{
		case 1://查看所有预约
		{
			t->all_order();
			break;
		}
		case 2://审核预约
		{
			t->audit_order();
			break;
		}
		case 0:
		{
			cout << "注销成功" << endl;
			delete t;
			
			
			return;
		}
		default:
			cout << "请重新输入" << endl;
			
			
			break;
		}

	}

}