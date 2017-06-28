//
//  textbox.cpp
//  Overworld
//
//  Created by Brendan Coppinger on 6/18/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#include "textbox.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

//private:
//    int TILE_WIDTH;
//    int TILE_HEIGHT;
//    int RESOLUTION;
//    sf::Vector2f size;
//    sf::RectangleShape background;
    
textbox::textbox(int tileheight, int tilewidth, int resolution){
    TILE_WIDTH = tilewidth;
    TILE_HEIGHT = tileheight;
    RESOLUTION = resolution;
    background.setFillColor(sf::Color::Black);
    size.x = TILE_WIDTH*RESOLUTION;
    size.y = TILE_HEIGHT*RESOLUTION;
    background.setSize(size);
    background.setPosition(0, (TILE_HEIGHT - 2)*RESOLUTION);
    }
    
void textbox::setHeadSprite(sf::Sprite & headsprite){
        
    }
void textbox::setText(std::string text){
    
    }

std::string textbox::getText(){
    
    }

void textbox::draw(sf::RenderWindow & window){
    window.draw(background);
}
    
    
    
    
    
