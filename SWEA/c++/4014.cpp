/*
N * N 크기의 절벽지대에 활주로를 건설하려고 한다.
각 셀의 숫자는 그 지형의 높이를 의미한다.
활주로를 가로 또는 세로 방향으로 건설할 수 있는 가능성을 확인하려고 한다.

활주로는 높이가 동일한 구간에서 건설이 가능하다.
높이가 다른 구간의 경우 활주로가 끊어지기 때문에 경사로를 설치해야만 활주로를 건설 할 수 있다.

경사로는 길이가 X 이고, 높이는 1 이다.
경사로는 높이 차이가 1 이고 낮은 지형의 높이가 동일하게 경사로의 길이만큼 연속되는 곳에 설치 할 수 있다.

경사로의 길이 X 와 절벽지대의 높이 정보가 주어질 때,
활주로를 건설할 수 있는 경우의 수를 계산하는 프로그램을 작성하라.

[제약사항]
1. 시간제한 : 최대 50 개 테스트 케이스를 모두 통과하는 데 C / C++ / Java 모두 3 초
2. N 의 크기는 6 이상 20 이하의 정수이다. ( 6 ≤ N ≤ 20 )
3. 경사로의 높이는 항상 1 이고, 길이 X 는 2 이상 4 이하의 정수이다. ( 2 ≤ X ≤ 4 )
4. 지형의 높이는 1 이상 6 이하의 정수이다.
5. 동일한 셀에 두 개 이상의 경사로를 겹쳐서 사용할 수 없다.
6. 경사로는 세워서 사용할 수 없다.

[입력]
입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T 가 주어지고,
그 다음 줄부터 T 개의 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 지도의 한 변의 크기인 N 과 경사로의 길이 X 가 주어진다.
다음 N 개의 줄에는 N * N 크기의 지형 정보가 주어진다.

[출력]
테스트 케이스 개수만큼 T 개의 줄에 각각의 테스트 케이스에 대한 답을 출력한다.
각 줄은 "#t" 로 시작하고 공백을 하나 둔 다음 정답을 출력한다. ( t 는 1 부터 시작하는 테스트 케이스의 번호이다. )
정답은 활주로를 건설할 수 있는 경우의 수이다.
*/

/*
사용 로직
1. 2차원 배열 제어
2. 각 조건 확인
*/

/*
배운것
1. 문제의 조건을 정확하게 읽기
2. 문제의 조건을 정확하게 파악
*/


#include <iostream>

using namespace std;

int ans;
int n, w;
int map[20][20];
bool visited[20][20];
int xd[4] = { 1, 0, -1, 0 };
int yd[4] = { 0, 1, 0, -1 };

bool isInside(int y, int x) {
	if(y >= n || y < 0) return false;
    if(x >= n || x < 0) return false;
    
    return true;
}

bool possible(int y, int x, int d) {
	for(int i = 0; i < w-1; ++i) {
        if(isInside(y+yd[d]*(i+1), x+xd[d]*(i+1)) && !visited[y+yd[d]*(i+1)][x+xd[d]*(i+1)]) {
        	if(map[y+yd[d]*i][x+xd[d]*i] != map[y+yd[d]*(i+1)][x+xd[d]*(i+1)]) return false;
        } else return false;
    }
    
    return true;
}

void setting(int y, int x, int d) {
	for(int i = 0; i < w; ++i) {
		visited[y+yd[d]*i][x+xd[d]*i] = true;
    }
}

int main(void) {
	int t, tc = 0;
    scanf("%d", &t);
    
    while(++tc <= t) {
    	ans = 0;
        scanf("%d %d", &n, &w);
        
        for(int i = 0; i < n; ++i) {
        	for(int j = 0; j < n; ++j) {
            	scanf("%d", &map[i][j]);
            }
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
            	visited[i][j] = false;
            }
            bool stair = true;
        	for(int j = 0; j < n; ++j) {
				int d = 0;
                if(isInside(i+yd[d], j+xd[d]) && map[i][j] - 1 == map[i+yd[d]][j+xd[d]]) {
                    if(!visited[i+yd[d]][j+xd[d]]) {
                        if(possible(i+yd[d], j+xd[d], d)) {
                            setting(i+yd[d], j+xd[d], d);
                        } else {
                        	stair = false;
                            break;
                        }
                    } else {
                    	stair = false;
                    	break;
                    }
                } else if(isInside(i+yd[d], j+xd[d]) && map[i][j] - 1 > map[i+yd[d]][j+xd[d]]) {
                	stair = false;
                    break;
                }
                d = 2;
                if(isInside(i+yd[d], j+xd[d]) && map[i][j] - 1 == map[i+yd[d]][j+xd[d]]) {
                    if(!visited[i+yd[d]][j+xd[d]]) {
                        if(possible(i+yd[d], j+xd[d], d)) {
                            setting(i+yd[d], j+xd[d], d);
                        } else {
                        	stair = false;
                            break;
                        }
                    } else {
                        stair = false;
                        break;
                    }
                } else if(isInside(i+yd[d], j+xd[d]) && map[i][j] - 1 > map[i+yd[d]][j+xd[d]]) {
                	stair = false;
                    break;
                }
            }
            if(stair) ans++;
        }
        
        for(int j = 0; j < n; ++j) {
            for(int i = 0; i < n; ++i) {
            	visited[i][j] = false;
            }
            bool stair = true;
        	for(int i = 0; i < n; ++i) {
				int d = 1;
                if(isInside(i+yd[d], j+xd[d]) && map[i][j] - 1 == map[i+yd[d]][j+xd[d]]) {
                    if(!visited[i+yd[d]][j+xd[d]]) {
                        if(possible(i+yd[d], j+xd[d], d)) {
                            setting(i+yd[d], j+xd[d], d);
                        } else {
                        	stair = false;
                            break;
                        }
                    } else {
                    	stair = false;
                        break;
                    }
                } else if(isInside(i+yd[d], j+xd[d]) && map[i][j] - 1 > map[i+yd[d]][j+xd[d]]) {
                	stair = false;
                    break;
                }
                d = 3;
                if(isInside(i+yd[d], j+xd[d]) && map[i][j] - 1 == map[i+yd[d]][j+xd[d]]) {
                    if(!visited[i+yd[d]][j+xd[d]]) {
                        if(possible(i+yd[d], j+xd[d], d)) {
                            setting(i+yd[d], j+xd[d], d);
                        } else {
                        	stair = false;
                            break;
                        }
                    } else {
                    	stair = false;
                        break;
                    }
                } else if(isInside(i+yd[d], j+xd[d]) && map[i][j] - 1 > map[i+yd[d]][j+xd[d]]) {
                	stair = false;
                    break;
                }
            }
            if(stair) ans++;
        }
        
        printf("#%d %d\n", tc, ans);
    }
}