#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e4,OO=0x3f3f3f3f;
string board,p;
int n;
bool is_win(string s)
{
    bool rows=((s[0]!='.'&&s[0]==s[1]&&s[1]==s[2])||
               (s[3]!='.'&&s[3]==s[4]&&s[4]==s[5])||
               (s[6]!='.'&&s[6]==s[7]&&s[7]==s[8]));

    bool columns=((s[0]!='.'&&s[0]==s[3]&&s[3]==s[6])||
                  (s[1]!='.'&&s[1]==s[4]&&s[4]==s[5])||
                  (s[2]!='.'&&s[2]==s[5]&&s[5]==s[8]));

    bool diag=((s[0]!='.'&&s[0]==s[4]&&s[4]==s[8])||
               (s[2]!='.'&&s[2]==s[4]&&s[4]==s[6]));
    return rows||columns||diag;
}
void bfs()
{
    string start=".........";
    queue<pair<string,bool>>q;
    int f=0;
    q.push({start,0});
    while(!q.empty())
    {
        string cur=q.front().first;
        bool cur_player=q.front().second;
        q.pop();
        if(cur==board)
        {
            puts("yes");
            f=1;
            break;
        }
        if(is_win(cur))continue;
        for(int i=0; i<9; ++i)
        {
            if(cur[i]=='.')
            {
                cur[i]=(cur_player?'O':'X');
                if(cur[i]==board[i])q.push({cur,cur_player^1});
                cur[i]='.';
            }
        }
    }
    if(!f)puts("no");
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        board="";
        for(int i=0; i<3; ++i)
        {
            cin>>p;
            board+=p;
        }

        bfs();
    }
    return 0;
}
