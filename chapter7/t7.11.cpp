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
#include "t7.6.h"

using std::cout;
using std::cin;

int main()
{
    //1st
    Sales_data sd1;
    print(cout, sd1);
    //2nd
    Sales_data sd2("10001");
    print(cout, sd2);

    //3rd
    Sales_data sd3("10002", 100, 200);
    print(cout, sd3);

    //4th
    Sales_data sd4(cin);
    print(cout, sd4);
    return 0;
}
