#include <iostream>

using namespace std;

bool check[101];
int main() {
	int N;
	cin>>N;
	
	int a[N], b[N];
	for(int i=0; i<N; i++) {
		cin>>a[i];
		a[i]--;
	}
	
	for(int i=0; i<N; i++) {
		int x;
		cin>>x;
		
		b[x-1]=i;
	}
	
	int cycle=0, len=-1;
	for(int i=0; i<N; i++) {
		int next=i;
		
		int l=0;
		while(!check[next]) {
			check[next]=true;
			next=b[a[next]];
			l++;
		}
		
		if(l>1) {
			cycle++;
			len=max(len,l);
		}
	}

	cout<<cycle<<" "<<len;

	return 0;
}
