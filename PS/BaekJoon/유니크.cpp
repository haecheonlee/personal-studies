#include <iostream>
#include <vector>

using namespace std;

bool checkIfExist(const vector<int> &v, int index) {
	bool exist = false;
	for(int i=0; i<v.size(); i++) {
		if(i == index) continue;
		
		if(v[index] == v[i]) {
			exist = true;
			break;
		}
	}
	
	return exist;
}

int main() {
	int N;
	cin>>N;
	
	int score1, score2, score3;
	
	vector<int> v1, v2, v3;
	for(int i=0; i<N; i++) {
		cin>>score1>>score2>>score3;
		v1.push_back(score1);
		v2.push_back(score2);
		v3.push_back(score3);
	}
	
	for(int i=0; i<v1.size(); i++) {
		int result = 0;
		if(!checkIfExist(v1, i)) result += v1[i];
		if(!checkIfExist(v2, i)) result += v2[i];
		if(!checkIfExist(v3, i)) result += v3[i];
	
		cout<<result<<endl;
	}

	return 0;
}

/*
boj.kr/5533

INPUT:
5
100 99 98
100 97 92
63 89 63
99 99 99
89 97 98

OUTPUT:
0
92
215
198
89
*/
