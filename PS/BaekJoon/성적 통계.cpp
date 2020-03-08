#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin>>t;
	
	int index=1;
	while(t--) {
		int n;
		cin>>n;
		
		int a[n],largest=-1,smallest=101,gap=0;
		for(int i=0; i<n; i++) { 
			cin>>a[i];
			
			largest=max(largest,a[i]);
			smallest=min(smallest,a[i]);
		}
		sort(a,a+n);
		for(int i=n-1; i>=1; i--) gap=max(a[i]-a[i-1],gap);
		
		cout<<"Class "<<index++<<'\n';
		cout<<"Max "<<largest<<", Min "<<smallest<<", Largest gap "<<gap<<'\n';
	}
	
	return 0;
}

/*
boj.kr/5800

INPUT:
2
5 30 25 76 23 78
6 25 50 70 99 70 90

OUTPUT:
Class 1
Max 78, Min 23, Largest gap 46
Class 2
Max 99, Min 25, Largest gap 25
*/
