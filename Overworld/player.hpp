//
//  player.hpp
//  Overworld
//
//  Created by Brendan Coppinger on 12/24/16.
//  Copyright © 2016 Brendan Coppinger. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class player {
    
private:
    float screenwidth;
    float screenheight;
    float x;
    float y;
    float xoffset;
    float yoffset;
    sf::Sprite charsprite;
    sf::Sprite headsprite;
    sf::Texture chartexture;
    
public:
    player(float width, float height, std::vector< std::vector<player*> >* spritemap, int x_, int y_);
    sf::Sprite getcharsprite();
    sf::Sprite getheadsprite();
    sf::Vector2f getposition();
    void move(float xchange, float ychange, std::vector< std::vector<player*> >* spritemap);
    void moveto(sf::Vector2f coord);
    void draw(sf::RenderWindow & window);
    
    
    
};

#endif /* player_hpp */
