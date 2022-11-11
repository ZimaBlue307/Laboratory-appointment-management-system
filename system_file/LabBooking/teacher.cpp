#include "teacher.h"

Teacher::Teacher()
{

}
Teacher::Teacher(int id, string name, string pwd)
{
	this->t_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
	o = new Order;
}
void Teacher::sub_menu()//子菜单
{
	cout << endl;
	cout << "\t\t\t ---------------------------------- " << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            1、查看所有预约       |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            2、审核预约           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t|            0、注销登录           |" << endl;
	cout << "\t\t\t|                                  |" << endl;
	cout << "\t\t\t----------------------------------- " << endl;
	cout << endl;
}
void Teacher::all_order()//查看所有预约
{
	cout << " 序号 " << "\t" << " 日期 " << "\t" << " 时间段 " << "\t" << " 实验室 " << "\t" << " 学号 " << "\t" << "   姓名   " << "\t" << "   状态   " << endl;
	for (map<int, map<string, string>>::iterator it = o->m.begin(); it != o->m.end(); it++)
	{
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
		else if ((it->second["status"]) == "3")
		{
			cout << "审核未通过" << endl;
		}
		else
		{
			cout << " 已取消 " << endl;
		}


	}

}
void Teacher::audit_order()//审核预约
{
	while (1)
	{
		this->work_order();
		if (vc.size() == 0)
		{
			cout << "您没有需要审核的预约" << endl;
			
			
			return;
		}
		
		cout << "请选择要审核预约的序号：";
		int opt = -1;
		cin >> opt;
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
			cout << "输入有误，请重新选择" << endl;
			
			
			continue;
		}
		int ret = check(opt);
		if (ret == 1)
		{
			cout << "在这条记录之后有条重复记录!!!" << endl;
		}
		else if(ret == -1)
		{
			cout << "在这条记录之前有条重复记录!!!" << endl;
		}
		int selct = 0;
		cout << "   1、通过     2、不通过   " << endl;

		cin >> selct;
		map<int, map<string, string>>::iterator it = o->m.find(opt);
		if (selct == 1)
		{
			it->second["status"] = "2";
			o->updata();
		}
		else if (selct == 2)
		{
			it->second["status"] = "3";
			o->updata();
		}
		else
		{
			cout << "输入有误，请重新选择" << endl;
			
			
			continue;
		}
		cout << "审核成功" << endl;
		cout << endl;
		
		cout << "   1、继续审核     0、离开   " << endl;
		cin >> selct;
		if (selct != 1)
		{
			break;
		}
	}

}
void Teacher::work_order()
{
	cout << "您需要审核的预约如下：" << endl;
	cout << " 序号 " << "\t" << " 日期 " << "\t" << " 时间段 " << "\t" << " 实验室 " << "\t" << " 学号 " << "\t" << "   姓名   " << "\t" << "   状态   " << endl;
	for (map<int, map<string, string>>::iterator it = o->m.begin(); it != o->m.end(); it++)
	{
		if (it->second["status"] == "1")
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
			else if ((it->second["status"]) == "3")
			{
				cout << "审核未通过" << endl;
			}
			else
			{
				cout << " 已取消 " << endl;
			}

		}
	}
	cout << endl;
}

int Teacher::check(int opt)
{
	map<int, map<string, string>>::iterator _it = o->m.find(opt);
	string _data = _it->second["data"];
	string _lab_id = _it->second["lab_id"];
	string _time_intver = _it->second["time_interval"];
	int tmp = 0;
	for (map<int, map<string, string>>::iterator it = o->m.begin(); it != o->m.end(); it++)
	{
		if (it->second["status"] != "4"|| it->second["status"] != "3")
		{
			if (_data == it->second["data"] && _lab_id == it->second["lab_id"] && _time_intver == it->second["time_interval"])
			{
				tmp = it->first;
				break;
			}
		}
	}
	cout << tmp << endl;
	if (opt < tmp)
	{
		return 1;
	}
	else if (opt > tmp)
	{
		return -1;
	}
	return tmp;
}
Teacher::~Teacher()
{
	delete o;
}
