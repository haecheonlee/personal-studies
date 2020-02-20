#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n,m,cnt=0;
	cin>>n;
	
	string s;
	unordered_map<string,int> dict;
	for(int i=0; i<n; i++) {
		cin>>s;
		dict[s]=1;
	}
	
	cin>>m;
	for(int i=0; i<m; i++) {
		cin>>s;
		if(dict[s]==1) cnt++;
	}
	
	cout<<cnt;
	return 0;
}

/*
boj.kr/13211

INPUT:
10
I220232074
D327045452
L261687170
H720628600
T181830847
I108428623
J316167657
M520837168
H364436380
J531555744
5
U133207838
D327045452
S374500074
U882158042
H364436380

OUTPUT:
2
*/
