#include <stdio.h>

int h, w;
int map[300][300];
bool visited[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isInside(int y, int x) {
    if(y >= h || y < 0) return false;
    if(x >= w || x < 0) return false;

    return true;
}

void dfs(int y, int x) {
    visited[y][x] = true;
    for(int d = 0; d < 4; ++d) {
        if(!visited[y+dy[d]][x+dx[d]] && map[y+dy[d]][x+dx[d]] > 0 && isInside(y+dy[d], x+dx[d])) dfs(y+dy[d], x+dx[d]);
    }
}

void meltDown(int y, int x) {
    int water = 0;
    for(int d = 0; d < 4; ++d) {
        if(map[y+dy[d]][x+dx[d]] == 0 && !visited[y+dy[d]][x+dx[d]] && isInside(y+dy[d], x+dx[d])) water++;
    }

    map[y][x] -= water;
    if(map[y][x] <= 0) {
        map[y][x] = 0;
        visited[y][x] = true;
    }
}

int main(void) {
    scanf("%d %d", &h, &w);
    int ans = 0;

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    int t = 0;

    while(true) {
        int ice = 0;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                visited[i][j] = false;
            }
        }

        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(!visited[i][j] && map[i][j] > 0) {
                    dfs(i, j);
                    ice++;
                }
            }
        }

        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                visited[i][j] = false;
            }
        }

        if(ice == 0) {
            ans = 0;
            break;
        } else if(ice >= 2) {
            ans = t;
            break;
        } else {
            for(int i = 0; i < h; ++i) {
                for(int j = 0; j < w; ++j) {
                    if(map[i][j] > 0) meltDown(i, j);
                }
            }
        }

        ++t;
    }

    printf("%d", ans);
}