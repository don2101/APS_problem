#include<iostream>

using namespace std;

int friends[501][501];
bool familiar[501];
int n, m;

int main(int argc, char** argv)
{
	int t, tc = 0;
 	scanf("%d", &t);
    
    while(++tc <= t) {
        scanf("%d %d", &n, &m);
        int ans = 0;
        
    	for(int i = 1; i <= n; ++i) {
            familiar[i] = false;
        	for(int j = 1; j <= n; ++j) {
            	friends[i][j] = 0;
            }
        }
        
        for(int i = 0; i < m; ++i) {
        	int a, b;
            scanf("%d %d", &a, &b);
            friends[a][b] = 1;
            friends[b][a] = 1;
        }
        
        for(int i = 2; i <= n; ++i) {
        	if(friends[1][i] == 1) {
                familiar[i] = true;
            	for(int j = 2; j <= n; ++j) {
                	if (i != j && friends[i][j]) {
                    	familiar[j] = true;
                    }
                }
            }
        }
        
        for(int i = 2; i <= n; ++i) {
        	if(familiar[i]) ans++;
        }
        
        printf("#%d %d\n", tc, ans);
        
    }
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}