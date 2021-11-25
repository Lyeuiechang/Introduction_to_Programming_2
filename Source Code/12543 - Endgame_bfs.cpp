#include<iostream>
#include<queue>
using namespace std;
typedef struct Corrd{
    int x;
    int y;
    int round;
}Corrd;
queue<Corrd> Q;
char maze[1002][1002] = {0};
int initial_x, initial_y;
int n,m;
int num_army = 0;
int killed_round = 0;
int isValid(Corrd c)
{
    if(c.x == 0 || c.y == 0 || c.x == n+1 || c.y == m+1)
    {
        return 0;
    }
    else if(maze[c.x][c.y] == 'W')
    {
        return 0;
    }
    else if(maze[c.x][c.y] == 'C')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void BFS(int cur_x, int cur_y)
{
    Corrd cur;
    cur.x = cur_x;
    cur.y = cur_y;
    cur.round = 0;
    Q.push(cur);
    while(!Q.empty())
    {
        if(num_army == 0)
        {
            break;
        }
        cur = Q.front();
        if(isValid(cur)==1)
        {
            if(maze[cur.x][cur.y] == 'T')
            {
                num_army--;
                killed_round = cur.round;
            }
            maze[cur.x][cur.y] = 'W';
            Corrd up, down, left, right;
            up.x = cur.x;
            up.y = cur.y+1;
            up.round = cur.round+1;
            down.x = cur.x;
            down.y = cur.y-1;
            down.round = cur.round+1;
            left.x = cur.x-1;
            left.y = cur.y;
            left.round = cur.round+1;
            right.x = cur.x+1;
            right.y = cur.y;
            right.round = cur.round+1;
            Q.push(up);
            Q.push(down);
            Q.push(left);
            Q.push(right);
        }
        Q.pop();
    }
    return;
}
int main(void)
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == 'I')
            {
                initial_x = i;
                initial_y = j;
            }
            else if(maze[i][j] == 'T')
            {
                num_army++;
            }
        }
    }
    //cout << endl;
    BFS(initial_x, initial_y);
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
    */
    if(num_army > 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << killed_round << endl;
    }
    return 0;
}
