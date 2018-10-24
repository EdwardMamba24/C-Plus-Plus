#include <iostream>

using namespace std;

int v[20],n,k,i;

int succesor(int v[], int n, int k)
{
    int i,j;
    for(i=k;i>=1;i--)
    {
        if(v[i]<n-k+i)
        {
            break;
        }
    }
    if(i==0) return 0;
    v[i]++;
    for(j=i+1;j<=k;j++)
    {
        v[j]=1+v[j-1];
    }
    return 1;
}
void afisare (int v[], int k)
{
    int i;
    for(i=1;i<=k;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        v[i]=i;
    }
    do{
        afisare(v,k);
    }while(succesor(v,n,k));
    return 0;
}
