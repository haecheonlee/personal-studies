#include <iostream>

using namespace std;

int main() {
	int _max, _min;
	
	int n,score;
	cin>>n;
	
	for(int i=0; i<n; i++) {
		cin>>score;
		
		if(i==0) {
			_max=score;
			_min=score;
		} else{ 
			_max=max(_max,score);
			_min=min(_min,score);
		}
	} 
	
	cout<<_max-_min;
	
	return 0;
}

/*
boj.kr/15969

INPUT:
8
85 42 79 95 37 11 72 32

OUTPUT:
84
*/
