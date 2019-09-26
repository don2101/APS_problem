#include <iostream>

using namespace std;

// 문제 풀이
// 1. 일단 조건을 만족하는 c가 존재한다.
// 2. 그렇다면 c 이상의 수는 무조건 조건을 만족하며, c 미만의 수는 조건을 만족하지 못한다.
// 3. 이분탐색을 통해 c값을 찾자.
// 4. 판단? 그리디로 확인

int ans;
int n, k, c;
bool visited[200000];
int w[200000];
int s[200000];

bool possible(int i, int k, int c) {
	for(int j = i; j < i+k; ++j) {
   		if(w[j] > c) return false;
        if(visited[j]) return false;
        
        
        
    }
}

bool check_block(int c) {
	for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    
    // 메모리 블록을 처음부터 대입
    int current = 0;
    for(int i = 0; i < n; ++i) {
    	// 메모리 블록이 현재 칸에 들어갈 수 있는지 확인
        if(possible()) {
        
        }
    }
}


int main(void) {
	int t, tc = 0;
    
    while(++tc <= t) {
    	cin >> n >> k;
        for (int i = 0; i < n; ++i) {
        	cin >> w[i];
        }
        
        for (int i = 0; i < k; ++i) {
        	cin >> s[i];
        }
        
        // 이분탐색 시작
        int big = n-1;
        int small = 0;
        
        while(small <= big) {
        	int mid = (big+small)/2;
            
            
        }
        
        
    }
}