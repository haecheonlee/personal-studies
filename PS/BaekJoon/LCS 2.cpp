#include <iostream>
#include <stack>

using namespace std;

int lcs[1001][1001];

int main() {
	string a,b;
	cin>>a>>b;
	
	a='0'+a;
	b='0'+b;
	
	int len1=a.length();
	int len2=b.length();
	
	for(int i=1; i<len1; i++) {
		for(int j=1; j<len2; j++) {
			if(a[i]==b[j]) {
				lcs[i][j]=lcs[i-1][j-1]+1;
			} else {
				lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	
	cout<<lcs[len1-1][len2-1]<<'\n';
	
	int i=len1-1;
	int j=len2-1;
	stack<int> st;
	
	while(lcs[i][j]!=0) {
		if(lcs[i][j]==lcs[i-1][j]) {
			i--;
		} else if(lcs[i][j]==lcs[i][j-1]) {
			j--;
		} else if((lcs[i][j]-1)==lcs[i-1][j-1]) {
			st.push(i);
			i--;
			j--;
		}
	}
	
	while(!st.empty()) {
		cout<<a[st.top()];
		st.pop();
	}
	
	return 0;
}

/*
INPUT:
ACAYKP
CAPCAK

OUTPUT:
4
ACAK
*/
