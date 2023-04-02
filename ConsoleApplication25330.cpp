// ConsoleApplication25330.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Duegeon
{
private:
    vector<int> m_mon;
    vector<int> m_pop;
    vector<int> m_re;
public:
    Duegeon(int n);
    void Insert(int n);
    inline vector<int> GetMonster() { return m_mon; }
    inline vector<int> GetPop() { return m_pop; }
    inline vector<int> GetReleased() { return m_re; }
    int Search(int n, int k, int td, int cd, int v);
};

int main()
{
    int N, K;
    cin >> N >> K;

    Duegeon player(N);
    player.Insert(N);

    cout << player.Search(N, K, 0, 0, 0) << "\n";

    system("pause");
    return 0;
}

Duegeon::Duegeon(int n)
{
    m_mon.assign(n, 0);
    m_pop.assign(n, 0);
    m_re.assign((1 << n) + 1, 0);
}

void Duegeon::Insert(int n)
{
    for (int i = 0; i < n; i++)
        cin >> this->m_mon[i];
    for (int i = 0; i < n; i++)
        cin >> this->m_pop[i];
}

int Duegeon::Search(int n, int k, int td, int cd, int v)
{
    static int mr = 0;
    for (int i = 0, b = 1; i < n; i++, b <<= 1)
    {
        if (!(v & b))
        {
            int nv = v | b;
            int ncd = cd + this->m_mon[i];
            int ntd = td + ncd;
            if (ntd <= k)
            {
                this->m_re[nv] = max(this->m_re[nv], this->m_re[v] + this->m_pop[i]);
                mr = max(mr, this->m_re[nv]);
                this->Search(n, k, ntd, ncd, nv);
            }
        }
    }
    return mr;
}
