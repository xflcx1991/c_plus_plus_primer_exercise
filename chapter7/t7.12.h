//在7.6基础上改
//把只接受一个 istream 作为参数的
//构造函数定义移到类的内部
#include <istream>
#include <ostream>
#include <string>

//需要这些函数声明放前面，放到后面导致类里面用不了read
struct Sales_data;
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

struct Sales_data
{
    //ISBN编号
    std::string bookNo;
    //售出单价
    unsigned units_sold = 0;
    //销售额，总收入
    double revenue = 0.0;

    //新增的构造函数
    Sales_data() = default;
    Sales_data(const std::string &s);
    Sales_data(const std::string &s, unsigned n, double p);

    Sales_data(std::istream &is)
    {
        read(is, *this);
    }

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
};

Sales_data::Sales_data(const std::string &s) : bookNo(s)
{
}

Sales_data::Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n)
{
}

//合并
Sales_data &Sales_data::combine(const Sales_data &sd)
{
    units_sold += sd.units_sold;
    revenue += sd.revenue;
    return *this;
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