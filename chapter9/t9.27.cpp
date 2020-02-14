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
#include <forward_list>


using std::forward_list;
using std::cout;
using std::endl;

int main()
{
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9,};
    auto prev = flst.cbefore_begin();
    auto curr = flst.cbegin();
    while(curr != flst.cend())
    {
        if(*curr % 2 != 0) //是奇数
        {
            cout << "即将删除：" << *curr << endl;
            curr = flst.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
        
    }



    return 0;
}