#include <iostream>
using namespace std;
#include "string"
#include "identity.h"
#include "fstream"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
//进入管理员子菜单
void managerMenu(Identity * &manager)
{
    while (true)
    {
        //管理员菜单
        manager->operMenu();
        //将父类指针转换为子类指针，调用子类其他接口
        Manager* man = (Manager*)manager;
        int select = 0;

        cin >> select;
        //接收用户选择
        if (select == 1)  //添加账号
        {
            cout << "添加账号" << endl;
            man->addPerson();
        }
        else if (select == 2) //查看账号
        {
            cout << "查看账号" << endl;
            man->showPerson();
        }
        else if (select == 3) //查看机房
        {
            cout << "增加机房" << endl;
            man->addComputerRoom();
        }
        else if (select == 4) //查看机房
        {
            cout << "删除机房" << endl;
            man->deleteComputerRoom();
        }
        else if (select == 5) //查看机房
        {
            cout << "修改机房" << endl;
            man->editComputerRoom();
        }
        else if (select == 6) //查看机房
        {
            cout << "查看机房" << endl;
            man->showComputer();
        }
        else if (select == 7) //清空预约
        {
            cout << "清空预约" << endl;
            man->cleanFile();
            cout << "清空完成" << endl;
        }
        else
        {
            delete manager;//销毁堆区对象
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}
//学生菜单
void studentMenu(Identity *&student) {
    while (true) {
        //学生菜单
        student->operMenu();
        //将父类指针转换为子类指针，从而可以调用子类中其他接口
        Student *stu = (Student *) student;
        int select = 0;
        cin >> select;
        if (select == 1) //申请预约
        {
            stu->applyOrder();
        } else if (select == 2) //查看自身预约
        {
            stu->showMyOrder();
        } else if (select == 3) //查看所有预约
        {
            stu->showAllOrder();
        } else if (select == 4) //取消预约
        {
            stu->cancelOrder();
        } else {
            delete student;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

//教师菜单
void TeacherMenu(Identity * &teacher)
{
    while (true)
    {
        //教师菜单
        teacher->operMenu();

        Teacher* tea = (Teacher*)teacher;
        int select = 0;

        cin >> select;

        if (select == 1)
        {
            //查看所有预约
            tea->showAllOrder();
        }
        else if (select == 2)
        {
            //审核预约
            tea->validOrder();
        }
        else
        {
            delete teacher;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }

    }
}

//登录功能
void LoginIn(string fileName, int type) {
    //父类指针用于指向子类对象
    Identity *person = NULL;

    //读文件
    ifstream ifs;
    ifs.open(fileName, ios::in);

    //判断文件是否存在
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;

    }
    //准备接受用户信息
    int id = 0;
    string name;
    string pwd;
    //判断身份
    if (type == 1)    //学生登录
    {
        cout << "请输入你的学号" << endl;
        cin >> id;
    } else if (type == 2) //教师登录
    {
        cout << "请输入你的职工号" << endl;
        cin >> id;
    }

    cout << "请输入用户名：" << endl;
    cin >> name;

    cout << "请输入密码： " << endl;
    cin >> pwd;


    if (type == 1) {
        //学生登录验证
        int fId;
        string fName;//文件中获取的姓名
        string fPwd;//文件中获取的密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            //与用户输入的信息做对比
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "学生验证登录成功!" << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);
                //进入学生身份子菜单
                studentMenu(person);
                return;
            }
        }
    } else if (type == 2) {
        //教师登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "教师验证登录成功!" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);
                //进入教师身份子菜单
                //进入教师子菜单
                TeacherMenu(person);
                return;
            }
        }
    } else if (type == 3) {
        //管理员登录验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd) {
            if (name == fName && pwd == fPwd) {
                cout << "验证登录成功!" << endl;
                //登录成功后，按任意键进入管理员界面
                system("pause");
                system("cls");
                //创建管理员对象
                person = new Manager(name, pwd);
                //进入管理员身份子菜单
                managerMenu(person);
                ifs.close();
                return;
            }
        }
    }

    cout << "验证登录失败!" << endl;

    system("pause");
    system("cls");
}


int main() {
    int select = 0;

    while (true) {

        cout << "======================  欢迎来到机房预约系统  =====================" << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表             |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        cin >> select; //接受用户选择

        switch (select) {
            case 1:  //学生身份
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2:  //老师身份
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3:  //管理员身份
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0:  //退出系统
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
                break;
            default:
                cout << "输入有误，请重新选择！" << endl;
                system("pause");
                system("cls");
                break;
        }

    }
    system("pause");

    return 0;
}
