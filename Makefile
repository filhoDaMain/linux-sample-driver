$(info Base Makefile called)

# For backwards compatibility with older Kbuild systems that
# won't call our Kbuild file automatically
ifneq ($(KERNELRELEASE),)
include Kbuild
else

# Kernel sources
KDIR ?= /lib/modules/`uname -r`/build

# Build directory
BUILD_DIR ?= $$PWD/build
BUILD_DIR_MAKEFILE ?= $(BUILD_DIR)/Makefile

default: $(BUILD_DIR_MAKEFILE)
	$(MAKE) -C $(KDIR) M=$(BUILD_DIR) src=$$PWD modules

$(BUILD_DIR):
	mkdir -p "$@"

$(BUILD_DIR_MAKEFILE): $(BUILD_DIR)
	touch "$@"

install:
	$(MAKE) -C $(KDIR) M=$(BUILD_DIR) src=$$PWD modules_install
	depmod -A

clean:
	$(MAKE) -C $(KDIR) M=$(BUILD_DIR) src=$$PWD clean
	rm -rf $(BUILD_DIR)

endif