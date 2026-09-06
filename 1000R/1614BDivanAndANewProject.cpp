#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<pair<int,int>> arr;
        long long result = 0;
        
        int temp;
        for(int i = 0; i < n; i++){    
            cin >> temp;
            arr.push_back({temp, i});
        }

        sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if(a.first > b.first) return true;
            return false;
        });

        int k = 1;
        for(int i = 0; i < n; i++){
            if(i != 0 && i%2 == 0) k++;

            result += 2LL * arr[i].first * k;

            if(i%2 == 0){
                
                arr[i].first = k;
            }
            else{
                arr[i].first = k * -1;
            }
        }

        sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if(a.second < b.second) return true;
            return false;
        });

        cout << result << "\n" << 0 << " ";

        for(auto it : arr){
            cout << it.first << " ";
        }
        cout << "\n";
    }

}