#include<iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

struct numbers {
    long long a;
    long long b;
};

numbers num_array[200000];
int n, ans;

bool compare(numbers num1, numbers num2) {
	double first, second;
    first = (double)(num1.a - 1)/(double)num1.b;
    second = (double)(num2.a - 1)/(double)num2.b;
    
    if(first <= second) return false;
    return true;
}

int main(int argc, char** argv)
{
	int t, tc = 0;
    cin >> t;
    
    while(++tc <= t) {
    	cin >> n;
        ans = 1;
        
        for(int i = 0; i < n; ++i) {
        	cin >> num_array[i].a >> num_array[i].b;
        }
        
        // 1. 부등호 관계를 이용하여 정렬
        // 1-1. 정렬할 때 comparable 함수 구현해서 진행
        sort(num_array, num_array+n, compare);
        
        // 2. 정렬된 배열을 통해 계산된 값을 구한다.
        for(int i = 0; i < n; ++i) {
        	ans = ((num_array[i].a * ans) + num_array[i].b) % MOD;
        }
        
        cout << &quot;#&quot; << tc << &quot; &quot; << ans << endl;
    }
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}