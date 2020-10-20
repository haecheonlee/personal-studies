#include <iostream>
#include <set>

using namespace std;

int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int main() {
	int a,b;
	cin>>a>>b;
	
	int r=gcd(a,b);
	set<int> div;
	for(int i=1; i*i<=r; i++) {
		if(r%i==0) { div.insert(i); div.insert(r/i); }
	}
	
	for(auto it : div) cout<<it<<' '<<a/it<<' '<<b/it<<'\n';

	return 0;
}
