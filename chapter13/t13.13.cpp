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
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct X
{
    X()
    {
        std::cout << "X()" << endl;
    }
    X(const X &)
    {
        cout << "X(const X&)" << endl;
    }
    X &operator=(const X &)
    {
        cout << "X& operator=(const X&)" << endl;
        return *this;
    }
    ~X()
    {
        cout << "~X()" << endl;
    }
};

void test1(X x)
{
    cout << "test1" << endl;
}

void test2(const X &x)
{
    cout << "test2" << endl;
}

X test3(const X &x)
{
    cout << "test3" << endl;
    return x;
}

X test4()
{
    cout << "test4" << endl;
    return X();
}

X *test5()
{
    cout << "test5" << endl;
    auto temp = new X;
    return temp;
}

X &test6(X &x)
{
    cout << "test6" << endl;
    return x;
}

const X &test7(const X &x)
{
    cout << "test7" << endl;
    return x;
}

int main()
{
    X x1;
    cout << "=======" << endl;
    X x2 = x1;
    cout << "=======" << endl;
    X x3(x1);
    cout << "=======" << endl;
    x3 = x2;
    cout << "=======" << endl;
    test1(x1);
    cout << "=======" << endl;
    test2(x2);
    cout << "=======" << endl;
    x1 = test4();
    cout << "=======" << endl;
    X x4 = test4();
    cout << "=======" << endl;
    vector<X> x5;
    x5.push_back(x1);
    cout << "=======" << endl;
    vector<X> x6 = x5;
    cout << "=======" << endl;
    vector<X> x7(x5);
    cout << "=======" << endl;
    x7 = x6;
    cout << "=======" << endl;
    return 0;
}