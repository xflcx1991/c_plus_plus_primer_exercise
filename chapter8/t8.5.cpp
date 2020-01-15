//在t8.4很像，从 getline 改为 >>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string fileName = "t8.4-data.txt";
    vector<string> lines;
    //默认就是以读模式打开
    std::ifstream is(fileName);
    if (is)
    {
        //如果正常打开

        string tempData;
        //用 is >> tempData 会导致一行内有空格
        //getline用法示例：https://en.cppreference.com/w/cpp/string/basic_string/getline
        while (is >> tempData)
        {
            lines.push_back(tempData);
        }
    }
    else
    {
        //打开失败
        cerr << "打开失败，请检查文件是否存在或是否有权限" << endl;
    }
    //打开失败时还能关闭吗？
    //这里（https://en.cppreference.com/w/cpp/io/basic_ifstream/close）不推荐手动关闭？！
    //This function is called by the destructor of basic_ifstream when the stream object goes out of scope and is not usually invoked directly.
    // is.close();

    //打印vector内容看看
    for (auto item : lines)
    {
        cout << item << endl;
    }
    return 0;
}