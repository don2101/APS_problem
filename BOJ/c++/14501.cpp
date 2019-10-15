#include <iostream>

using namespace std;


int ans;
int day[16];
int money[16];
int pos[16];
int n;


void init() {
    cin >> n;
    ans = 0;

    for(int i = 1; i <= n; ++i) {
        cin >> day[i] >> money[i];
        pos[i] = true;
    }
}


// void cancel(int c, int d) {
//     for(int i = c; i < c+d; ++i) {
//         pos[i] = !pos[i];
//     }
// }


void dfs(int d, int m) {
    if(d > n) {
        if(m > ans) ans = m;
        return;
    }

    if(d+day[d] <= n) dfs(d+day[d], m+money[d]);
    
    for(int i = d+1; i <= n; ++i) {
        dfs(i, m);
    }

    return;
}


int main(void) {
    init();
    dfs(1, 0);

    cout << ans << endl;
}