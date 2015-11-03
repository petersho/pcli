LIBDIRS  = $(shell find . -type d)

all:
	@for dir in $(LIBDIRS) ; do `cat $$dir/lib.conf >> ../config.mk` ; done

clean:
