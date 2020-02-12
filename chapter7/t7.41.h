//在7.26基础上改
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

class Sales_data
{
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

public:
    Sales_data();
    explicit Sales_data(const std::string &s);
    Sales_data(const std::string &s, unsigned n, double p);
    explicit Sales_data(std::istream &is);

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    //ISBN编号
    std::string bookNo = "default";
    //售出单价
    unsigned units_sold = 0;
    //销售额，总收入
    double revenue = 0.0;
    //定义处指明了inline
    double avg_price() const;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
//----------声明结束-----------------

Sales_data::Sales_data() : Sales_data("<->")
{
    std::cout << "Sales_data()" << std::endl;
}

Sales_data::Sales_data(const std::string &s) : Sales_data(s, 0, 0)
{
    std::cout << "Sales_data(const std::string &s)" << std::endl;
}

Sales_data::Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n)
{
    std::cout << "Sales_data(const std::string &s, unsigned n, double p)" << std::endl;
}

Sales_data::Sales_data(std::istream &is)
{
    std::cout << "Sales_data(std::istream &is)" << std::endl;
    read(is, *this);
}

//合并
Sales_data &Sales_data::combine(const Sales_data &sd)
{
    units_sold += sd.units_sold;
    revenue += sd.revenue;
    return *this;
}

inline double Sales_data::avg_price() const
{
    //如果units_sold是0，那就返回0；否则返回除法的值
    return units_sold ? revenue / units_sold : 0;
}

//-----------------------
Sales_data add(const Sales_data &lsd, const Sales_data &rsd)
{
    Sales_data result;
    if (lsd.bookNo != rsd.bookNo)
    {
        return result;
    }
    result.bookNo = lsd.bookNo;
    result.units_sold = lsd.units_sold + rsd.units_sold;
    result.revenue = lsd.revenue + rsd.revenue;
    return result;
}

std::ostream &print(std::ostream &os, const Sales_data &sd)
{
    os << "bookNo=" << sd.bookNo << ",units_sold=" << sd.units_sold << ",revenue=" << sd.revenue << std::endl;
    return os;
}

std::istream &read(std::istream &is, Sales_data &sd)
{
    is >> sd.bookNo >> sd.units_sold >> sd.revenue;
    return is;
}