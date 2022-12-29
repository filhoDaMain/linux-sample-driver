$(info Base Kbuild called)

# Module name
obj-m  := hellow.o

# Include directories (Kbuild system also includes kernel include dirs).
# NOTE: Include dirs must be specified with absolute path using $(src) which
# points to this Kbuild file path!
ccflags-y := -I$(src)/include

# Source Files
hellow-y := source/hello1.o
hellow-y += source/basicmath/add.o