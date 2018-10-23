/**Write a program to print all permutations of a given number**/
#include <iostream>

using namespace std;

int v[10],n,i;

int succesor(int v[], int n)
{
    int i,j,aux;
    for(i=n;i>=2;i--)
    {
        if(v[i-1]<v[i])
        {
            break;
        }
    }
    if(i==1) return 0;
    j=n;
    while(v[j]<=v[i-1])
    {
        j--;
    }
        aux=v[i-1];
        v[i-1]=v[j];
        v[j]=aux;
        j=n;
        while(i<j)
        {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            i++;
            j--;
        }
        return 1;
}
void afisare (int v[], int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        v[i]=i;
    }
    do
    {
        afisare(v,n);
    }while(succesor(v,n));
    return 0;
}
