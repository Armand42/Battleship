#include <iostream>
using namespace std;
#define M 10
#define N 10
#define SHIPS 5
class Board 
{
    public:
        int **createBoard();
        int isSpotTaken(int **matrix, int x, int y);
        void displayMessage();
        void printBoard(int** arr);


};


int** Board::createBoard()
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

void Board::printBoard(int** arr)
{
    for (int i = 0; i < M;i++)
    {
        for (int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
    cout << endl;
    }
    
}

void Board::displayMessage()
{
    cout << "********** WELCOME TO BATTLESHIP **********\n";
}


int Board::isSpotTaken(int **matrix, int x, int y)
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

