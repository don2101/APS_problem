/**
 * 완전 탐색 문제
 * 
 * 풀면서 어려웠던 점
 * 1. 문제를 깊게 생각하지 않고 풀었다.
 * 2. 여러 케이스에 대해 완벽한 고민을 하지 않고 풀었다.
 * 3. 그 결과, 문제를 복잡하게 풀었으며, 구현하는데 시간이 더 들었다.
 * */

#include<iostream>

using namespace std;

int incorrect[1000];
int incP;
int n;
int numArray[1000];
int ans;

int findInc(int num, int pos) {
    int ret = -1;
	for(int i = 0; i < incP; ++i) {
        if(incorrect[i] == -1) continue;
    	if(numArray[incorrect[i]]%3 == num && pos%3 == incorrect[i]%3) {
        	ret = incorrect[i];
            incorrect[i] = -1;
            break;
        }
    }
    
    if(ret == -1) {
    	for(int i = 0; i < incP; ++i) {
            if(incorrect[i] == -1) continue;
            if(numArray[incorrect[i]]%3 == num) {
                ret = incorrect[i];
                incorrect[i] = -1;
                break;
            }
        }
    }
    
    for(int i = 0; i < incP; ++i) {
    	if(numArray[incorrect[i]] == pos) {
        	incorrect[i] = ret;
            break;
        }
    }
    
    return ret;
}

void setNum(int num, int set) {
	for(int i = 0; i < incP; ++i) {
    	if(numArray[incorrect[i]] == num) {
        	incorrect[i] = set;
            break;
        }
    }
}

int main(int argc, char** argv)
{
	int t, tc = 0;
    cin >> t;
    
    while(++tc <= t) {
    	cin >> n;
		incP = 0; ans = 0;
        
        for(int i = 1; i <= n; ++i) {
        	cin >> numArray[i];
            
            if(numArray[i]%3 != i%3) {
            	incorrect[incP++] = i;
            }
        }
        
        for(int i = 1; i <= n; ++i) {
        	if(numArray[i]%3 != i%3) {
            	int ret = findInc(i%3, numArray[i]);
                int temp = numArray[i];
                numArray[i] = numArray[ret];
                numArray[ret] = temp;
                ans++;
                
                if(numArray[ret]%3 == ret%3) {
                	setNum(numArray[ret], -1);
                }
            }
        }
        
        cout << "#" << tc << " " << ans << endl;
    }
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}