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

//在t10.22上修改
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std::placeholders;

bool check_size(const string &str, string::size_type sz);

int main()
{
    string str1 = "hello";
    vector<int> mvec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    auto callable = std::bind(check_size, str1, _1);

    auto iter = std::find_if(mvec.cbegin(), mvec.cend(), callable);
    cout << "这个数是" << *iter << endl;

    return 0;
}

// sz是find_if提取的每一个容器里的int元素
bool check_size(const string &str, string::size_type sz)
{
    return sz >= str.size();
}