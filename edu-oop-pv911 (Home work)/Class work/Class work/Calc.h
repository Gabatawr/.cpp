#pragma once
#include "header.h"

using namespace std;


class Calc
{
	static string m_data;
	static int getPrioryti(const char c);
	static int operation(const int a, const int b, const char op);
	
public:
	explicit Calc() = default;
	static int getResult(string d);
};

string Calc::m_data = "";

inline int Calc::getResult(string d)
{
	m_data = d;
	Stack<int> num;
	Stack<char> op;
	auto i = 0;
	while (m_data[i])
	{
		if (isdigit(m_data[i]))
		{
			auto ch = 0;
			while (isdigit(m_data[i]))
			{
				ch = ch * 10 + (m_data[i] - 48);
				i++;
			}
			num.push(ch);
		};
		if (m_data[i] == '*' || m_data[i] == '/' || m_data[i] == '+' || m_data[i] == '-')
		{
			if (op.empty())
				op.push(m_data[i]);
			else
			{
				if (getPrioryti(m_data[i]) >= getPrioryti(op.head()))
				{
					op.push(m_data[i]);
				}
				else
				{
					auto b = num.pop();
					auto a = num.pop();
					num.push(operation(a, b, op.pop()));
					op.push(m_data[i]);
				}
			}
			i++;
		};
		if (m_data[i] == '(')
		{
			op.push(m_data[i]);
			i++;
			while (m_data[i] != ')')
			{
				if (isdigit(m_data[i]))
				{
					auto ch = 0;
					while (isdigit(m_data[i]))
					{
						ch = ch * 10 + (m_data[i] - 48);
						i++;
					}
					num.push(ch);
				};
				if (m_data[i] == '*' || m_data[i] == '/' || m_data[i] == '+' || m_data[i] == '-')
				{
					if (op.head() == '(')
						op.push(m_data[i]);
					else
					{
						if (getPrioryti(m_data[i]) >= getPrioryti(op.head()))
							op.push(m_data[i]);
						else
						{
							auto b = num.pop();
							auto a = num.pop();
							num.push(operation(a, b, op.pop()));
							op.push(m_data[i]);
						}
					}
					i++;
				}
			}
			while (op.head() != '(')
			{
				auto b = num.pop();
				auto a = num.pop();
				num.push(operation(a, b, op.pop()));
			}
			op.pop();
			i++;
		}
	}

	while (!op.empty())
	{
		auto b = num.pop();
		auto a = num.pop();
		num.push(operation(a, b, op.pop()));
	}

	return num.head();
}

inline int Calc::getPrioryti(const char c)
{
	switch (c)
	{
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;
	default:
		break;
	}
}

inline int Calc::operation(const int a, const int b, const char op)
{

	switch (op)
	{
	case '+': return a + b; break;
	case '-': return a - b; break;
	case '*': return a * b; break;
	case '/': return a / b; break;
	default:
		break;
	}
}