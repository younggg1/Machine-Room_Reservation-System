//
// Created by Quagmire on 2024/8/10.
//

#ifndef MACHINE_ROOM_RESERVATION_SYSTEM_STUDENT_H
#define MACHINE_ROOM_RESERVATION_SYSTEM_STUDENT_H

#endif //MACHINE_ROOM_RESERVATION_SYSTEM_STUDENT_H
#pragma once
#include<iostream>
#include <vector>

using namespace std;
#include "identity.h"
#include "computerRoom.h"

//学生类
class Student :public Identity
{
public:
    //默认构造
    Student();

    //有参构造(学号、姓名、密码)
    Student(int id, string name, string pwd);

    //菜单界面
    virtual void operMenu();

    //申请预约
    void applyOrder();

    //查看我的预约
    void showMyOrder();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    //机房容器
    vector<ComputerRoom> vCom;

    //学生学号
    int m_Id;

};