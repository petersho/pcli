DIRS  = $(shell find ./cmdlib/ -type d)

all: subdirs
	$(MAKE) -f Makefile.build

subdirs:
	rm -f config.mk
	touch config.mk
	@for dir in $(DIRS) ; do $(MAKE) -C $$dir || exit 1 ; done

lib:

clean:
	rm -f *.o pcli config.mk
	@for dir in $(DIRS) ; do $(MAKE) clean -C $$dir || exit 1 ; done
