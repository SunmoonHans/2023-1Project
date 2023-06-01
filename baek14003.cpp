#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1000001
using namespace std;

int arr[MAX];
int arr_index[MAX];

class Sequence
{
    private :
        int num;
        vector<int> v;
    public :
        int Getnum() { return this->num; };
        void Setnum(int n) { this->num = n; };
        vector<int> GetV() { return this->v; };
        void PushBackV(int num) { this->v.push_back(num); };
        void Insert();
        void SeqLength();
        void SeqPartPrt();
};

int main(void)
{
    Sequence s;

    s.Insert();
    cout << endl;

    s.SeqLength();
    s.SeqPartPrt();

    system("pause");
    return 0;
}

void Sequence::Insert()
{
    int num;
    cin >> num;
    this->Setnum(num);
    for (int i = 1; i <= this->Getnum(); i++)
    {
        cin >> arr[i];
    }
}

void Sequence::SeqLength()
{
    for (int i = 1; i <= this->Getnum(); i++)
    {
        if (this->GetV().size() == 0 || this->GetV()[this->GetV().size() - 1] < arr[i])
        {
            this->PushBackV(arr[i]);
            arr_index[i] = this->GetV().size() - 1;
        }
        else
        {
            int l = 0;
            int r = this->GetV().size() - 1;
            while (l < r)
            {
                int m = (l + r) / 2;

                if (this->GetV()[m] >= arr[i])
                    r = m;
                else 
                    l = m + 1;
            }
            this->GetV()[l] = arr[i];
            arr_index[i] = l;
        }
    }
    cout << this->GetV().size() << endl;
}

void Sequence::SeqPartPrt()
{
    vector<int> ans;
    int temp = this->GetV().size() - 1;
    for (int i = this->Getnum(); i > 0; i--)
    {
        if (arr_index[i] == temp)
        {
            ans.push_back(arr[i]);
            temp--;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) 
        cout << ans[i] << " ";
    cout << endl;
}
