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

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

//偷懒了
using namespace std;

class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    //添加和删除元素
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    //元素访问
    std::string &front();
    std::string &back();
    //重载front和back的const版本
    const std::string &front() const;
    const std::string &back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>())
{
}

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il))
{
}

/**
 * 检查索引是否在合法范围内
 */
void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}

/**
 * 得到第一个元素
 */
string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

/**
 * 得到最后一个元素
 */
string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

/**
 * 得到第一个元素，const重载
 */
const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

/**
 * 得到最后一个元素，const重载
 */
const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

/**
 * 删除最后一个元素
 */
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}