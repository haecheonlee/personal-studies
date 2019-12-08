#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int[3]> m;
int fibonacci(int n) {
    if(n<=1) {
        if(n == 0) {
            m[n][0] = 1;
        }else if(n == 1) {
            m[n][1] = 1;
        }
        
        return n;
    }
    
    if(m.find(n) != m.end()) return m[n][2];
    else {
        m[n][2] = fibonacci(n-1) + fibonacci(n-2);
        m[n][0] = m[n-1][0] + m[n-2][0];
        m[n][1] = m[n-1][1] + m[n-2][1]; 
        return m[n][2];
    }
}

int main()
{
    int T;
    cin>>T;
    
    int num;
    for(int i=0; i<T; i++) {
        cin>>num;
        fibonacci(num);
        cout<<m[num][0]<<" "<<m[num][1]<<"\n";
    }

    return 0;
}

/*
INPUT:
3
0
1
3

OUTPUT:
1 0
0 1
1 2
*/
