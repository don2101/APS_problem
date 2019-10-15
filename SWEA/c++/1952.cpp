/**
 * dfs 문제
 * 
 * 경우를 나눠서 dfs를 실행할 수 있어야 한다
 * */

#include <iostream>

using namespace std;

int date[13];
bool pay[13];
int ans;
int day, month, three, year;

void init() {
    date[0] = 0;
    pay[0] = false;

    cin >> day >> month >> three >> year;

    for(int i = 1; i < 13; ++i) {
        cin >> date[i];
        pay[i] = false;
    }
    
    ans = 9999999;
}


void dfs(int m, int cur) {
    if(m == 13) {
        if(ans > cur) ans = cur;
        return;
    }

    if(date[m] == 0 || pay[m]) {
        dfs(m+1, cur);
        return;
    }

    pay[m] = true;
    dfs(m+1, cur+date[m]*day);
    pay[m] = false;

    pay[m] = true;
    dfs(m+1, cur+month);
    pay[m] = false;


    int d = 0;
    for(; d < 3; ++d) {
        if(m+d > 12) break;
        pay[m+d] = true;
    }

    dfs(m+d, cur+three);

    for(d = 0; d < 3; ++d) {
        if(m+d > 12) break;
        pay[m+d] = false;
    }
}


int main(void) {
    int t, tc = 0;
    cin >> t;

    while(++tc <= t) {
        init();

        dfs(1, 0);

        if(year < ans) ans = year;

        cout << "#" << tc << " " << ans << endl;
    }

}