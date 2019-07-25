#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N              4
#define MAX_QUERYCOUNT 1000000

#define N 4

typedef struct {
    int strike;
	int ball;
} Result;

 
extern Result query(int guess[]);

bool used[10][10][10][10];
int queryList[5400][4];
int answered[5400][4];
Result resultList[5400];
int cur;
int last;
int ansCur;
int ansLast;


bool checkQuery(int *tryQuery) {
    for(int i = 0; i < ansLast; ++i) {
        int strike = 0;
        int ball = 0;

        for(int a = 0; a < 4; ++a) {
            for(int q = 0; q < 4; ++q) {
                if(answered[i][a] == tryQuery[q]) {
                    if(a == q) strike++;
                    else ball++;

                    break;
                }
            }
        }

        if(resultList[i].strike != strike || ball != resultList[i].ball) {
            return false;
        }
    }

    return true;
}

void initQuery() {
    int tryQuery[4];
    
    for(int a = 0; a < 9; ++a) {
        tryQuery[0] = a;
    	
        for(int b = 0; b < 9; ++b) {
            if(b == a) continue;
            tryQuery[1] = b;
        	
            for(int c = 0; c < 9; ++c) {
                if(c == a || c == b) continue;
            	tryQuery[2] = c;
            	
                for(int d = 0; d < 9; ++d) {
                	if(d== a || d == b || d == c) continue;
            		tryQuery[3] = d;
                    
                    if(checkQuery(tryQuery)) {
                        queryList[last][0] = tryQuery[0];
                        queryList[last][1] = tryQuery[1];
                        queryList[last][2] = tryQuery[2];
                        queryList[last++][3] = tryQuery[3];
                    }
                    
                }
            }
        }
    }
    
}


void init() {
	for(int a = 0; a < 10; ++a)
    	for(int b = 0; b < 10; ++b)
        	for(int c = 0; c < 10; ++c)
            	for(int d = 0; d < 10; ++d)
                	used[a][b][c][d] = false;

	cur = 0;
	last = 0;
	ansCur = 0;
	ansLast = 0;
}

void doUserImplementation(int guess[]) {
	init();
    int guess1[4];
    guess1[0] = 0; guess1[1] = 1; guess1[2] = 2; guess1[3] = 3;
    
    Result result = query(guess1);
    answered[ansLast][0] = 0;
    answered[ansLast][1] = 1;
    answered[ansLast][2] = 2;
    answered[ansLast][3] = 3;
    resultList[ansLast++] = result;
    used[0][1][2][3] = true;
    initQuery();
    
    while(true) {
        // queryList의 현재 위치한 query가 가능한 query인지 검증(check)
        if(!checkQuery(queryList[cur])) {
            cur++;
            continue;
        }
        // 검증되면 보낸다.
        result = query(queryList[cur]);
        if(result.strike == 4) {
            guess[0] = queryList[cur][0];
            guess[1] = queryList[cur][1];
            guess[2] = queryList[cur][2];
            guess[3] = queryList[cur][3];
            break;
        }
        // 보낸 결과와 보냈던 query를 저장
        answered[ansLast][0] = queryList[cur][0];
        answered[ansLast][1] = queryList[cur][1];
        answered[ansLast][2] = queryList[cur][2];
        answered[ansLast][3] = queryList[cur][3];
        resultList[ansLast++] = result;

        initQuery();
        cur++;

        // 반복
    }

    // 모든 경우를 따지면서 현재 결과에 대해 가능한 것을 정한다.
}







static int digits[N];
static int digits_c[10];

static int T;

extern void doUserImplementation(int guess[]);

static int querycount; 

// the value of limit_query will be changed in evaluation
static const int limit_query = 2520;


static bool isValid(int guess[]) {
	int guess_c[10];
	
	for (int count = 0; count < 10; ++count) guess_c[count] = 0;
	for (int idx = 0; idx < N; ++idx) {
		if (guess[idx] < 0 || guess[idx] >= 10 || guess_c[guess[idx]] > 0) return false;
		guess_c[guess[idx]]++;
	}
	return true;
}

// API : return a result for comparison with digits[] and guess[]
Result query(int guess[]) {
	Result result;
	
	if (querycount >= MAX_QUERYCOUNT) {
		result.strike = -1;
		result.ball = -1;
		return result;
	}
	
    querycount++;
		
	if (!isValid(guess)) {
		result.strike = -1;
		result.ball = -1;
		return result;
	}
	
	result.strike = 0;
	result.ball = 0;

	for (int idx = 0; idx < N; ++idx)
		if (guess[idx] == digits[idx])
			result.strike++;
		else if (digits_c[guess[idx]] > 0)
			result.ball++;

	return result;
}

static void initialize() {
	for (int count = 0; count < 10; ++count) digits_c[count] = 0;
	for (int idx = 0; idx < N; ++idx) {
		char c;
		do scanf("%c", &c); while(c < '0' || c > '9');
		digits[idx] = c - '0';
		digits_c[digits[idx]]++;
	}
	
	querycount = 0;
}

static bool check(int guess[]) {
	for (int idx = 0; idx < N; ++idx)
		if (guess[idx] != digits[idx]) return false;
	return true;
}

int main() {
	int total_score = 0;
	int total_querycount = 0;;
	
    // freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++testcase) {
        initialize();

        int guess[N];
		doUserImplementation(guess);

		if (!check(guess)) querycount = MAX_QUERYCOUNT;
        if (querycount <= limit_query) total_score++;
		printf("#%d %d\n", testcase, querycount);
		total_querycount += querycount;
    }
	if (total_querycount > MAX_QUERYCOUNT) total_querycount = MAX_QUERYCOUNT;
	printf("total score = %d\ntotal query = %d\n", total_score * 100 / T, total_querycount);
	return 0;
}