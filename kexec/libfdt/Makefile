# Makefile.libfdt
#
# This is not a complete Makefile of itself.  Instead, it is designed to
# be easily embeddable into other systems of Makefiles.
#

LIBFDT_SRCS = kexec/libfdt/fdt.c kexec/libfdt/fdt_ro.c \
	kexec/libfdt/fdt_wip.c kexec/libfdt/fdt_sw.c \
	kexec/libfdt/fdt_rw.c kexec/libfdt/fdt_strerror.c

LIBFDT_OBJS = $(call objify, $(LIBFDT_SRCS))

FDT_LIB = libfdt.a

dist += kexec/libfdt/Makefile	$(LIBFDT_SRCS)	\
	kexec/libfdt/fdt.h kexec/libfdt/libfdt.h	\
	kexec/libfdt/libfdt_env.h			\
	kexec/libfdt/libfdt_internal.h
clean += $(LIBFDT_OBJS)  $(FDT_LIB)

$(FDT_LIB):$(LIBFDT_OBJS)
	@$(MKDIR) -p $(@D)
	$(AR) rs $(FDT_LIB) $(LIBFDT_OBJS)
