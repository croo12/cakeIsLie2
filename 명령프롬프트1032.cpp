#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	
	char arr[51]{ 0 };
	char tmp[51]{ 0 };
	
	cin >> arr;

	for (int i = 1; i < n; i++)
	{
		cin >> tmp;
		for (int j = 0; arr[j] != '\0'; j++)
		{
			if (arr[j] != '?' && arr[j] != tmp[j]) {
				arr[j] = '?';
			}
		}
	}

	for (int i = 0; arr[i] != '\0'; i++)
	{
		cout << arr[i];
	}
}