//
// Created by Quagmire on 2024/8/10.
//

#ifndef MACHINE_ROOM_RESERVATION_SYSTEM_MANAGER_H
#define MACHINE_ROOM_RESERVATION_SYSTEM_MANAGER_H

#endif //MACHINE_ROOM_RESERVATION_SYSTEM_MANAGER_H
#pragma once
#include<iostream>
#include <vector>

using namespace std;
#include "identity.h"
#include "string"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

class Manager :public Identity
{
public:

    //默认构造
    Manager();

    //有参构造  管理员姓名，密码
    Manager(string name, string pwd);

    //选择菜单
    virtual void operMenu();

    //添加账号
    void addPerson();

    //查看账号
    void showPerson();

    //增加机房信息
    void addComputerRoom();
    //删除机房信息
    void deleteComputerRoom();
    //修改机房信息
    void editComputerRoom();
    //查看机房信息
    void showComputer();

    //清空预约记录
    void cleanFile();
    //初始化容器
    void initVector();

    //检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
    bool checkRepeat(int id, int type);

    //机房容器
    vector<ComputerRoom> vCom;

    //学生容器
    vector<Student> vStu;

    //教师容器
    vector<Teacher> vTea;

};