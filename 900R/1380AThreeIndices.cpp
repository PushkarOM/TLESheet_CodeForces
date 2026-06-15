#include<bits/stdc++.h>

using namespace std;

// The idea is to try the largest elements first as the middle "peak" element (j),
// because a larger value has a higher chance of having smaller elements on both
// its left and right, satisfying arr[i] < arr[j] > arr[k]. To do this, store each
// element along with its original index, sort them by value, and iterate from the
// largest to the smallest candidate. For each candidate, search left and right
// from its original position to find smaller elements. If both are found, we have
// a valid triplet of indices.

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);
        vector<pair<int,int>> cpy;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            cpy.push_back({arr[i],i});
        }


        // find the max element, check if it have 2 elements around it, 
        // if not check the next max
        // this is brute will take O(n^2)
        
        sort(cpy.begin(), cpy.end());
        bool found = false;
        
        
        for(int i = n-1; i >= 0; i--){
            int j = cpy[i].second;            

            if(j == 0 || j == n-1) continue;

            // element smaller that j on both directions
            int l = j-1;
            while(l >= 0 && arr[l] > arr[j]) l--;

            int k = j+1;
            while(k < n && arr[k] > arr[j]) k++;

            if(l != -1 && k != n){
                cout << "YES" << "\n";
                cout << l+1 << " " << j+1 << " " << k+1 << '\n';
                found = true;
                break;
            }

        }
        
        if(!found) cout << "NO" << "\n";
     
    }

}