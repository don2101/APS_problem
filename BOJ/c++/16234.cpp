/*
정보
1. N*N 크기 땅, 1*1로 나눠져 있다.
2. 각 땅에는 나라가 존재. A[r][c]명이 살고있다.

인구 이동
1. 국경선 공유 두 나라 인구차이가 L이상 R이하면, 국경선을 하루동안 오픈
2. 국경선이 열리면 인구 이동 시작
3. 국경선이 열려있으면 그 나라를 연합이라고 한다.
4. 연합을 이루고 있는 각 칸의 인구수 = 연합 인구수/연합의 칸수. 소수점 버린다.

인구 이동 몇번 발생?
*/

/*
풀이
1. 배열 돌면서 dfs 시작
2. 한 칸에서 4방향 조사하며 !visited고 범위 이하라면 자신이 갖고있는 값으로 초기화
3. 자신이 갖고 있는 값의 배열에 count, value 증가
4. 다음 dfs로 더한 값을 넘겨준다
*/


#include <iostream>

using namespace std;

int ans;
int visited[50][50];
int value[2500];
int count[2500];
int n;
int l, r;
int map[50][50];
int dx = {1, 0, -1, 0};
int dy = {0, 1, 0, -1};

bool isInside(int y, int x) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= n) return false;
    
    return true;
}

int abs(int num) {
    if(num < 0) return -num;
    return num;
}

void dfs(int y, int x, int idx) {
    visited[y][x] = idx;
    value[idx] += map[y][x];
    count[idx]++;

    for(int d = 0; d < 4; ++d) {
        if(isInside(y+dy[d], x+dx[d]) && visited[y+dy[d]][x+dx[d]] == -1 &&) {
            int temp = abs(map[y][x], map[y+dy[d]][x+dx[d]])
            if(l <= temp && temp <= r) {
                dfs(y+dy[d], x+dx[d], idx);
            }
        }
    }
}

int main(void) {
    int t, tc = 0;

    cin >> t;

    while(++tc <= t) {
        cin >> n >> l >> r;
        ans = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> map[i][j];
            }
        }

        while(true) {
            for(int i = 0; i < 2500; ++i) {
                value[i] = 0;
                count[i] = 0;
            }

            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    visited[i][j] = -1;
                }
            }

            int idx = 0;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(visited[y+dy[d]][x+dx[d]] == -1) dfs(i, j, idx);
                    idx++;
                }
            }

            bool sw = false;
            for(int i = 0; i < idx; ++i) {
                if(count[i] > 1) {
                    sw = true;
                    value[i] /= count[i];

                }
            }

            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    map[i][j] = value[visited[i][j]];
                }
            }
            ans++;
            if(!sw) break;
        }

        cout << "#" << tc << " " << ans << endl;
    }

}
