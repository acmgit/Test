#ifndef BAR_H
#define BAR_H

#include <allegro/gfx.h>
#include <allegro/draw.h>

/**************************************************************************************************************
 Barclass depend on Allegro 4.
 (?) by A.C.M.

 This class is CC0.

 Height is the maximum Value in Pixel for the Bar and is 100%.
 Width is the Size on the Bar
 PosX and PosY are the Coords on the Food of the Bar, which grows up.
 Same horizontally, the Bar grows from left to right.
***************************************************************************************************************/


class Bar
{
    public:
        Bar(BITMAP* Screen, int PosX, int PosY, int Width, int Height, int Color, bool vertical);
        virtual ~Bar();
        virtual void draw();

        void setPercent(int percentage);
        void setOrientation(bool vertical); // True when the Bar grows up, else the Bar grows from left to right.
        void setColor(int Color);

    protected:

        int calcHeight();

        BITMAP *currScreen;

        bool isVertical;

        int percent;

        int Pos_X;
        int Pos_Y;
        int width;
        int height;

        int currColor;

    private:
};

#endif // BAR_H
