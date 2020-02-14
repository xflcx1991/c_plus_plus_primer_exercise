/*************************************************************************************
* Copyright (c) 2019 xffish
* c_plus_plus_primer_exercise is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
* http://license.coscl.org.cn/MulanPSL2
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
* See the Mulan PSL v2 for more details.
*************************************************************************************/

/*
在7.5上进一步修改
*/
//不 include 可以吗？
//gcc 可以编译运行，但还是加上把
#include <string>
#include <istream>
#include <ostream>

struct Person
{
    std::string fullName;
    std::string address;
    
    /**获取姓名*/
    std::string getFullName() const;
    //获取地址
    std::string getAddress() const;
};


std::string Person::getFullName() const
{
    // 这是一个 const成员函数，this是常量指针，无法调用非const类型的fullName
    // fullName = "aaa";
    return fullName;
}

std::string Person::getAddress() const
{
    return address;
}
std::ostream &print(std::ostream&, const Person&);
std::istream& read(std::istream&, Person&);

//-----------------------
std::ostream& print(std::ostream& os, const Person& person)
{
    //不直接引用成员变量，改调用成员函数
    os << "fullName=" << person.getFullName() << ",getAddress=" << person.getAddress() << std::endl;
    return os;
}

std::istream& read(std::istream& is, Person& person)
{
    is >> person.fullName >> person.address;
    return is;
}