#include <iostream>
#include <numeric>

using namespace std;

#define SIZE 8

int main() {
	int list[SIZE];
	
	int total = 0, mushroom;
	for(int i=0; i<SIZE; i++) {
		cin>>mushroom;
		total += mushroom;
		list[i] = mushroom;
	}
	
	int max = 0;
	for(int i=0; i<SIZE-3; i++) {
		int result1 = 0, result2 = 0;
		
		for(int j=i; j<i+4; j++) {
			result2 += list[j];
		}
		
		result1 = total - result2;
		int selected = (result1 > result2) ? result1 : result2;
		max = (max > selected) ? max : selected; 
	}
	
	cout<<max<<endl;

	return 0;
}

/*
boj.kr/10643

INPUT:
2
6
5
3
3
7
2
6

OUTPUT:
19
*/
