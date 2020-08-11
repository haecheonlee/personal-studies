#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int a[N];
	string s[N];
	for(int i=0; i<N; i++) {
		cin>>a[i];
		a[i]--;
	}
	
	for(int i=0; i<N; i++) cin>>s[i];
	
	// three shuffles
	for(int i=0; i<3; i++) {
		string cpy[N];
		for(int j=0; j<N; j++) cpy[j]=s[a[j]];
		for(int j=0; j<N; j++) s[j]=cpy[j];
	}
	
	for(int i=0; i<N; i++) cout<<s[i]<<'\n';
	
	return 0;
}
