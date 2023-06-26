#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[21], x[21];
int res = 0;
int Sum = 0;
void Try(int u) {
    if(u == n + 1) {
        if(Sum == m) res++;
        return;
    }
    for(int value = 1; value <= (m - Sum)/a[u]; value++) {
        x[u] = value;
        int prev_sum = Sum;
        Sum += x[u] * a[u];
        if (Sum <= m) Try(u + 1);
        Sum = prev_sum;
        x[u] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    Try(1);
    cout << res;
}

