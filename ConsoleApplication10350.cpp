#include <iostream>
using namespace std;

typedef long long int ll;

int main()
{
	ll arr[100001] = { 0 };
	ll num, result = 0;
	cin >> num;

	ll kmoney = 0;
	for (int i = 1; i <= num; i++)
	{
		cin >> arr[i];
		kmoney += arr[i];
		arr[i + num] = arr[i];
	}
	for (int i = 1; i <= num; i++)
	{
		ll fairy = 0;
		for (int j = i; j < i + num; j++)
		{
			fairy = fairy + arr[j];
			if (fairy < 0)
			{
				ll x = -fairy; //자본이 0보다 작은경우 요정의 힘을 빌려 양수화
				result = result + (x - 1) / kmoney + 1; // 전체 양수화 카운트 횟수
			}
		}
	}

	cout << result << endl;

	//system("pause");
	return 0;
}