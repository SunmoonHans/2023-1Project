#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, string> is;
bool compare(is a, is b);
class Lsort
{
private :
    vector<is> m_is;
public :
    inline vector<is> GetIs() const { return m_is; }
    void SetIs(int n, string s);
    void sort() { stable_sort(m_is.begin(), m_is.end(), compare); }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    Lsort arr;
    for (int i = 0; i < n; i++)
    {
        is temp;
        cin >> temp.first >> temp.second;
        arr.SetIs(temp.first, temp.second);
    }
    arr.sort();
    for (int i = 0; i < n; i++)
        cout << arr.GetIs()[i].first << ' ' << arr.GetIs()[i].second << '\n';

    system("pause");
    return 0;
}

void Lsort::SetIs(int n, string s)
{
    is temp;
    temp.first = n;
    temp.second = s;
    m_is.push_back(temp);
}

bool compare(is a, is b)
{
    return a.first < b.first;
}
