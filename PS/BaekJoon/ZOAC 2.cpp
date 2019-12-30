#include <iostream>
#include <cmath>

using namespace std;

int main() {
	string s;
	cin>>s;
	
	int current_position=0, shortest=0;
	for(int i=0; i<s.size(); i++) {
		int next_position=(int)(s[i]-65);
		
		int small = (next_position > current_position) ? current_position : next_position;
		int big = (next_position > current_position) ? next_position : current_position;
		
		int right_side = abs(big-small);
		int left_side = abs((26-big)+small);
		shortest += (right_side > left_side) ? left_side : right_side;
		
		current_position=next_position;
	}
	
	cout<<shortest;
	
	return 0;
}

/*
boj.kr/18238

INPUT:
LBOLVUEEPMOIENMG

OUTPUT:
100
*/
