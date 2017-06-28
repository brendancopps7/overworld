
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "player.hpp"
#include "npc.hpp"

float SCALE = 1;
const float WINDOW_WIDTH = 768*SCALE;
const float WINDOW_HEIGHT = 640*SCALE;
const int TILE_WIDTH = 12;
const int TILE_HEIGHT = 10;
const int RESOLUTION = 64*SCALE;

int main(int, char const**)
{
    
    sf::Vector2f GridCoord[TILE_WIDTH][TILE_HEIGHT];
    for (int i =0; i<TILE_WIDTH; i++)
    {
        for (int j=0; j<TILE_HEIGHT; j++)
        {
            GridCoord[i][j].x = i*RESOLUTION;
            GridCoord[i][j].y = j*RESOLUTION;
        }
    }

    std::string map[TILE_WIDTH][TILE_HEIGHT];

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "vertsea.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    float a= SCALE*(13*.5/3);
    sprite.scale(a, a);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("It is not a story that the Jedi would tell you.", font, 32);
    text.setFillColor(sf::Color::Red);
    text.setPosition(0, 1*64);
    
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Create the Player Character
    player one(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    //create npc (NEED TO USE DIFFERENT SPRITE IN FUTURE)
    sf::Sprite two(texture);
    
    // Play the music
    //music.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                one.move(0, -1);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                one.move(0, 1);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
                one.move(1, 0);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
                one.move(-1, 0);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::RShift) {
                one.moveto(GridCoord[6][5]);
            }
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);
        
        // Draw the player
        window.draw(one.getcharsprite());

        // Draw the string
        window.draw(text);
        
        //draw test two
        //window.draw(two);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
