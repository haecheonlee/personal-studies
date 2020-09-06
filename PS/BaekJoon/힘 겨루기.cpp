#include <iostream>

using namespace std;

const int MAX=1e6+1;

int a[MAX];
int p1[MAX], p2[MAX];

int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) {
		cin>>a[i];
		p1[i]=max(p1[i-1], a[i]);	
	}

	p2[N]=a[N];
	for(int i=N-1; i>=1; i--) p2[i]=max(p2[i+1], a[i]);

	int R=0, B=0;
	for(int i=1; i<N; i++) {
		if(p1[i]<p2[i+1]) B++;
		else if(p1[i]>p2[i+1]) R++;
	}
	
	if(R==B) cout<<'X';
	else if(R<B) cout<<'B';
	else cout<<'R';

	return 0;
}
