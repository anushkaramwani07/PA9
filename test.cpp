#include "test.hpp"

/*************************************************************
* Function: testMazeConstructor()
* Date Created: 4/19/25
* Date Last Modified: 4/19/25
* Description: tests the constructor for the maze
* Input parameters: none
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Test::testMazeConstructor()
{
	Maze m(Vector2f(100, 100), Vector2f(0, 0), sf::Color::Cyan);
	sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Lets Test The Game!");

    cout << "Blocked: " << m.getBlocked() << " Paths: " << m.getPath() << endl; // these should also both print zero if constructor works properly
    m.printBoard(); // this should print all zeros if the constructor works properly

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(m); // a cyan square should be displayed to screen in the top left corner if constructor works
        window.display();
    }
}

/*************************************************************
* Function: testSetSprite()
* Date Created: 4/20/25
* Date Last Modified: 4/20/25
* Description: tests the setting the sprite image for the player
* Input parameters: none
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Test::testSetSprite()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Lets Play The Maze Game!");
    sf::Texture texture("spider.png", false, sf::IntRect({ 0,0 }, { 638,532 }));
    sf::Sprite spider(texture);
    Player m(40.f, Vector2f(400, 400), texture);

    cout << "X Position: " << m.getXPos() << " Y Position: " << m.getYPos(); // we will see the postion the spider is set too

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        m.setSprite(window, texture); // this should now place the top left corner of the spider in the middle of the screen
        window.display();
    }
}
