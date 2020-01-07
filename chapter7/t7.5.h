/*
在7.4上进一步修改
*/
#include <string>


struct Person
{
    std::string fullName;
    std::string address;

    std::string getFullName() const;
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

//这些函数应该是 const的，仅仅是返回值，不需要修改，禁止无意识的修改操作