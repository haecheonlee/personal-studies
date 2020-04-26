#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n;
		cin>>n;
		
		int mx=0;
		string player;
		
		while(n--) {
			int cost;
			string name;
			cin>>cost>>name;
			
			if(cost>mx) {
				mx=cost;
				player=name;
			}
		}
		
		cout<<player<<'\n';
	}

	return 0;
}

/*
INPUT:
2
3
10 Iversen
1000000 Nannskog
2000000 Ronaldinho
2
1000000 Maradona
999999 Batistuta

OUTPUT:
Ronaldinho
Maradona
*/
