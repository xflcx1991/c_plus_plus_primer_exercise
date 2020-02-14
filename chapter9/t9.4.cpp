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
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool findValue(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value);

int main()
{
    vector<int> mvector = {1,2,3,4,5,6,7,8};
    cout << findValue(mvector.cbegin(), mvector.cend(), 9) << endl;

    return 0;
}

bool findValue(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value)
{
    bool flag = false;
    for(; begin != end; ++begin)
    {
        if(*begin == value)
        {
            flag = true;
            break;
        }
    }

    return flag;
}