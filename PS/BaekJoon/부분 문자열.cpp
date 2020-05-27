#include <iostream>

using namespace std;

int mod=127;
int base=256;

int _HASH(string s) {
	int ans=0;
	for(char ch :s) ans=(ans*base+ch)%mod;
	
	return ans;
}

int match(string &s, string &p) {
	int n=s.length();
	int m=p.length();
	
	if(n<m) return 0;
	
	int hash_p = _HASH(p);
	int hash_s = _HASH(s.substr(0,m));	// p[0...m-1];
	
	int first=1;
	for(int i=0; i<m-1; i++) first = (first * base) % mod;
	
	for(int i=0; i<=n-m; i++) {
		if(hash_p == hash_s) {
			if(s.substr(i,m) == p) return 1;
		}
		
		if(i+m<n) {
			hash_s = hash_s - (s[i] * first) % mod;
			hash_s = (hash_s + mod)%mod;	// to prevent negative value
			hash_s = ((hash_s * base) % mod + s[i+m]) % mod;
		}
	}
	
	return 0;
}

int main() {
	string s,p;
	cin>>s>>p;
	
	cout<<match(s,p);

	return 0;
}
