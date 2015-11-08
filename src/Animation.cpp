#include <vector>
#include <iostream>

#include "Animation.h"


Animation::Animation(BITMAP* currentSheet, BITMAP* currentScreen)
{
    currSheet = currentSheet;
    currScreen = currentScreen;
    up = true;

    moveTo(0, 0, true);
    Frames.reserve(10);
    reset();
    cnt = -1;

} // Animation()

Animation::~Animation()
{
    //dtor
}

void Animation::addFrame(int SheetposX, int SheetposY, int Width, int Height)
{
    addFrame(SheetposX, SheetposY, Width, Height, true, 0);

} // addFrame()

void Animation::addFrame(int SheetposX, int SheetposY, int Width, int Height, bool transparency)
{
    addFrame(SheetposX, SheetposY, Width, Height, transparency, 0);

} // addFrame()

void Animation::addFrame(int SheetposX, int SheetposY, int Width, int Height, bool transparency, int spd)
{
    Frames.push_back(ASprite(SheetposX, SheetposY, Width, Height, transparency, spd));

} // addFrame()

void Animation::setFramespeed(int Frame, int spd)
{
    std::vector<ASprite>::iterator Spr = Frames.begin();

    int cnt = 0;

    while(cnt < Frame)
    {
        ++cnt;
        ++Spr;

        if(Spr == Frames.end())
        {
            return;

        } // if (Spr == Frames.end)

    } // while(cnt < Frame)

    (*Spr).setSpeed(spd);

} // setASpeed()

void Animation::deleteFrame(int Index)
{
    int del = 0;

    for(std::vector<ASprite>::iterator i = Frames.begin(); i != Frames.end(); ++i)
    {
        if(del == Index)
        {
            Frames.erase(i);
            break;

        } // if (del == Index)

        ++del;

    } // for(frames.begin; frames.end; ++i)

} // deleteFrame()

void Animation::moveTo(int X, int Y, bool absolute)
{
    if(absolute)
    {
        posX = X;
        posY = Y;

    }
    else
    {
        posX = posX + X;
        posY = posY + Y;

    }

} // moveTo()

void Animation::drawFrame()
{
    if(!Frames.empty())
    {
        (*Sprites).draw(currSheet, currScreen, posX, posY);

    }

} // drawFrame()

void Animation::play()
{
    --cnt;

    if(cnt < 0)
    {
        ++Sprites;

        if(Sprites == Frames.end())
        {
            Sprites = Frames.begin();

        } // if Sprites != Frames.end()

        cnt = (*Sprites).getSpeed();
    }

    drawFrame();

} // play()

void Animation::playLoop()
{
    --cnt;

    if(up)
    {
        if(cnt < 0)
        {
            ++Sprites;
            if(Sprites == Frames.end())
            {
                --Sprites;
                --Sprites;
                up = false;

            } // if Sprites != Frames.end()

            cnt = (*Sprites).getSpeed();
        }
    }
    else
    {
        if(cnt < 0)
        {
            --Sprites;
            if(Sprites == Frames.begin())
            {
                up = true;

            } // if Sprites != Frames.begin()

            cnt = (*Sprites).getSpeed();
        }
    } // if(up)

    drawFrame();

} // playLoop()


void Animation::reset()
{
    Sprites = Frames.begin();
    cnt = (*Sprites).getSpeed();

} // reset()

void Animation::setSheet(BITMAP* Sheet)
{
    currSheet = Sheet;

} // setSheet()

ASprite::ASprite(int SheetposX, int SheetposY, int Width, int Height, bool transparency, int Spd)
{
    sheetposX = SheetposX;
    sheetposY = SheetposY;
    width = Width;
    height = Height;
    transparent = transparency;
    speed = Spd;

} // Sprite()

void ASprite::draw(BITMAP* Src, BITMAP* Dst, int X, int Y)
{
    if(transparent)
    {
        masked_blit(Src, Dst, sheetposX, sheetposY, X, Y, width, height);

    }
    else
    {
        blit(Src, Dst, sheetposX, sheetposY, X, Y, width, height);

    }

} // draw()

void ASprite::setSpeed(int Spd)
{
    if(Spd < 0)
    {
        Spd = 0;
    }

    speed = Spd;
} // setSpeed()

int ASprite::getSpeed()
{
    return speed;

} // getSpeed()

ASprite::~ASprite()
{

} // ~ASprite()
