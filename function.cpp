#include <string>
#include <iostream>
// #include <functional>

void hello(std::string str)
{
	std::cout << str << std::endl;
}

template<typename Fty>
class myfunction {};


template<typename R,typename A1>
class myfunction<R(A1)>
{
public:
	using PFUNC = R(*)(A1);
	myfunction(PFUNC pfunc): _pfunc(pfunc){}
	R operator()(A1 arg)
	{
		return _pfunc(arg);
	}
private:
	PFUNC _pfunc;
};

int main()
{
	myfunction<void (std::string)> fuci(hello);

	fuci("hello world");
	return 0;
}
