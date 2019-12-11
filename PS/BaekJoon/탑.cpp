#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    stack<pair<int, int>> s;
    
    int N, height;
    cin>>N;
    
    for(int i=1; i<=N; i++) {
        cin>>height;
        
        while(!s.empty()) {
            if(s.top().second > height) {
                cout<<s.top().first<<" ";
                break;
            }
            
            s.pop();
        }
        
        if(s.empty()) cout<<"0 ";
        s.push(make_pair(i, height));
    }
    
    return 0;
}

/*
boj.kr/2493

INPUT:
5
6 9 5 7 4

OUTPUT:
0 0 2 2 4
*/
