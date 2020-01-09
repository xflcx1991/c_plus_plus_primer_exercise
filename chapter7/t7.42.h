//在7.40上修改
#include <string>
#include <iostream>

class Employee
{
public:
    Employee();
    Employee(const std::string &tid, const std::string& tname);
    Employee(const std::string &tid, const std::string &tname,
                const std::string &tdepartment, const int &tage, 
                const std::string &tsex, const double &tsalary);
    void show();
private:
    std::string id;
    std::string name;
    std::string department;
    int age;
    std::string sex;
    double salary;
    
};
//委托初始化可以表达那些字段必填的意思，非必填的项目由委托时默认给一个值
Employee::Employee():Employee("", "")
{

}

Employee::Employee(const std::string &tid, const std::string& tname):Employee(tid, tname, "", 0, "", 0.0)
{

}

Employee::Employee(const std::string &tid, const std::string &tname,
                const std::string &tdepartment, const int &tage, 
                const std::string &tsex, const double &tsalary):
        id(tid), name(tname), department(tdepartment),
        age(tage),sex(tsex),salary(tsalary)
{

}

void Employee::show()
{
    std::cout << "{id=" << id << ", name=" << name << ",department=" << department << ",age=" << age << ",sex=" << sex << ",salary=" << salary << "}"<< std::endl;
}