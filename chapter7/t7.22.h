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

//在7.15上进一步修改

#include <string>
#include <istream>
#include <ostream>

class Person
{
    friend std::ostream &print(std::ostream &, const Person &);
    friend std::istream &read(std::istream &, Person &);

public:
    Person() = default;
    Person(const std::string &fullName, const std::string &address);
    /* deprecated usage
    Person(const string& fullName, const string& address)
    {
        this->fullName = fullName;
        this->address = address;
    }
    */
    /**获取姓名*/
    std::string getFullName() const;
    //获取地址
    std::string getAddress() const;

private:
    std::string fullName;
    std::string address;
};

std::ostream &print(std::ostream &, const Person &);
std::istream &read(std::istream &, Person &);
//-----------------------

Person::Person(const std::string &fullName, const std::string &address) : fullName(fullName), address(address)
{
}

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

std::ostream &print(std::ostream &os, const Person &person)
{
    //不直接引用成员变量，改调用成员函数
    os << "fullName=" << person.getFullName() << ",getAddress=" << person.getAddress() << std::endl;
    return os;
}

std::istream &read(std::istream &is, Person &person)
{
    is >> person.fullName >> person.address;
    return is;
}