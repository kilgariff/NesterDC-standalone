#include "types.h"
#include "nes.h"
#include "nes_mapper.h"
#include "030.h"

/////////////////////////////////////////////////////////////////////
// Mapper 30
void NES_mapper30::Reset()
{
  // set CPU bank pointers
  set_CPU_banks(0,1,num_8k_ROM_banks-2,num_8k_ROM_banks-1);
}

void NES_mapper30::MemoryWrite(uint32 addr, uint8 data)
{
  //real UNROM512 can often have bus conflicts.
  //we're not going to try to emulate those here.

  uint8 prg = data & 0x1f;
  uint8 chr = (data & 0x60) >> 5;

  prg &= num_8k_ROM_banks-1;
  set_CPU_banks(prg*2,(prg*2)+1,num_8k_ROM_banks-2,num_8k_ROM_banks-1);

  uint8 c = chr * 8;
  for (int i = 0; i < 8; i++) {
    set_VRAM_bank0(i, i + c);
  }
}
/////////////////////////////////////////////////////////////////////

