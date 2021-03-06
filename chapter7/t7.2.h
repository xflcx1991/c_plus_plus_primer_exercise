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

//来自t2.40.h

#include <istream>
#include <ostream>
#include <string>



struct Sales_data
{
    //ISBN编号
    std::string bookNo;
    //售出单价
    unsigned units_sold = 0;
    //销售额，总收入
    double revenue = 0.0;

    std::string isbn() const{return bookNo;}
    Sales_data& combine(const Sales_data&);
};

//合并
Sales_data& Sales_data::combine(const Sales_data& sd)
{
    units_sold += sd.units_sold;
    revenue += sd.revenue;
    return *this;
}

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

//-----------------------
Sales_data add(const Sales_data& lsd, const Sales_data& rsd)
{
    Sales_data result;
    if(lsd.bookNo != rsd.bookNo)
    {
        return result;
    }
    result.bookNo = lsd.bookNo;
    result.units_sold = lsd.units_sold + rsd.units_sold;
    result.revenue = lsd.revenue + rsd.revenue;
    return result;
}

std::ostream &print(std::ostream& os, const Sales_data& sd)
{
    os << "bookNo=" << sd.bookNo << ",units_sold=" << sd.units_sold << ",revenue=" << sd.revenue << std::endl;
    return os;
}

std::istream& read(std::istream& is, Sales_data& sd)
{
    is >> sd.bookNo >> sd.units_sold >> sd.revenue;
    return is;
}