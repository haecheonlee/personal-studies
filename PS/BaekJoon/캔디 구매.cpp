#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double C;
	int K;
	cin>>C>>K;
	
	long p = pow(10, K);
	
	double result = (C / p);
    result = round(result);
	result *= p;
	
	cout<<(long)result;	

	return 0;
}

/*
boj.kr/2909

INPUT:
184 1

OUTPUT:
180
*/
