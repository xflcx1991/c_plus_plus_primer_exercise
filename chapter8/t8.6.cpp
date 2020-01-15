#include <iostream>
#include <fstream>
#include <string>
#include "../chapter7/t7.2.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    string fileName = argv[1];

    //默认就是以读模式打开
    std::ifstream is(fileName);
    
    
    Sales_data total;
    if(read(is, total))
    {
        Sales_data trans; //保存和的变量
        //读入并处理剩余交易记录
        while(read(is, trans))
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
