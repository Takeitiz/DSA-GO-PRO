// 4/5 pass

#include<bits/stdc++.h>
using namespace std;
const int MAX = 40;
int n, k;
int c[MAX][MAX];
int x[MAX];
int Sum = 0;
int res = 2147483647;
int minedge = 2147483647;
int num_visitor = 0;
bool visited[MAX];
void inputData(){
    cin >> n >> k;
    for(int i=0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++){
            cin >> c[i][j];
            minedge = min(minedge, c[i][j]);
        }
}

bool check(int u, int destination) {
    if(num_visitor == k && destination <= n) return false;
    if(c[x[u - 1]][destination] == 0) return false;
    if(destination > n && !visited[destination - n]) return false;
    if(!visited[destination]) return true;
    return false;
}
void solution() {
    Sum += c[x[2*n]][0];
    res = min(res,Sum);
    Sum -= c[x[2*n]][0];
}
void Try(int u) {
    for (int destination = 1; destination <= 2*n; destination++) {
        if(check(u, destination)) {
            x[u] = destination;
            visited[destination] = true;
            Sum += c[x[u - 1]][x[u]];
            if(destination <= n) num_visitor++;
            else num_visitor--;

            if (u == 2*n) solution();
            else
                if(Sum + (2*n - u + 1)*minedge < res) Try(u + 1);

            if(destination <= n) num_visitor--;
            else num_visitor++;
            visited[destination] = false;
            Sum -= c[x[u - 1]][x[u]];
        }
    }
}


int main() {
    inputData();
    Try(1);
    cout << res;
}

