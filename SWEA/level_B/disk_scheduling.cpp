#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum COMMAND {
	CMD_REQUEST = 0,
	CMD_FCFS = 1,
	CMD_SSTF = 2,
	CMD_LOOK = 3,
	CMD_CLOOK = 4
};

extern void init(int track_size, int head);
extern void request(int track);
extern int fcfs();
extern int sstf();
extern int look();
extern int clook();

static const int MAX = 100000;
static const int SAMPLE_SIZE = 200;
static int track_size;
static int track_head;
static int answer[MAX];
static int answer_size;
static int answer_idx;
static int req_q[MAX];
static int req_size;
static int req_idx;
static int cmd_q[MAX * 2];
static int cmd_size;
static int cmd_idx;

static bool flag[MAX];

static int mSeed;
static int mrand(int num)
{
	mSeed = mSeed * 1103515245 + 37209;
	if (mSeed < 0) mSeed *= -1;
	return ((mSeed >> 8) % num);
}

static void load_data(int tc) {
	scanf("%d %d", &track_size, &track_head);

	if (tc <= 4) {
		scanf("%d", &req_size);
		for (register int i = 0; i < req_size; ++i) scanf("%d", &req_q[i]);
		scanf("%d", &cmd_size);
		for (register int i = 0; i < cmd_size; ++i) scanf("%d", &cmd_q[i]);
		scanf("%d", &answer_size);
		for (register int i = 0; i < answer_size; ++i) scanf("%d", &answer[i]);
	}
	else {
		scanf("%d %d", &req_size, &answer_size);
		for (register int i = 0; i < answer_size; ++i) scanf("%d", &answer[i]);
		scanf("%d", &mSeed);
		cmd_size = req_size + answer_size;
	}
}

static int run(int tc) {
	answer_idx = req_idx = cmd_idx = 0;
	int correct = 0;
	int cmd = 0;
	int user_answer = 0;
	int new_track = 0;
	int req_cnt = 0;

	for (register int i = 0; i < track_size; ++i) flag[i] = false;

	while (req_size != req_cnt || (tc <= 4 && cmd_size != cmd_idx)) {
		if (tc <= 4)	cmd = cmd_q[cmd_idx++];
		else cmd = mrand(9);

		user_answer = -1;

		if (CMD_FCFS <= cmd && CMD_CLOOK >= cmd && (req_cnt - answer_idx) > 0) {
			if (cmd == CMD_FCFS) user_answer = fcfs();
			else if (cmd == CMD_SSTF) user_answer = sstf();
			else if (cmd == CMD_LOOK) user_answer = look();
			else user_answer = clook();

			if (answer[answer_idx++] == user_answer)	++correct;
		}
		else {
			if (tc <= 4) new_track = req_q[req_idx++];
			else {
				new_track = mrand(track_size);
				while (flag[new_track]) {
					++new_track;
					if (new_track == track_size) new_track = 0;
				}
			}

			request(new_track);
			flag[new_track] = true;
			++req_cnt;
		}
	}

	return correct;
}

int main() {
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int total_score = 0, T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc) {
		load_data(tc);
		init(track_size, track_head);
		int score = run(tc);
		printf("#%d %d\n", tc, score);
		total_score += score;
	}

	printf("Total score: %d\n", total_score);
	return 0;
}


int queue[200000];
bool track_number[200000];
int size_of_track;
int rear, front;
int head_point;
char direc;
int count;


void init(int track_size, int head) {
	for (int i = 0; i <= track_size; ++i) {
		queue[i] = -1;
		track_number[i] = false;
	}
	direc = -1;
	rear = 0;
	front = 0;
	size_of_track = track_size;
	head_point = head;
}

void request(int track) {
	queue[front++] = track;
	track_number[track] = true;
}

int fcfs() {
	int number = 0;

	while (rear != front) {
		number = queue[rear++];

		if (!track_number[number]) {
			rear++;
		}
		else {
			track_number[number] = false;
			head_point = number;
			rear++;
			break;
		}
	}

	return number;
}

int find() {
	int left = head_point - 1;
	int right = head_point + 1;

	int number = 0;

	while (left >= 0 && right <= size_of_track) {
		if (track_number[left] && !track_number[right]) {
			number = left;
			return number;
		} else if (!track_number[left] && track_number[right]) {
			number = right;
			return number;
		} else if (track_number[left] && track_number[right]) {
			number = left;
			return number;
		} else {
			left--;
			right++;
		}
	}

	if (right == size_of_track) {
		while (!track_number[left]) left--;
		number = left;
	} 
	else {
		while (!track_number[right]) right++;
		number = right;
	}

	return number;
}

int sstf() {
	int number = find();
	track_number[number] = false;
	head_point = number;

	return number;
}

int look() {
	int start = head_point;
	
	while (!track_number[head_point] && head_point >= 0 && head_point <= size_of_track-1) {
		head_point += direc;
	}

	if (head_point < 0 || head_point > size_of_track - 1) {
		direc *= -1;
		head_point = start;

		while (!track_number[head_point] && head_point >= 0 && head_point <= size_of_track - 1) {
			head_point += direc;
		}
	}

	track_number[head_point] = false;

	return head_point;
}

int clook() {
	
	while (!track_number[head_point] && head_point >= 0) {
		head_point--;
	}

	if (head_point < 0) {
		direc *= -1;
		head_point = size_of_track - 1;

		while (!track_number[head_point] && head_point >= 0) {
			head_point--;
		}
	}

	track_number[head_point] = false;

	return head_point;
}