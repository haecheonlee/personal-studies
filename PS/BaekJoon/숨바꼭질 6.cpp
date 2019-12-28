#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if(b==0) return a;
	else return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, S, a;
	cin>>N>>S;
	
	vector<int> v;
	for(int i=0; i<N; i++) {
		cin>>a;
		v.push_back(a);
	}
	
	int result=0;
	if(v.size() > 1) {
		result=gcd(abs(v[0]-S), abs(v[1]-S));
		for(int i=2; i<v.size(); i++) {
			result = gcd(result, abs(v[i]-S));
		}
	} else {
		result = v[0]-S;
	}
	
	cout<<result;
	
	return 0;
}

/*
boj.kr/17087

INPUT:
3 81
33 105 57

OUTPUT:
24
*/
