//
// Created by Quagmire on 2024/8/10.
//

#ifndef MACHINE_ROOM_RESERVATION_SYSTEM_IDENTITY_H
#define MACHINE_ROOM_RESERVATION_SYSTEM_IDENTITY_H

#endif //MACHINE_ROOM_RESERVATION_SYSTEM_IDENTITY_H
#pragma once
#include<iostream>
using namespace std;

//身份抽象类
class Identity
{
public:

    //操作菜单
    virtual void operMenu() = 0;

    string m_Name; //用户名
    string m_Pwd;  //密码
};