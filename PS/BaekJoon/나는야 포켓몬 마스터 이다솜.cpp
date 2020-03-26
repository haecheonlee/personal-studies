#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	map<int,string> m1;
	map<string,int> m2;
	
	string name;
	for(int i=1; i<=n; i++) {
		cin>>name;
		
		m1[i]=name;
		m2[name]=i;
	}
	
	string q;
	while(m--) {
		cin>>q;
		
		if(isdigit(q[0])) {
			cout<<m1[stoi(q)]<<'\n';
		} else {
			cout<<m2[q]<<'\n';
		}
	}

	return 0;
}

/*
INPUT:
26 5
Bulbasaur
Ivysaur
Venusaur
Charmander
Charmeleon
Charizard
Squirtle
Wartortle
Blastoise
Caterpie
Metapod
Butterfree
Weedle
Kakuna
Beedrill
Pidgey
Pidgeotto
Pidgeot
Rattata
Raticate
Spearow
Fearow
Ekans
Arbok
Pikachu
Raichu
25
Raichu
3
Pidgey
Kakuna

OUTPUT:
Pikachu
26
Venusaur
16
14
*/
