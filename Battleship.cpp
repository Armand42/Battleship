#include <iostream>
using namespace std;
#define M 10
#define N 10
#define SHIPS 5



class Ship {

    public:
        int placeOnRow(int **matrix, int row, int col, int shipSize);
        int placeOnCol(int **matrix, int row, int col, int shipSize);
        void getdata();
    private:
        int xCoordinate;
        int yCoordinate;
        int shipClass;

};

class Players
{

    private:
        int player1;
        int player2;
};

class Board 
{
    public:
        int **createBoard();
        void printBoard(int** arr);
    

};

class BattleShip: public Ship, public Board, public Players
{

};





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


int isSpotTaken(int **matrix, int x, int y)
{
    
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[x][y] == 1)
            {
               cout << "HIT!" << endl;
               return 0;
            }
            else
            {
                cout << "MISS!" << endl;
                return -1;
            }
        }
    }
   return -1;
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
    int count = 4;
    int i;
    int j;
    int ship;
    int damage = 0;
    int shipDamageCount = 0;
    char horizontal = 'h';
    char vertical = 'v';
    char orientation;
    // Placing pieces on board
    while (count < SHIPS)
    {
        cout << "Enter in i, j, ship:";
        cin >> i >> j >> ship >> orientation;
        shipDamageCount = shipDamageCount + ship;
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
    
    cout << "Game Board " << endl;
    int **gameBoard;
    gameBoard = createBoard();
    cout << "Enter i, j: ";
    int x;
    int y;
    //cin >> x >> y;
    // REMEMBER BOARD STARTS AT POSITION 0!!!
    while (damage < shipDamageCount)
    {
        cin >> x >> y;
        if (isSpotTaken(newBoard,x,y) == 0)
        {
            gameBoard[x][y] = 1;
            printBoard(gameBoard);
            damage++;

            
        }
        continue;
    }

    if (damage == shipDamageCount)
    {
        cout << "YOU WIN!" << endl;
    }
    
    // if (isSpotTaken(newBoard,x,y) == 0)
    // {
    //     gameBoard[x][y] = 1;
    // }
    // printBoard(gameBoard);
    // cout << endl;

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