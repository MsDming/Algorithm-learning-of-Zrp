#include<iostream>
#include<algorithm>
using namespace std;

void pipline_sche(int* A, int* B);

class Job {//定义工作类
public:
	bool operator<(Job a) {
		return this->key < a.key;
	}
	int key, index;
	bool job;
};

int main() {
	int A[5] = { 2,4,3,6,1 }, B[5] = { 5,2,3,1,7 };
	pipline_sche(A, B);
	return 0;
}

void pipline_sche(int* A, int* B) {
	Job* J = new Job[5];
	for (int i = 0; i < 5; i++) {
		J[i].index = i;
		J[i].key = A[i] < B[i] ? A[i] : B[i];
		J[i].job = A[i] < B[i];
	}
	//用Johnson法则求解
	sort(J, J + 4);//消耗时间由少到多排序
	Job* res = new Job[5];
	int j = 0, k = 4;
	for (int i = 0; i < 5; i++) {//一阶段时间短的往前排，二阶段时间短的往后排
		if (J[i].job) {
			res[j++] = J[i];
		} else {
			res[k--] = J[i];
		}
	}
	int t1 = A[res[0].index], t2 = A[res[0].index] + B[res[0].index];
	for (int i = 1; i < 5; i++) {//计算任务完成时间
		t1 += A[res[i].index];
		t2 = t1 < t2 ? t2 + B[res[i].index] : t1 + B[res[i].index];
	}
	cout << "最优调度次序：" << endl;
	for (int i = 0; i < 5; i++) {
		cout << res[i].index << '\t';
	}cout << endl;
	cout << "任务结束时间：" << t2 << endl;
	delete[] res;
	delete[] J;
}