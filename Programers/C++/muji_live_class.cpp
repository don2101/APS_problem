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

class node {
public:
    int number;
    int index;
    node* next;
    node(int num, int idx);
    ~node();
};

node::node(int num, int idx) {
    number = num;
    index = idx;
    next = NULL;
}

node::~node() {
    next = NULL;
}

class list {
public:
    node* head;
    node* tail;
    int size;
    void insert(int num, int idx);
    void del(node* preNode);
    
    list();
    ~list();
};

list::list() {
    head = new node(-1, -1);
    tail = new node(-1, -1);
    size = 0;
}

list::~list() {
    
}

void list::insert(int num, int idx) {
    node* newNode = new node(num, idx);
    
    if(size <= 0) {
        newNode->next = tail;
        head->next = newNode;
        tail->next = newNode;
    } else {
        tail->next->next = newNode;
        newNode->next = tail;
        tail->next = newNode;
    }
    size++;
}

void list::del(node* preNode) {
    node* delNode = preNode->next;
    preNode->next = delNode->next;
    if(delNode->next == tail) {
        tail->next = preNode;
    }
    size--;
    delete delNode;
}


int foods[200000];
bool visited[200000];
long long remain;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int size = food_times.size();
    remain = size;
    
    list* l = new list();
    
    bool find = false;
    
    for(int i = 0; i < size; ++i) {
        
    	l->insert(food_times[i], i);
	}
    
    while(remain > 0 && k > 0) {
        int min = 100000001;
        
        node* n = l->head->next;
        
        while(n->number != -1) {
        	int temp_num = n->number;
            if(temp_num > 0) {
                if(min > temp_num) {
                    min = temp_num;
                }
            }
            n = n->next;
		}
        
        if(k < remain*min) {
            k %= remain;
            
            n = l->head->next;
            
            while(n->number != -1) {
            	int temp_num = n->number;
            	
                if(temp_num > 0) {
                    k--;
                }
                
                if(k < 0) {
                    find = true;
                    answer = n->index + 1;
                    break;
                }    
                n = n->next;
            }
            
            if(find) {
                break;
            }
        }
        
        k -= remain*min;
        
        n = l->head->next;
        node* preN = l->head;
        
        while(n->number != -1) {
        	int temp_num = n->number;
            
			if(temp_num > 0) {
                n->number -= min;
                if(n->number == 0) {
                    l->del(preN);
                    remain--;
                }
            }
            preN = preN->next;
            n = n->next;
        }
    
    }
    
    if(find) {
        answer = answer;
    } else if(remain == 0) {
        answer = -1;
    } else {
    	node* n = l->head->next;
        while(n->number != -1) {
        	int temp_num = n->number;
        	
            if(temp_num > 0) {
                answer = n->index + 1;
                break;
            }
            n = n->next;
        }
    }
    
    return answer;
}