#include <iostream>

using namespace std;

int n,v[30],k,x;

int valid(int x, int y)
{
    if(y==n && x!=97) return 0;
    if(x<97 || x>122) return 0;
    return 1;
}

void afisare()
{
    for(int i=1;i<=n;i++)
    {
        cout<<(char)(v[i]);
    }
    cout<<"\n";
}

void back(int k)
{
    if(k==n+1)
    {
        afisare();
    }
    else
    {
        for(int i=v[k-1]-1;i<=v[k-1]+1;i=i+2)
        {
            if(valid(i,k))
            {
                v[k]=i;
                back(k+1);
                v[k]=0;
            }
        }
    }
}

int main()
{
    cin>>n;
    v[1]=97;
    back(2);
    return 0;
}
