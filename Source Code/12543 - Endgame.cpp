#include<iostream>
using namespace std;

char maze[1002][1002] = {0};
int initial_x, initial_y;
int n,m;
int num_army = 0;
int killed_round = -1;
void walk(int cur_x, int cur_y, int round)
{
    if(num_army == 0)
    {
        return;
    }
    if(cur_x == 0 || cur_y == 0 || cur_x == n+1 || cur_y == m+1)
    {
        return;
    }
    if(maze[cur_x][cur_y] == 'W')
    {
        return;
    }
    if(maze[cur_x][cur_y] == 'C')
    {
        return;
    }
    if(maze[cur_x][cur_y] == 'T')
    {
        num_army--;
        if(killed_round < round)
        {
            killed_round = round;
        }
    }
    maze[cur_x][cur_y] = 'W';
    //cout << "Round " << round << " Now at: " << cur_x << " " << cur_y << endl;
    walk(cur_x, cur_y+1, round+1);
    walk(cur_x, cur_y-1, round+1);
    walk(cur_x-1, cur_y, round+1);
    walk(cur_x+1, cur_y, round+1);
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
    walk(initial_x, initial_y, 0);
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
