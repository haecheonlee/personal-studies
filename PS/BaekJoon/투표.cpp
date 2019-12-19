#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Game{
public:	
	int price;
	int voted;
	int index;
	Game() {}
	Game(int _p, int _v, int _i) : price(_p), voted(_v), index(_i) {}
	~Game() {}
};

bool sortByVoted(const Game &a, const Game &b) {
	return a.voted > b.voted;
}

int main() {
	int N, M;
	cin>>N>>M;
	
	vector<Game> games;
	int p;
	for(int i=0; i<N; i++) {
		cin>>p;
		games.push_back({p, 0, i+1});
	}
	
	int b;
	for(int j=0; j<M; j++) {
		cin>>b;
		
		for(int i=0; i<N; i++) {
			if(games[i].price <= b) {
				games[i].voted++;
				break;
			}
		}
	}
	
	sort(games.begin(), games.end(), sortByVoted);
	cout<<games[0].index<<endl;
	
	return 0;
}

/*
boj.kr/10040

INPUT:
4 3
5
3
1
4
4
3
2

OUTPUT:
2
*/
