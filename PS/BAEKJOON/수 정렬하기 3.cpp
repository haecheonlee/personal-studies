#include <iostream>

using namespace std;

#define MAX 10001

int main()
{
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    int count[MAX] { 0 };
    int num;
    for(int i=0; i<N; i++) {
        cin>>num;
        count[num]++;
    }

    /* Counting Sort */
    int counted = 0;
    for(int i=1; i<MAX; i++) {
        for(int j=0; j<count[i]; j++) {
            cout<<i<<"\n";
            counted++;
        }
        
        if(counted == N) break;
    }
    
    return 0;
}
