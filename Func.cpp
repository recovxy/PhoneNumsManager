#include "Func.h"

void showMenu(){
    cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(Addressbooks *abs)
{
	//判断电话本是否满了
	if (abs->size_ == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->size_].name_ = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size_].sex_ = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->size_].age_ = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[abs->size_].phone_ = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->size_].addr_ = address;

		//更新通讯录人数
		abs->size_++;

		cout << "添加成功" << endl;
        cout << "请继续操作..." << endl;
	}
}

void showPerson(const Addressbooks * abs)
{
	if (abs->size_ == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size_; i++)
		{
			cout << "姓名：" << abs->personArray[i].name_ << "\t";
			cout << "性别：" << (abs->personArray[i].sex_ == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].age_ << "\t";
			cout << "电话：" << abs->personArray[i].phone_ << "\t";
			cout << "住址：" << abs->personArray[i].addr_ << endl;
		}
	}
}

int isExist(const Addressbooks*abs, string name){
    for (int i = 0; i < abs->size_; i++)
	{
		if (abs->personArray[i].name_ == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks*abs){
    cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

    int ret = isExist(abs, name);
    if(ret != -1){
        for (int i = ret; i < abs->size_; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
        abs->size_--;
		cout << "删除成功" << endl;
    }else{
        cout << "查无此人" << endl;
    }
}


void findPerson(Addressbooks * abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].name_ << "\t";
		cout << "性别：" << abs->personArray[ret].sex_ << "\t";
		cout << "年龄：" << abs->personArray[ret].addr_ << "\t";
		cout << "电话：" << abs->personArray[ret].phone_ << "\t";
		cout << "住址：" << abs->personArray[ret].addr_<< endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}

void modifyPerson(Addressbooks * abs){
    cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

    int ret  =  isExist(abs, name);
    if (ret != -1){
        cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].name_ = name;

        cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

        		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].sex_ = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].addr_ = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].phone_ = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].addr_ = address;

		cout << "修改成功" << endl;
    }else{
		cout << "查无此人" << endl;
	}
}

void cleanPerson(Addressbooks * abs){
    abs->size_ = 0;
    cout << "通讯录已清空" << endl;
}