/*************************************************************************************
* Copyright (c) 2020 xffish
* c_plus_plus_primer_exercise is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
* http://license.coscl.org.cn/MulanPSL2
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
* See the Mulan PSL v2 for more details.
*************************************************************************************/

//我认为insert更容易编写和阅读，因为有显式的if判断关键字是否在容器里，而下标操作:++mmap[word] 蕴含了一个
//潜在的操作，如果关键在还未在map里，草标操作会插入一个具有给定关键字的元素（P389）
//在t11.3基础上修改
#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    map<string, int> mmap;
    string word;
    cout << "请输入单词，按 ctrl+D 结束" << endl;
    while (cin >> word)
    {
        //以下本题答案
        auto ret = mmap.insert({word, 1});
        if (!ret.second)
        {
            //如果已经有了上面的insert插入失败，那就递增既有值
            ++ret.first->second; //ret是一个pair，first成员是一个迭代器指向关键字元素（即map里的pair），它的second就是输入的单词的统计值
        }
    }
    for (const auto &item : mmap)
    {
        cout << item.first << "---" << item.second << endl;
    }

    return 0;
}