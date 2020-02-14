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

#include <istream>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

std::istream& readDataFromStream(std::istream& is);

int main()
{
    readDataFromStream(cin);
    cout << "测-试cin是否是正常的" << endl;
    //先干掉缓冲，1024是随意取的一个比较大的数字
    cin.ignore(1024, '\n');
    
    int num2 = 1;
    cin >> num2;
    cout << num2 << endl;
    cout << "确实cin流恢复正常了" << endl;
    return 0;
}