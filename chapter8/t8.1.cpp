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
#include <string>

using std::string;
using std::cout;
using std::endl;

std::istream& readDataFromStream(std::istream& is)
{
    cout << is.rdstate() << endl;
    string data;
    while(is >> data)
    {
        cout << data << endl;
    }
    cout << is.rdstate() << endl;
    is.clear();
    cout << is.rdstate() << endl;
    return is;
}