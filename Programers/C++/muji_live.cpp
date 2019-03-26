/*
1. foods: 음식을 먹는데 걸리는 시간이 들어있는 배열
2. foods를 순회하며 가장 적은 시간이 걸리는 음식을 찾는다.
3. k에서 남은 음식 수 * 가장 적은 시간을 뺀다
3-1. 만약 k가 빼야하는 수 보다 작으면
4. foods를 순회하며 0이상인 음식 중 가장 적은 시간을 모두 뺀다
5. 남은 시간이 0이 된 음식 만큼 남은 음식수에서 뺀다
*/

#include <string>
#include <vector>

using namespace std;

int foods[200000];
bool visited[200000];
long long remain;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int size = food_times.size();
    remain = size;
    
    bool find = false;
    
    while(remain > 0 && k > 0) {
        int min = 100000001;
        
        for(int i = 0; i < size; ++i) {
            if(food_times[i] > 0) {
                if(min > food_times[i]) {
                    min = food_times[i];
                }
            }
        }
        
        if(k < remain*min) {
            k %= remain;
            
            int step = 0;
            
            for(int i = 0; i < size; ++i) {
                if(food_times[i] > 0) {
                    k--;
                }
                if(k < 0) {
                    find = true;
                    answer = i+1;
                    break;
                }    
            }
            
            if(find) {
                break;
            }
        }
        
        k -= remain*min;
        
        for(int i = 0; i < size; ++i) {
            if(food_times[i] > 0) {
                food_times[i] -= min;
                if(food_times[i] == 0) {
                    remain--;
                }
            }
        }
    
    }
    
    if(find) {
        answer = answer;
    } else if(remain == 0) {
        answer = -1;
    } else {
        for(int i = 0; i < size; ++i) {
            if(food_times[i] > 0 && !visited[i]) {
                answer = i + 1;
                break;
            }
        }
    }
    
    return answer;
}