#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

string is_perfect(int sum) {
    vector<int> all_factors;

    for(int i=1; i<=sum/2; i++) {
        if(sum%i == 0) all_factors.push_back(i);
    }
    int result = accumulate(all_factors.begin(), all_factors.end(), 0);
    
    string s;
    if(result == sum) {
        s = to_string(sum) + " = ";
        for(auto it = all_factors.begin(); it < all_factors.end(); it++) {
            s += to_string(*it);
            if(it != all_factors.end() - 1) {
                s += " + ";
            }
        }
    } else {
        s = to_string(sum) + " is NOT perfect.";
    }
    
    return s;
}

int main()
{
    int num;
    while(true) {
        cin>>num;
        if(num == -1) break;
        cout << is_perfect(num) << endl;
    }

    return 0;
}

/*
boj.kr/9506

INPUT:
6
12
28
-1

OUTPUT:
6 = 1 + 2 + 3
12 is NOT perfect.
28 = 1 + 2 + 4 + 7 + 14
*/
