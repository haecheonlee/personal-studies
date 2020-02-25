#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int convertValue(const vector<int> &v) {
	int sum=0;
	for(int i=0; i<v.size(); i++) sum+=(v[v.size()-i-1]*pow(10,i));
	return sum;
}

int main() {
	vector<int> vec;
	
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++) vec.push_back(s[i]-'0');
	
	int startValue=convertValue(vec);
	next_permutation(vec.begin(), vec.end());
	int result=convertValue(vec);

	if(result>startValue) cout<<result;
	else cout<<0;
	
	return 0;
}

/*
boj.kr/2992

INPUT:
156

OUTPUT:
165
*/
