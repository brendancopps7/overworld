
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
#include <vector>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "textbox.hpp"
#include "player.hpp"


float SCALE = 1;
const float WINDOW_WIDTH = 768*SCALE;
const float WINDOW_HEIGHT = 640*SCALE;
const int TILE_WIDTH = 12;
const int TILE_HEIGHT = 10;
const int RESOLUTION = 64*SCALE;

int main(int, char const**)
{
    std::vector< std::vector<player*> > spritemap(TILE_WIDTH, std::vector<player*>(TILE_HEIGHT));

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load background for map
    sf::Texture maptexture;
    if (!maptexture.loadFromFile(resourcePath() + "vertsea.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite background(maptexture);
    float a= SCALE*(13*.5/3);
    background.scale(a, a);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
    sf::RectangleShape textboxbackground;
    textboxbackground.setFillColor(sf::Color::Black);
    sf::Vector2f textboxsize;
    textboxsize.x=WINDOW_WIDTH;
    textboxsize.y=2*RESOLUTION;
    textboxbackground.setSize(textboxsize);
    textboxbackground.setPosition(0, (TILE_HEIGHT - 2)*RESOLUTION);
    
    sf::Text text("Cannot enter buildings yet. Working on it.", font, RESOLUTION/2);
    text.setFillColor(sf::Color::White);
    text.setPosition(2*RESOLUTION, (TILE_HEIGHT - 2)*RESOLUTION);
    
    //textbox text1(TILE_WIDTH, TILE_HEIGHT, RESOLUTION);
    
    sf::Vector2f trigger (3*RESOLUTION, 3*RESOLUTION);
    
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Create the Player Character
    player one(WINDOW_WIDTH, WINDOW_HEIGHT, &spritemap, 3, 6);
    
    //create npc
    player npc(WINDOW_WIDTH, WINDOW_HEIGHT, &spritemap, 5, 5);
    
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
            
            //Basic character movement from WASD
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {
                
                one.move(0, -1, &spritemap);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                one.move(0, 1, &spritemap);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
                one.move(-1, 0, &spritemap);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
                one.move(1, 0, &spritemap);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return){
                //one.talk(&text1, &spritemap);
            }
        }

        // Clear screen
        window.clear();

        // Draw the background
        window.draw(background);
        
        for (int y = 0; y < TILE_WIDTH; y++){
            for (int x = 0; x < TILE_HEIGHT; x++){
                if (spritemap[x][y] != nullptr){
                    spritemap[x][y]->draw(window);
                }
            }
        }
            
        
        // Draw the player
        //one.draw(window);
        
        // Draw the npc
        //npc.draw(window);

        // Draw the string
        //If location of player is (3,3), draw the string, with a textbox behind it.
        if(spritemap[3][3] == &one){
            window.draw(textboxbackground);
            window.draw(one.getheadsprite());
            window.draw(text);
        }
        
        //draw test two
        //window.draw(two);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
