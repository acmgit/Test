#include <iostream>

#include <allegro/gfx.h>
#include <allegro/graphics.h>
#include <allegro/draw.h>

#include "Bar.h"

Bar::Bar(BITMAP *Screen, int PosX, int PosY, int Width, int Height, int Color, bool vertical)
{
    currScreen = Screen;
    Pos_X = PosX;
    Pos_Y = PosY;

    width = Width;
    height = Height;
    percent = 0;

    setColor(Color);
    setOrientation(vertical);


} // Bar()

Bar::~Bar()
{
    //dtor
} // ~Bar()

void Bar::setPercent(int percentage)
{
    if(percentage > 100)
    {
        percentage = 100;

    } // if(percentage > 100)
    else
    {
        if(percentage < 0)
        {
            percentage = 0;

        } // if(percentage < 0)
    }

    percent = percentage;

} // setPercent

void Bar::setColor(int Color)
{
    currColor = Color;

} // setColor

void Bar::setOrientation(bool vertical)
{
    isVertical = vertical;

} // setOrientation

void Bar::draw()
{

    int currheight = calcHeight();

    if(isVertical)
    {
        currheight = currheight * -1; // The bar is growing up, so the height must be negative
        rectfill(currScreen, Pos_X, Pos_Y, Pos_X + width, Pos_Y + currheight, currColor);

    }
    else
    {
        // The Bar grows from left to right, so the Coord. X must expand.
        rectfill(currScreen, Pos_X, Pos_Y, Pos_X + currheight, Pos_Y + width, currColor);

    } // if(isVertical)

} // draw

int Bar::calcHeight()
{
    float x = (float) height / 100;
    x = x * percent;
    return (int) x;

} // calcHeight
