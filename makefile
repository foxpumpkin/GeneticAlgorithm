MAKE := make -C
QUICK := -j16
SRCDIR := src
MAINDIR := main
TEXDIR := latex
MD_MAIN := README.md
MD_DIR := ./markdown
MD_LS = $(shell ls $(MD_DIR)/*.md)
MD_LIST = $(MD_LS:%.md=master/%.md)
MD_LS2 = $(shell ls $(MD_DIR)/*.md | xargs -0 basename -a)
MD_LIST2 = $(MD_LS2:%.md=%.md)

small: src main
md: mdclear $(MD_LIST) mdupdate 
all: tex md small

mdclear:
	rm $(MD_MAIN)

%.md: 
	@echo `basename $@`
	@cat markdown/`basename $@` >> $(MD_MAIN)

tex: 
	$(MAKE) $(TEXDIR)

mdupdate:
	git add $(MD_MAIN)
	git commit -m "updating README.md"
	git push

src: FORCE
	@echo " + build libs"
	@$(MAKE) $(SRCDIR) $(QUICK)

main: FORCE
	@echo " + build excutable"
	@$(MAKE) $(MAINDIR) $(QUICK) -B

clean:
	@echo " + clean up"
	$(MAKE) $(TEXDIR) clean
	rm -rf lib/*.a *.out*

FORCE:
.FHONY: all clean FORCE
