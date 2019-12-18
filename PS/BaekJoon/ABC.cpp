#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v;
	
	int num = 0;
	for(int i=0; i<3; i++) {
		cin>>num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	
	string s;
	cin>>s;
	
	for(int i=0; i<s.size(); i++) {
		switch(s[i]) {
			case 'A':
				cout<<v[0]<<" ";
				break;
			case 'B':
				cout<<v[1]<<" ";
				break;
			case 'C':
				cout<<v[2]<<" ";
				break;
		}
	}
	
	return 0;
}

/*
boj.kr/3047

INPUT:
1 5 3
ABC

OUTPUT:
1 3 5
*/
