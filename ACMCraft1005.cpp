#include <iostream>
#include <vector>

using namespace std;
int getAns(int N, int K) {
	int* arr = new int[N + 1];

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	vector<int>* build = new vector<int>[N + 1];
	//����������
	int* bef = new int[N + 1] {0};

	int st, ed;
	for (int i = 0; i < K; i++)
	{
		cin >> st >> ed;
		build[st].push_back(ed);
		bef[ed]++;
	}

	int last;
	cin >> last;

	vector<int> now;

	for (int i = 1; i <= N; i++)
	{
		if (bef[i] == 0) {
			now.push_back(i);
		}
	}

	int time = 0;
	while (!now.empty()) {
		//���� on
		for (int i = 0; i < now.size(); i++)
		{
			//�ð� �ٵ�
			if (arr[now[i]] == 0) {
				//������ �ǹ�
				if (now[i] == last)
					return time;

				//���� 1�� ����
				for (int num : build[now[i]])
				{
					if (num != 0) {
						bef[num]--;
						//������ 0�γ� �Ǽ� ����
						if (bef[num] == 0) {
							if (num == last)
								return time + arr[num];

							now.push_back(num);
						}
					}
				}
				//���� �ǹ� ����
				now.erase(now.begin() + i);
				i--;
			}
		}

		//���� ����
		for (int num : now) {
			arr[num]--;
		}

		time++;
	}
};

int main() {
	int T, N, K;
	cin >> T;

	while (T-- > 0){
		cin >> N >> K;
		cout << getAns(N, K) << '\n';
	}

	return 0;
}