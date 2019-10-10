#include<iostream>

using namespace std;

/**
 * 2개 원자 충돌 => 에너지 방출하고 소멸
 * 상: y증가, 하: y감소, 좌: x감소, 우: x증가
 * 크기 1000*1000
 * 
 * - 메서드
 * 1. 원자를 0.5만큼 이동
 * 2. 원자의 위치가 같은지 확인
 * 3. 소멸 먼저
 * 4. 이동 가능?(inbound, )
 * 
 * - 자료구조
 * 1. 원자의 위치x, y(double 배열)
 * 2. 원자의 생존 여부
 * 3. 원자의 방향
 * 4. 원자의 에너지
 * */

int n, ans;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
double x[1000];
double y[1000];
bool alive[1000];
int direc[1000];
int energy[1000];
int remain;

bool isInside(double y_, double x_) {
    if(y_ > (double) 1000 || y_ < (double) -1000) return false;
    if(x_ > (double) 1000 || x_ < (double) -1000) return false;

    return true;
}

void destroyOne(int i) {
    energy[i] = energy[n-1];
    alive[i] = alive[n-1];
    x[i] = x[n-1];
    y[i] = y[n-1];
    direc[i] = direc[n-1];
    n--;
    remain--;
}

double abs(double num) {
    if(num < 0) return -num;
    
    return num;
}

bool isSame(int i, int j) {
    if(abs(x[i]-x[j]) < 0.1 && abs(y[i]-y[j]) < 0.1) return true;

    return false;
}


void sumEnergy() {
    for(int i = 0; i < n-1;) {
        if(!isInside(y[i], x[i])) {
            destroyOne(i);
            continue;
        }

        int tempEnergy = energy[i];
        for(int j = i+1; j < n;) {
            if(!isInside(y[j], x[j])) {
                destroyOne(j);
                continue;
            }
            
            if(isSame(i, j)) {
                tempEnergy += energy[j];
                destroyOne(j);
            } else {
                ++j;
            }
        }

        if(tempEnergy > energy[i]) {
            destroyOne(i);
            ans += tempEnergy;
        } else {
            ++i;
        }
    }
}

void move() {
    for(int i = 0; i < n; ++i) {
        if(!alive[i]) continue;

        x[i] += (double)dx[direc[i]]*0.5;
        y[i] += (double)dy[direc[i]]*0.5;
    }
}

void init() {
    cin >> n;
    ans = 0;
    remain = n;
    

    for(int i = 0; i < n; ++i) {
        alive[i] = true;
        int tempX, tempY;
        cin >> tempX >> tempY;
        
        x[i] = (double) tempX;
        y[i] = (double) tempY;
        cin >> direc[i] >> energy[i];
    }

}

int main(int argc, char** argv)
{
    int t, tc = 0;
    cin >> t;

    while(++tc <= t) {
        init();

        while(true) {
            move();
            sumEnergy();
            if(remain == 0) break;
        }

        cout << "#" << tc << " " << ans << endl;
    }
    

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}