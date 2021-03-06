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
#include <list>

using std::list;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    
    vector<int> mvector;
    list<int> mlist;
    for(auto item : ia)
    {
        mvector.push_back(item);
        mlist.push_back(item);
    }
    //删除list中奇数元素
    auto it_list = mlist.cbegin();
    while(it_list != mlist.cend())
    {
        if(*it_list % 2 != 0)
        {
            it_list = mlist.erase(it_list);
        }
        else
        {
            ++it_list;
        }
        
    }

    //删除vector中偶数元素
    auto it_vector = mvector.cbegin();
    while(it_vector != mvector.cend())
    {
        if(*it_vector % 2 == 0)
        {
            it_vector = mvector.erase(it_vector);
        }
        else
        {
            ++it_vector;
        }
    }

    return 0;
}
