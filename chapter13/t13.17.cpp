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

//int序号生成器麻烦，我换了一个UUID生成器
//Special notes
//    clang/g++ users: both -std=c++11 and -lrt may be required when compiling sole.cpp

#include "sole.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class numbered
{
    friend void f13_15(numbered s);
    friend void f13_16(const numbered &s);

public:
    numbered() : mysn(sole::uuid1().str())
    {
        cout << "默认构造函数" << endl;
    }
    numbered(const numbered &source)
    {
        cout << "拷贝构造函数" << endl;
        mysn = sole::uuid1().str();
    }
    void showInfo()
    {
        cout << "mysn:" << mysn << endl;
    }

private:
    // size_t mysn;
    string mysn;
};

void f13_15(numbered s)
{
    cout << s.mysn << endl;
}

void f13_16(const numbered &s)
{
    cout << s.mysn << endl;
    ;
}

int main()
{
    numbered a, b = a, c = b;
    cout << "====原始a，b，c的值是====" << endl;
    a.showInfo();
    b.showInfo();
    c.showInfo();
    ;
    ;
    ;

    cout << "=============" << endl;
    cout << "注释拷贝构造函数是t13.14的情况" << endl;
    cout << "保留拷贝构造函数是t13.15的情况" << endl;
    f13_15(a);
    f13_15(b);
    f13_15(c);
    cout << "-------------" << endl;
    f13_16(a);
    f13_16(b);
    f13_16(c);
    return 0;
}
