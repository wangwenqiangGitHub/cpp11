//=====================================================================
//
// string.cpp - 
//
// Created by wwq on 2022/05/27
// Last Modified: 2022/05/27 13:28:15
//
//=====================================================================
#include <cstdio>
#include <cstring>
#include <iostream>

class String
{
public:
	String(const char* str = NULL);//普通构造函数
	String(const String& other); //拷贝构造函数
	String(const String&& other);//移动构造函数
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

int main(){
	String aa = "abc";
	String bb = "edf";
	printf("aa:%s,%d\n",aa.c_str(),aa.length());
	aa = bb;
	printf("aa:%s,%d\n",aa.c_str(),aa.length());
	return 0;
}
