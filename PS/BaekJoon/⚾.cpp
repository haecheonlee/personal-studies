#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define SIZE 9

using namespace std;

int N;
int a[51][SIZE];
bool base[3] {false};	// 1st base, 2nd base, 3rd base

int update(int strike) {
	if(strike==4) {
		// if home-run
		int homerun=1;
		for(int i=0; i<=2; i++) {
			if(base[i]) {
				base[i]=false;	
				homerun++;
			}
		}
		
		return homerun;
	}
	
	int score=0;
	for(int i=2; i>=0; i--) {
		if(i+strike>=3) {
			if(base[i]) {
				base[i]=false;
				score++;
			}
		} else {
			base[i+strike]=base[i];
			base[i]=false;
		}
	}
	
	base[strike-1]=true;
	
	return score;
}

int go(const vector<int> &p) {
	int score=0;
	int current_index=0;
	int out_count;
	
	// i: current inning
	for(int i=0; i<N; i++) {
		// each player
		memset(base,false,sizeof(base));	// reset base
		out_count=3;	// reset out_count
		
		while(out_count) {
			int x=a[i][p[current_index]];
			if(x==0) out_count--;
			else if(x==1) score+=update(x);
			else if(x==2) score+=update(x);
			else if(x==3) score+=update(x);
			else if(x==4) score+=update(x);

			current_index++;
			if(current_index==SIZE) current_index=0;
		}
	}

	return score;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<SIZE; j++) cin>>a[i][j];
	}
	
	vector<int> p;	//[0] to [8], SIZE: 9
	for(int i=0; i<SIZE; i++) {
		p.push_back(i);
	}
	
	int ans=0;
	do {
		if(p[3]!=0) continue;	// first player must be at 4th place
		
		int score=go(p);
		ans=max(ans,score);
	} while(next_permutation(p.begin(), p.end()));
	cout<<ans;
	
	return 0;
}
