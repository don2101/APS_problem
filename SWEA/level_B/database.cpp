#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define NULL nullptr

typedef enum
{
	CMD_INIT,
	CMD_ADD,
	CMD_DELETE,
	CMD_CHANGE,
	CMD_SEARCH
} COMMAND;

typedef enum
{
	NAME,
	NUMBER,
	BIRTHDAY,
	EMAIL,
	MEMO
} FIELD;

typedef struct
{
	int count;
	char str[20];
} RESULT;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

extern void InitDB();
extern void Add(char* name, char* number, char* birthday, char* email, char* memo);
extern int Delete(FIELD field, char* str);
extern int Change(FIELD field, char* str, FIELD changefield, char* changestr);
extern RESULT Search(FIELD field, char* str, FIELD returnfield);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

static int dummy[100];
static int Score, ScoreIdx;
static char name[20], number[20], birthday[20], email[20], memo[20];

static char lastname[10][5] = { "kim", "lee", "park", "choi", "jung", "kang", "cho", "oh", "jang", "lim" };
static int lastname_length[10] = { 3, 3, 4, 4, 4, 4, 3, 2, 4, 3 };

static int mSeed;
static int mrand(int num)
{
	mSeed = mSeed * 1103515245 + 37209;
	if (mSeed < 0) mSeed *= -1;
	return ((mSeed >> 8) % num);
}

static void make_field(int seed)
{
	int name_length, email_length, memo_length;
	int idx, num;

	mSeed = (unsigned int)seed;

	name_length = 6 + mrand(10);
	email_length = 10 + mrand(10);
	memo_length = 5 + mrand(10);

	num = mrand(10);
	for (idx = 0; idx < lastname_length[num]; idx++) name[idx] = lastname[num][idx];
	for (; idx < name_length; idx++) name[idx] = 'a' + mrand(26);
	name[idx] = 0;

	for (idx = 0; idx < memo_length; idx++) memo[idx] = 'a' + mrand(26);
	memo[idx] = 0;

	for (idx = 0; idx < email_length - 6; idx++) email[idx] = 'a' + mrand(26);
	email[idx++] = '@';
	email[idx++] = 'a' + mrand(26);
	email[idx++] = '.';
	email[idx++] = 'c';
	email[idx++] = 'o';
	email[idx++] = 'm';
	email[idx] = 0;

	idx = 0;
	number[idx++] = '0';
	number[idx++] = '1';
	number[idx++] = '0';
	for (; idx < 11; idx++) number[idx] = '0' + mrand(10);
	number[idx] = 0;

	idx = 0;
	birthday[idx++] = '1';
	birthday[idx++] = '9';
	num = mrand(100);
	birthday[idx++] = '0' + num / 10;
	birthday[idx++] = '0' + num % 10;
	num = 1 + mrand(12);
	birthday[idx++] = '0' + num / 10;
	birthday[idx++] = '0' + num % 10;
	num = 1 + mrand(30);
	birthday[idx++] = '0' + num / 10;
	birthday[idx++] = '0' + num % 10;
	birthday[idx] = 0;
}

static void cmd_init()
{
	scanf("%d", &ScoreIdx);

	InitDB();
}

static void cmd_add()
{
	int seed;
	scanf("%d", &seed);

	make_field(seed);

	Add(name, number, birthday, email, memo);
}

static void cmd_delete()
{
	int field, check, result;
	char str[20];
	scanf("%d %s %d", &field, str, &check);

	result = Delete((FIELD)field, str);
	if (result != check)
		Score -= ScoreIdx;
}

static void cmd_change()
{
	int field, changefield, check, result;
	char str[20], changestr[20];
	scanf("%d %s %d %s %d", &field, str, &changefield, changestr, &check);

	result = Change((FIELD)field, str, (FIELD)changefield, changestr);
	if (result != check)
		Score -= ScoreIdx;
}

static void cmd_search()
{
	int field, returnfield, check;
	char str[20], checkstr[20];
	scanf("%d %s %d %s %d", &field, str, &returnfield, checkstr, &check);

	RESULT result = Search((FIELD)field, str, (FIELD)returnfield);

	if (result.count != check || (result.count == 1 && (strcmp(checkstr, result.str) != 0)))
		Score -= ScoreIdx;
}

static void run()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int cmd;
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:   cmd_init();   break;
		case CMD_ADD:    cmd_add();    break;
		case CMD_DELETE: cmd_delete(); break;
		case CMD_CHANGE: cmd_change(); break;
		case CMD_SEARCH: cmd_search(); break;
		default: break;
		}
	}
}

static void init()
{
	Score = 1000;
	ScoreIdx = 1;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	int TotalScore = 0;
	for (int tc = 1; tc <= T; tc++)
	{
		init();

		run();

		if (Score < 0)
			Score = 0;

		TotalScore += Score;
		printf("#%d %d\n", tc, Score);
	}
	printf("TotalScore = %d\n", TotalScore);

	return 0;
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

class Record {
public:
	char name[20];
	char number[20];
	char birthday[20];
	char email[20];
	char memo[20];
	Record *next;
	Record *prev;

	Record(char* name, char* number, char* birthday, char* email, char* memo) {
		copy(this->name, name);
		copy(this->number, number);
		copy(this->birthday, birthday);
		copy(this->email, email);
		copy(this->memo, memo);
		this->next = NULL;
		this->prev = NULL;
	}
	
	void copy(char *dest, char *str) {
		int idx = 0;
		while (str[idx] != '\0') {
			dest[idx] = str[idx];
			idx++;
		}
		dest[idx] = str[idx];
	}

	bool compare(char *dest, char *str) {
		int dp = 0;
		int sp = 0;
		while (dest[dp] != '\0' && str[sp] != '\0') {
			if (dest[dp] != str[sp]) return false;
			dp++; sp++;
		}

		if (dest[dp] != '\0' && str[sp] == '\0') return false;
		if (dest[dp] == '\0' && str[sp] != '\0') return false;

		return true;
	}

	bool isSame(FIELD field, char *str) {
		switch (field)
		{
		case NAME: return compare(this->name, str); break;
		case NUMBER: return compare(this->number, str); break;
		case BIRTHDAY: return compare(this->birthday, str); break;
		case EMAIL: return compare(this->email, str); break;
		case MEMO: return compare(this->memo, str); break;
		default: break;
		}

		return false;
	}

	void fieldCopy(FIELD field, char *str) {
		switch (field)
		{
		case NAME: copy(this->name, str); break;
		case NUMBER: copy(this->number, str); break;
		case BIRTHDAY: copy(this->birthday, str); break;
		case EMAIL: copy(this->email, str); break;
		case MEMO: copy(this->memo, str); break;
		default: break;
		}
	}
	
	~Record() {
	/*	delete[] name;
		delete[] number;
		delete[] birthday;
		delete[] email;
		delete[] memo;*/
	}
};


class RecordList{
public:
	Record* first;
	Record* last;

	RecordList() {
		this->first = NULL;
		this->last = NULL;
	}
	~RecordList();
};

RecordList *rl;


void InitDB()
{

	rl = new RecordList();
}

void Add(char* name, char* number, char* birthday, char* email, char* memo)
{
	Record *newRecord = new Record(name, number, birthday, email, memo);
	
	if (rl->first == NULL) {
		rl->first = newRecord;
		rl->last = newRecord;
	}
	else {
		rl->last->next = newRecord;
		newRecord->prev = rl->last;
		rl->last = newRecord;
	}
}

int Delete(FIELD field, char* str)
{
	Record *search = rl->first;
	int count = 0;

	while (search != NULL) {
		if (search->isSame(field, str)) {
			Record *deleteNode = search;
			Record *temp = search->next;
			
			deleteNode->prev->next = deleteNode->next;
			deleteNode->next->prev = deleteNode->prev;
			count++;
			delete deleteNode;

			search = temp;
		}
		else {
			search = search->next;
		}
	}
	
	return count;
}

int Change(FIELD field, char* str, FIELD changefield, char* changestr)
{
	Record *search = rl->first;
	int count = 0;

	while (search != NULL) {
		if (search->isSame(field, str)) {
			search->fieldCopy(changefield, changestr);
			count++;
			search = search->next;
		}
		else {
			search = search->next;
		}
	}

	return count;
}

RESULT Search(FIELD field, char* str, FIELD ret_field)
{
	RESULT result;
	Record *search = rl->first;
	bool flag_ = false;

	result.count = 0;

	while (search != NULL) {
		if (search->isSame(field, str)) {
			result.count++;
			if (!flag_) {
				switch (ret_field) {
				case NAME: search->copy(result.str, search->name); break;
				case NUMBER: search->copy(result.str, search->number); break;
				case BIRTHDAY: search->copy(result.str, search->birthday); break;
				case EMAIL: search->copy(result.str, search->email); break;
				case MEMO: search->copy(result.str, search->memo); break;
				default: break;
				}
				flag_ = true;
			}
			search = search->next;
		}
		else {
			search = search->next;
		}
	}

	return result;
}