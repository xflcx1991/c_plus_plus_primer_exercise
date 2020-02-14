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

#include <string>
#include <vector>

class Screen;

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex index);
    Window_mgr() = default;
    Window_mgr(Screen &);

public:
    std::vector<Screen> screens;
};

class Screen
{
    friend void Window_mgr::clear(ScreenIndex index);

public:
    //类型成员
    using pos = std::string::size_type;

    //默认构造函数
    Screen() = default;
    //接受宽和高，将contents初始化成给定数量的空白
    Screen(pos ht, pos wd);
    //接受宽和高以及一个字符，该字符作为初始化后屏幕的内容
    Screen(pos ht, pos wd, char c);

    char get() const;
    char get(pos r, pos c) const;
    Screen &move(pos r, pos c);
    Screen &set(char ch);
    Screen &display(std::ostream &os);
    
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
    pos size() const
    {
        return height * width;
    }
};

Screen::Screen(pos ht, pos wd)
    : height(ht), width(wd), contents(ht * wd, ' ')
{
}

Screen::Screen(pos ht, pos wd, char c)
    : height(ht), width(wd), contents(ht * wd, c)
{
}

char Screen::get() const
{
    return contents[cursor];
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

Screen &Screen::set(char ch)
{
    contents[cursor] = ch;
    return *this;
}

Screen &Screen::display(std::ostream &os)
{
    os << contents;
    return *this;
}

// pos Screen::size() const
// {
//     return height * width;
// }

Window_mgr::Window_mgr(Screen& screen)
{
    screens.push_back(screen);
}

void Window_mgr::clear(ScreenIndex index)
{
    Screen &s = screens[index];
    s.contents = std::string(s.height * s.width, ' ');
}

