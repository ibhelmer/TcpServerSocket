// This software is part of OpenMono, see http://developer.openmono.com
// and is available under the MIT license, see LICENSE.txt

#include "text_label_view.h"
#include <string.h>
#include "consoles.h"

using namespace mono::ui;

TextLabelView::TextLabelView(String txt) :
    textColor(StandardTextColor),
    bgColor(StandardBackgroundColor)
{
    this->text = txt;
    this->setTextSize(1);
    
    viewRect.setSize( geo::Size(TextPixelWidth(), TextPixelHeight()) );
}

TextLabelView::TextLabelView(const char *txt) :
    textColor(StandardTextColor),
    bgColor(StandardBackgroundColor)
{
    this->text = txt;
    this->setTextSize(1);
    
    viewRect.setSize( geo::Size(TextPixelWidth(), TextPixelHeight()) );
}

TextLabelView::TextLabelView(geo::Rect rct, String txt) :
    View(rct),
    textColor(StandardTextColor),
    bgColor(StandardBackgroundColor)
{
    this->text = txt;
    this->setTextSize(2);
}

TextLabelView::TextLabelView(geo::Rect rct, const char *txt) :
    View(rct),
    textColor(StandardTextColor),
    bgColor(StandardBackgroundColor)
{
    this->text = txt;
    this->setTextSize(2);
}

// Getters
uint8_t TextLabelView::TextSize() const
{
    return textSize;
}

mono::display::Color TextLabelView::TextColor() const
{
    return textColor;
}

TextLabelView::TextAlignment TextLabelView::Alignment() const
{
    return alignment;
}

uint16_t TextLabelView::TextPixelWidth() const
{
    return text.Length()*5*TextSize()+TextSize()+1;
}

uint16_t TextLabelView::TextPixelHeight() const
{
    return 7*TextSize()+1;
}


// Setters
void TextLabelView::setTextSize(uint8_t newSize)
{
    textSize = newSize;
}

void TextLabelView::setTextColor(display::Color col)
{
    textColor = col;
}

void TextLabelView::setBackgroundColor(display::Color col)
{
    bgColor = col;
}

void TextLabelView::setAlignment(TextAlignment align)
{
    alignment = align;
}

void TextLabelView::setText(char *text, bool resizeViewWidth)
{
    this->setText(String(text), resizeViewWidth);
}

void TextLabelView::setText(const char *txt, bool resizeViewWidth)
{
    this->setText(String(txt), resizeViewWidth);
}

void TextLabelView::setText(mono::String text, bool resizeViewWidth)
{
    this->text = String(text);
    if (resizeViewWidth)
    {
        viewRect.setWidth(TextPixelWidth());
    }
    
    scheduleRepaint();
}


void TextLabelView::repaint()
{
    painter.setBackgroundColor(bgColor);
    View::painter.drawFillRect(this->viewRect.X(), viewRect.Y(), viewRect.Width(), viewRect.Height(), true);
    
    int cnt = 0;
    char c = text[cnt];
    mono::geo::Point offset = this->viewRect.Point();
    
    switch (alignment) {
        case ALIGN_RIGHT:
            offset.setX(viewRect.X() + viewRect.Width() - TextPixelWidth());
            break;
        case ALIGN_CENTER:
            if (TextPixelWidth() > viewRect.Width())
                break;
            offset.setX( viewRect.X() + ((viewRect.Width() / 2) - (TextPixelWidth() / 2)) );
            break;
        case ALIGN_LEFT:
        default:
            break;
    }
    
    View::painter.setTextSize(TextSize());
    painter.setForegroundColor(TextColor());
    
    while (c != '\0' && c != '\n' && offset.X()+TextSize()*5 < viewRect.X2()) {
        View::painter.drawChar(offset.X(), offset.Y(), c);
        offset.appendX(TextSize()*5+TextSize()-1);
        c = text[++cnt];
    }
}
