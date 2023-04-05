#include <iostream>
#include <string>
#include <map>

#define MAX 101
using namespace std;

string S;
map<char, int> m;

int main(void)
{
    cin >> S;

    cout << "문자열을 입력하시오 : "; 

    for (int i = 97; i < 123; i++)
    {
        m.insert(make_pair(i, -1));
    }

    for (int i = 0; i < S.length(); i++)
    {
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (S[i] == it->first && it->second == -1) it->second = i;
        }
    }

    for (auto it = m.begin(); it != m.end(); ++it) cout << it->second << endl;

    //system("pause");
    return 0;
}
