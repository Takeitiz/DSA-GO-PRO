#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int l1, l2; cin >> l1 >> l2;
    vector<long> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    vector<long> dp(n + 1);
    deque<long> q;
    long ans = 0;
    for(int i = 1; i <= n; i++) {
        while(!q.empty() && q.front() < i - l2)
            q.pop_front();
        if(i - l1 >= 1) {
            while(!q.empty() && dp[q.back()] < dp[i - l1])
                q.pop_back();
            q.push_back(i - l1);
        }
        dp[i] = arr[i] + (q.empty() ? 0 : dp[q.front()]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

