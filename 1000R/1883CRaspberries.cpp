#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n , k;
        cin >> n >> k;

        int ops = INT_MAX, curr = 0, evenCnt = 0;

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;

            if(temp%k == 0){
                ops = 0;
            }
            else{
                curr = k - temp%k;
                ops = min(curr, ops);
            }

            if(temp%2 == 0) evenCnt++;

        }


        if (k == 4) {
            if (evenCnt >= 2)
                ops = 0;
            else if (evenCnt == 1)
                ops = min(ops, 1);
            else
                ops = min(ops, 2);
        }
        
        cout << ops << "\n";
    }

}