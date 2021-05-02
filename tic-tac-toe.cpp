#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int grid[10][10];

    // Direction Arrays
    int rs[25]{}, cs[25]{}, dr[25]{}, dc[25]{};

    int verify{};

    for(verify = 0; verify < n; ++verify)
        rs[verify] = verify, cs[verify] = 0, dr[verify] = 0, dc[verify++] = 1;
    
    for(verify = 0; verify < n; ++verify)
        rs[verify] = 0, cs[verify] = verify, dr[verify] = 1, dc[verify++] = 0;

        rs[verify] = 0, cs[verify] = 0, dr[verify] = 1, dc[verify++] = 1;
        rs[verify] = 0, cs[verify] = n - 1, dr[verify] = 1, dc[verify] = -1;

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
                if(grid[i][j])
                    cout<<symbol;
                else 
                    cout<<".";
                cout<<" ";
            }
            cout<<"\n";
        }
    }

    cout<<"\nTie-game"<<"\n";


    return 0;
}