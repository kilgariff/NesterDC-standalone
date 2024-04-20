#include "types.h"
#include "nes.h"
#include "nes_mapper.h"
#include "030.h"

/////////////////////////////////////////////////////////////////////
// Mapper 2
void NES_mapper30::Reset()
{
  // set CPU bank pointers
  set_CPU_banks(0,1,num_8k_ROM_banks-2,num_8k_ROM_banks-1);
}

void NES_mapper30::MemoryWrite(uint32 addr, uint8 data)
{
  //data &= num_8k_ROM_banks-1;
  //set_CPU_banks(data*2,(data*2)+1,num_8k_ROM_banks-2,num_8k_ROM_banks-1);
  uint8 prg = data & 0x1f;
  uint8 chr = (data & 0x60) >> 5;

  prg &= num_8k_ROM_banks-1;
  set_CPU_banks(prg*2,(prg*2)+1,num_8k_ROM_banks-2,num_8k_ROM_banks-1);

  uint8 c = chr * 4;
  //set_PPU_banks(c + 0, c + 1, c + 2, c + 3, c + 4, c + 5, c + 6, c+ 7);
  //set_VRAM_bank0(0,0);

  if (c == 0) {
    set_VRAM_bank0(0, 0);
    set_VRAM_bank0(1, 1);
    set_VRAM_bank0(2, 2);
    set_VRAM_bank0(3, 3);

    ///// this works////
    set_VRAM_bank0(4, 4);
    set_VRAM_bank0(5, 5);
    set_VRAM_bank0(6, 6);
    set_VRAM_bank0(7, 7);
  } else {
    set_VRAM_bank0(0, 8);
    set_VRAM_bank0(1, 9);
    set_VRAM_bank0(2, 10);
    set_VRAM_bank0(3, 11);
    set_VRAM_bank0(4, 12);
    set_VRAM_bank0(5, 13);
    set_VRAM_bank0(6, 14);
    set_VRAM_bank0(7, 15);

    ///// this works////
    //set_VRAM_bank0(4, 8);
    //set_VRAM_bank0(5, 9);
    //set_VRAM_bank0(6, 10);
    //set_VRAM_bank0(7, 11);
  }


}
/////////////////////////////////////////////////////////////////////

