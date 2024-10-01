STARTUP = $(KOS_BASE)/kernel/arch/dreamcast/kernel/startup.o
NESTERDC_LIBS = -L$(KOS_BASE)/lib -lkallisti -L$(BZ_BASE) -lbz2 -L${KOS_CC_BASE}/../newlibc_hack
NESTERDC_LIBS += -lsupc++ -lm -lnewlibc -lgcc

all:
	$(KOS_MAKE) -C utils 
	$(KOS_MAKE) -C $(BZ_BASE)
	$(KOS_MAKE) -C $(KOS_BASE)
	$(KOS_MAKE) -C $(NESTER_BASE) -f Makefile.dreamcast 
	$(KOS_CCPLUS) $(KOS_CPPFLAGS) $(KOS_LDFLAGS) -o obj/nester.elf $(STARTUP) $(NESTER_OBJ)/*.o $(NESTERDC_LIBS)
	$(KOS_STRIP) -o obj/nester-strip.elf obj/nester.elf

build:
	rsync -avPI ./ ross@dc-build:/home/ross/Desktop/NesterDC || fail
	ssh -t ross@dc-build "cd /home/ross/Desktop/NesterDC && ./dcmake && ./dcmake 1ST_READ.BIN" || fail
	rm -f sword.iso sword.cdi
	rsync -avPI ross@dc-build:/home/ross/Desktop/NesterDC/obj/1ST_READ.BIN disc/cd || fail
	mkisofs -V sword -G disc/IP.BIN -l -r -o sword.iso disc/cd
	cdi4dc sword.iso sword.cdi -d
	

test:
	/home/tolbert/opt/redream sword.cdi



#

clean: 
	-rm -f obj/*
	$(KOS_MAKE) -C utils clean
	$(KOS_MAKE) -C $(BZ_BASE) clean
	$(KOS_MAKE) -C $(KOS_BASE) clean 
	$(KOS_MAKE) -C $(NESTER_BASE) -f Makefile.dreamcast clean 

install:
	tcpcat -h yuri:4711 obj/nester-strip.elf

devel:
	$(KOS_MAKE) -C $(NESTER_BASE) -f Makefile.dreamcast clean
	$(KOS_MAKE) all

makeasm: disasm
	$(NDC_BASE)/utils/asmfilter/asmfilter < disasm > asm

disasm: force
	$(KOS_OBJDUMP) -D obj/nester.elf > disasm

1ST_READ.BIN: 
	$(KOS_OBJCOPY) -O binary obj/nester-strip.elf obj/nester.bin
	$(NDC_BASE)/utils/scramble/scramble obj/nester.bin obj/1ST_READ.BIN

force: 

