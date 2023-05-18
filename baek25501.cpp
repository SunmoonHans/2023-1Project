#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int cnt = 0;
        int l = 0;
        int r = s.length() - 1;
        bool flag = true;
        for (; l <= r; l++, r--)
        {
            cnt++;
            if (s[l] != s[r])
            {
                flag = false;
                break;
            }
        }
        cout << (flag ? 1 : 0) << " " << (flag && s.length() % 2 == 0 ? cnt + 1 : cnt) << "\n";
    }
    return 0;
}
