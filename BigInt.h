#pragma once
#include <iostream>
using namespace std;

const unsigned int SIZE = 50;
class BigInt
{
	unsigned int _v[SIZE];
public:
	BigInt();
	BigInt(unsigned int v);
	BigInt(const string& s);
	BigInt& MulBy10(int Power);
	friend ostream& operator<<(ostream& os, const BigInt& i);
	friend BigInt operator+(const BigInt& i1, const BigInt& i2);
	friend BigInt operator*(const BigInt& i1, const BigInt& i2);
	friend BigInt operator*(const BigInt& i1, const BigInt& i2);
private:
	void ClearV();
};
