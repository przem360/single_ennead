#pragma once

#include "card.h"

#define CC(a1,a2,a3,a4,a5,a6,a7,a8,e,s,n) \
    {{0x##a1,0x##a2,0x##a3,0x##a4,0x##a5,0x##a6,0x##a7,0x##a8},0x##e,0x##s,n}

PROGMEM const Card CARDS [] = {
    CC(38,47,82,84,84,82,47,38, 24,1234, "Cat"),
    CC(76,89,8d,81,8e,81,4d,32, 25,567A, "Bunny"),
    CC(38,44,82,81,81,87,49,32, 24,89AA, "Water Sprite"),
    CC(77,89,c2,c4,84,82,49,37, 24,1111, "Dingo"),
    CC(1c,22,e1,a1,a1,e1,22,1c, 23,2327, "Mushroom"),
    CC(b8,c4,44,44,c4,59,e3,3e, 14,4734, "Scorpion"),
    CC(fc,42,81,41,81,41,82,fc, 23,8888, "Ghost"),
    CC(38,44,82,81,81,81,42,3c, 24,1214, "Slime"),
    CC(7b,c5,c2,84,44,32,0d,03, 14,5538, "Jackal"),


    CC(00,00,00,00,00,00,00,00, 00,0000, "")
};
