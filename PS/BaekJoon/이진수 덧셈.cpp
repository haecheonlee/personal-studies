#include <iostream>
#include <stack>

using namespace std;

string trim(string s) {
	int len=s.length();
	int i;
	for(i=0; i<len; i++) {
		if(s[i]=='1') break;
	}
	
	if(i==len) return "0";
	return s.substr(i);
}

int main() {
	string a,b;
	cin>>a>>b;

	a=trim(a);
	b=trim(b);

	int i=a.length()-1;
	int j=b.length()-1;
	int temp;
	bool carry=false;
	stack<bool> result;
	
	while(i>=0 || j>=0 || carry) {
		int temp=((i>=0)?a[i--]-'0':0)+((j>=0)?b[j--]-'0':0)+carry;
		carry=(temp>=2);
		result.push(temp%2);
	}
	
	while(!result.empty()) {
		cout<<result.top();
		result.pop();
	}

	return 0;
}

/*
INPUT:
1001101 10010

OUTPUT:
1011111
*/
