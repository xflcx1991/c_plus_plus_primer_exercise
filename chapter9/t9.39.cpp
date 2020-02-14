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
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<string> svec; //声明并初始化了一个存储string类型元素的容器，元素个数是0
    svec.reserve(1024); //要求该容器至少能存储1024个元素
    string word; //声明并初始化一个空字符串
    while (cin >> word) //键盘读入一个字符串并赋值给word
    {
        svec.push_back(word); //把这个字符串存入容器
    }
    svec.resize(svec.size() + svec.size() / 2); //容器的元素个数增长50%，增长的元素全是空字符串。

    return 0;
}