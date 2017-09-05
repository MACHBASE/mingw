###############################################################################
# Copyright of this product 2013-2023,
# InfiniFlux Corporation(Incorporation) or its subsidiaries.
# All Rights reserved
###############################################################################
CC=gcc
LD_CC=gcc
CXX=g++
LD_CXX=g++
COMPILE.cxx=g++ -c -g -W -Wall -O3 -finline-functions -fno-omit-frame-pointer -fno-strict-aliasing -m64 -mtune=k8
COMPILE.cc=gcc -c -g -W -Wall -O3 -finline-functions -fno-omit-frame-pointer -fno-strict-aliasing -m64 -mtune=k8
DEF_OPT=-D
INC_OPT=-I
LIBDIR_OPT=-L
LIBDEF_OPT=
LIB_AFT=
LIB_OPT=-l
LD_LIBS=-lm -lpthread -Wl,-Bstatic -Wl,-Bdynamic
AR_OUT_OPT=
LD_OUT_OPT=-o
CC_OUT_OPT=-o
AR_FLAGS=-sruv
CXX_DEFINES=-D_POSIX_PTHREAD_SEMANTICS -D_POSIX_THREADS -D_POSIX_THREAD_SAFE_FUNCTIONS -D_REENTRANT -D_THREAD_SAFE -D_GNU_SOURCE -D_FILE_OFFSET_BITS=64
CC_DEFINES=-D_POSIX_PTHREAD_SEMANTICS -D_POSIX_THREADS -D_POSIX_THREAD_SAFE_FUNCTIONS -D_REENTRANT -D_THREAD_SAFE -D_GNU_SOURCE -D_FILE_OFFSET_BITS=64
CC_FLAGS=-g -W -Wall -O3 -finline-functions -fno-omit-frame-pointer -fno-strict-aliasing -m64 -mtune=k8
CXX_FLAGS=-g -W -Wall -O3 -finline-functions -fno-omit-frame-pointer -fno-strict-aliasing -m64 -mtune=k8 -fno-rtti -fno-exceptions
SO_FLAGS=-shared -static-libgcc -m64 -mtune=k8
LD_FLAGS= -m64 -mtune=k8
OBJ_SUF=.o
EXEC_SUF=
LIB_SUF=.a
LIB_PRE=lib
INCLUDES = $(INC_OPT)$(MACHBASE_HOME)\include $(INC_OPT).
LIBDIRS = $(LIBDIR_OPT)$(MACHBASE_HOME)\lib
LD_FLAGS += $(LIBDIRS)

%.$(OBJ_SUF): %.cpp
	$(COMPILE.cxx) $(INCLUDES) $(CC_OUT_OPT)$@ $<

%.$(OBJ_SUF): %.c
	$(COMPILE.cc) $(INCLUDES) $(CC_OUT_OPT)$@ $<

