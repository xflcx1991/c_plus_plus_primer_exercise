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

//insert函数的参数类型是 std::pair<const std::string, std::vector<int>>
//返回值类型是 std::pair<std::map<std::string, std::vector<int>>::iterator, bool>
#include <iostream>
#include <map>
#include <string>
#include <vector>
//就不用using了
int main()
{
    std::map<std::string, std::vector<int>> mmap;
    std::string word = "apple";
    std::vector<int> mvec = {1, 2, 3, 4, 5};
    std::pair<const std::string, std::vector<int>> tempPair = {word, mvec};
    std::pair<std::map<std::string, std::vector<int>>::iterator, bool> returnValue = mmap.insert(tempPair);
    std::cout << (*returnValue.first).first << "===" << (returnValue.second ? "true" : "false") << std::endl;
    for (const auto &item : mmap)
    {
        std::cout << item.first << "---";
        for (auto num : item.second)
        {
            std::cout << num << ",";
        }
        std::cout << std::endl;
    }

    return 0;
}
