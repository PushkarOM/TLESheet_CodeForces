#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        long long n, k;
        cin >> n >> k;

        vector<pair<long,long>> arr;

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            arr.push_back({temp,i+1});
        }

        // death start occuring once a monster healt reached <= k,
        // so hits before that just reduce the health and don't contribute to the sequence of death
        // so we can update the health of eachm monster with %k, if we get a remainder that the health of
        // the monster now, if we get 0, we set it's health k
        for(int i = 0; i < n; i++){
            arr[i].first = arr[i].first % k == 0 ? k : arr[i].first % k;
        }

        // sort
        sort(arr.begin(), arr.end(), 
            [](const pair<int,int>& a,const pair<int,int>& b){
                if(a.first == b.first)
                    return a.second < b.second;
                return a.first > b.first;
        });
        
        for(auto it : arr){
            cout << it.second << ' ';
        }
        cout << "\n";
    
    }

}