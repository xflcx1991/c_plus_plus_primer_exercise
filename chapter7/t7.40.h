#include <string>


class Employee
{
public:
    Employee() = default;
    Employee(const std::string &tid, const std::string &tname,
                const std::string &tdepartment, const int &tage, 
                const std::string &tsex, const double &tsalary);
private:
    std::string id;
    std::string name;
    std::string department;
    int age;
    std::string sex;
    double salary;
    
};

Employee::Employee(const std::string &tid, const std::string &tname,
                const std::string &tdepartment, const int &tage, 
                const std::string &tsex, const double &tsalary):
        id(tid), name(tname), department(tdepartment),
        age(tage),sex(tsex),salary(tsalary)
{

}
//没什么阐明的，这是自然而然的。