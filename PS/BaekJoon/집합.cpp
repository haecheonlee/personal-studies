#include <iostream>

using namespace std;

string s;
int x;
bool check[25] {false};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	while(n--) {
		cin>>s;
		
		if(s=="all") {
			for(int i=1; i<=20; i++) check[i]=true;
		} else if(s=="empty") {
			for(int i=1; i<=20; i++) check[i]=false;
		} else {
			cin>>x;
			
			if(s=="add") {
				if(check[x]==false) check[x]=true;
			} else if(s=="remove") {
				if(check[x]==true) check[x]=false;
			} else if(s=="check") {
				if(check[x]) cout<<1<<'\n';
				else cout<<0<<'\n';
			} else if(s=="toggle") {
				if(check[x]==true) check[x]=false;
				else check[x]=true;
			}
		}
	}

	return 0;
}

/*
INPUT:
26
add 1
add 2
check 1
check 2
check 3
remove 2
check 1
check 2
toggle 3
check 1
check 2
check 3
check 4
all
check 10
check 20
toggle 10
remove 20
check 10
check 20
empty
check 1
toggle 1
check 1
toggle 1
check 1

OUTPUT:
1
1
0
1
0
1
0
1
0
1
1
0
0
0
1
0
*/
