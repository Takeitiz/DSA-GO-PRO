#include<bits/stdc++.h>
using namespace std;
int n;
int x[23];
int c[23][23];
int Sum = 0;
int passengers = 0;
int res = INT32_MAX;
int min_edge = INT32_MAX;
bool visited[23];
bool check(int u) {
    if(passengers > 1 || passengers < 0) return false;
    if(x[u] > n && !visited[x[u] - n]) return false;
    if(x[u] <= n && visited[x[u] + n]) return false;
    if(visited[x[u]]) return false;
    if(Sum + (2*n - u + 1)*min_edge > res) return false;
    return true;
}
void Try(int u) {
    if(u == 2*n + 1) {
        res = min(res, Sum + c[x[2*n]][x[0]]);
        return;
    }
    for(int location = 1; location <= 2*n; location++) {
        x[u] = location;
        if(location > n) passengers--;
        else passengers++;
        Sum += c[x[u - 1]][x[u]];

        if(check(u)) {
            visited[location] = true;
            Try(u + 1);
            visited[location] = false;
        }

        Sum -= c[x[u - 1]][x[u]];
        if(location > n) passengers++;
        else passengers--;
        x[u] = 0;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i <= 2*n; i++)
        for(int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];
            min_edge = min(min_edge, c[i][j]);
        }
    Try(1);
    cout << res;
}

