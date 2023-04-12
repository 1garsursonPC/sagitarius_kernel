#############################################################
################## CONFIGURATION VARIABLES ##################
#############################################################

NAME ?= kernel.elf

# escape charcacter for sed ! (for OBJDIR)
SRCDIR ?= sources
HDRDIR ?= headers
OBJDIR ?= objects
DEPDIR ?= dependencies
# LIMDIR : limine binary release folder
LIMDIR ?= ../limine/

CC := x86_64-elf-gcc
CFLAGS += \
	-std=gnu18 \
	-ffreestanding \
	-fno-stack-protector \
	-fno-stack-check \
	-fno-lto \
	-fno-pie \
	-fno-pic \
	-m64 \
	-march=x86-64 \
	-mabi=sysv \
	-mno-80387 \
	-mno-mmx \
	-mno-sse \
	-mno-sse2 \
	-mno-red-zone \
	-mcmodel=kernel
CPPFLAGS += -O2 -pipe -Wall -Wextra

AS := x86_64-elf-as
ASFLAGS +=

LD := x86_64-elf-ld
LDFLAGS += \
	-nostdlib \
	-static \
	-m elf_x86_64 \
	-z max-page-size=0x1000 \
	-T $(SRCDIR)/linker.ld
LDLIBS +=


#############################################################
#################### INTERNAL VARIABLES #####################
#############################################################

SRCFILES := $(shell find -L $(SRCDIR) -type f -name '*.c' -printf '%f ')

DEPFILES := $(SRCFILES:%.c=$(DEPDIR)/%.d)
OBJFILES := $(SRCFILES:%.c=$(OBJDIR)/%.o)
# SRCFILES := $(addprefix $(SRCDIR)/,$(SRCFILES)) : not used elsewhere

HDRFILES := $(shell find -L $(HDRDIR) -type f -name '*.h' -printf '%f ')
HDRFILES := $(HDRFILES:%.h=$(HDRDIR)/%.h)

CFLAGS += -I $(LIMDIR)


#############################################################
######################### TARGETS ###########################
#############################################################

.PHONY: clean
.DELETE_ON_ERROR:

$(NAME): $(OBJFILES) # default goal
	$(LD) $(LDFLAGS) $(LOADLIBES) $(LDLIBS) $(OBJFILES) -o $@

clean:
	$(RM) -r $(OBJDIR)
	$(RM) -r $(DEPDIR)
	$(RM) $(NAME)


#############################################################
####################### PATTERN RULE ########################
#############################################################

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(HDRDIR)/ -c $< -o $@

$(DEPDIR)/%.d: $(SRCDIR)/%.c
	@echo "$(CC) $(CFLAGS) $(CPPFLAGS) -I $(HDRDIR)/ -MM $< > $@"
	@mkdir -p $(dir $@)
	@set -e; $(RM) $@; \
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(HDRDIR)/ -MM $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(OBJDIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$


#############################################################
######################### INCLUDES ##########################
#############################################################

# if the an include contain targets of its own,
# it must be after the first target (default goal)
include $(DEPFILES)
