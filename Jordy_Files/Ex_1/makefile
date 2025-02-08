# Makefile for generating PDF from LaTeX source

SOURCE = Feynmann.tex

OUTPUT = Feynmann.pdf

LATEX = pdflatex

LATEX_FLAGS = 

all: $(OUTPUT)

$(OUTPUT): $(SOURCE)
	$(LATEX) $(LATEX_FLAGS) $<
	$(LATEX) $(LATEX_FLAGS) $<

clean:
	rm -f *.aux *.log *.out *.toc

distclean: clean
	rm -f $(OUTPUT)
