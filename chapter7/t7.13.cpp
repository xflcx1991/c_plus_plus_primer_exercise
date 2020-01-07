#include <iostream>
#include "t7.12.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
    // Sales_data total;
    Sales_data total(cin);
    if(total.isbn() != "")
    {
        while(true)
        {
            Sales_data trans(cin); //保存和的变量
            //读入并处理剩余交易记录
            if(trans.isbn() == "")
            {
                break;
            }
            //如果我们仍在处理相同的书
            if(total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                //打印前一本书的结果
                print(cout, total) << endl;
                total = trans; //total现在表示下一本书的销售额
            }
        }
        print(cout, total) << endl; //打印最后一本书的结果
    }
    else
    {
        //没有输入！警告
        cerr << "No data?!" << endl;
        return -1; //表示失败
    }
    
    return 0;
}
