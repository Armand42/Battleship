#include <iostream>
using namespace std;
#define M 10
#define N 10
#define SHIPS 5


void printMatrix(int matrix[M][N])
{
    
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

int placeOnRow(int **matrix, int row, int col, int shipSize)
{
    int k = 0;
    int temp = col;
    //int size = 3;               // ship size
    int bound = shipSize - k;       // bound = 3
    if (col + shipSize > N)
    {
        cout << "Error, out of bounds\n";
        return -1;
    }
    while (k < shipSize && col + shipSize <= N && matrix[row][temp] != 1) //&& temp < N)
    {
        matrix[row][temp] = 1;
        temp++;
        k++;
    }
    return 0;
}

int placeOnCol(int **matrix, int row, int col, int shipSize)
{
    int k = 0;
    int temp = row;
    //int size = 3;
    //int bound = size - k;       // bound = 3

    if (row + shipSize > N)
    {
        cout << "Error, out of bounds\n";
        return -1;
    }
    while (k < shipSize && row + shipSize <= M && matrix[temp][row] != 1)   // check if within bounds or spot is taken
    {
        matrix[temp][row] = 1;
        temp++;
        k++;
    }
    return 0;
}


bool isSpotTaken(int matrix[M][N])
{
    bool row[M] = {false};
    bool col[N] = {false};

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] == 1)
            {
                row[i] = true;      // keep track of 1 in row
                col[j] = true;      // keep track of 1 in col
            }
        }
    }
    return false;
}

int** createBoard()
{
    int** board = new int*[M];
    for (int i = 0; i < M;i++)
    {
        board[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    return board;
}

void printBoard(int** arr)
{
    for (int i = 0; i < M;i++)
    {
        for (int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
    cout << endl;
    }
}




int main()
{
    cout << "********** WELCOME TO BATTLESHIP **********\n";
    int **newBoard;
    newBoard = createBoard();
    printBoard(newBoard);
    cout << endl;
    // int matrix[M][N] = 
    // {
    //     0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0
    // };

    cout << "Player 1, enter your ships on the board\n";
    int count = 0;
    int i;
    int j;
    int ship;
    char horizontal = 'h';
    char vertical = 'v';
    char orientation;
    // Placing pieces on board
    while (count < SHIPS)
    {
        cout << "Enter in i, j, ship:";
        cin >> i >> j >> ship >> orientation;
        if (orientation == 'h') 
        {
            if (placeOnRow(newBoard,i,j,ship) != 0)     
            {
            break;
            }
        }
        if (orientation == 'v')
        {
            if (placeOnCol(newBoard,i,j,ship) != 0)
            {
            break;
            }
        }
        count++;
    }
    //placeOnRow(newBoard,2,2,3);
    printBoard(newBoard);
    delete newBoard;
    //cout << endl;
    //placeOnCol(newBoard,2,2,3);
    //printBoard(newBoard);
    



    // cout << "Original Matrix:\n";
    // printMatrix(matrix);
    //  cout << "Subset row matrix:\n";
    // placeOnRow(matrix,2,2,3);
    // printMatrix(matrix);
    // cout << "Subset col matrix: \n";
    // placeOnCol(matrix,0,2,3);
    // printMatrix(matrix);
    // cout << endl;
    // placeOnRow(matrix,2,0,3);
    // printMatrix(matrix);




    return 0;
}