MAKE := make -C
QUICK := -j16
SRCDIR := src
MAINDIR := main
MD_MAIN := README.md
MD_DIR := ./markdown
MD_LS = $(shell ls $(MD_DIR)/*.md | xargs -0 -n1 basename )
MD_LIST = $(MD_LS:%.md=%.md)

small: src main

all: mdclear $(MD_LIST) small

mdclear:
	rm $(MD_MAIN)

%.md: 
	cat ./markdown/$@ >> $(MD_MAIN)
	doxygen

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
