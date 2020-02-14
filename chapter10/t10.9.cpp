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
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void elimDups(vector<int> &mvec);

int main()
{
    vector<int> mvec = {10, 20, -1, 2, 3, 4, 5, 10, 100, 20};
    elimDups(mvec);

    return 0;
}

void elimDups(vector<int> &mvec)
{
    std::sort(mvec.begin(), mvec.end());
    auto iter = std::unique(mvec.begin(), mvec.end());
    mvec.erase(iter, mvec.cend());
    for (auto item : mvec)
    {
        cout << item << endl;
    }
}