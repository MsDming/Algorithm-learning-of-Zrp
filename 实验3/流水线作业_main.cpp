#include<iostream>
#include<algorithm>
using namespace std;

void pipline_sche(int* A, int* B);

class Job {//���幤����
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
	//��Johnson�������
	sort(J, J + 4);//����ʱ�����ٵ�������
	Job* res = new Job[5];
	int j = 0, k = 4;
	for (int i = 0; i < 5; i++) {//һ�׶�ʱ��̵���ǰ�ţ����׶�ʱ��̵�������
		if (J[i].job) {
			res[j++] = J[i];
		} else {
			res[k--] = J[i];
		}
	}
	int t1 = A[res[0].index], t2 = A[res[0].index] + B[res[0].index];
	for (int i = 1; i < 5; i++) {//�����������ʱ��
		t1 += A[res[i].index];
		t2 = t1 < t2 ? t2 + B[res[i].index] : t1 + B[res[i].index];
	}
	cout << "���ŵ��ȴ���" << endl;
	for (int i = 0; i < 5; i++) {
		cout << res[i].index << '\t';
	}cout << endl;
	cout << "�������ʱ�䣺" << t2 << endl;
	delete[] res;
	delete[] J;
}