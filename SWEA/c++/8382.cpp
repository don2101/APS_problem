/**
 * 간단한 시뮬레이션 문제
 * 
 * 풀면서 어려웠던 점
 * 1. 문제의 조건을 검토하지 않아 헤멤
 * */

#include<iostream>

using namespace std;

int curX, curY;
int x, y;
int ans;
bool flag_;

int abs(int num) {
	if(num < 0) return -num;
    return num;
}

int main(int argc, char** argv)
{
	int t, tc = 0;
    cin >> t;
    
    while(++tc <= t) {
    	cin >> curX >> curY >> x >> y;
        ans = 0;
        
        if(abs(curX - x) > abs(curY - y)) flag_ = true;
        else flag_ = false;
        
        while(curX != x || curY != y) {
        	if(flag_) {
            	if(curX >= x) curX--;
                else curX++;
            } else {
            	if(curY >= y) curY--;
                else curY++;
            }
            flag_ = !flag_;
            ans++;

        }
        
        cout << "#" << tc << " " << ans << endl;
    }
    
	return 0;
}