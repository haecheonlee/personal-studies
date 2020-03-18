#include <iostream>
#include <algorithm>

using namespace std;

string calc(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	string result="";
	int next=0;
	for(int i=0; i<a.length(); i++) {
		int num1=a[i]-'0';
		int num2=(b.length()>i) ? b[i]-'0' : 0;
		int sum=num1+num2+next;
		
		if(sum>=10) {
			sum-=10;
			next=1;
		} else {
			next=0;
		}
		result+=(sum+'0');
	}
	if(next) result+='1';
	
	reverse(result.begin(), result.end());
	
	return result;
}

int main() {
	int n;
	cin>>n;
	
	string fib[n+1];
	
	fib[0]="0";
	if(n>=1) fib[1]="1";

	for(int i=2; i<=n; i++) fib[i]=calc(fib[i-1],fib[i-2]);
	
	cout<<fib[n];
	
	return 0;
}

/*
INPUT:
10

OUTPUT:
55
*/
