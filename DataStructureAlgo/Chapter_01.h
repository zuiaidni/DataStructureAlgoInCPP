#pragma once
#include<iostream>


//第一章所有函数测试的方法
void TestChapter_01();

//第一章 1.5节（不含1.5节）之前的程序测试
void TestChapter1_1();


void TestChapter1_2();


//函数与参数

//程序 1-1 计算一个整型表达式
int abc(int a, int b, int c);


//程序 1-2 计算一个浮点型表达式
float abc(float a, float b, float c);

//程序 1-3 利用模板函数计算一个表达式
template<class T>
T abc(T a, T b, T c)
{
	return a + b * c;
}

//程序 1-4 省略...

//程序 1-5 利用引用参数计算一个表达式
template<class T>
T abc2(const T& a, const T& b, const T& c)
{
	return a + b * c;
}

//程序 1-5 的更通用版本
template<class Ta, class Tb, class Tc>
Ta abc2(const Ta& a, const Tb& b, const Tc& c)
{
	return a + b * c;
}

//程序 1-10 为一个二维数组分配存储空间
//思路：先分配行指针，然后根据行指针再分配列，最后形成二维数组
template <class T>
bool Make2dArray(T ** & x, int numberOfRows, int numberOfColums)
{
	try 
	{
		//创建一个行指针
		x = new T * [numberOfRows];
		
		//为每一行分配空间
		for (size_t i = 0; i < numberOfColums; i++)
		{
			x[i] = new int[numberOfColums];
			return true;
		}

	}
	catch (std::bad_alloc) { return false; }
}

// 程序 1 - 12 释放函数Make2dArray中分配的空间
template <class T>
void Dele2dArray(T ** & x, int numberOfRows)
{
	//删除行数组空间
	for (size_t i = 0; i < numberOfRows; i++)
	{
		delete[] x[i];
	}

	delete[] x;

	x = NULL;
}

//接下来是Demo一个 处理货币类型currency的对象
//对象有三种成员：符号（+/-），美元和美分。操作方法为加减货币

enum signType { plus, minus};

//程序 1-13 currency的类声明
class Currency
{
public:
	Currency(signType theSign = plus, unsigned long theDollars = 0, unsigned int theCents = 0)
		: m_sign(theSign), m_dollars(theDollars), m_cents(theCents) { }
	
	~Currency() { }

	//程序 1-15 给私有数据成员赋值。（我按照了自己的理解去修改，感觉书上代码不是很合理）
	void SetValue(signType sign, unsigned long dollars, unsigned int cents);

	//程序 1-15 给私有数据成员赋值。（我按照了自己的理解去修改，感觉书上代码不是很合理）
	void SetValue(double money);

	//是正数 还是 负数
	signType GetSign() { return m_sign; }
	
	//返回美元
	unsigned long GetDollars() { return m_dollars; }
	
	//返回美分
	unsigned int GetCents() { return m_cents; }

	//程序相加
	Currency Add(const Currency& currency);

	//原书有这个案例 是程序 1-17 我认为不太符合逻辑，所以做了自己的优化和思路省略了
	//Currency& Increment(const Currency& currency);

	void output() const;

private:
	signType m_sign;
	unsigned long m_dollars;
	unsigned int m_cents;

};



