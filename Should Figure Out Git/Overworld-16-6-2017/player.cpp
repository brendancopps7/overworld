//
//  player.cpp
//  Overworld
//
//  Created by Brendan Coppinger on 12/24/16.
//  Copyright © 2016 Brendan Coppinger. All rights reserved.
//

#include "player.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

player::player(float width, float height) {
    screenwidth = width;
    screenheight = height;
    xoffset = .25*64;
    yoffset = .5*64;
    float charscale = 1.5;
    x=3*64 - xoffset;
    y=6*64 - yoffset;
    if (!chartexture.loadFromFile(resourcePath() + "sprite_1.png")) {
        return EXIT_FAILURE;
    }
    charsprite.setTexture(chartexture);
    charsprite.setPosition(x, y);
    charsprite.scale(charscale, charscale);
    //Check main.cpp : the float in the following line should match the global const SCALE
    charsprite.scale(1, 1);
};

sf::Sprite player::getcharsprite(){
    return charsprite;
}

void player::move(float xchange, float ychange){
    x=x+xchange*64;
    if (x>=screenwidth - xoffset)
        x=screenwidth-(64+xoffset);
    else if (x<xoffset*-1)
        x=xoffset*-1;
    y=y+ychange*64;
    if (y>=screenheight - yoffset)
        y=screenheight-(64 + yoffset);
    else if (y<yoffset*-1)
        y=yoffset*-1;
    charsprite.setPosition(x, y);
};

void player::moveto(sf::Vector2f coord){
    x=coord.x;
    y=coord.y;
    charsprite.setPosition(coord);
};

void player::draw(sf::RenderWindow & window){
    window.draw(charsprite);
};
