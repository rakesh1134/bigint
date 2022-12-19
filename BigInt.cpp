#include "BigInt.h"
#include <sstream>
#include <vector>

BigInt::BigInt(unsigned int v)
{
	ClearV();
	int index = SIZE-1;
	int t = v;
	while (t != 0 && index >=0)
	{
		int r = t % 10;
		t = t / 10;
		_v[index--] = r;
	}
}

BigInt::BigInt()
{
	ClearV();
}

BigInt::BigInt(const string& s)
{
	ClearV();
	int index = SIZE - 1;
	for(int j = s.length() - 1; j >= 0; --j)
	{
		_v[index--] = s[j] - '0';
	}
}

void BigInt::ClearV()
{
	for (int i = 0; i < SIZE; ++i)
		_v[i] = -1;
}

ostream& operator<<(ostream& os, const BigInt& b)
{
	for (int i = 0; i < SIZE; ++i)
		cout << b._v[i];
	cout << endl;
	return os;
}

BigInt operator+(const BigInt& i1, const BigInt& i2)
{
	std::string sSumFinal;
	int carry = 0;
	for (int i = SIZE - 1; i >= 0; --i)
	{
		stringstream strStream;

		int d1 = i1._v[i];
		int d2 = i2._v[i];
		if (d1 == -1) d1 = 0;
		if (d2 == -1) d2 = 0;
		int sum = carry + d1 + d2;
		carry = sum / 10;
		sum = sum % 10;
		strStream << sum;
		sSumFinal = strStream.str() + sSumFinal;
	}
	BigInt sum(sSumFinal);
	return sSumFinal;
}

BigInt operator*(const BigInt& num1, const BigInt& num2)
{
	BigInt Prod3(0);

	vector<BigInt> _Prods;

	int Exp1 = 0;
	for (int i = SIZE - 1; i >= 0; --i)
	{
		BigInt Prod1(0);
		int d1 = num1._v[i];
		if(d1 == -1)
			break;
		int Exp = 0;
		bool bFirst = true;
		for (int j = SIZE - 1; j >= 0; --j)
		{
			int d2 = num2._v[j];
			if (d2 == -1)
				break;
			BigInt Prod2(d1 * d2);
			if (bFirst == true)
			{
				Prod1 = Prod2 + Prod1;
				bFirst = false;
			}
			else
			{
				Prod1 = Prod2.MulBy10(Exp) + Prod1;
			}
			++Exp;
		}
		_Prods.push_back(Prod1);
	}

	for (int i = 0; i < _Prods.size(); ++i)
	{
		_Prods[i] = _Prods[i].MulBy10(i);
	}

	if (_Prods.size() > 0)
	{
		Prod3 = _Prods[0];
		for (int i = 1; i < _Prods.size(); ++i)
		{
			Prod3 = Prod3 + _Prods[i];
		}
	}

	return Prod3;
}

BigInt& BigInt::MulBy10(int Power)
{
	for (int i = 1; i <= Power; ++i)
	{
		for (int j = 0; j < SIZE - 1; ++j)
		{
			_v[j] = _v[j + 1];
		}
		_v[SIZE - 1] = 0;
	}
	return *this;
}