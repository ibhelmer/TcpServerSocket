// This software is part of OpenMono, see http://developer.openmono.com
// Released under the MIT license, see LICENSE.txt

#include "display_painter.h"
#include "glcdfont.h"

using namespace mono::display;

DisplayPainter::DisplayPainter(IDisplayController *dispctrl) : foregroundColor(WetAsphaltColor), backgroundColor(CloudsColor)
{
    displayCtrl = dispctrl;

//    if (displayCtrl != NULL)
//        displayCtrl->AddRefreshCallback(&displayRefreshHandler);
    displayCtrl->setRefreshHandler(&displayRefreshHandler);
    lineWidth = 1;
    textSize = 1;
}

DisplayPainter::~DisplayPainter()
{
//    if (displayCtrl != NULL)
//        displayCtrl->RemoveRefreshCallback(&displayRefreshHandler);
}

void DisplayPainter::setForegroundColor(Color color)
{
    foregroundColor = color;
}

void DisplayPainter::setBackgroundColor(Color color)
{
    backgroundColor = color;
}

uint8_t DisplayPainter::LineWidth() const
{
    return lineWidth;
}

void DisplayPainter::setLineWidth(uint8_t w)
{
    lineWidth = w;
}

uint8_t DisplayPainter::TextSize() const
{
    return textSize;
}

void DisplayPainter::setTextSize(uint8_t size)
{
    textSize = size;
}

uint16_t DisplayPainter::CanvasWidth() const
{
    return displayCtrl->ScreenWidth();
}

uint16_t DisplayPainter::CanvasHeight() const
{
    return displayCtrl->ScreenHeight();
}

IDisplayController* DisplayPainter::DisplayController() const
{
    return displayCtrl;
}

// MARK: Draw methods

void DisplayPainter::drawPixel(uint16_t x, uint16_t y, bool bg)
{
    displayCtrl->setWindow(x, y, 1, 1);
    displayCtrl->write(bg ? backgroundColor : foregroundColor);
}

void DisplayPainter::drawPixel(geo::Point const &pos, bool background)
{
    drawPixel(pos.X(), pos.Y(), background);
}

void DisplayPainter::drawRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool bg)
{
    drawVLine(x, y, y+height, bg);
    drawVLine(x+width, y, y+height, bg);
    drawHLine(x, x+width, y, bg);
    drawHLine(x, x+width, y+height, bg);
}

void DisplayPainter::drawRect(geo::Rect const &rct, bool background)
{
    drawRect(rct.X(), rct.Y(), rct.Width(), rct.Height(), background);
}

void DisplayPainter::drawFillRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bool bg)
{
    displayCtrl->setWindow(x, y, width, height);
    //displayCtrl->setCursor(x, y);

    Color color = bg ? backgroundColor : foregroundColor;
    uint32_t size = width*height;
    for (uint32_t i=0; i<size; i++) {
        displayCtrl->write(color);
    }
}

void DisplayPainter::drawFillRect(geo::Rect const &rct, bool background)
{
    drawFillRect(rct.X(), rct.Y(), rct.Width(), rct.Height(), background);
}

void DisplayPainter::drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, bool bg)
{
    //use VLine or HLine if possible
    if (x0==x1)
        return drawVLine(x0, y0, y1, bg);
    else if (y0==y1)
        return drawHLine(x0, x1, y0, bg);

    // Use Bresenham's
    int16_t steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        swap(x0, y0);
        swap(x1, y1);
    }

    if (x0 > x1) {
        swap(x0, x1);
        swap(y0, y1);
    }

    int16_t dx, dy;
    dx = x1 - x0;
    dy = abs(y1 - y0);

    int16_t err = dx / 2;
    int16_t ystep;

    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (; x0<=x1; x0++) {
        if (steep) {
            drawPixel(y0, x0, bg);
        } else {
            drawPixel(x0, y0, bg);
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
}

void DisplayPainter::drawLine(geo::Point const &from, geo::Point const &to, bool background)
{
    drawLine(from.X(), from.Y(), to.X(), to.Y(), background);
}


void DisplayPainter::drawChar(uint16_t x, uint16_t y, char character)
{
    if((x >= displayCtrl->ScreenWidth())    || // Clip right
       (y >= displayCtrl->ScreenHeight())   || // Clip bottom
       ((x + 6 * textSize - 1) < 0)         || // Clip left
       ((y + 8 * textSize - 1) < 0))           // Clip top
        return;


    for (int8_t i=0; i<6; i++ ) {
        uint8_t line;

        if (i == 5)
            line = 0x0;
        else
            line = *(font+(character*5)+i);

        // only relevant for textSize = 1
        this->displayCtrl->setWindow(x+i, y, 1, 8);

        for (int8_t j = 0; j<8; j++) {

            if (line & 0x1) {
                if (textSize == 1) // default size
                    displayCtrl->write(foregroundColor);
                    //drawPixel(x+i, y+j);
                else {  // big size
                    drawFillRect(x+(i*textSize), y+(j*textSize), textSize, textSize);
                }
            } else if (backgroundColor != foregroundColor) {
                if (textSize == 1) // default size
                    displayCtrl->write(backgroundColor);
                    //drawPixel(x+i, y+j, true);
                else {  // big size
                    drawFillRect(x+i*textSize, y+j*textSize, textSize, textSize, true);
                }
            }

            line >>= 1;
        }
    }
}

void DisplayPainter::drawVLine(uint16_t x, uint16_t y1, uint16_t y2, bool bg)
{
    if (y1 > y2)
        swap(y1, y2);

    displayCtrl->setWindow(x, y1, 1, y2-y1);
    for (int i=0; i<y2-y1; i++)
    {
        displayCtrl->write(bg ? backgroundColor : foregroundColor);
    }
}

void DisplayPainter::drawHLine(uint16_t x1, uint16_t x2, uint16_t y, bool bg)
{
    if (x1 > x2)
        swap(x1, x2);

    displayCtrl->setWindow(x1, y, x2-x1, 1);
    for (int i=0; i<x2-x1; i++)
    {
        displayCtrl->write(bg ? backgroundColor : foregroundColor);
    }
}

void DisplayPainter::drawCircle(uint16_t x0, uint16_t y0, uint16_t r, bool color)
{
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    drawPixel(x0  , y0+r, color);
    drawPixel(x0  , y0-r, color);
    drawPixel(x0+r, y0  , color);
    drawPixel(x0-r, y0  , color);

    while (x<y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        drawPixel(x0 + x, y0 + y, color);
        drawPixel(x0 - x, y0 + y, color);
        drawPixel(x0 + x, y0 - y, color);
        drawPixel(x0 - x, y0 - y, color);
        drawPixel(x0 + y, y0 + x, color);
        drawPixel(x0 - y, y0 + x, color);
        drawPixel(x0 + y, y0 - x, color);
        drawPixel(x0 - y, y0 - x, color);
    }
}

void DisplayPainter::drawCircle(geo::Circle const &circle, bool bg)
{
    drawCircle(circle.X(), circle.Y(), circle.Radius(), bg);
}

void DisplayPainter::drawFillCircle(uint16_t x0, uint16_t y0, uint16_t r, bool color)
{
    drawVLine(x0, y0-r, y0-r+2*r+1, color);
    fillCircleHelper(x0, y0, r, 3, 0, color);
}

void DisplayPainter::drawFillCircle(geo::Circle const &circle, bool bg)
{
    drawFillCircle(circle.X(), circle.Y(), circle.Radius(), bg);
}

void DisplayPainter::fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, bool color)
{
    int16_t f     = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x     = 0;
    int16_t y     = r;

    while (x<y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f     += ddF_y;
        }
        x++;
        ddF_x += 2;
        f     += ddF_x;

        if (cornername & 0x1) {
            drawVLine(x0+x, y0-y, y0-y+2*y+1+delta, color);
            drawVLine(x0+y, y0-x, y0-x+2*x+1+delta, color);
        }
        if (cornername & 0x2) {
            drawVLine(x0-x, y0-y, y0-y+2*y+1+delta, color);
            drawVLine(x0-y, y0-x, y0-x+2*x+1+delta, color);
        }
    }
}


void DisplayPainter::swap(uint16_t &a, uint16_t &b)
{
    uint16_t t = a;
    a = b;
    b = t;
}

int16_t DisplayPainter::abs(int16_t a)
{
    return a<0 ? -a : a;
}
