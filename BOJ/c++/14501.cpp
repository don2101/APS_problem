/**
 * dfs 문제
 * 
 * 1. 베이스 케이스에 도달하지 않는 조건을 사용하여 찾아내는데 힘들었다
 * **/

#include <iostream>

using namespace std;


int ans;
int day[16];
int money[16];
bool pos[16];
int n;


void init() {
    cin >> n;
    ans = 0;
    day[0] = 0;
    money[0] = 0;
    pos[0] = false;

    for(int i = 1; i <= n; ++i) {
        cin >> day[i] >> money[i];
        pos[i] = true;
    }
}


void dfs(int d, int m) {
    if(d > n) {
        if(m > ans) ans = m;
        return;
    }
    
    if(d+day[d]-1 <= n) dfs(d+day[d], m+money[d]);
    else if(m > ans) ans = m;

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