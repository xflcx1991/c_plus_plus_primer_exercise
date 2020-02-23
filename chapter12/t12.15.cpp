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
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;

struct destination
{
    size_t id;    //序号
    string ip;    //ip地址
    string port;  //端口号
    string brief; //描述信息
};

struct connection
{
    size_t id;        //序号
    string startTime; //连接成功的时间
    string brief;     //描述信息
    destination dest;
};

connection connect(destination *);
void disconnect(connection);
void print(const destination &);
void print(const connection &);
//核心处理函数
void f(destination &);

int main()
{
    destination dest1 = {10001, "192.168.1.100", "3389",
                         "我想连接到192.168.1.100计算机的3389端口"};
    print(dest1);
    f(dest1);
    return 0;
}

connection connect(destination *destP)
{
    cout << "建立对" << destP->ip << ":" << destP->port << "的连接" << endl;
    connection conn = {destP->id + 1, "2020-02-23 16:10:01", "连接成功", *destP};
    return conn;
}

void disconnect(connection conn)
{
    cout << "断开对" << conn.dest.ip << ":" << conn.dest.port << "的连接" << endl;
    conn.brief = "连接中断";
}

/**
 * 打印destination的信息
 */
void print(const destination &dest)
{
    cout << "序号：" << dest.id << "，ip/端口：" << dest.ip << ":" << dest.port
         << "，描述信息：" << dest.brief << endl;
}

/**
 * 打印connection的信息
 */
void print(const connection &conn)
{
    cout << "============================================" << endl;
    cout << "序号：" << conn.id << "，建立连接时间：" << conn.startTime << "，描述信息：" << conn.brief << endl;
    cout << "内部的destination信息：";
    print(conn.dest);
    cout << "============================================" << endl;
}

void f(destination &d)
{
    connection c = connect(&d);

    shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
    //会自动调用end_connection
    //不能把这个智能指针就这样return出去，因为一出去c就被销毁了，等到传出的智能指针自动销毁时c已经不存在了
}
