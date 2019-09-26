#include <iostream>

using namespace std;

long long ans;
bool check_prime[1000001];
long long counting[1000001];
int a, b;

void eratostenith() {
    for(int i = 0; i <= 1000000; ++i) {
    	counting[i] = i;
        check_prime[i] = true;
    }
    
	for(int i = 2; i <= 1000000; ++i) {
        if(!check_prime[i])  continue;
        int k = 1;
    	
        while(k*i <= 1000000) {
        	check_prime[k*i] = false;
            counting[k*i] = counting[k*i]/(long long)i;
            counting[k*i] = counting[k*i] * (long long)(i-1);
            k++;
        }
    }
    
    // for(int i = 0; i <= 1000000; ++i) {
    //     cout << i << " : " << counting[i] << endl;
    // }

    
    for(int i = 1; i < 1000000; ++i) {
    	counting[i+1] += counting[i];
    }
}


int main(void) {
	int t, tc = 0;
    cin >> t;
    eratostenith();
    
    while(++tc <= t) {
    	cin >> a >> b;
        ans = counting[b] - counting[a-1];
		
        cout << "#" << tc << " " << ans << endl;
    }
}
