#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int Mcnt = 0;
    cin >> Mcnt;
    vector<int> v(Mcnt);

    for (int i = 0; i < Mcnt; i++)  cin >> v[i];
    sort(v.begin(), v.end());

    cin >> Mcnt;
    vector<int> ans(Mcnt);

    for (int i = 0; i < Mcnt; i++) 
    {
        int temp;
        cin >> temp;
        auto upper = upper_bound(v.begin(), v.end(), temp);
        auto lower = lower_bound(v.begin(), v.end(), temp);
        ans[i] = upper - lower;
    }

    for (auto num : ans) cout << num << " ";

    system("pause");
    return 0;
}
