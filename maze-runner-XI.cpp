#include<bits/stdc++.h>
using namespace std;

int adj[100][100]={0},p,q,v,ko=0,a[100],b[100],jd;

void display()
{
    cout<<"\t\t\t\t";
    for(int k=1; k<=v; k++)
    {
        cout<<"  "<<k;
    }
    cout<<"\n";
    cout<<"\t\t\t\t";
    for(int l=1; l<=v; l++)
    {
        cout<<"---";
    }
    cout<<"\n";
    cout<<"\t\t\t\t";
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            cout<<"  "<<adj[i][j];
        }
        cout<<" | "<<i;
        cout<<"\n\n";
        cout<<"\t\t\t\t";
    }
    cout<<"\n\n";
    cout<<"\t\t\t\t";
    cout<<" Where 1 is the path and 0 is the wall(block)\n\n\n\n";
}

void build_graph()
{
    jd=1;
    do
    {
        display();
        cout<<" Path "<<jd<<":";
        cin>>p>>q;
        if(p==0&&q==0)
        {
            break;
        }
        else if(p<=0||q<=0)
        {
            cout<<"\n Invalid Input\n";
            system("pause");
            system("cls");
        }
        else if(p>v||q>v)
        {
            cout<<"\n Invalid Input\n";
            system("pause");
            system("cls");
        }
        else if(adj[p][q]==1)
        {
            cout<< "\n Invalid Input\n";
            system("pause");
            system("cls");
        }
        else
        {
            adj[p][q]=1;
            a[jd-1]=p;
            b[jd-1]=q;
            jd++;
            cout<<endl;
            system("pause");
            system("cls");
        }
    }
    while(1);
}

void maze(int i,int j,int m,int n)
{
    stack <int> s;
    s.push(i);
    s.push(j);
    adj[i][j]=-1;
    while(1)
    {
        int mo=0;
        if(i==m&j==n)
        {
            cout<<"\n The end point ("<<i<< ","<<j<<") has been found\n";
            ko=1;
            break;
        }
        else if(adj[i][j+1]==1)
        {
            s.push(i);
            s.push(j+1);
            adj[i][j+1]=-1;
            cout<<"\n The mice has move towards ("<<i<<","<<j+1<<") points\n";
            j++;
            mo=1;
        }
        else if(adj[i-1][j]==1)
        {
            s.push(i-1);
            s.push(j);
            adj[i-1][j]=-1;
            cout<<"\n The mice has move towards ("<<i-1<<","<<j<<") points\n";
            i--;
            mo=1;
        }
        else if(adj[i+1][j]==1)
        {
            s.push(i+1);
            s.push(j);
            adj[i+1][j]=-1;
            cout<<"\n The mice has move towards ("<<i+1<<","<<j<<") points\n";
            i++;
            mo=1;
        }
        else if(adj[i][j-1]==1)
        {
            s.push(i);
            s.push(j-1);
            adj[i][j-1]=-1;
            cout<<"\n The mice has move towards ("<<i<<","<<j-1<<") points\n";
            j--;
            mo=1;
        }
        else if(mo==0)
        {
            int c=s.size();
            for(int x=0; x<c/2; x++)
            {
                j=s.top();
                s.pop();
                i=s.top();
                s.pop();
                if(adj[i-1][j]==1)
                {
                    s.push(i-1);
                    s.push(j);
                    cout<<"\n There is nowhere to go to go\n";
                    cout<<"\n So it's gonna backtrack to ("<<i<< ","<<j<<") coordinates\n";
                    cout<<"\n The mice has move towards ("<<i-1<< ","<<j<<") points\n";
                    i--;
                    adj[i][j]=-1;
                    break;
                }
                else if(adj[i+1][j]==1)
                {
                    s.push(i+1);
                    s.push(j);
                    cout<<"\n There is nowhere to go to go\n";
                    cout<<"\n So it's gonna backtrack to ("<<i<< ","<<j<<") coordinates\n";
                    cout<<"\n The mice has move towards ("<<i+1<< ","<<j<<") points\n";
                    i++;
                    adj[i][j]=-1;
                    break;
                }
                else if(adj[i][j-1]==1)
                {
                    s.push(i);
                    s.push(j-1);
                    cout<<"\n There is nowhere to go\n";
                    cout<<"\n So it's gonna backtrack to ("<<i<< ","<<j<<") coordinates\n";
                    cout<<"\n The mice has move towards ("<<i<< ","<<j-1<<") points\n";
                    j--;
                    adj[i][j]=-1;
                    break;
                }
                else if(adj[i][j+1]==1)
                {
                    s.push(i);
                    s.push(j+1);
                    cout<<"\n There is nowhere to go to go\n";
                    cout<<"\n So it's gonna backtrack to ("<<i<< ","<<j<<") coordinates\n";
                    cout<<"\n The mice has move towards ("<<i<< ","<<j+1<<") points\n";
                    j++;
                    adj[i][j]=-1;
                    break;
                }
            }
        }
        else
        {
            cout<<"\n So, there is no path left to go\n";
            cout<<"\n The goal unachieved\n";
            break;
        }
    }
}

void display3()
{
    cout<<"\t\t\t\t";
    for(int k=1; k<=v; k++)
    {
        cout<<"  "<<k;
    }
    cout<<"\n";
    cout<<"\t\t\t\t";
    for(int l=1; l<=v; l++)
    {
        cout<<"---";
    }
    cout<<"\n";
    cout<<"\t\t\t\t";
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            if(adj[i][j]==-1)
            {
                cout<< "  "<< "1";
            }
            else
            {
                cout<<"  "<<adj[i][j];
            }
        }
        cout<<"|"<<i;
        cout<<"\n";
        cout<<"\t\t\t\t";
    }
}

void display2(int m,int n)
{
    cout<<"\t\t\t\t";
    for(int k=1; k<=v; k++)
    {
        cout<<"  "<<k;
    }
    cout<<"\n";
    cout<<"\t\t\t\t";
    for(int l=1; l<=v; l++)
    {
        cout<<"---";
    }
    cout<<"\n";
    cout<<"\t\t\t\t";
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            if(adj[i][j]==-1)
            {
                cout<< "  "<< "1";
            }
            else
            {
                cout<<"  "<<adj[i][j];
            }
        }
        cout<<"|"<<i;
        cout<<"\n";
        cout<<"\t\t\t\t";
    }

    cout<<"\n\n";
    cout<<"\t\t\t\t";
    cout<< " Where 1 is the path and 0 is the wall(block)\n\n\n\n";
    cout<< "\n";
    for(int i=0; i<jd-1; i++)
    {
        cout<< " {"<<a[i]<< ", "<<b[i]<< "}"<<endl;
    }
    if(ko==0)
    {
        cout<<"\n\n Maze Unsolved"<<endl;
    }
    else
    {
        cout<< "\n\n Maze Solved\n\n";
        cout<<"\t\t\t\t";
        for(int k=1; k<=v; k++)
        {
            cout<< "  "<<k;
        }
        cout<<"\n";
        cout<<"\t\t\t\t";
        for(int l=1; l<=v; l++)
        {
            cout<<"---";
        }
        cout<<"\n";
        cout<<"\t\t\t\t";
        for(int i=1; i<=v; i++)
        {
            for(int j=1; j<=v; j++)
            {
                if(adj[i][j]==-1||i==m&&j==n)
                {
                    cout<<"  "<< "M";
                }
                else if(adj[i][j]==1)
                {
                    cout<< "  "<< "0";
                }
                else
                {
                    cout<< "  "<<adj[i][j];
                }
            }
            cout<<"|  "<<i;
            cout<<"\n";
            cout<<"\t\t\t\t";
        }
    }
}

int main()
{
    system("COLOR F0");
    cout<<"\t\t\t\t Maze Runners\n\n\n";
    cout<< " Input Number of row and column:";
    cin>>v;
    cout<<endl;
    system("pause");
    system("cls");
    build_graph();
    cout<< "\n";
    system("pause");
    system("cls");
    display();
    int i,j,m,n;
    cout<<("\n\n Enter the starting point of the maze\n");
    cout<<" Enter the row point:";
    cin>>i;
    cout<<" Enter the column point:";
    cin>>j;
    while(adj[i][j]!=1)
    {
        cout<< "\n Invalid Input\n";
        system("pause");
        system("cls");
        cout<<" Enter the row point:";
        cin>>i;
        cout<<" Enter the column point:";
        cin>>j;
    }
    cout<<"\n\n Enter the end point of the maze\n";
    cout<<" Enter the row point:";
    cin>>m;
    cout<<" Enter the column point:";
    cin>>n;
    while(adj[m][n]!=1)
    {
        cout<<"\n Invalid Input\n";
        system("pause");
        system("cls");
        cout<<" Enter the row point:";
        cin>>m;
        cout<<" Enter the column point:";
        cin>>n;
    }
    while(i==m&&j==n)
    {
        cout<< "\n Invalid Input\n";
        system("pause");
        system("cls");
        cout<<" Enter the row point:";
        cin>>m;
        cout<<" Enter the column point:";
        cin>>n;
        while(adj[m][n]!=0)
        {
            cout<<"\n Invalid Input\n";
            cout<<" Enter the row point:";
            cin>>m;
            cout<<" Enter the column point:";
            cin>>n;
        }
    }
    cout<< "\n";
    system("pause");
    system("cls");
    display3();
    maze(i,j,m,n);
    cout<< "\n";
    system("pause");
    system("cls");
    display2(m,n);
    return 0;
}
