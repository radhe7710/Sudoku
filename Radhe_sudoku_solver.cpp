#include <bits/stdc++.h>

using namespace std;
void printsudoku(vector<vector<int>> &v)
{
   for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}
void finalsudoku(vector<vector<int>> &v, vector<map<int,int>> &row, vector<map<int,int>> &col,map<pair<int,int>,map<int,int>> &m,int r,int c)
{
    if(r==9)
    printsudoku(v);
    else if(c==9)
    finalsudoku(v,row,col,m,r+1,0);
    else if(v[r][c]!=0)
    finalsudoku(v,row,col,m,r,c+1);
    else if(v[r][c]==0)
    {

        for(int i=1;i<=9;i++)
        {
            if(!row[r][i] && !col[c][i] && !m[{r/3,c/3}][i])
            {
               row[r][i]=1;
               col[c][i]=1;
               m[{r/3,c/3}][i]=1;
               v[r][c]=i;
               finalsudoku(v,row,col,m,r,c+1);
               row[r][i]=0;
               col[c][i]=0;
               m[{r/3,c/3}][i]=0;
               v[r][c]=0;
            }

        }

    }
    return;
}
void takeinputsudoku( vector<vector<int>> &v)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            int x;cin>>x;
            v[i].push_back(x);
        }
    }
    return;
}
void solvesudoku( vector<vector<int>> &v)
{
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);
    map<pair<int,int>,map<int,int>> m;
     for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
           row[i][j+1]=0;
           col[i][j+1]=0;
        }
    }
     for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
           if(v[i][j]!=0)
           {
               row[i][v[i][j]]=1;
               col[j][v[i][j]]=1;
               m[{i/3,j/3}][v[i][j]]=1;
           }

        }
    }
    finalsudoku(v,row,col,m,0,0);
    return;

}

int main()
{
    vector<vector<int>> v(9);
    takeinputsudoku(v);
    solvesudoku(v);

    return 0;
}
