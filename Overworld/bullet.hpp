//
//  bullet.hpp
//  Overworld
//
//  Created by Brendan Coppinger on 9/13/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#ifndef bullet_hpp
#define bullet_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class bullet
{
private:
    float screenwidth;
    float screenheight;
    float x;
    float y;
    float xvel;
    float yvel;
    int charscale;
    bool gravity;
    bool toErase;
    sf::Sprite charsprite;
    sf::Texture chartexture;
    
public:
    bullet(int width, int height, int x_, int y_, float xvel_, float yvel_);
    bool getToErase();
    void update(float elapsedTime);
    void draw(sf::RenderWindow & window);
};

#endif /* bullet_hpp */
