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


bool check(int tryQuery[]) {
	if(used[tryQuery[0]][tryQuery[1]][tryQuery[2]][tryQuery[3]]) {
        return false;
    }

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
                    
                    if(check(tryQuery)) {
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
    
    guess[0] = 0; guess[1] = 1; guess[2] = 2; guess[3] = 3;
    
    Result result = query(guess);
    answered[ansLast][0] = 0;
    answered[ansLast][1] = 1;
    answered[ansLast][2] = 2;
    answered[ansLast][3] = 3;
    resultList[ansLast++] = result;
    initQuery();

    while(result.strike < 4) {
        // queryList의 현재 위치한 query가 가능한 query인지 검증(check)
        // 검증되면 보낸다.
        // 보낸 결과와 보냈던 query를 저장
        // 반복
    }

    // 모든 경우를 따지면서 현재 결과에 대해 가능한 것을 정한다.

	
}