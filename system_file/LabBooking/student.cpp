#include "student.h"


Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	this->s_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
	//机房容器初始化
	ifstream ifs;
	ifs.open(LAB_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！！！" << endl;
		return;
	}
	while (ifs >> id && ifs >> name)
	{
		vl.push_back(Lab(id, name));
	}
	ifs.close();

	o = new Order;
}
void Student::sub_menu()//子菜单
{
	cout << endl;
	cout << "\t\t\t ---------------------------------- " << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            1、申请预约           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            2、查看自身预约       |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            3、取消预约           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            0、注销登录           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t----------------------------------- " << endl;
	cout << endl;
}
void Student::apply_order()//申请预约
{
	cout << "实验室开放时间为每周一到周五" << endl;
	cout << "1、周一 " << endl;
	cout << "2、周二 " << endl;
	cout << "3、周三 " << endl;
	cout << "4、周四 " << endl;
	cout << "5、周五 " << endl;

	int data;//周几
	int time_interval;//时间段
	int lab_id;//机房编号
	while (1)
	{
		cout << "您想预约到周几？" << endl;
		cin >> data;
		if (data <= 5 && data >= 1)
		{
			break;
		}
		cout << "请重新选择" << endl;
	}
	cout << "您预约的时间段？" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (1)
	{
		
		cin >> time_interval;
		if (time_interval == 1 || time_interval == 2)
		{
			break;
		}
		cout << "请重新选择" << endl;
	}
	cout << "实验室信息如下：" << endl << endl;
	cout << "实验室编号 " << "\t" << "实验室名称" << endl;
	for (vector<Lab>::iterator it = vl.begin(); it != vl.end(); it++)
	{
		cout << "   " << it->l_id << "\t\t" << it->l_name << endl;
	}
	cout << endl;
	while (1)
	{
		cout << "您预约的实验室？" << endl;
		cin >> lab_id;
		int find = 0;
		for (vector<Lab>::iterator it = vl.begin(); it != vl.end(); it++)
		{
			if (lab_id == it->l_id) {
				find = 1;
			}
		}
		if (find) {
			break;
		}
		cout << "请重新选择" << endl;
	}
	/*ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "data:" << data << " ";
	ofs << "time_interval:" << time_interval << " ";
	ofs << "lab_id:" << lab_id << " ";
	ofs << "stu_id:" << s_id << " ";
	ofs << "stu_name:" << this->m_name << " ";
	ofs << "status:" << "1" << endl;*/

	map<string, string> temp;
	temp.insert(pair<string, string>("data", to_string(data)));
	temp.insert(pair<string, string>("time_interval", to_string(time_interval)));
	temp.insert(pair<string, string>("lab_id", to_string(lab_id)));
	temp.insert(pair<string, string>("stu_id",to_string(s_id)));
	temp.insert(pair<string, string>("stu_name", this->m_name));
	temp.insert(pair<string, string>("status", "1"));
	o->m.insert(pair<int, map<string, string>>(o->m_size, temp));
	o->m_size++;
	o->updata();
	//o->init_map();
	cout << "申请成功，审核中！" << endl;


}
void Student::self_order()//查看自己的预约
{

	string tmp;
	tmp = to_string(this->s_id);
	
	cout << " 序号 " << "\t" << " 日期 " << "\t" << " 时间段 " << "\t" << " 实验室 " << "\t" << " 学号 " << "\t" << " 姓名 " << "\t" << " 状态 " << endl;
	for (map<int, map<string, string>>::iterator it = o->m.begin(); it != o->m.end(); it++)
	{
		if (it->second["stu_id"] == tmp)
		{
			
			cout << "  " << it->first << " \t";
			if ((it->second["data"]) == "1")
			{
				cout << " 周一 " << "\t";
			}
			else if ((it->second["data"]) == "2")
			{
				cout << " 周二 " << "\t";
			}
			else if ((it->second["data"]) == "3")
			{
				cout << " 周三 " << "\t";
			}
			else if ((it->second["data"]) == "4")
			{
				cout << " 周四 " << "\t";
			}
			else
			{
				cout << " 周五 " << "\t";
			}
			if ((it->second["time_interval"]) == "1")
			{
				cout << " 上午 " << "\t\t";
			}
			else
			{
				cout << " 下午 " << "\t\t";
			}

			for (vector<Lab>::iterator itv = vl.begin(); itv != vl.end(); itv++)
			{
				if ((it->second["lab_id"]) == to_string(itv->l_id))
				{
					cout << " " << itv->l_name << " " << "\t ";
				}
			}

			// if ((it->second["lab_id"]) == "1")
			// {
			// 	cout << " 物理实验室 " << "\t ";
			// }
			// else if ((it->second["lab_id"]) == "2")
			// {
			// 	cout << " 化学实验室 " << "\t ";
			// }
			// else if ((it->second["lab_id"]) == "3")
			// {
			// 	cout << " 生物实验室 " << "\t ";
			// }

			cout << " " << it->second["stu_id"] << " \t";
			cout << " " << it->second["stu_name"] << " \t";

			if ((it->second["status"]) == "1")
			{
				cout << " 审核中 " << endl;
			}
			else if ((it->second["status"]) == "2")
			{
				cout << " 审核已通过 " << endl;
			}
			else if ((it->second["status"]) == "3")
			{
				cout << " 审核未通过 " << endl;
			}
			else
			{
				cout << " 已取消 " << endl;
			}
			
		}
	}

}

void Student::cancel_order()//取消预约
{
	cout << "========您可以取消审核中或者审核已通过的预约======" << endl << endl;

	cout << "可以取消的预约如下：" << endl;

	string tmp;
	tmp = to_string(this->s_id);
	vector<int> vc;
	cout << " 序号 " << "\t" << " 日期 " << "\t" << " 时间段 " << "\t" << " 实验室 " << "\t" << " 学号 " << "\t" << "   姓名   " << "\t" << "   状态   " << endl;
	for (map<int, map<string, string>>::iterator it = o->m.begin(); it != o->m.end(); it++)
	{
		if ((it->second["stu_id"] == tmp) && ( (it->second["status"] == "1") || (it->second["status"] == "2")))
		{
			vc.push_back(it->first);
			cout << "  " << it->first << "\t";
			if ((it->second["data"]) == "1")
			{
				cout << " 周一 " << "\t";
			}
			else if ((it->second["data"]) == "2")
			{
				cout << " 周二 " << "\t";
			}
			else if ((it->second["data"]) == "3")
			{
				cout << " 周三 " << "\t";
			}
			else if ((it->second["data"]) == "4")
			{
				cout << " 周四 " << "\t";
			}
			else
			{
				cout << " 周五 " << "\t";
			}
			if ((it->second["time_interval"]) == "1")
			{
				cout << " 上午 " << "\t\t";
			}
			else
			{
				cout << " 下午 " << "\t\t";
			}

			if ((it->second["lab_id"]) == "1")
			{
				cout << "物理实验室" << "\t ";
			}
			else if ((it->second["lab_id"]) == "2")
			{
				cout << "化学实验室" << "\t ";
			}
			else if ((it->second["lab_id"]) == "3")
			{
				cout << "生物实验室" << "\t ";
			}

			cout << it->second["stu_id"] << "\t";
			cout << it->second["stu_name"] << "\t";

			if ((it->second["status"]) == "1")
			{
				cout << " 审核中 " << endl;
			}
			else if ((it->second["status"]) == "2")
			{
				cout << "审核已通过" << endl;
			}
			
		}
	}
	if (vc.size() == 0)
	{
		cout << "您没有可以取消的预约" << endl;
		
		
		return;
	}
	cout << "请选择要取消预约的序号：";
	int opt = -1;
	cin >> opt;
	cout << "是否取消" << opt << "号预约 ?" << endl;
	int selct = 0;
	cout << "   1、是     0、否   " << endl;
	cin >> selct;
	if (selct == 0)
	{
		
		
		return;
	}
	else {
		vector<int>::iterator vit = vc.begin();
		for (; vit != vc.end(); vit++)
		{
			if (*vit == opt)
			{
				break;
			}
		}
		if (vit == vc.end())
		{
			cout << "输入有误，以为您取消操作" << endl;
			
			
			return;
		}
		map<int,map<string,string>>::iterator it = o->m.find(opt);
		it->second["status"] = "4";
		o->updata();
		cout << "取消成功" << endl;
		
		
	}
}

Student::~Student()
{
	delete o;
}