//
//  fighter.hpp
//  Overworld
//
//  Created by Brendan Coppinger on 7/22/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#ifndef fighter_hpp
#define fighter_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class fighter {
    
private:
    float screenwidth;
    float screenheight;
    float xdirection;
    float xvelocity;
    float yvelocity;
    float x;
    float y;
    bool grounded;
    bool slow;
    sf::Sprite charsprite;
    sf::Texture chartexture;
    
public:
    fighter(float height, float width);
    sf::Sprite getcharsprite();
    void setXSpeed(float xdirection);
    void setYSpeed(float ydirection);
    void walk(float xdirection);
    void jump();
    void slowing();
    void moveto(sf::Vector2f coord);
    void update(float elapsedTime);
    void draw(sf::RenderWindow & window);
    
    
    
};

#endif /* fighter_hpp */
