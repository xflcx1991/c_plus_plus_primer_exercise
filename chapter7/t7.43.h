class NoDefault
{
public:
    NoDefault(int targ):arg1(targ){}
private:
    int arg1;
};

class C
{
public:
    C():ndf(NoDefault(1)){}; //这是匿名对象？可以的。
private:
    NoDefault ndf;
};