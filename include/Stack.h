#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <string>

using namespace std;

template <class ValType>
class Stack
{
private:
	ValType *stack;
	ValType *elem;
	int len_stack;
	int index_elem;
	void res_mem()
	{
		ValType *obl = new ValType[len_stack];
		for (int i = 0; i < len_stack; i++)
			obl[i] = stack[i];
		len_stack = len_stack + len_stack / 3 + 1;
		delete[] stack;
		stack = new ValType[len_stack];
		for (int i = 0; i <= index_elem; i++)
		{
			stack[i] = obl[i];
		}
	}
public:
	Stack()
	{
		len_stack = 9;
		stack = new ValType[len_stack];
		index_elem = -1;
	}
	Stack(int len)
	{
		if (len < 1)
			throw 1;
		len_stack = len;
		stack = new ValType[len_stack];
		index_elem = -1;
	}
	Stack(const Stack &s)
	{
		len_stack = s.len_stack;
		stack = new ValType[len_stack];
		index_elem = s.index_elem;
		for (int i = 0; i <= index_elem; i++)
		{
			stack[i] = s.stack[i];
		}
		elem = &stack[index_elem];
	}
	bool empty()
	{
		return (index_elem < 0);
	}
	bool full()
	{
		return (index_elem + 1 == len_stack);
	}
	int size()
	{
		return len_stack;
	}
	ValType top()
	{
		if (index_elem < 0)
			throw 1;
		return *elem;
	}
	void pop()
	{
		if (empty())
			throw 1;
		index_elem--;
		elem--;
	}
	void push(ValType inp)
	{
		if (full())
		{
			res_mem();
		}
		index_elem++;
		if (index_elem == 0)
		{
			stack[0] = inp;
			elem = &stack[0];
		}
		else
			elem++;
		*elem = inp;
		
	}
};

bool zad1(string s)
{
	Stack <char> brackets;
	int i = 0;
	while (i < s.length())
	{
		if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
			brackets.push(s[i]);
		else if ((s[i] == ')') && (brackets.top() == '(') || (s[i] == '}') && (brackets.top() == '{') || (s[i] == ']') && (brackets.top() == '['))
			brackets.pop();
		else if ((s[i] == ')') || (s[i] == '}') || (s[i] == ']'))
			return false;
		i++;
	}
	if (brackets.empty())
		return true;
	return false;
}
#endif
