#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14159265358979

int main() {
	double r;
	cin>>r;
		
	double u = PI * r * r;
	double t = 2 * r * r;
	
  cout<<fixed<<setprecision(6)<<u<<endl;
	cout<<fixed<<setprecision(6)<<t<<endl;
	
	return 0;
}

/*
boj.kr/3053

INPUT:
1

OUTPUT:
3.141593
2.000000
*/
