#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	
	int score=0;
	for(int i=0; i<50; i++) {
		cin>>score;
		v.push_back(score);
	}
	
	int my_score=0;
	cin>>my_score;
	
	int count=0;
	for(int i=0; i<v.size(); i++) {
		if(v[i] == my_score) { 
			count = i + 1;
			break;
		}
	}
	
	if(count <= 5) {
		cout<<"A+";
	} else if(count <= 15) {
		cout<<"A0";
	} else if(count <= 30) {
		cout<<"B+";
	} else if(count <= 35) {
		cout<<"B0";
	} else if(count <= 45) {
		cout<<"C+";
	} else if(count <= 48) {
		cout<<"C0";
	} else {
		cout<<"F";
	}
	
	return 0;
}

/*
boj.kr/17826

INPUT:
285 271 270 268 264 251 237 236 228 227 226 225 224 217 216 205 198 193 192 190 182 168 165 161 157 146 141 135 127 126 122 114 105 81 80 76 70 67 63 59 55 44 34 24 19 14 9 5 2 1
251

OUTPUT:
A0
*/
