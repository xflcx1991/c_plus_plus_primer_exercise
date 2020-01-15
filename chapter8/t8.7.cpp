#include <iostream>
#include <fstream>
#include <string>
#include "../chapter7/t7.2.h"


using std::cerr;
using std::endl;
using std::string;

/**
 * argv[1]:读入的文件
 * argv[2]:输出的文件
*/
int main(int argc, char **argv)
{

    //默认就是以读模式打开
    std::ifstream is(argv[1]);
    //默认是写 && 截断模式打开
    std::ofstream os(argv[2]);

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
                print(os, total) << endl;
                total = trans; //total现在表示下一本书的销售额
            }
        }
        print(os, total) << endl; //打印最后一本书的结果
    }
    else
    {
        //没有输入！警告
        cerr << "No data?!" << endl;
        return -1; //表示失败
    }
    
    return 0;
}
