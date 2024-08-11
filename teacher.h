//
// Created by Quagmire on 2024/8/10.
//

#ifndef MACHINE_ROOM_RESERVATION_SYSTEM_TEACHER_H
#define MACHINE_ROOM_RESERVATION_SYSTEM_TEACHER_H

#endif //MACHINE_ROOM_RESERVATION_SYSTEM_TEACHER_H
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "identity.h"

class Teacher :public Identity
{
public:

    //默认构造
    Teacher();

    //有参构造 (职工编号，姓名，密码)
    Teacher(int empId, string name, string pwd);

    //菜单界面
    virtual void operMenu();

    //查看所有预约
    void showAllOrder();

    //审核预约
    void validOrder();

    int m_EmpId; //教师编号

};