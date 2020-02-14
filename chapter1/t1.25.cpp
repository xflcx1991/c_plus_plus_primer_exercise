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

#include <iostream>

#include "Sales_item.h"



int main()
{
    Sales_item total; //保存下一条交易记录的变量
    //读入第一条交易记录，并确保有数据可以处理
    if(std::cin >> total)
    {
        Sales_item trans; //保存和的变量
        //读入并处理剩余交易记录
        while(std::cin >> trans)
        {
            //如果我们仍在处理相同的书
            if(total.isbn() == trans.isbn())
            {
                total += trans;
            }
            else
            {
                //打印前一本书的结果
                std::cout << total << std::endl;
                total = trans; //total现在表示下一本书的销售额
            }
        }
        std::cout << total << std::endl; //打印最后一本书的结果
    }
    else
    {
        //没有输入！警告
        std::cerr << "No data?!" << std::endl;
        return -1; //表示失败
    }
    return 0;
}