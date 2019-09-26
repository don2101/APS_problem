#include <iostream>

using namespace std;

long long ans;
int n, l, r;
long long dp[21][21][21];

long long search(int n, int l, int r) {
    if(n == 1 && r == 1 && l == 1) return 1;
    if(n < 1 || r < 1 || l < 1) return 0;
    if(n < r || n < l) return 0;
    if(n+1 < l+r) return 0;
    
	if(dp[n-1][l-1][r] == 0) dp[n-1][l-1][r] = search(n-1, l-1, r);
    if(dp[n-1][l][r-1] == 0) dp[n-1][l][r-1] = search(n-1, l, r-1);
    if(dp[n-1][l][r] == 0) dp[n-1][l][r] = search(n-1, l, r);
    
    return dp[n][l][r] = dp[n-1][l-1][r] + dp[n-1][l][r-1] + (n-2)*dp[n-1][l][r];
}

int main(void) {
	int t, tc = 0;
    cin >> t;
    
    while(++tc <= t) {
		cin >> n >> l >> r;
        
        for(int i = 0; i <= 20; ++i) {
        	for(int j = 0; j <= 20; ++j) {
            	for(int k = 0; k <= 20; ++k) dp[i][j][k] = 0;
            }
        }
        
        dp[1][1][1] = 1;
        dp[n][l][r] = search(n, l, r);
        
        cout << "#" << tc << " " << dp[n][l][r] << endl;
    }
    
}