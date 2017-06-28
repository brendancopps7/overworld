//
//  npc.cpp
//  Overworld
//
//  Created by Brendan Coppinger on 6/16/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#include "npc.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

npc::npc(float width, float height) {
    screenwidth = width;
    screenheight = height;
    float charscale = 1.5;
    x=0;
    y=0;
    if (!chartexture.loadFromFile(resourcePath() + "sprite_1.png")) {
        return EXIT_FAILURE;
    }
    charsprite.setTexture(chartexture);
    charsprite.setPosition(x, y);
    charsprite.scale(charscale, charscale);
    charsprite.scale(5, 5);
};

sf::Sprite npc::getcharsprite(){
    return charsprite;
}

void npc::move(float xchange, float ychange){
    x=x+xchange*5*64;
    if (x>=screenwidth)
        x=screenwidth-5*64;
    else if (x<0)
        x=0;
    y=y+ychange*5*64;
    if (y>=screenheight)
        y=screenheight-5*64;
    else if (y<0)
        y=0;
    charsprite.setPosition(x, y);
};

void npc::moveto(sf::Vector2f coord){
    x=coord.x;
    y=coord.y;
    charsprite.setPosition(coord);
};

void npc::draw(sf::RenderWindow & window){
    window.draw(charsprite);
};
