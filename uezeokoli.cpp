#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
#include <list>
#include <vector>
#define INFINITY (int)(123456789)
using namespace std;
int n;

void  MatrixChainOrder(int p[], vector<vector<int> >& m, vector<vector<int> >& s)
{
    int n = m.size();

    int i,j,k,l,q;

    for (i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }
    for (l = 2; l < n; l++)
    {
        for (i = 1; i < (n - l + 1); i++)
        {
            j = i + l - 1;
            m[i][j] = INFINITY;
            
            for (k = i; k <= (j - 1); k++)
            {
                q = m[i][k] + m[k + 1][j] + (p[i - 1]*p[k]*p[j]);

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int PrintOptimalParens(vector<vector<int> >& s, int i, int j)
{
    if (i == j)
    {
        cout << "A" << (i - 1);
    }
    else
    {
        cout << "(";
        PrintOptimalParens(s,i,s[i][j]);
        PrintOptimalParens(s,(s[i][j] + 1),j);
        cout << ")";
    }
}

int main ()
{

    cin >> n;

    int p[n];
    int i;
    if (n >= 1)
    {
        for (i = 0; i <= n; i++)
        {
            cin >> p[i];
        }
    }

    vector<vector<int> > m(n + 1, vector<int>(n + 1,0));
    vector<vector<int> > s(n + 1, vector<int>(n + 1,0));

    MatrixChainOrder(p,m,s);
    
    cout << m[1][n]<< endl;

    PrintOptimalParens(s,1,n);

    cout << endl;
}