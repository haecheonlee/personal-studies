#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    
    int N;
    cin>>N;
    
    for(int i=1; i<=N; i++) {
        q.push(i);
    }
    
    for(int i=0; i<N; i++) {
        if(q.size() > 1) {
            q.pop();
            int value = q.front();
            q.pop();
            q.push(value);
        } else {
            break;
        }
    }
    
    cout<<q.front()<<endl;
    
    return 0;
}

/*
boj.kr/2164
INPUT:
6

OUTPUT:
4
*/
