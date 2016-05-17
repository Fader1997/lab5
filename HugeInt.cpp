#include "HugeInt.h"

HugeInt::HugeInt(){
	for(int i = 0; i < 200; i++)
	store[i] = 0;
}

HugeInt::HugeInt(int a){
	for(int i = 0; i < 200; i++){
		store[i] = 0;
	}
	int j =0;
	while(a != 0){
		store[j] = a % 10;
		a /= 10;
		j++;
	}
}

HugeInt::HugeInt(const char* a){
	for(int i = 0; i < 200; i++){
		store[i] = 0;
	}
	int length = strlen(a);
	for(int i = length - 1; i >= 0; --i){
		store[length - i - 1] = a[i] - '0';
	}
}

HugeInt& HugeInt::operator=(const HugeInt& a){
	for(int i = 0; i < 200; i++){
		store[i] = a.store[i];
	}
	return *this;
}

HugeInt HugeInt::operator+(const HugeInt& a){
	int i = 0;
	int lens = 0;
	HugeInt result;
	while(i < 200){
		result.store[i] = store[i] + a.store[i] + lens;
		lens = result.store[i] / 10;
		result.store[i] %= 10;
		i++;
	}
	return result;
}

HugeInt HugeInt::operator-(const HugeInt& a){
	int i = 0;
	int slen = 0;
	HugeInt result;
	while(i < 200){
		result.store[i] = store[i] - a.store[i] - slen;
		if(result.store[i] < 0){
			slen = 1;
			result.store[i] += 10; 
		}
		else
			slen = 0;
		i++;
	}													   
	return result;
}

istream& operator>>(istream& input, HugeInt& a){
	int temp[200] = {0};
	int c = 0;
	char sr;
	input.get(sr);
	while(sr != '\n'){
		temp[c] = sr - '0';
		c++;  
		input.get(sr);
	}
	c--;
	int j = c;
	while(c >= 0){
		a.store[c] = temp[0 + j - c];
		c--;
	}
	return input;
}

ostream& operator<<(ostream& output, const HugeInt& a){
	int i = 199;
	while(a.store[i] == 0)
		i--;
	if(i <= 0)
		output << 0;
	while(i >= 0){
		output << a.store[i];
		i--;
	}
	return output;
}
