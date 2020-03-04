#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	double a,b;
	cin>>a>>b;
	
    double result = sqrt(a * b);
	
	cout<<fixed<<setprecision(3)<<result<<" "<<result;
	
	return 0;
}

/*
boj.kr/12012

INPUT:
1 1

OUTPUT:
1.000 1.000
*/
