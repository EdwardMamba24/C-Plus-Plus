/** The Knight’s tour MAX, where the Knight can move on a n*m matrix starting from the first line and the first column and must get to the n line and m column avoiding the obstacles marked with "1". **/

#include <iostream>

using namespace std;

int n,m,a[11][11],i,j,k,x,y,s=-1,sol[11][11];
int dx[]={-2,-2,-1,1,2,2,1,-1};
int dy[]={-1,1,2,2,1,-1,-2,-2};

int valid(int x, int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m && a[x][y]==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void afisare()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void cal(int x, int y, int k)
{
    if(x==n && y==m && k>s)
    {
        s=k;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                sol[i][j]=a[i][j];
            }
        }
    }
    else
    {
        for(int i=0;i<=7;i++)
        {
            if(valid(x+dx[i],y+dy[i]))
            {
                a[x+dx[i]][y+dy[i]]=k;
                cal(x+dx[i],y+dy[i],k+1);
                a[x+dx[i]][y+dy[i]]=0;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1)
            {
                a[i][j]=-1;
            }
        }
    }
    a[1][1]=1;
    cal(1,1,2);
    afisare();
    return 0;
}
