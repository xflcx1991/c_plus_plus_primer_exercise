/*************************************************************************************
* Copyright (c) 2020 xffish
* c_plus_plus_primer_exercise is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
* http://license.coscl.org.cn/MulanPSL2
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
* See the Mulan PSL v2 for more details.
*************************************************************************************/

#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point()
    {
        cout << "Point的默认构造函数" << endl;
    }
    Point(const Point &source)
    {
        cout << "Point的拷贝构造函数" << endl;
    }
    ~Point()
    {
        cout << "Point的析构函数" << endl;
    }
};

Point global;            //默认构造函数
Point foo_bar(Point arg) //函数参数不是引用类型，这里有一次拷贝构造函数
{
    Point local = arg;               //拷贝构造函数初始化
    Point *heap = new Point(global); //拷贝构造函数直接初始化
    *heap = local;
    Point pa[4] = {local, *heap}; //两次拷贝构造函数，两次默认构造函数
    return *heap;                 //返回的不是引用类型，还有一次拷贝构造函数
}

int main()
{
    foo_bar(global);
}