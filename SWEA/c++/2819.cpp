/*
1. dfs문제
2. 모든 가능한 경우를 따져 이미 있는 값과 비교
3. 비교하는 단계에서 시간을 줄이기 위해 배열 hash 사용
*/

# include <iostream>
# define MAX_VALUE 10000000

using namespace std;

int map[4][4];
bool hashValue[MAX_VALUE];
int str;
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isInside(int y, int x) {
    if(y >= 4 || y < 0) return false;
    if(x >= 4 || x < 0) return false;
    return true;
}

void dfs(int y, int x, int depth) {
    if(depth == 6) {
        for(int d = 0; d < 4; ++d) {
            if(isInside(y+dy[d], x+dx[d])) {
                str *= 10;
                str += map[y+dy[d]][x+dx[d]];
                if(!hashValue[str]) {
                    ans++;
                    hashValue[str] = true;
                }
                str /= 10;
            }
        }
        return;
    }


    for(int d = 0; d < 4; ++d) {
        if(isInside(y+dy[d], x+dx[d])) {
            str *= 10;
            str += map[y+dy[d]][x+dx[d]];
            dfs(y+dy[d], x+dx[d], depth+1);
            str /= 10;
        }
    }
}

int main(void) {
    int t, tc = 0;
    scanf("%d", &t);

    while(++tc <= t) {
        ans = 0;

        for(int i = 0; i < MAX_VALUE; ++i) hashValue[i] = false;

        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                scanf("%d", &map[i][j]);
            }
        }

        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                str = 0;
                str += map[i][j];
                dfs(i, j, 1);
            }
        }

        printf("#%d %d\n", tc, ans);
    }
}