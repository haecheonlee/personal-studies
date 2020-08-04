/* https://mygumi.tistory.com/126 */

#include <iostream>

using namespace std;

int d[4001][4001];

int main() {
	
	string s1, s2;
	cin>>s1>>s2;
	
	int ans=0;
	for(int i=1; i<=s1.size(); i++) {
		for(int j=1; j<=s2.size(); j++) {
			if(s1[i-1]==s2[j-1]) {
				d[i][j]=d[i-1][j-1]+1;
				if(ans<d[i][j]) ans=d[i][j];	
			}
		}
	}
	cout<<ans;
	
	return 0;
}
