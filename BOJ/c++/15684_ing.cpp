/*
정보
1. 1 ~ N까지의 세로선, 1 ~ H 까지 가로선 존재
2. M개의 가로선을 놓는다
3. i번째 세로선의 결과가 i번이 나오도록 추가 조작

풀이
1. dfs, 백트래킹, 조합 문제
2. 사다리를 놓을 수 있는 모든 공간에 대해 검사
3. 3개이하, 양쪽에 없을 경우를 check하며 백트래킹
*/

#include <iostream>

using namespace std;

int ans;
int n, m, h;
int map[32][11];
bool ladder[32][11];
int result[11];


void swap(int h, int a, int b) {
    int temp = map[h][a];
    map[h][a] = map[h][b];
    map[h][b] = temp;
}

bool scan() {
    for(int i = 1; i <= n; ++i) {
        if(map[h+1][i] != i) return false;
    }

    return true;
}



int main(void) {
    cin >> n >> m >> h;
    ans = -1;
    count = 0;

    for(int i = 0; i <= h+1; ++i) {
        for(int j = 0; j <= n; ++j) {
            ladder[i][j] = false;
            map[i][j] = 0;
        }
    }

    for(int i = 0; i <= n; ++i) {
        result[i] = 0;
    }

    int a, b;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        ladder[a][b] = true;
    }

    for(int j = 1; j <= n; ++j) {
        map[0][j] = j;
    }

    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= n; ++j) {
            map[i][j] = map[i-1][j];
        }

        for(int j = 1; j <= n; ++j) {
            if(ladder[i][j]) swap(i, j, j+1);
        }
    }

    for(int i = 1; i <= h+1; ++i) {
        for(int j = 1; j <= n; ++j) {
            map[i][j] = map[i-1][j];
        }

        for(int j = 1; j <= n; ++j) {
            if(ladder[i][j]) swap(i, j, j+1);
        }
    }

    int depth = 1;

    if(scan()) {
        cout << 0 << endl;
    } else {
        for(int i = 1; i <= h; ++i) {
            for(int j = 1; j < n; ++j) {
                if(!ladder[i][j]) {
                    ladder[i][j] = true;
                    int n1 = map[i][j];
                    int n2 = map[i][j+1];
                    int idx1, idx2;
                    for(int k = 1; k <= n; ++k) {
                        if(map[i][k] == n1) idx1 = k;
                        if(map[i][k] == n2) idx2 = k;
                    }
                    swap(i, idx1, idx2);

                    if(scan()) {
                        
                    }
                }
            }
        }
    }


    cout << ans << endl;
}