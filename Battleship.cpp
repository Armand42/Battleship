#include <iostream>
#include "ship.cpp"
#include "board.cpp"
#include "players.cpp"
using namespace std;
#define M 10
#define N 10
#define SHIPS 5




class BattleShip: public Ship, public Board, public Players
{

};



int main()
{
    BattleShip board;
    int **newBoard;
    board.displayMessage();
    newBoard = board.createBoard();
    board.printBoard(newBoard);
    cout << endl;
    
    cout << "Player 1, enter your ship's position on the board\n";
    int count = 4;
    int i = board.getXCoor();
    int j = board.getYCoor();
    int ship;
    int damage = 0;
    int shipDamageCount = board.getShipDamageCount();
    char horizontal = 'h';
    char vertical = 'v';
    char orientation;
    // Placing pieces on board
    while (count < SHIPS)
    {
        cout << "Enter in i, j, ship, orientation: ";
        cin >> i >> j >> ship >> orientation;
        shipDamageCount = shipDamageCount + ship;
        if (orientation == 'h') 
        {
            if (board.placeOnRow(newBoard,i,j,ship) != 0)     
            {
            break;
            }
        }
        if (orientation == 'v')
        {
            if (board.placeOnCol(newBoard,i,j,ship) != 0)
            {
            break;
            }
        }
        count++;
    }
    //placeOnRow(newBoard,2,2,3);
    board.printBoard(newBoard);
    
    cout << "Game Board: " << endl;
    int **gameBoard;
    gameBoard = board.createBoard();
    //cout << "Enter i, j: ";
    int x;
    int y;
    //cin >> x >> y;
    // REMEMBER BOARD STARTS AT POSITION 0!!!
    while (damage < shipDamageCount)
    {
        cout << "Enter i, j: ";
        cin >> x >> y;
        if (board.isSpotTaken(newBoard,x,y) == 0)
        {
            gameBoard[x][y] = 1;
            board.printBoard(gameBoard);
            damage++;

            
        }
        continue;
    }

    if (damage == shipDamageCount)
    {
        cout << "YOU WIN!" << endl;
    }
    
    



    delete gameBoard;
    delete newBoard;
    




    return 0;
}