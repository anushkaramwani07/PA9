#include "Maze.hpp"

void Maze::setMaze(sf::RenderWindow& window, sf::Font font, Player p)
{
    sf::Vector2f size(99, 99);
    sf::Vector2f pos;

    sf::Texture texture("Brick.jpg", false, sf::IntRect({ 0, 0 }, { 800, 800 }));
    texture.setSmooth(true);
    sf::Sprite sprite(texture);
    //sprite.setTextureRect(sf::IntRect({ 60, 60 }, { 860, 860 }));
    sprite.setColor(sf::Color(125, 66, 55, 128));
    window.draw(sprite);
    

    int yPos = 0; //the row we are at

    while (yPos < 8)
    {
        int xPos = 0; // which column we are in

        while (xPos < 8)
        {
            pos.x = xPos * 100 + 0.5; // x position
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

    if (this->getBlocked() > 0)
    {
        // make the block appear
        // you can create an array (maybe double) to keep track of wear on the grid is vlocked and if they have hit that spot yet
        // 1 means path, 0 is blocked and then -1 is blocked and have already tried it
    }

    sf::Text text(font);

    //displaying the start text on the screen
    text = sf::Text{ font, "Start" };
    text.setCharacterSize(25);
    Vector2f position(text.getLocalBounds().position.x / 50, text.getLocalBounds().position.y / 50);
    text.setOrigin(position);
    text.setFillColor(sf::Color(43, 227, 98));
    window.draw(text);

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

void Maze::easyMaze(sf::RenderWindow& window)
{
    
    this->arrBoard[0][0] = 3; //start
    arrBoard[1][0] = arrBoard[2][0] = arrBoard[3][0] = arrBoard[4][0] = arrBoard[5][0] = arrBoard[6][0] =
        arrBoard[2][1] = arrBoard[3][1] = arrBoard[6][1] =
        arrBoard[3][2] = arrBoard[4][2] = arrBoard[5][2] = arrBoard[6][2] =
        arrBoard[0][3] = arrBoard[1][3] = arrBoard[4][3] =
        arrBoard[1][4] = arrBoard[2][4] = arrBoard[3][4] = arrBoard[4][4] = arrBoard[6][4] =
        arrBoard[2][5] = arrBoard[5][5] = arrBoard[6][5] = arrBoard[7][5] =
        arrBoard[2][6] = arrBoard[3][6] = arrBoard[4][6] = arrBoard[5][6] = arrBoard[7][6] =
        arrBoard[1][7] = arrBoard[2][7] = arrBoard[5][7] = 1;
    arrBoard[7][7] = 2; // end

    mPaths = 33;
}

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

    auto rectangle = sf::RectangleShape{ {600.f, 500.f} };
    rectangle.setFillColor(sf::Color(146, 187, 252));
    rectangle.setOrigin(rectangle.getGlobalBounds().size / 2.f);
    rectangle.setPosition(text.getPosition());

    window.draw(rectangle);
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

bool Maze::checkSpot(Player p, int x, int y)
{
    if (arrBoard[y - 1][x - 1] == 0)
    {
        arrBoard[y - 1][x - 1] = -1;

        return false;
    }
    else if (arrBoard[y - 1][x - 1] == -1)
    {
        return false;
    }

    return true;
}

//setters
void Maze::setPath(int newPath)
{
    mPaths = newPath;
}
void Maze::setBlacked(int newBlock)
{
    mBlocked = newBlock;
}

//getters
int Maze::getPath()
{
    return this->mPaths;
}
int Maze::getBlocked()
{
    return this->mBlocked;
}
