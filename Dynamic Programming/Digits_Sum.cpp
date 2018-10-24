#include <iostream>

using namespace std;

int n,s,a[1001][9001],i,j;

int main()
{
    cin>>n>>s;
    for(i=1;i<=9;i++)
    {
        a[1][i]=1;
    }
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=9*i && j<=s;j++)
        {
            if(j-10<=0)
            {
                a[i][j]=(a[i-1][j]+a[i][j-1])%666013;
            }
            else
            {
                a[i][j]=(a[i-1][j]+a[i][j-1]-a[i-1][j-10]+666013)%666013;
            }
        }
    }
    cout<<a[n][s];;
    return 0;
}
