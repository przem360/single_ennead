#include "jaylib.h"
#include "utils.h"

void Jaylib::drawBand(uint8_t x, uint8_t y, const uint8_t * sprite, uint8_t cols, uint8_t color) {
    uint16_t s;
    uint16_t p = (y >> 3) * WIDTH + cols + x - 1;

    for(; cols --; p --) {
        s = pgm_read_byte(sprite + cols) << (y & 0x7);

        if(color) {
            sBuffer[p] |= s;
            sBuffer[p + WIDTH] |= s >> 8;
        } else {
            sBuffer[p] &=~ s;
            sBuffer[p + WIDTH] &= ~s >> 8;
        }
    }
}

void Jaylib::smallPrint(uint8_t x, uint8_t y, const uint8_t * str, uint8_t color) {
    char c;
    for(;c = *str ++;) {
        c -= 32;
        drawBand(x, y, PRINTABLE_CHARS + 3 * c, 3, color);
        x += 4;
    }
}

void Jaylib::largePrint(uint8_t x, uint8_t y, const uint8_t * str, uint8_t kern, uint8_t color) {
    char c;
    for(;c = *str ++;) {
        c &= 0x1F; // Lucky that SPACE % 32 == 0
        drawBand(x, y, PRINTABLE_CHARS_LARGE + 5 * c, 5, color);
        x += 5 + kern;
    }
}

void Jaylib::drawFastVLine(uint8_t x, uint8_t y, uint8_t h, uint8_t color) {
    uint8_t i;
    for(i = h; i --;)
        drawPixel(x, y + i, color);
}

void Jaylib::drawFastHLine(uint8_t x, uint8_t y, uint8_t w, uint8_t color) {
    uint8_t i;
    for(i = w; i --;)
        drawPixel(x + i, y, color);
}

void Jaylib::display() {
    counter ++;
    Arduboy2Base::display();
}
