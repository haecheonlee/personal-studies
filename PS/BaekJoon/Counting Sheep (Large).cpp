#include <iostream>
#include <set>

using namespace std;

bool is_possible(bool *check) {
	bool pos=true;
	
	for(int i=0; i<=9; i++) {
		if(check[i]==false) 
			pos=false;
	}
	
	return pos;
}

int main() {
	int T;
	cin>>T;
	
	for(int tc=1; tc<=T; tc++) {
		int N;
		cin>>N;
		
		set<int> a;
		bool check[10] {false};
		int L=1;
		int x=N*L;
		while(a.find(x)!=a.end()==false && is_possible(check)==false) {
			a.insert(x);
			while(1) {
				check[x%10]=true;
				x/=10;
				if(x==0) break;
			}
			
			L++;
			x=N*L;
		}
		
		cout<<"Case #"<<tc<<": ";
		if(is_possible(check)) cout<<(L-1)*N<<'\n';
		else cout<<"INSOMNIA\n";
	}

	return 0;
}
