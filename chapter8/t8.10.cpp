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

//在8.4上修改
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;

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
        while (std::getline(is, tempData))
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

    //到此vector内容准备好了，开始打印
    string word;
    for(auto line : lines)
    {
        //line是每一行内容，类型是 string
        istringstream iss(line);
        while(iss >> word)
        {
            cout << word << endl;
        }
    }
    
    return 0;
}