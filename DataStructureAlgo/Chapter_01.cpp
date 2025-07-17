#include "Chapter_01.h"
#include <iostream>

int abc(int a, int b, int c)
{
	return a + b * c;
}

float abc(float a, float b, float c)
{
	return a + b * c;
}

void TestChapter1_1()
{
	using namespace std;
	cout << "test Function named abc(1,2,3) = " << abc(1, 2, 3) << endl;
	cout << "test Function named abc(1.1,2,3) = " << abc(1.1f, 2.f, 3.f) << endl;
	cout << "test Template func named abc<double>(1.0, 2.0, 4.1) = " << abc<double>(1.0, 2.0, 4.1) << endl;
	cout << "test Template func named abc2 <double>(1.0, 2.0, 4.2) = " << abc2<double>(1.0, 2.0, 4.2) << endl;
	cout << "test Template func named abc2 <double>(3.0, 2, 4) = " << abc2<double,int,int>(3.0, 2, 4) << endl;

}

void TestChapter1_2()
{

}

//所有第一章节的代码测试函数
void TestChapter_01()
{
	TestChapter1_1();

	TestChapter1_2();
}



void Currency::SetValue(signType sign, unsigned long dollars, unsigned int cents)
{
	if (cents > 99)
	{
		throw std::invalid_argument("Cents must be less than 100");
	}

	this->m_sign = sign;
	this->m_dollars = dollars;
	this->m_cents = cents;
}


void Currency::SetValue(double money)
{

	m_dollars = (unsigned long)money;
	m_cents = (unsigned int)((money - m_dollars) * 100);
	if(money < 0)
		m_sign = signType::minus;
	else 
		m_cents = signType::plus;
}


Currency Currency::Add(const Currency& currency)
{
	double Mycurrency = m_dollars + m_cents / 100.0;
	double currency1 = currency.m_dollars + currency.m_cents / 100.0;
	double sum = Mycurrency + currency1;

	this->m_dollars = (unsigned long)sum;
	this->m_cents = (unsigned int)((sum - m_dollars) * 100);

	if(sum < 0)
		m_sign = signType::minus;
	else
		m_sign = signType::plus;
	return *this;
}

void Currency::output() const
{
	using std::cout;
	if (m_sign == signType::minus) cout << '-';
	else if (m_sign == signType::plus) cout << '+';

	cout << "＄ " << m_dollars << '.' << m_cents;
}