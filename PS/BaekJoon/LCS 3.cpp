#include <iostream>

using namespace std;

int lcs[101][101][101] {0};

int main() {
	string a,b,c;
	cin>>a>>b>>c;
	
	a='0'+a;
	b='0'+b;
	c='0'+c;
	
	int len1=a.length();
	int len2=b.length();
	int len3=c.length();
	
	for(int i=1; i<len1; i++) {
		for(int j=1; j<len2; j++) {
			for(int k=1; k<len3; k++) {
				if(a[i]==b[j] && b[j]==c[k]) {
					lcs[i][j][k]=lcs[i-1][j-1][k-1]+1;
				} else {
					lcs[i][j][k]=max(lcs[i-1][j][k], max(lcs[i][j-1][k],lcs[i][j][k-1]));
				}
			}
		}
	}
	
	cout<<lcs[len1-1][len2-1][len3-1];
	
	return 0;
}

/*
INPUT:
abcdefghijklmn
bdefg
efg

OUTPUT:
3
*/
