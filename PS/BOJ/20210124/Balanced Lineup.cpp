#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 5e4 + 1;

int a[MAX_N];
int tree1[MAX_N * 4], tree2[MAX_N * 4];

int init1(int node, int start, int end) {
	// tallest
	if(start == end) return tree1[node] = a[start];
	return tree1[node] = max(init1(node * 2, start, (start + end) / 2), 
							 init1(node * 2 + 1, (start + end) / 2 + 1, end));
}

int init2(int node, int start, int end) {
	// shortest
	if(start == end) return tree2[node] = a[start];
	return tree2[node] = min(init2(node * 2, start, (start + end) / 2), 
							 init2(node * 2 + 1, (start + end) / 2 + 1, end));
}

int query1(int node, int start, int end, int L, int R) {
	if(L > end || R < start) return -1;
	if(L <= start && end <= R) return tree1[node];
	
	int r1 = query1(node * 2, start, (start + end) / 2, L, R);
	int r2 = query1(node * 2 + 1, (start + end) / 2 + 1, end, L, R);
	
	if(r1 == -1) return r2;
	if(r2 == -1) return r1;
	
	return max(r1, r2);
}

int query2(int node, int start, int end, int L, int R) {
	if(L > end || R < start) return -1;
	if(L <= start && end <= R) return tree2[node];
	
	int r1 = query2(node * 2, start, (start + end) / 2, L, R);
	int r2 = query2(node * 2 + 1, (start + end) / 2 + 1, end, L, R);
	
	if(r1 == -1) return r2;
	if(r2 == -1) return r1;
	
	return min(r1, r2);
}


int main() {
	fastio
	
	int N, Q;
	cin >> N >> Q;
	
	for(int i = 1; i <= N; i++) cin >> a[i];

	init1(1, 1, N);	init2(1, 1, N);
	while(Q--) {
		int A, B;
		cin >> A >> B;
		
		int tallest = query1(1, 1, N, A, B);
		int smallest = query2(1, 1, N, A, B);
		
		cout << tallest - smallest << '\n';
	}

	return 0;
}
