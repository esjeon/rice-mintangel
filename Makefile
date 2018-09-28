
NAME = mintangel
PREFIX = $(HOME)/.local/

PARTS = dwm st dmenu

#
# Big targets
#

.PHONY: all clean install uninstall $(PARTS)

all: $(PARTS)

$(PARTS):
	@make -C $@

clean:
	@for part in $(PARTS); do \
		make -C $$part clean; \
	done

install:
	@mkdir -p "$(PREFIX)"
	@for part in $(PARTS); do \
		make -C $$part install PREFIX="$(PREFIX)"; \
	done
	@mkdir -p $(PREFIX)/share/backgrounds/
	@for image in background-*.jpg; do \
		cp -fv "$$image" "$(PREFIX)/share/backgrounds/$(NAME)-$${image}"; \
	done
	
uninstall:
	@for part in $(PARTS); do \
		make -C $$part uninstall PREFIX="$(PREFIX)"; \
	done
	@rm -v "$(PREFIX)/share/backgrounds/$(NAME)-background-"*.jpg


#
# Some random plumbing...
#

dwm: dwm/config.h
dwm/config.h: configs/dwm-config.h
	@ cp -v $< $@

st: st/config.h
st/config.h: configs/st-config.h
	@ cp -v $< $@

dmenu: dmenu/config.h
dmenu/config.h: configs/dmenu-config.h
	@ cp -v $< $@
