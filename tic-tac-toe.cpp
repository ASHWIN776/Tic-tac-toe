#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int grid[10][10]{};

    // Direction Arrays
    int rs[25]{}, cs[25]{}, dr[25]{}, dc[25]{};

    int verify{};

    for(int r = 0; r < n; ++r)
        rs[verify] = r, cs[verify] = 0, dr[verify] = 0, dc[verify++] = 1;
    
    for(int c = 0; c < n; ++c)
        rs[verify] = 0, cs[verify] = c, dr[verify] = 1, dc[verify++] = 0;

        rs[verify] = 0, cs[verify] = 0, dr[verify] = 1, dc[verify++] = 1;
        rs[verify] = 0, cs[verify] = n - 1, dr[verify] = 1, dc[verify++] = -1;

    int steps{}, turn{};

    while(steps < n*n)
    {
        char symbol = 'O';

        if(turn) 
            symbol = 'X';
        
        int r{}, c{};

        while(true)
        {
            cout<<"Player : "<<symbol<<"'s turn, input the location: ";

            cin>>r>>c;

            r--, c--;
            if(r < n && r >= 0 && c < n && c >= 0 && grid[r][c] == 0)
                break;
            cout<<"Invalid Location\n";
        }

        grid[r][c] = turn + 1;

        // Printing the grid
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                    cout<<"O";
                else if(grid[i][j] == 2)
                    cout<<"X";
                else 
                    cout<<".";
                cout<<" ";
            }
            cout<<"\n";
        }


        // Checking Game stats
        for(int i = 0; i < verify; ++i)
        {
            int r_start = rs[i], c_start = cs[i], step_r = dr[i], step_c = dc[i];
            int check;

            if(grid[r_start][c_start])
                check = grid[r_start][c_start];

            else    
                continue;
            
            int count = 0;

            for(int step = 0; step < n; ++step)
            {
                count += (grid[r_start][c_start] == check);

                r_start += step_r;
                c_start += step_c;
            }

            if(count == n) 
            {
                cout<<"Player "<<symbol<<" has won!\n";
                return 0;
            }
        }

        ++steps;
        turn = !turn;
    }

    cout<<"\nTie-game"<<"\n";


    return 0;
}