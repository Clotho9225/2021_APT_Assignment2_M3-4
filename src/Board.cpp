#include <iostream>

#include "Board.h"
#include "Types.h"

Board::Board()
{
    this->position.resize(BOARD_SIZE);

    for (unsigned int row = 0; row < this->position.size(); row++)
    {
        this->position[row].resize(BOARD_SIZE);
    }

    for (unsigned int row = 0; row < this->position.size(); row++)
    {
        for (unsigned int col = 0; col < this->position[row].size(); col++)
        {
            Node *node = new Node();
            //this->position[row][col]->setNode(node);
            this->position[row][col] = node;
        }
    }
}

// deep copy the board
Board::Board(Board &other) : position(other.position)
{
    // initilise the size of the board, get rid of junk
    this->position.resize(BOARD_SIZE);

    for (unsigned int row = 0; row < this->position.size(); row++)
    {
        this->position[row].resize(BOARD_SIZE);
    }
    // copy
    for (unsigned int row = 0; row < this->position.size(); row++)
    {
        for (unsigned int col = 0; col < this->position[row].size(); col++)
        {
            //this->position[row][col](other.position[row][col]);
        }
    }
}

Board::~Board()
{
}

//save the position of the tile
void Board::putTile2Board(Colour colour, Shape shape, int row, int col)
{
    Tile *tile = new Tile();
    tile->colour = colour;
    tile->shape = shape;
    this->position[row][col]->setTile(tile);
}

// print current board
void Board::printBoard()
{
    // first line
    std::cout << "   ";
    for (int row = 0; row < 26; row++)
    {
        if (row >= 10)
        {
            if (row == 25)
            {
                std::cout << row;
            }
            else
            {
                std::cout << row;
                std::cout << " ";
            }
        }
        else
        {
            std::cout << row;
            std::cout << "  ";
        }
    }
    std::cout << std::endl;

    // second line
    std::cout << "  -------------------------------------------------------";
    std::cout << "------------------------";
    std::cout << std::endl;

    for (unsigned int row = 0; row < this->position.size(); row++)
    {
        char c;
        c = row + 'A';
        std::cout << c << " |";
        for (unsigned int col = 0; col < this->position[row].size(); col++)
        {
            //Node *node = this->position[row][col];

            if (this->position[row][col]->tile == nullptr)
            {
                std::cout << "  |";
            }
            else
            {
                Colour colour = this->position[row][col]->tile->colour;
                Shape shape = this->position[row][col]->tile->shape;
                if (colour == 'R')
                {
                    //std::cout << colour;
                    printf("\033[31m%c%d", colour, shape);
                    std::cout << "\033[0m";	
                }
                else if (colour == 'O')
                {
                    //std::cout << colour;
                    printf("\033[91m%c%d", colour, shape);
                    std::cout << "\033[0m";	
                }
                else if (colour == 'Y')
                {
                    //std::cout << colour;
                    printf("\033[33m%c%d", colour, shape);
                    std::cout << "\033[0m";	
                }
                else if (colour == 'G')
                {
                    //std::cout << colour;
                    printf("\033[32m%c%d", colour, shape);
                    std::cout << "\033[0m";	
                }
                else if (colour == 'B')
                {
                    //std::cout << colour;
                    printf("\033[34m%c%d", colour, shape);
                    std::cout << "\033[0m";	
                }
                else if (colour == 'P')
                {
                    //std::cout << colour;
                    printf("\033[35m%c%d", colour, shape);
                    std::cout << "\033[0m";	
                }
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
