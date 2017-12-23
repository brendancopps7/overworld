//
//  realtimesprite.cpp
//  Overworld
//
//  Created by Brendan Coppinger on 9/14/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#include "realtimesprite.hpp"
#include "ResourcePath.hpp"

realtimesprite::realtimesprite(){
    x=0;
    y=0;
    xvel=0;
    yvel=0;
}

realtimesprite::realtimesprite(std::string resourcepath, int x_, int y_){
    x=x_;
    y=y_;
    if (!chartexture.loadFromFile(resourcePath() + resourcepath)) {
        return EXIT_FAILURE;
    }
    charsprite.setTexture(chartexture);
    charsprite.setPosition(x, y);
}

void realtimesprite::update(float elapsedtime){
    x=x+xvel*elapsedtime*60;
    y=y+yvel*elapsedtime*60;
    charsprite.setPosition(x, y);
}

void realtimesprite::draw(sf::RenderWindow &window){
    window.draw(charsprite);
}

void realtimesprite::moveTo(int x_, int y_){
    x=x_;
    y=y_;
    charsprite.setPosition(x, y);
}

void realtimesprite::moveTo(sf::Vector2i coord){
    x=coord.x;
    y=coord.y;
    charsprite.setPosition(x, y);
}
