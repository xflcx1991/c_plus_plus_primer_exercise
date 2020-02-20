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

//一个完整的程序，包含了P375和P382
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
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
    {
        ++word_count[word];
    }

    //这是本题要的答案
    std::map<string, size_t>::const_iterator map_it = word_count.cbegin();

    while (map_it != word_count.cend())
    {
        cout << map_it->first << " occurs "
             << map_it->second << " times" << endl;
        ++map_it;
    }

    return 0;
}
