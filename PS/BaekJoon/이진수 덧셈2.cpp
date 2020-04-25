#include <iostream>
#include <stack>

using namespace std;

string trim(string s) {
	int i;
	for(i=0; i<s.size(); i++) {
		if(s[i]=='1') return s.substr(i);
	}
	
	return "0";
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		string a,b;
		cin>>a>>b;
		
		a=trim(a);
		b=trim(b);
		
		int i=a.size()-1;
		int j=b.size()-1;
		bool carry=false;
		
		stack<int> result;
		while(i>=0 || j>=0 || carry) {
			int sum=((i>=0)?a[i--]-'0':0)+((j>=0)?b[j--]-'0':0)+carry;
			
			carry=(sum>=2);
			result.push(sum%2);
		}

		while(!result.empty()) {
			cout<<result.top();
			result.pop();
		}
		cout<<'\n';
	}
	
	return 0;
}

/*
INPUT:
3
1001101 10010
1001001 11001
1000111 1010110

OUTPUT:
1011111
1100010
10011101
*/
