#include <print>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    // window height and width
    unsigned int winx = 1920;
    unsigned int winy = 1080;

    // calling window
    auto window = sf::RenderWindow(sf::VideoMode({winx, winy}), "CMake SFML Project");
    window.setFramerateLimit(60); // sets framrate limit

    // initiat a clock for delta time
    sf::Clock clock;
    
    // some basic game variables
    float gameXMargin = 25.0f;
    float gameYMargin = 25.0f;
    float gameStartingYPos = 500.f;
    float paddleWidth = 40.0f;
    float paddleHeight = 180.0f;

    // player one inital vars
    sf::Vector2f p1Positon = { gameXMargin, gameStartingYPos };
    unsigned int p1r = 100;
    unsigned int p1g = 250;
    unsigned int p1b = 50;

    // player two initial vars
    sf::Vector2f p2Position = { winx - paddleWidth - gameXMargin, gameStartingYPos };
    unsigned int p2r = 50;
    unsigned int p2g = 0;
    unsigned int p2b = 100;

    // ball initial vars
    sf::Vector2f ballPosition = { winx * .5f, winy * .5f };
    unsigned int br = 255;
    unsigned int bg = 255;
    unsigned int bb = 255;

    // player one initialize
    sf::RectangleShape playerOne = sf::RectangleShape({ paddleWidth, paddleHeight });
    playerOne.setFillColor(sf::Color(p1r, p1g, p1b));
    playerOne.setPosition(p1Positon);

    // player two initialize
    sf::RectangleShape playerTwo = sf::RectangleShape({ paddleWidth, paddleHeight });
    playerTwo.setFillColor(sf::Color(p2r, p2g, p2b));
    playerTwo.setPosition(p2Position);

    // ball initialize
    sf::CircleShape ball = sf::CircleShape(15.f);
    ball.setFillColor(sf::Color(br, bg, bb));
    ball.setPosition(ballPosition);

    // game loop
    while (window.isOpen())
    {
        // event manager loop
        while (const std::optional event = window.pollEvent())
        {


            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // delta time
        float dt = clock.restart().asSeconds();
        // speed for paddles
        float paddleSpeed = 600.0f;

        // position/size vars for movment
        auto p1pos = playerOne.getPosition();
        auto p2pos = playerTwo.getPosition();
        auto ballpos = ball.getPosition();
        float paddleHeight = playerOne.getSize().y;
        float winHorizontalSize = window.getSize().y;
        

        // if statments for updown movement on characters
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
        {
            if (p1pos.y > 0 + gameYMargin)
            {
                playerOne.move({ 0.f, -paddleSpeed * dt });
                //std::println("Going Up!: ({}, {})", pos.x, pos.y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S))
        {
            if (p1pos.y < winHorizontalSize - paddleHeight - gameYMargin)
            {
                playerOne.move({ 0.f, paddleSpeed * dt });
                //std::println("Going Down!: ({}, {})", pos.x, pos.y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
        {
            if (p2pos.y > 0 + gameYMargin)
            {
                playerTwo.move({ 0.f, -paddleSpeed * dt });
                std::println("Going Up!: ({}, {})", p2pos.x, p2pos.y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
        {
            if (p2pos.y < winHorizontalSize - paddleHeight - gameYMargin)
            {
                playerTwo.move({ 0.f, paddleSpeed * dt });
                std::println("Going Down!: ({}, {})", p2pos.x, p2pos.y);
            }
        }

        ball.setPosition({ ballpos.x-5, ballpos.y });

        window.clear();
        // draw things down here


        window.draw(playerOne);
        window.draw(playerTwo);
        window.draw(ball);

        // end of current frame
        window.display();
    }
}
