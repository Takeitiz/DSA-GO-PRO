#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<long long> v(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> v[i];
    vector<long long> even(n+1,INT32_MIN);
    vector<long long> odd(n+1, INT32_MIN);
    if(v[1] % 2 == 0) even[1] = v[1];
    else odd[1] = v[1];
    for(int i = 2 ; i <= n ; i++){
        if(v[i] % 2 == 0){
            even[i] = max(even[i-1] + v[i], v[i]);
            if(odd[i-1] == INT32_MIN) odd[i] = INT32_MIN;
            else odd[i] = odd[i-1] + v[i];
        } else {
            if(odd[i-1] == INT32_MIN) even[i] = INT32_MIN;
            else even[i] = odd[i-1] + v[i];
            odd[i] = max(even[i-1] + v[i], v[i]);
        }
    }
    long long res = LLONG_MIN;
    for(int i =  1 ; i <= n ; i++) res = max(res, even[i]);
    if(res == LLONG_MIN) cout << "NOT_FOUND" << endl;
    else cout << res << endl;
    return 0;
}
