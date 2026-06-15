#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int  n, k;
        cin >> n >> k;

        vector<int> arr(n*k);
        
        for(int i = 0; i < n*k; i++){
            cin >> arr[i];
        }

        long long sum = 0;
        int index = (n/2) + 1;
        int temp = k;
        while(temp--){

            sum += arr[(n*k) - index];
            index += (n/2) + 1;
        }

        cout << sum << "\n";
    
    }

}

/*
The array is already sorted, so to maximize the sum of medians, we try to pick
medians as far to the right (largest values) as possible.

For a group of size n, the median is at position ceil(n/2), which means it must
have floor(n/2) elements greater than or equal to it on its right.

Therefore, the largest elements cannot be chosen as medians because they are
needed to fill the right side of the groups.

While moving from the end of the array:
- Skip floor(n/2) elements to act as the right side of the current median.
- Take the next element as the largest possible median.
- After using that median, move past it as well before finding the next median.

Hence, the gap between two consecutive chosen medians is:
    floor(n/2) + 1

We start from the first possible median from the right and keep moving left by
this fixed gap k times, adding each chosen median to the answer.
*/