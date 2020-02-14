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

class Debug
{
public:
    constexpr Debug(bool b = true) : Debug(b, b, b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    constexpr bool any();
    constexpr void setHw(bool h);
    void setIo(bool i);
    void setOther(bool o);
private:
    bool hw;
    bool io;
    bool other;
};

constexpr bool Debug::any()
{
    return hw || io || other;
}

constexpr void Debug::setHw(bool h)
{
    hw = h;
}

void Debug::setIo(bool i)
{
    io = i;
}

void Debug::setOther(bool o)
{
    other = o;
}