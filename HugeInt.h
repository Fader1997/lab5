#ifndef HUGEINT_H_
#define HUGEINT_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

class HugeInt{
	public:
		HugeInt();
		HugeInt(int a);
		HugeInt(const char* a);
		HugeInt operator+(const HugeInt& a);
		HugeInt operator-(const HugeInt& a);
		HugeInt& operator=(const HugeInt& a);
		friend istream& operator>>(istream& input, HugeInt& a);
		friend ostream& operator<<(ostream& output, const HugeInt& a);
	private:
		int store[200];

};

#endif
