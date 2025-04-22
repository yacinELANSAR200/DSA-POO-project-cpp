#pragma once
#include <iostream>
using namespace std;
#include <stack>

class clsMyString
{
private:
	stack<string>_Undo;
	stack<string>_Redo;
	string _value;
public:
	void setValue(string NewValue)
	{
		_Undo.push(_value);
		_value = NewValue;
	}

	string getValue()
	{
		return _value;
	}
	__declspec(property(get = getValue, put = setValue))string value;

	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_value);
			_value = _Undo.top();
			_Undo.pop();
		}
	}
	void Redo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_value);
			_value = _Redo.top();
			_Redo.pop();
		}
	}

};

