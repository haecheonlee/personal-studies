#include <iostream>

using namespace std;

bool d[30][30];
int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		char x,y;
		string is;
		cin>>x>>is>>y;
		
		d[x-'a'][y-'a']=true;
	}
	
	for(int k=0; k<26; k++) {
		for(int i=0; i<26; i++) {
			for(int j=0; j<26; j++) {
				d[i][j]=(d[i][j] || (d[i][k] && d[k][j]));
			}
		}
	}
	
	int M;
	cin>>M;

	for(int i=0; i<M; i++) {
		char x,y;
		string is;
		cin>>x>>is>>y;
	
		if(d[x-'a'][y-'a']) cout<<"T\n";
		else cout<<"F\n";
	}

	return 0;
}
