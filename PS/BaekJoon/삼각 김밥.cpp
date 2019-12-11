#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double X, Y;
	cin>>X>>Y;
	
	double result = (1000 / Y) * X; 
	
	int N;
	cin>>N;
	
	double _x, _y;
	double selected_result;
	for(int i=0; i<N; i++) {
		cin>>_x>>_y;
		selected_result = (1000 / _y )* _x;
		
		if(result > selected_result) {
			result = selected_result;	
		} 
	}
	
	cout<<fixed<<setprecision(2)<<result<<endl;
	
	return 0;
}
/*
boj.kr/2783

INPUT:
5 100
3
4 100
3 100
7 100

OUTPUT:
30.00
*/
