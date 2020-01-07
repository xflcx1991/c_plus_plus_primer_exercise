/*
和7.1一样
7.1不使用这些成员难道能运行起来吗？
*/
#include <iostream>
#include "t7.2.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
    Sales_data total;
    if(read(cin, total))
    {
        Sales_data trans; //保存和的变量
        //读入并处理剩余交易记录
        while(read(cin, trans))
        {
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
