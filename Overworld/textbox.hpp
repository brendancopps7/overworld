//
//  textbox.hpp
//  Overworld
//
//  Created by Brendan Coppinger on 6/18/17.
//  Copyright © 2017 Brendan Coppinger. All rights reserved.
//

#ifndef textbox_hpp
#define textbox_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class textbox {
    
private:
    int TILE_WIDTH;
    int TILE_HEIGHT;
    int RESOLUTION;
    sf::Vector2f size;
    sf::RectangleShape background;
    
    
    
public:
    textbox(int tileheight, int tilewidth, int resolution);
    void setHeadSprite(sf::Sprite & headsprite);
    void setText(std::string text);
    std::string getText();
    void draw(sf::RenderWindow & window);
    
    
    
};

#endif /* textbox_hpp */
