#include <iostream>

using namespace std;

int table[256];
string map[10];
int number[10000];
int pointer;

void insert(int num) {
	number[pointer] = num;
    for(int i = pointer; i > 0; --i) {
    	if(number[i] < number[i-1]) {
        	int tmp = number[i];
            number[i] = number[i-1];
            number[i-1] = tmp;
        }
    }
    pointer++;
}

int main(void) {
	int t, tc = 0;
    cin >> t;
    t = 1;
    
    for(int i = 0; i < 256; ++i) {
    	table[i] = -1;
    }
    table['Z'+'R'] = 0;
    table['O'+'N'] = 1;
    table['T'+'W'] = 2;
    table['T'+'H'] = 3;
    table['F'+'O'] = 4;
    table['F'+'I'] = 5;
    table['S'+'I'] = 6;
    table['S'+'V'] = 7;
    table['E'+'G'] = 8;
    table['N'+'I'] = 9;
    map[0] = "ZRO";
    map[1] = "ONE";
    map[2] = "TWO";
    map[3] = "THR";
    map[4] = "FOR";
    map[5] = "FIV";
    map[6] = "SIX";
    map[7] = "SVN";
    map[8] = "EGT";
    map[9] = "NIN";
    
    while(++tc <= t) {
        string title;
        int n = 0;
        cin >> title;
        cin >> n;
        pointer = 0;
        
        string s;
        for(int i = 0; i < n; ++i) {
        	cin >> s;
			insert(table[s[0]+s[1]]);
        }
        
        cout << "#" << tc << endl;
        for(int i = 0; i < n; ++i) {
                cout << map[number[i]] << " ";
            }
        cout << endl;
    }   
}