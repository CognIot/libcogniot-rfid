# Specify extensions of files to delete when cleaning
CLEANEXTS   = o a 

# Specify the target file and the install directory
OUTPUTFILE  = libcogniot-rfid.a
INSTALLDIR  = ./bin

# Default target
.PHONY: all
all: $(OUTPUTFILE)



# Build CognIoT API library from source

$(OUTPUTFILE): src/GetCmdResult.o src/SendCmds.o src/SetTagMode.o src/WaitForCTS.o
	ar crv $@ $^
	ranlib $@

# No rule to build .o files from .c files is required; 
# this is handled by make's database of implicit rules

.PHONY: install
install:
	mkdir -p $(INSTALLDIR)
	cp -p $(OUTPUTFILE) $(INSTALLDIR)

.PHONY: clean 
clean:
	for file in $(CLEANEXTS); do rm -f *.$$file; done

# Indicate dependencies of .ccp files on .hpp files
src/GetCmdResult.o: include/CognIoT-RFID.h
src/SendCmds.o: include/CognIoT-RFID.h
src/SetTagMode.o: include/CognIoT-RFID.h
src/WaitForCTS.o: include/CognIoT-RFID.h
