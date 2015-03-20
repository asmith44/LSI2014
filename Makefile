PROJECT=LSIPaper2014
TEX=pdflatex
BIBTEX=bibtex
BUILDTEX=$(TEX) $(PROJECT).tex

.SUFFIXES: .pdf .png .ps
PDFIMAGES=$(wildcard Fig*.pdf)
PSIMAGES=$(wildcard *.ps)
PNGIMAGES=$(PDFIMAGES:.pdf=.png) $(PSIMAGES:.ps=.png)

all:	convert tex

tex:
	$(BUILDTEX)
	$(BIBTEX) $(PROJECT)
	$(BUILDTEX)
	$(BUILDTEX)

convert:	$(PNGIMAGES)

.pdf.png:
	@echo converting $< to $@ using ImageMagick
	@convert $< $@
	@echo conversion to $@ successful!
	@echo linking $<
	@ln -sf $@

.ps.png:
	@echo converting $< to $@ using ImageMagick
	@convert $< $@
	@echo conversion to $@ successful!
	@echo linking $<
	@ln -sf $@


clean-all:
	rm -f *.dvi *.log *.bak *.aux *.bbl *.blg *.idx *.ps *.eps *.pdf *.toc *.out *~

clean:
	rm -f *.log *.bak *.aux *.bbl *.blg *.idx *.toc *.out *~

clean-convert:
	rm -rf $(PNGIMAGES)