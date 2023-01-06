#include <iostream>
using namespace std;
int main() {
	int N, S;
	cin >> N >> S;

	int* arr = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//���� �Ӹ�
	int start, end;
	start	= 0;
	end = 0;
	//����
	int len = 0;
	//���� ��
	int sum = 0;
	//�ּұ���
	int min = N + 1;

	while (start != N || end != N) {
		if (sum >= S) {
			min = min > len ? len : min;

			if (start != N) {
				sum -= arr[start++];
				len--;
			}
		}
		else {
			if (end != N) {
				sum += arr[end++];
				len++;
			}

			if (end == N && sum < S) {
				break;
			}
		}
	}

	delete[] arr;
	if (min != N + 1)
		cout << min;
	else
		cout << 0;
}