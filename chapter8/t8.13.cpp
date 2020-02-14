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

//在8.10、8.11上修改
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
using std::ostringstream;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const string &);
string format(const string &);
PersonInfo transformStringToPersonInfo(const string&);



int main()
{
    /**
     * 读文件
    */
    string fileName = "t8.13-data.txt";

    vector<PersonInfo> people;
    //默认就是以读模式打开
    std::ifstream is(fileName);
    if (is)
    {
        //如果正常打开
        string line;
        
        //用 is >> tempData 会导致一行内有空格
        //getline用法示例：https://en.cppreference.com/w/cpp/string/basic_string/getline
        while (std::getline(is, line)) //从这里接8.11的28行
        {
            people.push_back(transformStringToPersonInfo(line));
        }
    }
    else
    {
        //打开失败
        cerr << "打开失败，请检查文件是否存在或是否有权限" << endl;
    }
    is.close();
///////////////////////////////////////////
//到这里，文件内容处理完成，vector<PersonInfo>内容填充好，开始构造输出
///////////////////////////////////////////

    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
        {
            if (!valid(nums))
            {
                badNums << " " << nums; //将数的字符串形式存入badNums
            }
            else
            {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
        {
            //没有错误的话
            cout << entry.name << " " << formatted.str() << endl;
        }
        else
        {
            cerr << "input error:" << entry.name << " invalid number(s) " << badNums.str() << endl;
        }
    }
}

bool valid(const string& nums)
{
    constexpr int PHONE_NUM_SIZE = 11;
    if(nums.size() != PHONE_NUM_SIZE)
    {
        return false;
    }
    for(auto ch : nums)
    {
        if(ch < '0' || ch > '9')
        {
            return false;
        }
    }
    return true;
}

string format(const string &nums)
{
    ostringstream format;
    format << nums.substr(0, 3);
    format << "-";
    format << nums.substr(3, 4);
    format << "-";
    format << nums.substr(7, 4);

    return format.str();
}


/**
 * 根据一行字符串内容转换成PersonInfo对象
 * 来自8.11
*/
PersonInfo transformStringToPersonInfo(const string& line)
{
        PersonInfo info;
        istringstream record(line);
        string word; //代表一个电话号码

        record >> info.name;

        while (record >> word)
        {
            info.phones.push_back(word);
        }

        return info;
}