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

#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

string &standardizedWord(string &word);

int main()
{
    map<string, int> mmap;
    string word;
    cout << "请输入单词，按 ctrl+D 结束" << endl;
    while (cin >> word)
    {
        standardizedWord(word);
        ++mmap[word];
    }
    for (const auto &item : mmap)
    {
        cout << item.first << "---" << item.second << endl;
    }

    return 0;
}

/**
 * 1.去除所有的标点：!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
 * 2. 变为全小写
 */
string &standardizedWord(string &word)
{
    //1.先去除标点
    auto iter = std::remove_if(word.begin(), word.end(), ::ispunct);
    word.erase(iter, word.end());
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}