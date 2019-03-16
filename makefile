MAKE := make -C
QUICK := -j16
SRCDIR := src
MAINDIR := main
all: src main

src: FORCE
	@echo " + build libs"
	@$(MAKE) $(SRCDIR) $(QUICK)

main: FORCE
	@echo " + build excutable"
	@$(MAKE) $(MAINDIR) $(QUICK) -B

clean:
	@echo " + clean up"
	rm -rf lib/*.a *.out*

FORCE:
.FHONY: all clean FORCE
