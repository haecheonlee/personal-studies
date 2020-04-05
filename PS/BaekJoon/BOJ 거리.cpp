#include <iostream>
#include <vector>

using namespace std;

char check(char x) {
	if(x=='B') return 'J';
	else if(x=='O') return 'B';
	else if(x=='J') return 'O';
}

int main() {
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	
	vector<int> d(n,-1);
	d[0]=0;
	
	for(int i=1; i<n; i++) {
		char now=s[i];
		char prev=check(s[i]);
		
		for(int j=0; j<i; j++) {
			if(d[j]==-1) continue;
			if(s[j]!=prev) continue;
			
			int cost=d[j]+(i-j)*(i-j);
			if(d[i]==-1 || d[i]>cost) d[i]=cost;
		}
	}
	
	cout<<d[n-1];

	return 0;
}

/*
INPUT:
9
BOJBOJBOJ

OUTPUT:
8
*/
