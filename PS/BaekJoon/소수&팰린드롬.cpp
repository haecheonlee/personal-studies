#include <iostream>

using namespace std;
const int MAX=1e6+1e5;

bool is_not_prime[MAX+1];
bool is_palindrome(string &s) {
	int len=s.size();
	for(int i=0; i<len/2; i++) {
		if(s[i]!=s[len-i-1]) return false;
	}
	
	return true;
}

int main() {
	is_not_prime[1]=true;
	for(int i=2; i<=MAX; i++) {
		for(int j=i+i; j<=MAX; j+=i) is_not_prime[j]=true;
	}
	
	int N;
	cin>>N;
	
	for(int i=N; i<=MAX; i++) {
		if(is_not_prime[i]) continue;
		
		string s=to_string(i);
		if(is_palindrome(s)) {
			cout<<s;
			break;
		}
	}
		
	return 0;
}
