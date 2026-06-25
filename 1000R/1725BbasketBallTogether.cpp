#include <bits/stdc++.h>

using namespace std;

/*
Observation:

If a team has size K and maximum power M,
Pak Chanek changes every player's power to M.

Therefore:

    team_power = K * M

A team wins iff:

    K * M > D

For a leader with power M, the minimum team size needed is:

    K = floor(D / M) + 1

Greedy:

Sort powers in descending order.

Use the strongest unused player as the team leader.

To maximize the number of winning teams, every winning team
should use the minimum number of players necessary.

The remaining players only serve as helpers, and their actual
powers do not matter after the transformation. Therefore,
we should sacrifice the weakest available players as helpers
and preserve stronger players for future teams.

Two pointers:

left  -> strongest unused player (candidate leader)
right -> weakest unused player

If the current leader requires K players, we consume:
    - 1 leader from the left
    - K - 1 helpers from the right

If the number of available players is less than K,
then the current leader cannot form a winning team.
Since all future leaders are weaker, they will require
at least as many players, so no more teams can be formed.

Complexity:
    Sorting: O(N log N)
    Two-pointer scan: O(N)
*/

int main() {

    int N;
    long long D;
    cin >> N >> D;

    vector<long long> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    sort(p.rbegin(), p.rend());

    int left = 0;
    int right = N - 1;
    int wins = 0;

    while (left <= right) {
        // Minimum team size required if p[left] is the leader
        long long need = D / p[left] + 1;

        // Number of players currently available
        long long available = right - left + 1;

        if (available < need) {
            break;
        }

        wins++;

        // Consume leader
        left++;

        // Consume need - 1 weakest helpers
        right -= (need - 1);
    }

    cout << wins << '\n';
}