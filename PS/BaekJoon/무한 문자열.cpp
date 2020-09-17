#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int main() {
	string s,t;
	cin>>s>>t;
	
	if(s.size()>t.size()) swap(s,t);
	
	int N=s.size();
	int M=t.size();
	
	string c1=s, c2=t;
	int g=gcd(N,M);
	int L=(N/g)*(M/g)*g;

	while(s.size()<L) s+=c1;
	while(t.size()<L) t+=c2;
	
	cout<<(s==t);

	return 0;
}
