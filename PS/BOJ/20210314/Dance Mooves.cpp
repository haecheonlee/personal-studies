/* reference: https://www.youtube.com/channel/UCPkhk5gFov8vIPXj0zHyxEQ */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll N, K;

vector<pii> swaps;
vector<int> jumpTable;

vector<int> G;
vector<vector<int>> groups;
vector<vector<int>> trace;
vector<int> ans;

// simulate to get the trace for each node
void simulation(vector<ll>& a) {
	// include itself
	for(int i = 1; i <= N; i++) trace[i].push_back(i);
	
	// simulate first K cycles
	for(int i = 0; i < swaps.size(); i++) {
		int l = swaps[i].fi;
		int r = swaps[i].sc;
		
		trace[a[l]].push_back(r);
		trace[a[r]].push_back(l);
		
		swap(a[l], a[r]);
	}
}

void make_table(vector<ll>& a) {
	// create jumpTable ( ending position after k swaps )
	for(int i = 1; i < a.size(); i++) jumpTable[a[i]] = i;
}

void findCycles(vector<ll>& a) {
	int currentID = 0;
	
	for(int i = 1; i <= N; i++) {
		if(G[i] != -1) continue;
		
		vector<int> groupIds;
		G[i] = currentID;
		groupIds.push_back(i);
		
		int j = jumpTable[i];
		int currPhase = 0;
		
		while(j != i) {
			G[j] = currentID;
			groupIds.push_back(j);
			j = jumpTable[j];
			currPhase++;
		}
		
		groups.push_back(groupIds);
		currentID++;
	}
}

int main() {
	cin >> N >> K;
	
	swaps.resize(K);
	trace.resize(N + 1);
	jumpTable.resize(N + 1);
	G.resize(N + 1, -1);
	ans.resize(N + 1, 0);
	
	for(int i = 0; i < K; i++) {
		int a, b; cin >> a >> b;
		swaps[i].fi = a, swaps[i].sc = b;
	}
	
	vector<ll> a(N + 1);
	for(int i = 0; i <= N; i++) a[i] = i;

	simulation(a);
	make_table(a);
	findCycles(a);
	
	map<int, int> finAns;
	for(int groupId = 0; groupId < groups.size(); groupId++) {
		unordered_set<int> currSet;
		
		for(int j = 0; j < groups[groupId].size(); j++) {
			for(auto k : trace[groups[groupId][j]]) {
				currSet.insert(k);
			}
		}
		
		finAns[groupId] = currSet.size();
	}
	
	for(int i = 1; i <= N; i++) {
		cout << max(finAns[G[i]], 1) << '\n';
	}
	
	return 0;
}
