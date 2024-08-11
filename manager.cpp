//
// Created by Quagmire on 2024/8/10.
//
#include <fstream>
#include <algorithm>
#include "manager.h"
#include "globalFile.h"
#include "computerRoom.h"

//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{   //初始化管理员信息
    this->m_Name=name;
    this->m_Pwd=pwd;
    //初始化容器，获取所有文件学生和老师信息
    this->initVector();

    //获取机房信息
    ifstream ifs;

    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
    {
        vCom.push_back(c);
    }
    cout << "当前机房数量为： " << vCom.size() << endl;

    ifs.close();

}

//选择菜单
void Manager::operMenu()
{
    cout << "欢迎管理员："<<this->m_Name << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.添加账号              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看账号              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.增加机房              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.删除机房              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          5.修改机房              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          6.查看机房              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          7.清空预约              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

//添加账号
void Manager::addPerson()
{
    cout << "请输入添加账号的类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName;
    string tip;

    //string errorTip;//重复错误提示
    int id;

    int select = 0;
    cin >> select;

    string name;
    string pwd;
    cout <<tip << endl;
    if (select == 1)
    {
        fileName = STUDENT_FILE;
        tip = "请输入学号： ";
        cout<<tip;
        while(true){
            cin >> id;
            bool ret =  checkRepeat(id,select);
            if (ret){
                cout<<"学号重复，请重新输入"<<endl;
            } else{
                break;
            }
        }
        cout << "请输入姓名： " << endl;
        cin >> name;

        cout << "请输入密码： " << endl;
        cin >> pwd;
        //向文件添加数据
        ofstream ofs;
        ofs.open(fileName, ios::out | ios::app);
        ofs << id << " " << name << " " << pwd << " " << endl;

        cout << "添加成功" << endl;
        ofs.close();
        //重新获取文件中数据
        this->initVector();
    }
    else if(select == 2)
    {
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
        cout<<tip;
        while(true){
            cin >> id;
            bool ret =  checkRepeat(id,select);
            if (ret){
                cout<<"编号重复，请重新输入"<<endl;
            } else{
                break;
            }
        }
        cout << "请输入姓名： " << endl;
        cin >> name;

        cout << "请输入密码： " << endl;
        cin >> pwd;
        //向文件添加数据
        ofstream ofs;
        ofs.open(fileName, ios::out | ios::app);
        ofs << id << " " << name << " " << pwd << " " << endl;
        cout << "添加成功" << endl;
        ofs.close();
        //重新获取文件中数据
        this->initVector();
    } else{
        cout<<"输入有误，请重新输入"<<endl;
    }

    system("pause");
    system("cls");



}

//查看账号
void printStudent(Student & s)
{
    cout << "学号： " << s.m_Id << " 姓名： " << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher & t)
{
    cout << "职工号： " << t.m_EmpId << " 姓名： " << t.m_Name << " 密码：" << t.m_Pwd << endl;
}

void Manager::showPerson()
{
    cout << "请选择查看内容：" << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;

    int select = 0;

    cin >> select;

    if (select == 1)
    {
        cout << "所有学生信息如下： " << endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    }
    else
    {
        cout << "所有老师信息如下： " << endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }
    system("pause");
    system("cls");
}
//增加机房信息
void Manager::addComputerRoom()
{
    int id, maxNum;
    cout << "请输入机房编号：";
    cin >> id;
    cout << "请输入机房最大容量：";
    cin >> maxNum;

    ComputerRoom newRoom;
    newRoom.m_ComId = id;
    newRoom.m_MaxNum = maxNum;

    vCom.push_back(newRoom);
    // 写入文件
    ofstream ofs(COMPUTER_FILE, ios::app); // 追加模式写入
    ofs << id << " " << maxNum << endl;
    ofs.close();

    cout << "机房信息添加成功！" << endl;
    system("pause");
    system("cls");
}
//删除机房信息
void Manager::deleteComputerRoom()
{
    int id;
    cout << "请输入要删除的机房编号：";
    cin >> id;

    bool found = false;
    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); ++it)
    {
        if (it->m_ComId == id)
        {
            vCom.erase(it);
            found = true;
            break;
        }
    }

    if (found)
    {
        // 重新写入文件，覆盖原文件内容
        ofstream ofs(COMPUTER_FILE, ios::trunc);
        for (const auto& room : vCom)
        {
            ofs << room.m_ComId << " " << room.m_MaxNum << endl;
        }
        ofs.close();

        cout << "机房编号 " << id << " 的信息删除成功！" << endl;
    }
    else
    {
        cout << "未找到编号为 " << id << " 的机房信息。" << endl;
    }

    system("pause");
    system("cls");
}
//修改机房信息
void Manager::editComputerRoom()
{
    int id;
    cout << "请输入要修改的机房编号：";
    cin >> id;

    bool found = false;
    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); ++it)
    {
        if (it->m_ComId == id)
        {
            cout << "当前机房容量为： " << it->m_MaxNum << endl;
            cout << "请输入新的机房容量：";
            cin >> it->m_MaxNum;
            found = true;
            break;
        }
    }

    if (found)
    {
        // 重新写入文件，覆盖原文件内容
        ofstream ofs(COMPUTER_FILE, ios::trunc);
        for (const auto& room : vCom)
        {
            ofs << room.m_ComId << " " << room.m_MaxNum << endl;
        }
        ofs.close();

        cout << "机房编号 " << id << " 的信息修改成功！" << endl;
    }
    else
    {
        cout << "未找到编号为 " << id << " 的机房信息。" << endl;
    }

    system("pause");
    system("cls");
}

//查看机房信息
void Manager::showComputer()
{
    cout << "机房信息如下： " << endl;
    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
    {
        cout << "机房编号： " << it->m_ComId << " 机房最大容量： " << it->m_MaxNum << endl;
    }
    system("pause");
    system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "清空成功！" << endl;
    system("pause");
    system("cls");
}

//初始化容器
void Manager::initVector() {
    //确保容器清空状态
    vStu.clear();
    vTea.clear();

    //读取信息，学生
    ifstream  ifs;
    ifs.open(STUDENT_FILE,ios::in);
    if (!ifs.is_open()){
        cout<<"文件读取失败"<<endl;
        return;
    }
    Student s;
    while(ifs>>s.m_Id&&ifs>>s.m_Name&&ifs>>s.m_Pwd){
        vStu.push_back(s);
    }
    cout<<"当前学生数量为："<<vStu.size()<<endl;
    //读取信息，老师
    ifs.open(TEACHER_FILE,ios::in);
    if (!ifs.is_open()){
        cout<<"文件读取失败"<<endl;
        return;
    }
    Teacher t;
    while(ifs>>t.m_EmpId&&ifs>>t.m_Name&&ifs>>t.m_Pwd){
        vTea.push_back(t);
    }
    cout<<"当前老师数量为："<<vTea.size()<<endl;

}
//检测是否重复
bool Manager::checkRepeat(int id, int type)
{
    if (type == 1)
    {
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
        {
            if (id == it->m_Id)
            {
                return true;
            }
        }
    }
    else
    {
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
        {
            if (id == it->m_EmpId)
            {
                return true;
            }
        }
    }
    return false;
}