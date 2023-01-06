#include <iostream>
#include <unordered_map>;
using namespace std;
int main() {

	//입력
	int R, C, K;
	cin >> R >> C;
	string* arr = new string[R];
	for (int i = 0; i < R; i++)
	{
		cin >> arr[i];
	}
	cin >> K;

	//정답을 구하기위해
	int ans = 0;
	unordered_map<string, int> map;
	int select;
	int now;
	for (int i = 0; i < R; i++)
	{
		select = 0;
		for (int j = 0; j < C; j++)
		{
			if (arr[i].at(j) == '0')
				select++;
		}

		if (select <= K && (K - select) % 2 == 0) {
			now = map[arr[i]];
			map[arr[i]] = ++now;

			ans = now > ans ? now : ans;
		}
	}

	delete[] arr;

	cout << ans;
}