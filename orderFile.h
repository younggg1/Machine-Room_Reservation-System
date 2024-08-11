//
// Created by Quagmire on 2024/8/10.
//

#ifndef MACHINE_ROOM_RESERVATION_SYSTEM_ORDERFILE_H
#define MACHINE_ROOM_RESERVATION_SYSTEM_ORDERFILE_H

#endif //MACHINE_ROOM_RESERVATION_SYSTEM_ORDERFILE_H
#pragma once
#include<iostream>
using namespace std;
#include <map>
#include "globalFile.h"

class OrderFile
{
public:

    //构造函数
    OrderFile();

    //更新预约记录
    void updateOrder();

    //记录的容器  key --- 记录的条数  value --- 具体记录的键值对信息
    map<int, map<string, string>> m_orderData;

    //预约记录条数
    int m_Size;
};