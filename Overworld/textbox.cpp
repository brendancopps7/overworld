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
//    sf::Text text;
//    sf::Vector2f size;
//    sf::RectangleShape background;
    
textbox::textbox(int tilewidth, int tileheight, int resolution){
    TILE_WIDTH = tilewidth;
    TILE_HEIGHT = tileheight;
    RESOLUTION = resolution;
    background.setFillColor(sf::Color::Black);
    size.x = TILE_WIDTH*RESOLUTION;
    size.y = 2*RESOLUTION;
    background.setSize(size);
    background.setPosition(0, (TILE_HEIGHT - 2)*RESOLUTION);
    text.setString("Haven't put in doors yet, give me a minute");
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    text.setFont(font);
    text.setColor(sf::Color::White);
                
    }
    
void textbox::setHeadSprite(sf::Sprite & headsprite){
        
    }
void textbox::setText(std::string text){
    
    }

bool textbox::isVisible()
{
    return visible;
}

std::string textbox::getText(){
    
    }

void textbox::draw(sf::RenderWindow & window){
    window.draw(background);
}

void textbox::makeVisible(){
    visible = true;
}
    
    
    
    
