#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	
	vector<double> v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	
	stack<char> c;
	stack<double> d;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='A' && s[i]<=(int)'Z') {
			d.push(v[int(s[i]-65)]);
			c.push(s[i]);
		} else {
			double l[2];
			for(int j=1; j>=0; j--) {
				if(c.top()>='A' && c.top()<='Z') {
					l[j]=v[int(c.top()-65)];
					d.pop();
					c.pop();
				} else {
					l[j]=d.top();
					d.pop();
					c.pop();
				}
			}

			double result=0;
			if(s[i]=='*') result=l[0]*l[1];
			if(s[i]=='+') result=l[0]+l[1];
			if(s[i]=='-') result=l[0]-l[1];
			if(s[i]=='/') result=l[0]/l[1];
			
			d.push(result);
			c.push('+');
		}
	}

	cout<<fixed<<setprecision(2)<<d.top();

	return 0;
}

/*
boj.kr/1935

INPUT:
5
ABC*+DE/-
1
2
3
4
5

OUTPUT:
6.20
*/
