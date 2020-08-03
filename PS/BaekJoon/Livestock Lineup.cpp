#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
using pi=pair<int,int>;
using ps=pair<string,int>;

bool check[10][10];
vector<ps> cows={{"Bessie",0}, {"Buttercup",1}, {"Belinda",2}, 
				 {"Beatrice",3}, {"Bella",4}, {"Blue",5}, 
				 {"Betsy",6}, {"Sue",7}};
vector<pi> pos;

int findIndex(string s) {
	for(auto& cow : cows) {
		if(s==cow.first) return cow.second;
	}
}

int main() {
	sort(cows.begin(), cows.end());

	int N;
	cin>>N;

	for(int i=0; i<N; i++) {
		string s1, s2;
		cin>>s1>>s2>>s2>>s2>>s2>>s2;
		
		int i1=findIndex(s1);
		int i2=findIndex(s2);
		pos.push_back(make_pair(i1,i2));
	}
	
	do {
		// check who's next to
		memset(check,false,sizeof(check));
		for(int i=0; i<cows.size()-1; i++) {
			int i1=cows[i].second;
			int i2=cows[i+1].second;
			
			check[i1][i2]=check[i2][i1]=true;
		}
		
		bool ans=true;
		for(auto& p : pos) {
			int i1=p.first;
			int i2=p.second;
			
			if(check[i1][i2]==false && check[i2][i1]==false) {
				ans=false;
				break;
			}
		}
		
		if(ans) {
			for(auto& cow : cows) cout<<cow.first<<'\n';
			break;
		}
	} while(next_permutation(cows.begin(), cows.end()));
	
	return 0;
}
