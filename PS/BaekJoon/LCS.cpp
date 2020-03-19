#include <iostream>

using namespace std;

int lcs[1001][1001];

int main() {
	string a,b;
	cin>>a>>b;

	a='0'+a;b='0'+b;
	
	int len1=a.length();
	int len2=b.length();
	
	int ans=-1;
	for(int i=1; i<len1; i++) {
		for(int j=1; j<len2; j++) {
			if(a[i]==b[j]) {
				lcs[i][j]=lcs[i-1][j-1]+1;
			} else {
				lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
			}
			
			ans=max(ans,lcs[i][j]);
		}
	}

	cout<<ans;

	return 0;
}

/*
INPUT:
ACAYKP
CAPCAK

OUTPUT:
4
*/
