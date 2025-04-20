/*******************************************************************************
 * Programmers: Abaigail Kubli and Anushka Ramwani
 * Class: CptS 122; Lab Section 10
 * Programming Assignment: 9 - A Graphical Game or Application
 * Date: 4/12/2025
 *
 * Description: Creating our own game using sfml and inheritance
 *
 ******************************************************************************/

#include "Maze.hpp"

 /*************************************************************
* Function: setMaze()
* Date Created: 4/14/25
* Date Last Modified: 4/20/25
* Description: draws the maze and the cahracter
*				constantly updating the game
* Input parameters: sf::RenderWindow& window, sf::Font font, Player
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Maze::setMaze(sf::RenderWindow& window, sf::Font font, Player p)
{
    sf::Vector2f size(99, 99);
    sf::Vector2f pos;

    sf::Texture texture("Brick.jpg", false, sf::IntRect({ 0, 0 }, { 800, 800 }));
    texture.setSmooth(true);
    sf::Sprite sprite(texture);
    sprite.setColor(sf::Color(158, 76, 73, 128));
    window.draw(sprite);
    

    int yPos = 0; //the row we are at

    while (yPos < 8)
    {
        int xPos = 0; // which column we are in

        while (xPos < 8)
        {
            pos.x = xPos * 100 + 0.5; // x position (0.5 buffer for the grid)
            pos.y = yPos * 100 + 0.5; // y postition

            this->setSize(size);
            this->setFillColor(sf::Color::Transparent);
            this->setOutlineThickness(0.5);
            this->setOutlineColor(sf::Color::White);
            this->setPosition(pos);

            window.draw(*this);

            ++xPos;
        }

        ++yPos;
    }

    if (this->getBlocked() > 0) // the palyer has found a blocked path
    {
        for (int i = 0; i < 8;i++)
        {
            for (int j = 0; j < 8;j++)
            {
                if (arrBoard[i][j] == -1)
                {
                    pos.x = j * 100 + 0.5; // x position
                    pos.y = i * 100 + 0.5; // y postition

                    this->setSize(size);
                    this->setFillColor(sf::Color(255, 133, 180, 128)); // marks the spots that have been found by the player to not be a path
                    this->setOutlineThickness(0.5);
                    this->setOutlineColor(sf::Color::White);
                    this->setPosition(pos);

                    window.draw(*this);
                }
            }
        }
    }

    sf::Text text(font);
    text = sf::Text{ font, "Start" };
    text.setCharacterSize(25);
    Vector2f position(-15, -0);

    for (int i = 0; i < 8;i++)
    {
        for (int j = 0; j < 8;j++)
        {
            if (arrBoard[i][j] == 3)
            {
                position.x = position.x + j * -100; // x position
                position.y = position.y + i * -100; // y postition

                //displaying the start text on the screen                
                text.setOrigin(position);
                text.setFillColor(sf::Color(43, 227, 98));
                window.draw(text);

                window.draw(*this);
            }
        }
    }

    //displaying the end text on the screen
    text.setString("End");
    text.setCharacterSize(25);
    position.y = -770;
    position.x = -750;
    text.setOrigin(position);
    text.setFillColor(sf::Color(245, 24, 80));
    window.draw(text);

    window.draw(p);
}

/*************************************************************
* Function: easyMaze()
* Date Created: 4/14/25
* Date Last Modified: 4/18/25
* Description: changes the arrBoard for easy mode
* Input parameters: none
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Maze::easyMaze()
{
    this->arrBoard[0][0] = 3; //start
    arrBoard[1][0] = arrBoard[2][0] = arrBoard[3][0] = arrBoard[4][0] = arrBoard[5][0] = arrBoard[6][0] =
        arrBoard[2][1] = arrBoard[3][1] = arrBoard[6][1] =
        arrBoard[3][2] = arrBoard[4][2] = arrBoard[5][2] = arrBoard[6][2] =
        arrBoard[0][3] = arrBoard[1][3] = arrBoard[4][3] =
        arrBoard[1][4] = arrBoard[2][4] = arrBoard[3][4] = arrBoard[4][4] = arrBoard[6][4] =
        arrBoard[2][5] = arrBoard[5][5] = arrBoard[6][5] = arrBoard[7][5] =
        arrBoard[2][6] = arrBoard[3][6] = arrBoard[4][6] = arrBoard[5][6] = arrBoard[7][6] =
        arrBoard[1][7] = arrBoard[2][7] = arrBoard[5][7] = 1; // paths
    arrBoard[7][7] = 2; // end

    mPaths = 33; // not includeing start and end
}

/*************************************************************
* Function: mediumMaze()
* Date Created: 4/14/25
* Date Last Modified: 4/18/25
* Description: changes the arrBoard for medium mode
* Input parameters: none
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Maze::mediumMaze()
{
    this->arrBoard[3][0] = 3; //start
    arrBoard[5][0] =
        arrBoard[1][1] = arrBoard[3][1] = arrBoard[5][1] = arrBoard[6][1] = arrBoard[7][1] =
        arrBoard[1][2] = arrBoard[3][2] = arrBoard[4][2] = arrBoard[5][2] = arrBoard[7][2] =
        arrBoard[0][3] = arrBoard[1][3] = arrBoard[2][3] = arrBoard[4][3] = arrBoard[6][3] = arrBoard[7][3] =
        arrBoard[0][4] = arrBoard[2][4] = arrBoard[3][4] = arrBoard[4][4] = arrBoard[5][4] =
        arrBoard[0][5] /*= arrBoard[5][5]*/ = arrBoard[7][5] = 
        arrBoard[0][6] = arrBoard[1][6] = arrBoard[2][6] = arrBoard[3][6] = arrBoard[4][6] = arrBoard[5][6] = arrBoard[6][6] =
        arrBoard[0][7] = arrBoard[2][7] = arrBoard[5][7] = arrBoard[6][7] = 1; // paths
    arrBoard[7][7] = 2; // end

    mPaths = 35;
}

/*************************************************************
* Function: hardMaze()
* Date Created: 4/18/25
* Date Last Modified: 4/21/25
* Description: changes the arrBoard for hard mode
* Input parameters: none
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Maze::hardMaze() // enimies
{

}

/*************************************************************
* Function: gameMenu()
* Date Created: 4/14/25
* Date Last Modified: 4/18/25
* Description: displays the game difficulty choices
* Input parameters: sf::RenderWindow& window, sf::Font font
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Maze::gameMenu(sf::RenderWindow& window, sf::Font font)
{
    sf::Text text(font);    

    // Medium
    text.setString("2. Medium");
    text.setCharacterSize(100);
    auto center = text.getGlobalBounds().size / 2.f;
    auto bounds = center + text.getLocalBounds().position;
    text.setOrigin(bounds);
    text.setPosition(sf::Vector2f{ 400,400 });
    text.setFillColor(sf::Color(242, 242, 145));

    auto rec = sf::RectangleShape{ {600.f, 500.f} };
    rec.setFillColor(sf::Color(146, 187, 252));
    rec.setOutlineThickness(10);
    rec.setOutlineColor(sf::Color(160, 144, 252));
    rec.setOrigin(rec.getGlobalBounds().size / 2.f);
    rec.setPosition(text.getPosition());

    window.draw(rec);
    window.draw(text);

    // Easy
    text = sf::Text{ font, "1. Easy" };
    text.setCharacterSize(100);
    center = text.getGlobalBounds().size / 2.f;
    bounds = center + text.getLocalBounds().position;
    text.setOrigin(bounds);
    text.setPosition(sf::Vector2f{ 400,300 });
    text.setFillColor(sf::Color(173, 255, 174));
    window.draw(text);

    // Hard
    text.setString("3. Hard");
    text.setCharacterSize(100);
    center = text.getGlobalBounds().size / 2.f;
    bounds = center + text.getLocalBounds().position;
    text.setOrigin(bounds);
    text.setPosition(sf::Vector2f{ 400,500 });
    text.setFillColor(sf::Color(255, 138, 138));
    window.draw(text);
}

/*************************************************************
* Function: checkSpot()
* Date Created: 4/15/25
* Date Last Modified: 4/17/25
* Description: determines if the spot the player wants to go it blocked
*				and then marks it with -1 if it is
* Input parameters: Player p, int x, int y
* Returns: bool (true or false)
* Preconditions: none
* Postconditions: none
*************************************************************/
bool Maze::checkSpot(Player p, int x, int y)
{
    if (x < 9 && y < 9 && x > 0 && y > 0) // is this a place on the board?
    {
        if (arrBoard[y - 1][x - 1] == 0) // is blocked
        {
            arrBoard[y - 1][x - 1] = -1;

            ++mBlocked;

            return false;
        }
        else if (arrBoard[y - 1][x - 1] == -1) // already has been there
        {
            return false;
        }

        return true;
    }

    return false; // spot doesn't exist in the array
}

/*************************************************************
* Function: checkWin()
* Date Created: 4/15/25
* Date Last Modified: 4/17/25
* Description: constructor for the maze
* Input parameters: sf::RenderWindow& window, sf::Font font, int x, int y, int gameDif
* Returns: a number based on if the player has made it to the end
* Preconditions: none
* Postconditions: none
*************************************************************/
int Maze::checkWin(sf::RenderWindow& window, sf::Font font, int x, int y, int gameDif)
{

    if (arrBoard[y - 1][x - 1] == 2) //end
    {
        return 10;
    }

    return gameDif;
}

/*************************************************************
* Function: printBoard()
* Date Created: 4/19/25
* Date Last Modified: 4/19/25
* Description: prints the arrBoard
* Input parameters: none
* Returns: mBlocked
* Preconditions: none
* Postconditions: none
*************************************************************/
void Maze::printBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8;j++)
        {
            cout << i << ", " << j << ": " << arrBoard[i][j] << endl;
        }
    }
}

//setters
/*************************************************************
* Function: setPath()
* Date Created: 4/14/25
* Date Last Modified: 4/14/25
* Description: setter for the private member mPaths
* Input parameters: int newPath
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Maze::setPath(int newPath)
{
    mPaths = newPath;
}
/*************************************************************
* Function: setBlocked()
* Date Created: 4/14/25
* Date Last Modified: 4/14/25
* Description: setter for the private member mBlocked
* Input parameters: int newBlock
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Maze::setBlacked(int newBlock)
{
    mBlocked = newBlock;
}

//getters
/*************************************************************
* Function: getPath()
* Date Created: 4/14/25
* Date Last Modified: 4/14/25
* Description: getter for the private member mPaths
* Input parameters: none
* Returns: mPaths
* Preconditions: none
* Postconditions: none
*************************************************************/
int Maze::getPath()
{
    return this->mPaths;
}
/*************************************************************
* Function: getBlocked()
* Date Created: 4/14/25
* Date Last Modified: 4/14/25
* Description: getter for the private member mBlocked
* Input parameters: none
* Returns: mBlocked
* Preconditions: none
* Postconditions: none
*************************************************************/
int Maze::getBlocked()
{
    return this->mBlocked;
}
