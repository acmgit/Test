#ifndef ANIMATION_H
#define ANIMATION_H

#include <allegro/gfx.h>
#include <allegro/draw.h>

#include <vector>

class ASprite;

/**************************************************************************************************************
 Animationclass depend on Allegro 4.
 (?) by A.C.M.

 This class is CC0.

 The Class works with an simple Kind of Sprites.
 You don't have to generate a Sprite, this will do the Function addFrame for you.

 The moveTo set's or move's the whole Animation to the given Coords. Is absolute true,
 moveTo sets directly the Animation to the Coords, else moveTo adds the Value to the
 last Position. You can give negative Values too.

 Reset() sets the Animation to the first Frame, but don't changes the Coords.
***************************************************************************************************************/

class Animation
{
    public:
        Animation(BITMAP* currentSheet, BITMAP* currentScreen);
        ~Animation();

        /*
        addFrame:
        SheetposX = Startposition X on the Spritesheet
        SheetposY = Startposition Y on the Spritesheet
        Width = Width in Pixel of the Frame
        Height = Height in Pixel of the Frame
        If you call this Function, the Transparency is by default on and the Speed is by default 0)
        */

        void addFrame(int SheetposX, int SheetposY, int Width, int Height);
        void addFrame(int SheetposX, int SheetposY, int Width, int Height, bool transparency);
        void addFrame(int SheetposX, int SheetposY, int Width, int Height, bool transparency, int spd);

        void deleteFrame(int Index);

        /*
        moveTo:
        Moves the whole Animation on the Screen
        if absolute = true: the Animation is moved to the Position X and Y on the Screen
        if absolute = false: the Values of X and Y will be added to the current X and Y Position of the Animation
        */

        void moveTo(int X, int Y, bool absolute);

        void reset();       // Set to the first Frame

        void drawFrame();   // draw the current Frame without an jumpt to the next Frame;

        void play();        // draws the Frame and increases to the next frame
        void playLoop();    // draws the Frames from begin to end and then from end to begin (loop)

        void setScreen(BITMAP* Screen);
        void setSheet(BITMAP* Sheet);

        /*
        setFramespeed:
        the next Frame will drawn after spd Frames
        */
        void setFramespeed(int Frame, int spd);

    protected:

    private:

        //void checkSpeed();

        BITMAP* currSheet;
        BITMAP* currScreen;

        std::vector<ASprite> Frames;
        std::vector<ASprite>::iterator Sprites;

        int posX;
        int posY;
        bool up;            // Directionflag
        int cnt;

}; // Animation

/**************************************************************************************************************
 Spriteclass to add
 needed for addFrame()
***************************************************************************************************************/

class ASprite
{
    public:
        ASprite(int SheetposX, int SheetposY, int Width, int Height, bool transparency, int spd);
        ~ASprite();

        void draw(BITMAP* Src, BITMAP* Dst, int X, int Y);
        void setSpeed(int Spd);
        int getSpeed();

    protected:
    private:

        int sheetposX;
        int sheetposY;
        int width;
        int height;
        bool transparent;
        int speed;

}; // ASprite


#endif // ANIMATION_H
