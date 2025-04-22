/*******************************************************************************
 * Programmers: Abaigail Kubli and Anushka Ramwani
 * Class: CptS 122; Lab Section 10
 * Programming Assignment: 9 - A Graphical Game or Application
 * Date: 4/12/2025
 *
 * Description: Creating our own game using sfml and inheritance
 *
 ******************************************************************************/

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
    Player p(40.f, Vector2f(400, 400), texture);

    cout << "X Position: " << p.getXPos() << " Y Position: " << p.getYPos() << endl; // we will see the postion the spider is set too
    cout << "Postion seet X: 400, Y: 400";

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        p.setSprite(window, texture); // this should now place the spider in the middle of the screen
        window.display();
    }
}

/*************************************************************
    * Function: testCheckSpot()
* Date Created: 4/20/25
* Date Last Modified: 4/20/25
* Description: tests checkSpot() and sees if it can actually
    check each part of the array to see if the player can move there
* Input parameters: none
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Test::testCheckSpot()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Lets Play The Maze Game!");
    sf::Texture texture("spider.png", false, sf::IntRect({ 0,0 }, { 638,532 }));
    sf::Font font("Game Bubble.ttf");
    Player p(20.f, Vector2f(30, 30), texture);
    Maze m(Vector2f(0, 0), Vector2f(0, 0), sf::Color::Transparent);

    m.easyMaze();
    m.printBoard(); // should display what the board now looks like

    //true means that they can travel to that spot
    if (m.checkSpot(p, 10, -1) == false) //out of bounds
    {
        cout << "Checking out of bounds: False" << endl;
        
        if (m.checkSpot(p, 8, 8) == true) // this is the end of the maze in the array
        {
            cout << "Checking end of maze spot: True" << endl;

            if (m.checkSpot(p, 1, 1) == true) // start of the easy maze
            {
                cout << "Checking start of maze spot: True" << endl;

                if (m.checkSpot(p, 1, 8) == false) // spot that is blocked in the maze
                {
                    cout << "Checking blocked part of maze spot: False" << endl;

                    if (m.checkSpot(p, 1, 8) == false) // check the spot again now that checkSpot() has changed that array entry
                    {
                        cout << "Checking blocked part of maze spot: False" << endl;

                        if (m.checkSpot(p, 1, 5) == true) // part of maze that is a path
                        {
                            cout << "Checking path part of maze spot: True" << endl;
                        }
                        else {
                            cout << "Checking path part of maze spot: False (Wrong)" << endl;
                        }
                    }
                    else {
                        cout << "Checking blocked part of maze spot: True (Wrong)" << endl;
                    }
                }
                else {
                    cout << "Checking blocked part of maze spot: True (Wrong)" << endl;
                }
            }
            else {
                cout << "Checking start of maze spot: Flase (Wrong)" << endl;
            }
        }
        else {
            cout << "Checking end of maze spot: Flase (Wrong)" << endl;
        }
    }
    else {
        cout << "Checking out of bounds: True (Wrong)" << endl;
    }

    m.printBoard(); // has the board changed?
    //does the postion [7][0] in the array now say -1
}

/*************************************************************
* Function: testMazeConstructor()
* Date Created: 4/20/25
* Date Last Modified: 4/20/25
* Description: tests if the sprite rotates in the drirection we want
* Input parameters: none
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Test::testRotateSprite()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Lets Play The Maze Game!");
    sf::Texture texture("spider.png", false, sf::IntRect({ 0,0 }, { 638,532 }));
    Player p(20.f, Vector2f(400, 400), texture);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            p.rotateSprite("down");
            cout << "down" << endl;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            p.rotateSprite("up");
            cout << "up" << endl;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            p.rotateSprite("left");
            cout << "left" << endl;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            p.rotateSprite("right");
            cout << "right" << endl;
        }

        p.setSprite(window, texture); // this should now place the spider in the middle of the screen and in the direction 
        //the player just pushed the arrow keys
        window.display();
    }
}

/*************************************************************
* Function: testCheckWin()
* Date Created: 4/21/25
* Date Last Modified: 4/21/25
* Description: tests the check win function for maze
* Input parameters: none
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Test::testCheckWin()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Lets Play The Maze Game!");
    Maze m(Vector2f(0, 0), Vector2f(0, 0), sf::Color::Transparent);
    sf::Font font("Game Bubble.ttf");

    sf::Texture texture("spider.png", false, sf::IntRect({ 0,0 }, { 638,532 }));
    Player p(20.f, Vector2f(400, 400), texture);

    m.easyMaze();

    if (m.checkWin(window, font, 1, 1, 1) != 10) // at the start
    {
        cout << "Not win. Pass" << endl;

        if (m.checkWin(window, font, 8, 8, 1) == 10) // end
        {
            cout << "Win. Pass" << endl;

            if (m.checkWin(window, font, 1, 8, 1) != 10) // blocked (0)
            {
                cout << "Not win. Pass" << endl;

                if (m.checkWin(window, font, 1, 8, 1) != 10) // blocked and marked (-1)
                {
                    cout << "Not win. Pass" << endl;

                    if (m.checkWin(window, font, 1, 5, 1) != 10) // path (1)
                    {
                        cout << "Not win. Pass" << endl;
                    }
                    else {
                        cout << "Win. Fail" << endl;
                    }
                }
                else {
                    cout << "Win. Fail" << endl;
                }
            }
            else {
                cout << "Win. Fail" << endl;
            }
        }
        else {
            cout << "Not win. Fail" << endl;
        }
    }
    else {
        cout << "Win. Fail" << endl;
    }
}
