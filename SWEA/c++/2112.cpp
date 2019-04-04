/*
사용 로직
1. dfs
2. 백트래킹
3. 조건문 제어
4. 조합
5. 구간 확인
*/

/******* old version *******/
#include <iostream>

using namespace std;

int ans;
int d, w, k;
int map[13][20];
bool chemical[13];

bool test(int col) {
    bool ret = false;
	for(int i = 0; i < d-(k-1); ++i) {
    	ret = true;
        for(int j = 0; j < k-1; ++j) {
        	if(map[i+j][col] != map[i+j+1][col]) {
                ret = false;
            }
        }
        if(ret) break;
    }
    return ret;
}

void dfs(int start, int count, int cnt) {
    if(count <= 0) {
    	bool success;
        for(int i = 0; i < w; ++i) {
        	success = test(i);
            if(!success) break;
        }
        if(success) {
        	if(ans > cnt) ans = cnt;
        }
        return;
    }
    
    int selected = -1;
	for(int i = start; i < d; ++i) {
    	if(chemical[i]) {
        	selected = i;
            break;
        }
    }
    
    int tempMap[20];
    for(int i = 0; i < w; ++i) tempMap[i] = map[selected][i];
    
    for(int i = 0; i < w; ++i) map[selected][i] = 1;
    dfs(selected+1, count-1, cnt);
    for(int i = 0; i < w; ++i) map[selected][i] = 0;
    dfs(selected+1, count-1, cnt);
    
    for(int i = 0; i < w; ++i) map[selected][i] = tempMap[i];
}



int main(void) {
	int t, tc = 0;
    scanf("%d", &t);
    
    while(++tc <= t) {
        ans = 99999;
    	scanf("%d %d %d", &d, &w, &k);
        
        for(int i = 0; i < d; ++i) {
        	for(int j = 0; j < w; ++j) {
            	scanf("%d", &map[i][j]);
            }
        }
        
        bool success;
        for(int i = 0; i < w; ++i) {
        	success = test(i);
            if(!success) break;
        }
        
        if(!success) {
        	for(int comb = 1; comb < 1<< d; ++comb) {
                for(int j = 0; j < d; ++j) chemical[j] = false;
                int count = 0;
                
                for(int j = 0; j < d; ++j) {
                	if(comb & 1<<j) {
                    	count++;
                        chemical[j] = true;
                    }
                }
                
                if(count > ans) continue;
                dfs(0, count, count);
            }
        } else {
        	ans = 0;
        }

    	printf("#%d %d\n", tc, ans);
    }
    
}


/*
1. 바: 가로 W, 필름: 가로 W, 두께 D
2. 세로방향 셀들의 특징이 중요: 세로방향에 동일 특성셀이 K개 이상 연속으로 경우 합격(특성: A, B)
3. 약품 사용: 막 별로 투입 => 모든 특성을 A or B로 변경 
4. 약품 투입 횟수를 최소로 성능 통과를 하여라, 투입 X 통과=>0
5. 3 <= D <= 13, 1 <= W <= 20, 1 <= k <= D, 특성: A(0) or B(1)
*/

/*
풀이
1. 부분집합, 백 트래킹 문제
2. void injection(int n): 투입할 바를 n만큼 정함(부분집합 bit연산) => A or B 투입 => scan => 맞지 않을 경우 원래상태(original)로 돌려놓음
3. bool scan(): 모든 column에 대해 셀을 탐색하면서 조건에 맞는지 확인(k칸씩 더하면서 갯수가 K이거나 0이거나 확인), 하나의 column이라도 조건에 맞지 않을 경우 false return
4. true일 경우 값을 저장하고 탐색을 종료
*/

/******* new version(faster) *******/
#include <iostream>

using namespace std;

int map[13][20];
int original[13][20];
int d, w, k;
int ans;


bool scan() {
    for(int j = 0; j < w; ++j) {
        int sum = 0;
        bool find = false;

        for(int i = 0; i < k-1; ++i) sum += map[i][j];

        for(int i = k-1; i < d; ++i) {
            sum += map[i][j];
            if(sum == k || sum == 0) find = true;
            sum -= map[i-k+1][j];
        }

        if(!find) return false;
    }

    return true;
}


void injection(int n) {
    bool check[13];

    for(int i = 0; i < 1<<d; ++i) {
        int count = 0;

        for(int j = 0; j < d; ++j) {
            check[j] = false;
            if(i & 1<<j) {
                count++;
                check[j] = true;
            }
        }
        if(count != n) continue;

        for(int j = 0; j < d; ++j) {
            if(!check[j]) continue;

            for(int k = 0; k < w; ++k) {
                map[j][k] = 1;
            }
        }
        if(scan()) {
            ans = n;
            return;
        }

        for(int j = 0; j < d; ++j) {
            if(!check[j]) continue;

            for(int k = 0; k < w; ++k) {
                map[j][k] = 0;
            }
        }
        if(scan()) {
            ans = n;
            return;
        }

        for(int j = 0; j < d; ++j) {
            if(!check[j]) continue;

            for(int k = 0; k < w; ++k) {
                map[j][k] = original[j][k];
            }
        }
    }
}

int main(void) {
    int t, tc = 0;
    scanf("%d", &t);

    while(++tc <= t) {
        ans = -1;
        scanf("%d %d %d", &d, &w, &k);

        for(int i = 0; i < d; ++i) {
            for(int j = 0; j < w; ++j) {
                scanf("%d", &map[i][j]);
                original[i][j] = map[i][j];
            }
        }

        for(int i = 0; i < d; ++i) {
            injection(i);
            if(ans > -1) break;
        }

        printf("#%d %d\n", tc, ans);
    }
}