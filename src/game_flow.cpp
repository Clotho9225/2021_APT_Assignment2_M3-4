#include "game_flow.h"
#include "check_input.h"

void qwirkle()
{
    std::cout << "Welcome to Qwirkle!" << std::endl;
    std::cout << "-------------------" << std::endl;
}

void newGame()
{
    std::string player1_name, player2_name, player3_name;
    std::cout << "Starting a New Game" << std::endl << std::endl;

    std::cout << "Enter a name for player 1(uppercase characters only)" << std::endl;
    
    do
    {
        std::getline(std::cin, player1_name);
        if (std::cin.eof())
        {
            std::cout << std::endl;
            std::cout << "Goodbye" << std::endl;
            exit(0);
        }
        else if (isHelp(player1_name))
        {
            helpInfo_enteringName();
        }
        else if (!isValidPlayerName(player1_name))
        {
            std::cout << "Invalid name, please try again." << std::endl;
        }
    } while (!isValidPlayerName(player1_name) || isHelp(player1_name));
    
       
    std::cout << "Enter a name for player 2(uppercase characters only)" << std::endl;
    do
    {
        std::getline(std::cin, player2_name);
        if (std::cin.eof())
        {
            std::cout << std::endl;
            std::cout << "Goodbye" << std::endl;
            exit(0);
        }
        else if (isHelp(player2_name))
        {
            helpInfo_enteringName();
        }
        else if (!isValidPlayerName(player2_name))
        {
            std::cout << "Invalid name, please try again." << std::endl;
        }
    } while (!isValidPlayerName(player2_name) || isHelp(player2_name));
    
     std::cout << "Enter a name for player 3(uppercase characters only)" << std::endl;
    do
    {
        std::getline(std::cin, player3_name);
        if (std::cin.eof())
        {
            std::cout << std::endl;
            std::cout << "Goodbye" << std::endl;
            exit(0);
        }
        else if (isHelp(player3_name))
        {
            helpInfo_enteringName();
        }
        else if (!isValidPlayerName(player3_name))
        {
            std::cout << "Invalid name, please try again." << std::endl;
        }
    } while (!isValidPlayerName(player3_name) || isHelp(player3_name));

    // initialise players
    Player *player1 = new Player(player1_name);
    Player *player2 = new Player(player2_name);
    Player *player3 = new Player(player3_name);
    // initialise board
    Board *board = new Board();

    //board->printBoard();

    // initialise tile bag which contains shuffled tiles
    LinkedList *tileBag = new LinkedList();
    tileBag->iniTileBag();

    // initialise tiles in players' hands
    player1->initialiseTilesInHand(tileBag);
    player2->initialiseTilesInHand(tileBag);
    player3->initialiseTilesInHand(tileBag);

    std::cout << std::endl;
    std::cout << "Let's Play!" << std::endl;

    int playerFlag = 1;
    std::string instructure;
    Player *currentPlayer = new Player();
    while (tileBag->getSize() > 0 && (player1->getTilesInHand()->getSize() > 0
        || player2->getTilesInHand()->getSize() > 0 
        || player3->getTilesInHand()->getSize() > 0)  && !std::cin.eof())
    {
        int inputCount = 0;
        if (tileBag->getSize() > 0)
        {
            if (playerFlag == 1)
            {
                currentPlayer = player1;
                game(currentPlayer, player1, player2, player3, board, tileBag,
                     instructure, inputCount);

                inputCount = 1;
                playerFlag = 2;
            }
            if (playerFlag == 2)
            {
                currentPlayer = player2;
                game(currentPlayer, player1, player2, player3, board, tileBag,
                     instructure, inputCount);
                playerFlag = 3;
            }
            if (playerFlag == 3)
            {
                currentPlayer = player3;
                game(currentPlayer, player1, player2, player3, board, tileBag,
                     instructure, inputCount);
                playerFlag = 1;
            }
        }
        else
        {
            for (unsigned int turn = 0; turn < TILES_IN_HAND_NUM; turn++)
            {
                if (playerFlag == 1)
                {
                    currentPlayer = player1;

                    game(currentPlayer, player1, player2, player3, board, tileBag,
                         instructure, inputCount);
                    playerFlag = 2;
                }
                if (playerFlag == 2)
                {
                    currentPlayer = player2;

                    game(currentPlayer, player1, player2, player3, board, tileBag,
                         instructure, inputCount);
                    playerFlag = 3;
                }
                if (playerFlag == 3)
                {
                    currentPlayer = player3;

                    game(currentPlayer, player1, player2, player3, board, tileBag,
                         instructure, inputCount);
                    playerFlag = 1;
                }
            }
        }
    }

    checkEnd(tileBag, player1, player2, player3);
}

void continueGame(Player **currentPlayer, Player *player1, 
    Player *player2, Player *player3, LinkedList *tileBag, Board *board)
{
    int playerFlag = 0;
    if ((*currentPlayer)->getName().compare(player1->getName()) == 0)
    {
        playerFlag = 1;
    }
    else if ((*currentPlayer)->getName().compare(player2->getName()) == 0)
    {
        playerFlag = 2;
    }
    
    {
        playerFlag = 3;
    }

    std::string instructure;

    while (tileBag->getSize() > 0 && (player1->getTilesInHand()->getSize() > 0
        || player2->getTilesInHand()->getSize() > 0) && !std::cin.eof())
    {
        int inputCount = 0;
        if (tileBag->getSize() > 0)
        {
            if (playerFlag == 1)
            {
                *currentPlayer = player1;
                game(*currentPlayer, player1, player2, player3,
                            board, tileBag, instructure, inputCount);

                inputCount = 1;
                playerFlag = 2;
            }
            if (playerFlag == 2)
            {
                *currentPlayer = player2;
                game(*currentPlayer, player1, player2, player3,
                            board, tileBag, instructure, inputCount);
                playerFlag = 3;
            }
            if (playerFlag == 3)
            {
                *currentPlayer = player3;
                game(*currentPlayer, player1, player2, player3,
                            board, tileBag, instructure, inputCount);
                playerFlag = 1;
            }
        }
        else
        {
            for (unsigned int turn = 0; turn < TILES_IN_HAND_NUM; turn++)
            {
                if (playerFlag == 1)
                {
                    *currentPlayer = player1;

                    game(*currentPlayer, player1, player2, player3,
                            board, tileBag, instructure, inputCount);
                    playerFlag = 2;
                }
                if (playerFlag == 2)
                {
                    *currentPlayer = player2;

                    game(*currentPlayer, player1, player2, player3,
                            board, tileBag, instructure, inputCount);
                    playerFlag = 3;
                }
                if (playerFlag == 3)
                {
                    *currentPlayer = player2;

                    game(*currentPlayer, player1, player2, player3,
                            board, tileBag, instructure, inputCount);
                    playerFlag = 1;
                }
            }
        }
    }

    checkEnd(tileBag, player1, player2, player3);
}

void credits()
{
    std::cout << "---------------------------------- " << std::endl;
    std::cout << std::endl;
    // print group members' information
    std::cout << "Name: Yi Yang" << std::endl;
    std::cout << "Student ID: s3798354" << std::endl;
    std::cout << "Email: s3798354@student.rmit.edu.au" << std::endl;
    std::cout << std::endl;
    std::cout << "---------------------------------- " << std::endl;
}

void checkEnd(LinkedList *tileBag, Player *player1, 
                Player *player2, Player *player3)
{
    int tilesInBag = tileBag->getSize();
    int p1Tiles = player1->getTilesInHand()->getSize();
    int p2Tiles = player2->getTilesInHand()->getSize();
    int p3Tiles = player3->getTilesInHand()->getSize();
    if (tilesInBag == 0 && p1Tiles == 0 && p2Tiles == 0 && p3Tiles == 0)
    {
        std::cout << "Game over" << std::endl;
        std::cout << "Score for " << player1->getName() << ": ";
        std::cout << player1->getScore() << std::endl;
        std::cout << "Score for " << player2->getName() << ": ";
        std::cout << player2->getScore() << std::endl;
        std::cout << "Score for " << player3->getName() << ": ";
        std::cout << player3->getScore() << std::endl;
        if (player1->getScore() > player2->getScore()
            && player1->getScore() > player3->getScore())
        {
            std::cout << "Player " << player1->getName() << "won!";
            std::cout << std::endl;
        }
        else if (player2->getScore() > player1->getScore()
            && player2->getScore() > player3->getScore())
        {
            std::cout << "Player " << player2->getName() << "won!";
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Player " << player3->getName() << "won!";
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Goodbye" << std::endl;
        exit(0);
    }
}

void scores(Player *player1, Player *player2, Player *player3)
{
    std::cout << "Score for " << player1->getName() << ": ";
    std::cout << player1->getScore() << std::endl;

    std::cout << "Score for " << player2->getName() << ": ";
    std::cout << player2->getScore() << std::endl;

    std::cout << "Score for " << player3->getName() << ": ";
    std::cout << player3->getScore() << std::endl;
}


// after checking the instruction, check if it's able to place the tile
bool checkRule(Player *currentPlayer, Board *board,
               LinkedList *tileBag, std::string instructure)
{
    int turn = 0;
    if (tileBag->getSize() < 60)
    {
        turn = 1;
    }

    bool check = true;
    // put the tile on the board, update tiles in hand
    // update tile bag
    Colour colour = instructure[6];
    Shape shape = instructure[7] - '0';

    int row = -1;
    int col = -1;
    int digits = instructure[14] - '0';
    int tens = (instructure[13] - '0') * 10;
    if (instructure.size() == 14)
    {
        col = instructure[13] - '0';
    }
    else if (instructure.size() == 15)
    {
        col = tens + digits;
    }
    row = instructure[12] - '0' - ASCII_DIF;

    Rules *rule = new Rules();
    check = rule->boardRules(row, col, board,
                                  colour, shape, turn);
    return check;
}

void placeTile(Player *currentPlayer, Board *board,
               LinkedList *tileBag, std::string instructure)
{
    int turn = 0;
    if (tileBag->getSize() < 60)
    {
        turn = 1;
    }
    // put the tile on the board, update tiles in hand
    // update tile bag
    Colour colour = instructure[6];
    Shape shape = instructure[7] - '0';

    int row = -1;
    int col = -1;
    int digits = instructure[14] - '0';
    int tens = (instructure[13] - '0') * 10;
    if (instructure.size() == 14)
    {
        col = instructure[13] - '0';
    }
    else if (instructure.size() == 15)
    {
        col = tens + digits;
    }
    row = instructure[12] - '0' - ASCII_DIF;

    Rules *rule = new Rules();
    int earnedScore = 0;
    board->putTile2Board(colour, shape, row, col);
    earnedScore = rule->scoreRules(row, col, board, turn);

    currentPlayer->playOneTile(colour, shape);
    currentPlayer->getNewTile(tileBag);

    // increase the score
    currentPlayer->increaseScore(earnedScore);
}

void game(Player *currentPlayer, Player *player1, Player *player2, 
    Player *player3, Board *board, LinkedList *tileBag, 
            std::string instructure, int inputCount)
{
    // turn
    std::cout << std::endl;
    std::cout << currentPlayer->getName();
    std::cout << ", it's your turn" << std::endl;

    // print
    scores(player1, player2, player3);
    board->printBoard();
    std::cout << "Your hand is" << std::endl;
    currentPlayer->printTilesInHand();

    // input
    int toDo = -1;
    bool healperBool = true;
    bool check = true;
    do
    {
        healperBool = true;
        instructure.clear();
        std::getline(std::cin, instructure);

        // check instruction and do
        toDo = checkInstruction(instructure, currentPlayer);

        if (std::cin.eof())
        {
            std::cout << std::endl;
            std::cout << "Goodbye" << std::endl;
            exit(0);
        }
        else if (toDo == 0)
        {
            std::cout << std::endl;
            std::cout << "Please input again." << std::endl;
            std::cout << std::endl;
            healperBool = false;
        }
        else if (toDo == 1)
        {
            check = checkRule(currentPlayer, board, tileBag, instructure);
            if (!check)
            {
                std::cout << std::endl;
                std::cout << "Please input again." << std::endl;
                std::cout << std::endl;
                healperBool = false;
            }
            else
            {
                placeTile(currentPlayer, board, tileBag, instructure);
            }
        }
        else if (toDo == 2)
        {
            Colour colour = instructure[8];
            Shape shape = instructure[9] - '0';
            currentPlayer->replaceOneTile(colour, shape, tileBag);
        }
        else if (toDo == 3)
        {
            std::string fileName = instructure.substr(5,
                                                    instructure.size() - 5);
            GameFile *file = new GameFile();
            file->saveGame(fileName, currentPlayer,
                        player1, player2, player3, tileBag, board);
            // continue gaming
        }
        else if (toDo == 5)
        {
            helpInfo();
            healperBool = false;
        }
        
    } while (!healperBool);

    
}


void helpInfo()
{   
    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Welcome to the qwirkle game." << std::endl;
    std::cout << std::endl;
    std::cout << "Try commands below:" << std::endl;
    std::cout << std::endl;
    std::cout << "--- place <tile colour><tile shape> at <Row><Column>";
    std::cout << " to place a tile on the board." << std::endl;
    std::cout << "    Row should be uppercase letter A to Z." << std::endl;
    std::cout << "    Column should be number 0 to 25." << std::endl;
    std::cout << std::endl;
    std::cout << "--- replace <tile colour><tile shape>";
    std::cout << " to replace a tile in your hand." << std::endl;
    std::cout << std::endl;
    std::cout << "--- save <file name>";
    std::cout << " to save current game progress." << std::endl;
    std::cout << std::endl;
    std::cout << "--- ctrl + D";
    std::cout << " to quit the game." << std::endl;
    std::cout << std::endl;
    std::cout << "Your command: " << std::endl;
}

void helpInfo_mainMenu()
{   
    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Welcome to the qwirkle game." << std::endl;
    std::cout << std::endl;
    std::cout << "Try commands below:" << std::endl;
    std::cout << std::endl;
    std::cout << "--- 1";
    std::cout << " to start a new game" << std::endl;
    std::cout << std::endl;
    std::cout << "--- 2";
    std::cout << " to load a game from a exist and valid file." << std::endl;
    std::cout << std::endl;
    std::cout << "--- 3";
    std::cout << " to show students' information." << std::endl;
    std::cout << std::endl;
    std::cout << "--- 4 or Ctrl + D";
    std::cout << " to quit the game." << std::endl;
    std::cout << std::endl;
    std::cout << "Your command: " << std::endl;
}

void helpInfo_enteringName()
{   
    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Welcome to the qwirkle game." << std::endl;
    std::cout << std::endl;
    std::cout << "Please enter your name:" << std::endl;
    std::cout << std::endl;
    std::cout << "    The name should be uppercase letters." << std::endl;
    std::cout << "    For example 'DAVID'." << std::endl;
    std::cout << std::endl;
    std::cout << "or you can enter ctrl + D";
    std::cout << " to quit the game." << std::endl;
    std::cout << std::endl;
    std::cout << "Your name: " << std::endl;
}
