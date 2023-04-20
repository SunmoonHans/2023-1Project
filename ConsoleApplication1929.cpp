// ConsoleApplication1929.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>
using namespace std;

class PrimeNum
{
private:
    int m_primeNum;
public:
    PrimeNum() { m_primeNum = 0; }
    inline int GetPrimeNum() { return m_primeNum; }
    inline void SetPrimeNum(int num) { m_primeNum = num; }
    void InsertNum() { cin >> m_primeNum; }
    bool isPrime(int num);
    int PrimeSum(int num);
    int FindMin(int num);
};

int main()
{
    PrimeNum pnMin, pnMax;
    bool primeCheck;
    pnMin.InsertNum();
    pnMax.InsertNum();

    for (int i = pnMin.GetPrimeNum(); i <= pnMax.GetPrimeNum(); i++)
    {
        primeCheck = pnMin.isPrime(i);
        if (primeCheck == true)  cout << i << endl;
    }

    system("pause");
    return 0;
}

bool PrimeNum::isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if ((n % i) == 0) return false;
    }
    return true;
}

int PrimeNum::PrimeSum(int num)
{
    int sum = 0;
    while (num <= this->m_primeNum)
    {
        if (isPrime(num)) sum = sum + num;
        num++;
    }
    if (sum == 0) return -1;
    else return sum;
}

int PrimeNum::FindMin(int num)
{
    int minNum = 0;
    while (num <= this->m_primeNum)
    {
        if (isPrime(num))
        {
            minNum = num;
            break;
        }
        num++;
    }
    return minNum;
}