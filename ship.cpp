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
        int getXCoor();
        int getYCoor();
        int getShipClass();
        int getShipDamageCount();
    private:
        int xCoordinate;
        int yCoordinate;
        int shipClass;
        int shipDamageCount;

};

int Ship::placeOnRow(int **matrix, int row, int col, int shipSize)
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

int Ship::placeOnCol(int **matrix, int row, int col, int shipSize)
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

int Ship::getXCoor()
{
    return xCoordinate;
}

int Ship::getYCoor()
{
    return yCoordinate;
}

int Ship::getShipClass()
{
    return shipClass;
}

int Ship::getShipDamageCount()
{
    return shipDamageCount;
}