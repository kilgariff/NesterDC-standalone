/* this file is generated by makemisc */

#include "nester.h"
#include "nes.h"
#include "nes_mapper.h"
#include "nes_mapper_all.h"

NES_mapper*
GetMapper(int mapper_num)
{
  switch(mapper_num) {
  case 0:
    return new NES_mapper0();

  case 1:
    return new NES_mapper1();

  case 2:
    return new NES_mapper2();

  case 3:
    return new NES_mapper3();

  case 4:
    return new NES_mapper4();

  case 5:
    return new NES_mapper5();

  case 6:
    return new NES_mapper6();

  case 7:
    return new NES_mapper7();

  case 8:
    return new NES_mapper8();

  case 9:
    return new NES_mapper9();

  case 10:
    return new NES_mapper10();

  case 11:
    return new NES_mapper11();

  case 13:
    return new NES_mapper13();

  case 15:
    return new NES_mapper15();

  case 16:
    return new NES_mapper16();

  case 17:
    return new NES_mapper17();

  case 18:
    return new NES_mapper18();

  case 19:
    return new NES_mapper19();

  case 20:
    return new NES_mapper20();

  case 21:
    return new NES_mapper21();

  case 22:
    return new NES_mapper22();

  case 23:
    return new NES_mapper23();

  case 24:
    return new NES_mapper24();

  case 25:
    return new NES_mapper25();

  case 26:
    return new NES_mapper26();

  case 30:
    return new NES_mapper30();

  case 32:
    return new NES_mapper32();

  case 33:
    return new NES_mapper33();

  case 34:
    return new NES_mapper34();

  case 40:
    return new NES_mapper40();

  case 41:
    return new NES_mapper41();

  case 42:
    return new NES_mapper42();

  case 43:
    return new NES_mapper43();

  case 44:
    return new NES_mapper44();

  case 45:
    return new NES_mapper45();

  case 46:
    return new NES_mapper46();

  case 47:
    return new NES_mapper47();

  case 48:
    return new NES_mapper48();

  case 49:
    return new NES_mapper49();

  case 50:
    return new NES_mapper50();

  case 51:
    return new NES_mapper51();

  case 52:
    return new NES_mapper52();

  case 57:
    return new NES_mapper57();

  case 58:
    return new NES_mapper58();

  case 60:
    return new NES_mapper60();

  case 64:
    return new NES_mapper64();

  case 65:
    return new NES_mapper65();

  case 66:
    return new NES_mapper66();

  case 67:
    return new NES_mapper67();

  case 68:
    return new NES_mapper68();

  case 69:
    return new NES_mapper69();

  case 70:
    return new NES_mapper70();

  case 71:
    return new NES_mapper71();

  case 72:
    return new NES_mapper72();

  case 73:
    return new NES_mapper73();

  case 75:
    return new NES_mapper75();

  case 76:
    return new NES_mapper76();

  case 77:
    return new NES_mapper77();

  case 78:
    return new NES_mapper78();

  case 79:
    return new NES_mapper79();

  case 80:
    return new NES_mapper80();

  case 82:
    return new NES_mapper82();

  case 83:
    return new NES_mapper83();

  case 85:
    return new NES_mapper85();

  case 86:
    return new NES_mapper86();

  case 87:
    return new NES_mapper87();

  case 88:
    return new NES_mapper88();

  case 89:
    return new NES_mapper89();

  case 90:
    return new NES_mapper90();

  case 91:
    return new NES_mapper91();

  case 92:
    return new NES_mapper92();

  case 93:
    return new NES_mapper93();

  case 94:
    return new NES_mapper94();

  case 95:
    return new NES_mapper95();

  case 96:
    return new NES_mapper96();

  case 97:
    return new NES_mapper97();

  case 99:
    return new NES_mapper99();

  case 100:
    return new NES_mapper100();

  case 101:
    return new NES_mapper101();

  case 105:
    return new NES_mapper105();

  case 111:
    return new NES_mapper111();

  case 112:
    return new NES_mapper112();

  case 113:
    return new NES_mapper113();

  case 117:
    return new NES_mapper117();

  case 118:
    return new NES_mapper118();

  case 119:
    return new NES_mapper119();

  case 122:
    return new NES_mapper122();

  case 151:
    return new NES_mapper151();

  case 160:
    return new NES_mapper160();

  case 180:
    return new NES_mapper180();

  case 181:
    return new NES_mapper181();

  case 182:
    return new NES_mapper182();

  case 183:
    return new NES_mapper183();

  case 185:
    return new NES_mapper185();

  case 187:
    return new NES_mapper187();

  case 188:
    return new NES_mapper188();

  case 189:
    return new NES_mapper189();

  case 225:
    return new NES_mapper225();

  case 226:
    return new NES_mapper226();

  case 227:
    return new NES_mapper227();

  case 228:
    return new NES_mapper228();

  case 229:
    return new NES_mapper229();

  case 230:
    return new NES_mapper230();

  case 231:
    return new NES_mapper231();

  case 232:
    return new NES_mapper232();

  case 233:
    return new NES_mapper233();

  case 234:
    return new NES_mapper234();

  case 235:
    return new NES_mapper235();

  case 236:
    return new NES_mapper236();

  case 237:
    return new NES_mapper237();

  case 240:
    return new NES_mapper240();

  case 242:
    return new NES_mapper242();

  case 243:
    return new NES_mapper243();

  case 245:
    return new NES_mapper245();

  case 246:
    return new NES_mapper246();

  case 248:
    return new NES_mapper248();

  case 255:
    return new NES_mapper255();

#if 0
  case 12:
    return new NES_mapperNSF();
#endif

  case 184:
    return new NES_mapper122();

  default:
    ERROR("unsupported mapper");
    return NULL;  // mapper not supported
  }
}
