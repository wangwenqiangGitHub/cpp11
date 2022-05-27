//=====================================================================
//
// string.cpp - 
//
// Created by wwq on 2022/05/27
// Last Modified: 2022/05/27 13:28:15
// 参考:陈硕：https://coolshell.cn/articles/10478.html
//=====================================================================
#include <cstdio>
#include <cstring>
#include <iostream>
// 功能:
//能像int类一样，定义变量，并且支持赋值，赋值
//能用作为函数的参数类型和返回类型
//能用作标准库容器的元素类型，即vector/list/deque的value_type.(std::map的key_type是需要更进一步要求)

// 思路：
// 首先选择数据成员，最简单的String只有一个char*成员变量。好处是容易实现，坏处是某些操作的复杂度
// 较高(size()会是线性时间)。为了面试时写代码不出错，本文设计的String只有一个char* data_成员。而且
// 规定invariant如下:一个valid的string对象的data_保证不为NULL。data_以'\0'结尾，以方便配合c语言的str*()系列函数
// 支持操作，构造，析构，拷贝构造，赋值这几样操作，c++11的移动构造和移动赋值也可以有。

// strlen 函数是一个标准库函数，其作用为计算字符串的长度，但是不包括“\0”在内。

// 注意点:
// 只在构造函数里调用new char[],只在析构函数里调用delete[].
// 每个函数都在一两行代码，没有条件判断。
// 析构函数不必检查data_是否为NULL。
// 构造函数String(const char* str)没有检查str的合法性，这是一个永无止境的争论话题。
// 这里在初始化列表里就用到了str,因此在函数体内用assert()是无意义的。
class String
{
public:
	String()
		:date_(new char[1])
	{
		*date_ = '\0';
	}
	String(const char* str)
		:date_(new char[strlen(str) + 1])
	{
		strcpy(date_, str);
	}
	String(const String& rhs)
		:date_(new char[rhs.size() + 1])
	{
		strcpy(date_, rhs.c_str());
	}

	~String()
	{
		delete [] date_;
	}

	String& operator=(String rhs)
	{
		swap(rhs);
		return *this;
	}

	String(String&& rhs)
		: date_(rhs.date_)
	{
		rhs.date_ = nullptr;
	}

	String& operator=(String&& rhs)
	{
		swap(rhs);
		return *this;
	}

	size_t size() const
	{
		return strlen(date_);
	}

	const char* c_str() const
	{
		return date_;
	}

	void swap(String& rhs)
	{
		std::swap(date_, rhs.date_);
	}
private:
	char* date_;
};

int main()
{
	String aa = "abc";
	String bb = "edf";
	printf("aa:%s,%ld\n",aa.c_str(),aa.size());
	aa = bb;
	printf("aa:%s,%ld\n",aa.c_str(),aa.size());
	return 0;
}

# if 0
class String
{
public:
	String(const char* str = NULL);//普通构造函数
	String(const String& other); //拷贝构造函数
	String(String&& other);//移动构造函数
	~String(void);//析构函数
	String &operator =(const String& other);//赋值函数

	const char* c_str(){return m_data;}
	int length(){return m_size;}
private:
	char* m_data; //用于保存字符串
	int m_size;
};

//普通构造函数
String::String(const char* str)
{
	if(str==NULL)
	{
		//对于空字符串自动申请存放结束标志'\0'的空
		m_data = new char[1];
		//对m_data加NULL判断
		*m_data = '\0';
	}
	else{
		int length = strlen(str);
		m_data = new char[length+1];
		m_size = length;
		strcpy(m_data, str);
	}
}

// String的析构函数
String::~String()
{
	// 或者delete m_data;
	delete [] m_data;
}

//拷贝构造函数
String::String(const String& other)
{
	int length = strlen(other.m_data);
	m_data = new char[length+1];
	m_size = length;
	strcpy(m_data, other.m_data);
}

// 赋值构造
String& String::operator=(const String& other)
{
	if(this == &other)
		return *this;
	// 释放原有的内存资源
	if(m_data){
		delete [] m_data;
	}
	int length = strlen(other.m_data);
	m_data = new char[length+1];
	m_size = length;
	strcpy(m_data, other.m_data);
	return *this;
}

// 移动构造函数
String::String(String&& other){
	m_data = other.m_data;
	m_size = other.m_size;
	other.m_data = nullptr;
<<<<<<< HEAD
=======
}
#endif

int main()
{
	String aa = "abc";
	String bb = "edf";
	printf("aa:%s,%ld\n",aa.c_str(),aa.size());
	aa = bb;
	printf("aa:%s,%ld\n",aa.c_str(),aa.size());
	return 0;
>>>>>>> a656f10036166ae0fe3396cc9d02672c9b5f28b0
}
#endif

