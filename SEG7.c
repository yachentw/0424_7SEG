
#include "system.h"
#include "alt_types.h"
#include "io.h"
#include "SEG7.h"


#define SEG7_NUM 4

static alt_u32 seg7_mask[] = {
	0xFFFFFF00,0xFFFF00FF,0xFF00FFFF,0xFFFFFF
};

static unsigned char szMap[] = {
  63, 6, 91, 79, 102, 109, 125, 7,
  127, 111, 119, 124, 57, 94, 121, 113
};  // 0,1,2,....9, a, b, c, d, e, f

void SEG7_SET(int index, alt_u32 seg_mask){
	implement here ***
}

void SEG7_Clear(void) {
  int i;

  for(i=0; i<SEG7_NUM; i++)
    SEG7_SET(i, 0x00);
}

void SEG7_Full(void) {
  int i;
  for(i=0; i<SEG7_NUM; i++){
    SEG7_SET(i, 0xFF);
  }
}

void SEG7_Number(void) {
  int i;

  implement here ***
}

void SEG7_Hex(alt_u32 Data, alt_u8 point_mask) {
  alt_u8 mask = 0x01;
  alt_u8 seg_mask;
  int i;

  seg_mask = 0;
  for(i = 0; i < SEG7_NUM; i++) {
    seg_mask = szMap[Data & 0x0F];
    Data >>= 4;

    if (point_mask & mask)
      seg_mask |= 0x80;

    mask <<= 1;
    SEG7_SET(i, seg_mask);
  }
}

void SEG7_Decimal(alt_u32 Data, alt_u8 point_mask) {
  alt_u8 mask = 0x01;
  alt_u8 seg_mask;
  int i;
  seg_mask = 0;

  implement here ***
}
