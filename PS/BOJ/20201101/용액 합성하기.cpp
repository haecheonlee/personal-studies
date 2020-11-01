#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    
    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];
    
    int L = 0, R = N -1;
    int d = 1e9, p1 = -1, p2 = -1;
    while(L < R) {
        if(abs(a[L] + a[R]) < d) {
            p1 = a[L], p2 = a[R];
            d = abs(a[L] + a[R]);
        }
        
        if(a[L] + a[R] < 0) L++;
        else R--;
    }
    
    cout << p1 + p2;
    
	return 0;
}
