#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, p;
        cin >> n >> p;

        vector<pair<long long,long long>> people;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            people.push_back({a,0});
        }

        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            people[i].second = a;
        }

        // sort according to Cost, if cost is same, 
        // check who can relay to larger number of people
        sort(people.begin(), people.end(),

            [](const pair<int,int>& a, const pair<int,int>& b) {
                return a.second < b.second;
            }
        );

        // create a min heap to keep track of the next avaliable cheapest informant
        priority_queue<
            pair<long long,long long>,
            vector<pair<long long,long long>>,
            greater<pair<long long,long long>>
        > pq;


        long long minCost = 0;

        for(int i = 0 ; i < n; i++){
            
            while (!pq.empty() && pq.top().second == 0) // if pq is not empty, 
                pq.pop();                  // and the remaning trasmissoin of the current informant is 0
                
            // pop the cheapest informant, use it tranmissions, update and put back in min heap
            if (!pq.empty() && pq.top().first < p) { // if pak chen himself can inform for less cost do that
                auto cur = pq.top();
                pq.pop();

                minCost += cur.first;
                cur.second--;

                if (cur.second)
                    pq.push(cur);
            } else {
                minCost += p;  // directly informed by pak chen
            }
        
            pq.push({people[i].second, people[i].first}); // pushing the new activated informant
        }

        cout << minCost << "\n";
    }

}
// Sort residents by increasing b.
// Inform residents in that order.
//
// Maintain all currently available transmission sources
// as (cost b, remaining capacity a) in a min-heap.
//
// To activate the next resident:
//   - use cheapest available transmission if b < p
//   - otherwise inform directly using Pak Chen (cost p)
//
// After activating resident i,
// add (b_i, a_i) to the heap.
//
// O(n log n)