// ConsoleApplication18870.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Lsort
{
private:
    vector<int> m_num;
public:
    inline vector<int> GetNum() const { return m_num; }
    void SetNum(int n) { m_num.push_back(n); }
    void Sort() { sort(m_num.begin(), m_num.end()); }
    //void Earse() { m_num.erase(unique(m_num.begin(), m_num.end()), m_num.end()); }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Lsort ls;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int temp;
        cin >> temp;
        ls.SetNum(temp);
    }
    ls.Sort();
    vector<int> cv(ls.GetNum()); 
    cv.erase(unique(cv.begin(), cv.end()), cv.end());
    for (int i = 0; i < num; i++)
    {
        auto it = lower_bound(cv.begin(), cv.end(), ls.GetNum()[i]);
        cout << it - cv.begin() << ' ';
    }
    cout << '\n';

    system("pause");
    return 0;
}