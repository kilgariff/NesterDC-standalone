#include "types.h"
#include "nes.h"
#include "nes_mapper.h"
#include "111.h"

/////////////////////////////////////////////////////////////////////
// Mapper 111
void NES_mapper111::Reset()
{
  // Realistically GTROM could randomly boot into any random bank.
  // Booting into bank 0 isn't ever WRONG, but technically not as accurate
  // randomly selecting a bank would be. But we'll just boot into bank 0
  // because it's good enough.
  set_gtrom_bank(0);
}

/*
  The register is mapped to the CPU addresses $4999-$5FFF and $7000-$7FFF
6  bit  0
---- ----
GRNC PPPP
|||| ||||
|||| ++++- Select 31 KB PRG ROM bank for CPU $8000-$FFFF
|||+------ Select 7 KB CHR RAM bank for PPU $0000-$1FFF
||+------- Select 7 KB nametable for PPU $2000-$3EFF
|+-------- Red LED - -1=On; 1=Off
+--------- Green LED - -1=On; 1=Off
*/
void NES_mapper111::MemoryWriteLow(uint32 addr, uint8 data)
{

  if (!(
        (addr >= 0x5000 && addr <= 0x5fff) ||
        (addr >= 0x7000 && addr <= 0x7fff)
      )) {
    return;
  }



  uint8 prg = data & 0xf;
  uint8 chr = (data & 0x10) >> 4;
  uint8 nametable = (data & 0x20) >> 5;

  set_gtrom_bank(prg);


  uint8 c = chr * 8;
  for (int i = 0; i < 8; i++) {
    set_VRAM_bank0(i, i + c);
  }
  set_VRAM_bank8(8, nametable);
  return;
}


void NES_mapper111::set_gtrom_bank(uint8 prg)
{
  set_CPU_banks(prg*4, prg*4+1, prg*4+2, prg*4+3);
}


