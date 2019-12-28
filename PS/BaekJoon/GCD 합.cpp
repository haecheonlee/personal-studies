#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if(b==0) return a;
	else return gcd(b, a%b);
}

int main() {
	vector<int> v;

	int t;
	cin>>t;
	
	int n, num;
	for(int i=0; i<t; i++) {
		cin>>n;
		v.clear();
		
		for(int j=0; j<n; j++) {
			cin>>num;
			v.push_back(num);
		}
		
		long long int total=0;
		for(int j=0; j<v.size()-1; j++) {
			for(int x=j+1; x<v.size(); x++) {
				total+=gcd(v[j], v[x]);
			}
		}
		cout<<total<<'\n';
	}

	return 0;
}

/*
boj.kr/9613

INPUT:
3
4 10 20 30 40
3 7 5 12
3 125 15 25

OUTPUT:
70
3
35
*/
