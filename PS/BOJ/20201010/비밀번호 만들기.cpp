/* reference: https://www.acmicpc.net/problem/9252 */

#include <iostream>
#include <stack>

using namespace std;

const int MAX=42;

int d[MAX][MAX];

int main() {
	string a,b;
	cin>>a>>b;
	
	a=' '+a;
	b=' '+b;
	
	int N=a.size();
	int M=b.size();

	for(int i=1; i<N; i++) {
		for(int j=1; j<M; j++) {
			if(a[i]==b[j]) {
				d[i][j]=d[i-1][j-1]+1;
			} else {
				d[i][j]=max(d[i-1][j], d[i][j-1]);
			}
		}
	}
	
	int i=N-1, j=M-1;
	stack<int> stk;
	while(d[i][j]!=0) {
		if(d[i][j]==d[i-1][j]) i--;
		else if(d[i][j]==d[i][j-1]) j--;
		else if((d[i][j]-1)==d[i-1][j-1]) stk.push(i), i--, j--;
	}
	
	while(!stk.empty()) {
		cout<<a[stk.top()];
		stk.pop();
	}
	
	return 0;
}
