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
#include "textbox.hpp"

class bullet
{
private:
    int x;
    int y;
    int xvel;
    int yvel;
    bool gravity;
    sf::Sprite charsprite;
    sf::Texture chartexture;
    
public:
    void update();
    void draw();
    void update(float elapsedTime);
    void draw(sf::RenderWindow & window);
};

#endif /* bullet_hpp */
