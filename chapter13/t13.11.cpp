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

//完全照搬t13.8
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class HasPtr
{
public:
    explicit HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0)
    {
    }
    HasPtr(const HasPtr &source) : ps(new string(*source.ps)), i(source.i)
    {
    }
    HasPtr &operator=(const HasPtr &source)
    {
        auto tempPtr = new string(*source.ps);
        delete ps;

        ps = tempPtr;
        i = source.i;

        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }
    void showInfo()
    {
        cout << "ps:" << *ps << ",ps's address:" << ps << ",i:" << i << endl;
    }

private:
    std::string *ps;
    int i;
};

int main()
{
    HasPtr hp1("apple");
    HasPtr hp2 = hp1;
    HasPtr hp3(hp1);
    hp1.showInfo();
    hp2.showInfo();
    hp3.showInfo();
    HasPtr hp4("banana");
    hp4.showInfo();
    hp4 = hp3; //现在没有内存泄露了
    hp4.showInfo();
    return 0;
}