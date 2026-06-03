#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int a, b, c, d, ops = 0;
        cin >> a >> b >> c >> d;

        // based on change in y value
        int temp = d - b;
        
        if(temp < 0){
            cout << -1 << "\n";
            continue;
        }
        ops += temp;
        b += 1 * temp;
        a += 1 * temp; 

        temp = abs(c - a);
        ops += temp;
        a -= 1 * temp; 
        
        if(a == c && b == d)
            cout << ops << '\n';
        else cout << -1 << "\n";
    }


}