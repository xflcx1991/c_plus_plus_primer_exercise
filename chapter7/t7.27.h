//在7.24上修改
#include <string>
#include <ostream>

class Screen
{
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
    Screen& move(pos r, pos c);
    Screen& set(char ch);
    Screen& display(std::ostream &os);

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
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

Screen& Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

Screen& Screen::set(char ch)
{
    contents[cursor] = ch;
    return *this;
}

Screen& Screen::display(std::ostream &os)
{
    os << contents;
    return *this;
}
