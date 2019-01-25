# Catch default rule in case no one as been defined in the including 
# Makefile before the inclusion of Makefile.inc

catch_makefile_inc:

# Root dir of the repositories

ROOT_DIR=/home/bayashi/GitHub

# Compiler arguments depending on BUILD_MODE

ifeq ($(BUILD_MODE), 0)
	BUILD_ARG=-Wall -Wextra -Og -ggdb -g3 -DPBERRALL='1' \
	  -DBUILDMODE=$(BUILD_MODE)
	LINK_ARG=-rdynamic
else 
  ifeq ($(BUILD_MODE), 1)
	  BUILD_ARG=-Wall -Wextra -Werror -Wfatal-errors -O3 \
		  -DPBERRSAFEMALLOC='1' -DPBERRSAFEIO='1' -DBUILDMODE=$(BUILD_MODE)
	  LINK_ARG=-rdynamic
  else 
    ifeq ($(BUILD_MODE), 2)
	    BUILD_ARG=-Wall -Wextra -Werror -Wfatal-errors -O3 \
		    -DBUILDMODE=$(BUILD_MODE)
	    LINK_ARG=
		endif
	endif
endif

# Compiler

COMPILER=gcc

# Cleaning rule

clean:
	rm -f main *.o

# Valgrind rule

valgrind :
	valgrind -v --track-origins=yes --leak-check=full \
	--gen-suppressions=yes --show-leak-kinds=all ./main

# Make the documentation

latex:
	cd Doc; pdflatex -synctex=1 -interaction=nonstopmode -shell-escape  doc.tex; cd ..

# Definition of Wget rules
pberr_wget:
	if [ ! -d $(ROOT_DIR)/PBErr ]; then wget https://github.com/BayashiPascal/PBErr/archive/master.zip; unzip master.zip; rm -f master.zip; mv PBErr-master $(ROOT_DIR)/PBErr; fi
gset_wget:
	if [ ! -d $(ROOT_DIR)/GSet ]; then wget https://github.com/BayashiPascal/GSet/archive/master.zip; unzip master.zip; rm -f master.zip; mv GSet-master $(ROOT_DIR)/GSet; fi
gtree_wget:
	if [ ! -d $(ROOT_DIR)/GTree ]; then wget https://github.com/BayashiPascal/GTree/archive/master.zip; unzip master.zip; rm -f master.zip; mv GTree-master $(ROOT_DIR)/GTree; fi
pbjson_wget:
	if [ ! -d $(ROOT_DIR)/PBJson ]; then wget https://github.com/BayashiPascal/PBJson/archive/master.zip; unzip master.zip; rm -f master.zip; mv PBJson-master $(ROOT_DIR)/PBJson; fi
pbmath_wget:
	if [ ! -d $(ROOT_DIR)/PBMath ]; then wget https://github.com/BayashiPascal/PBMath/archive/master.zip; unzip master.zip; rm -f master.zip; mv PBMath-master $(ROOT_DIR)/PBMath; fi
bcurve_wget:
	if [ ! -d $(ROOT_DIR)/BCurve ]; then wget https://github.com/BayashiPascal/BCurve/archive/master.zip; unzip master.zip; rm -f master.zip; mv BCurve-master $(ROOT_DIR)/BCurve; fi
shapoid_wget:
	if [ ! -d $(ROOT_DIR)/Shapoid ]; then wget https://github.com/BayashiPascal/Shapoid/archive/master.zip; unzip master.zip; rm -f master.zip; mv Shapoid-master $(ROOT_DIR)/Shapoid; fi
pbphys_wget:
	if [ ! -d $(ROOT_DIR)/PBPhys ]; then wget https://github.com/BayashiPascal/PBPhys/archive/master.zip; unzip master.zip; rm -f master.zip; mv PBPhys-master $(ROOT_DIR)/PBPhys; fi
grad_wget:
	if [ ! -d $(ROOT_DIR)/Grad ]; then wget https://github.com/BayashiPascal/Grad/archive/master.zip; unzip master.zip; rm -f master.zip; mv Grad-master $(ROOT_DIR)/Grad; fi
knapsack_wget:
	if [ ! -d $(ROOT_DIR)/KnapSack ]; then wget https://github.com/BayashiPascal/KnapSack/archive/master.zip; unzip master.zip; rm -f master.zip; mv KnapSack-master $(ROOT_DIR)/KnapSack; fi
elorank_wget:
	if [ ! -d $(ROOT_DIR)/ELORank ]; then wget https://github.com/BayashiPascal/ELORank/archive/master.zip; unzip master.zip; rm -f master.zip; mv ELORank-master $(ROOT_DIR)/ELORank; fi
genalg_wget:
	if [ ! -d $(ROOT_DIR)/GenAlg ]; then wget https://github.com/BayashiPascal/GenAlg/archive/master.zip; unzip master.zip; rm -f master.zip; mv GenAlg-master $(ROOT_DIR)/GenAlg; fi
neuranet_wget:
	if [ ! -d $(ROOT_DIR)/NeuraNet ]; then wget https://github.com/BayashiPascal/NeuraNet/archive/master.zip; unzip master.zip; rm -f master.zip; mv NeuraNet-master $(ROOT_DIR)/NeuraNet; fi
fracnoise_wget:
	if [ ! -d $(ROOT_DIR)/FracNoise ]; then wget https://github.com/BayashiPascal/FracNoise/archive/master.zip; unzip master.zip; rm -f master.zip; mv FracNoise-master $(ROOT_DIR)/FracNoise; fi
genbrush_wget:
	if [ ! -d $(ROOT_DIR)/GenBrush ]; then wget https://github.com/BayashiPascal/GenBrush/archive/master.zip; unzip master.zip; rm -f master.zip; mv GenBrush-master $(ROOT_DIR)/GenBrush; fi
miniframe_wget:
	if [ ! -d $(ROOT_DIR)/MiniFrame ]; then wget https://github.com/BayashiPascal/MiniFrame/archive/master.zip; unzip master.zip; rm -f master.zip; mv MiniFrame-master $(ROOT_DIR)/MiniFrame; fi
pixeltoposestimator_wget:
	if [ ! -d $(ROOT_DIR)/PixelToPosEstimator ]; then wget https://github.com/BayashiPascal/PixelToPosEstimator/archive/master.zip; unzip master.zip; rm -f master.zip; mv PixelToPosEstimator-master $(ROOT_DIR)/PixelToPosEstimator; fi
pbdataanalysis_wget:
	if [ ! -d $(ROOT_DIR)/PBDataAnalysis ]; then wget https://github.com/BayashiPascal/PBDataAnalysis/archive/master.zip; unzip master.zip; rm -f master.zip; mv PBDataAnalysis-master $(ROOT_DIR)/PBDataAnalysis; fi
pbimganalysis_wget:
	if [ ! -d $(ROOT_DIR)/PBImgAnalysis ]; then wget https://github.com/BayashiPascal/PBImgAnalysis/archive/master.zip; unzip master.zip; rm -f master.zip; mv PBImgAnalysis-master $(ROOT_DIR)/PBImgAnalysis; fi
sdsia_wget:
	if [ ! -d $(ROOT_DIR)/SDSIA ]; then wget https://github.com/BayashiPascal/SDSIA/archive/master.zip; unzip master.zip; rm -f master.zip; mv SDSIA-master $(ROOT_DIR)/PBImgAnalysis; fi

# Definition of rules for each repository

# ---- PBErr
repo:=pberr
# Name of the repository, must be the name of the directory
$(repo)_NAME:=PBErr
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:= 
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- GSet
repo:=gset
# Name of the repository, must be the name of the directory
$(repo)_NAME:=GSet
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H) \
	$(ROOT_DIR)/PBMath/pbmath.h
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	-I$(ROOT_DIR)/PBJson/ \
	-I$(ROOT_DIR)/GTree/ \
	-I$(ROOT_DIR)/PBMath/
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O) \
	pbmath.o \
	gtree.o \
	pbjson.o
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- GTree
repo:=gtree
# Name of the repository, must be the name of the directory
$(repo)_NAME:=GTree
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(gset_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(gset_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:= 
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- PBJson
repo:=pbjson
# Name of the repository, must be the name of the directory
$(repo)_NAME:=PBJson
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(gtree_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(gtree_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(gtree_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:= 
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- PBMath
repo:=pbmath
# Name of the repository, must be the name of the directory
$(repo)_NAME:=PBMath
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbjson_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbjson_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbjson_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- BCurve
repo:=bcurve
# Name of the repository, must be the name of the directory
$(repo)_NAME:=BCurve
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbmath_H) \
	$(gset_H) \
	$(ROOT_DIR)/Shapoid/shapoid.h
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbmath_INC_DIR) \
	$(gset_INC_DIR) \
	-I$(ROOT_DIR)/Shapoid/
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbmath_DEP_O) \
	$(gset_DEP_O) \
	shapoid.o
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O) \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- Shapoid
repo:=shapoid
# Name of the repository, must be the name of the directory
$(repo)_NAME:=Shapoid
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbmath_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbmath_INC_DIR) \
	$(gset_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbmath_DEP_O) \
	$(gset_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- PBPhys
repo:=pbphys
# Name of the repository, must be the name of the directory
$(repo)_NAME:=PBPhys
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(shapoid_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(shapoid_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(shapoid_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- Grad
repo:=grad
# Name of the repository, must be the name of the directory
$(repo)_NAME:=Grad
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbmath_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbmath_INC_DIR) \
	$(gset_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbmath_DEP_O) \
	$(gset_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- KnapSack
repo:=knapsack
# Name of the repository, must be the name of the directory
$(repo)_NAME:=KnapSack
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(gset_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(gset_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- ELORank
repo:=elorank
# Name of the repository, must be the name of the directory
$(repo)_NAME:=ELORank
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbmath_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbmath_INC_DIR) \
	$(gset_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbmath_DEP_O) \
	$(gset_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- GenAlg
repo:=genalg
# Name of the repository, must be the name of the directory
$(repo)_NAME:=GenAlg
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbmath_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbmath_INC_DIR) \
	$(gset_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbmath_DEP_O) \
	$(gset_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- NeuraNet
repo:=neuranet
# Name of the repository, must be the name of the directory
$(repo)_NAME:=NeuraNet
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbmath_H) \
	$(genalg_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbmath_INC_DIR) \
	$(genalg_INC_DIR) \
	$(gset_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbmath_DEP_O) \
	$(gset_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O) \
	$(genalg_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- FracNoise
repo:=fracnoise
# Name of the repository, must be the name of the directory
$(repo)_NAME:=FracNoise
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbmath_H) \
	$(shapoid_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbmath_INC_DIR) \
	$(shapoid_INC_DIR) \
	$(gset_INC_DIR) \
	$(bcurve_INC_DIR) \
	-I$(ROOT_DIR)/GenBrush/
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbmath_DEP_O) \
	$(shapoid_DEP_O) \
	$(gset_DEP_O) \
	$(bcurve_DEP_O) \
	genbrush.o
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O) \
	$(genbrush_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- GenBrush
repo:=genbrush
# Name of the repository, must be the name of the directory
$(repo)_NAME:=GenBrush
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h \
	$($(repo)_DIR)/$(repo)-GTK.h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbmath_H) \
	$(bcurve_H) \
	$(shapoid_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbmath_INC_DIR) \
	$(bcurve_INC_DIR) \
	$(shapoid_INC_DIR) \
	$(gset_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbmath_DEP_O) \
	$(bcurve_DEP_O) \
	$(shapoid_DEP_O) \
	$(gset_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
ifeq ($(BUILDWITHGRAPHICLIB),1)
	GTKPARAM=`pkg-config --cflags gtk+-3.0` -DBUILDWITHGRAPHICLIB=$(BUILDWITHGRAPHICLIB)
	GTKLINK=`pkg-config --libs gtk+-3.0`
	CAIROPARAM=`pkg-config --cflags cairo`
	CAIROLINK=`pkg-config --libs cairo`
endif
$(repo)_BUILD_ARG:=$(GTKPARAM) $(CAIROPARAM)
$(repo)_LINK_ARG:=-lm $(GTKLINK) $(CAIROLINK)
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_DIR)/$(repo)-GTK.c \
		$($(repo)_DIR)/$(repo)-inline-GTK.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- MiniFrame
repo:=miniframe
# Name of the repository, must be the name of the directory
$(repo)_NAME:=MiniFrame
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h \
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbmath_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbmath_INC_DIR) \
	$(gset_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbmath_DEP_O) \
	$(gset_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:=
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- PixelToPosEstimator
repo:=pixeltoposestimator
# Name of the repository, must be the name of the directory
$(repo)_NAME:=PixelToPosEstimator
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(genalg_H) \
	$(pberr_H) \
	$(pbmath_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbmath_INC_DIR) \
	$(gset_INC_DIR) \
	$(genalg_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbmath_DEP_O) \
	$(gset_DEP_O) \
	$(genalg_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- PBDataAnalysis
repo:=pbdataanalysis
# Name of the repository, must be the name of the directory
$(repo)_NAME:=PBDataAnalysis
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbmath_H) \
	$(gset_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbmath_INC_DIR) \
	$(gset_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbmath_DEP_O) \
	$(gset_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- PBImgAnalysis
repo:=pbimganalysis
# Name of the repository, must be the name of the directory
$(repo)_NAME:=PBImgAnalysis
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(pbdataanlysis_H) \
	$(genbrush_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(pbdataanalysis_INC_DIR) \
	$(genbrush_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(pbdataanalysis_DEP_O) \
	$(genbrush_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

# ---- SDSIA
repo:=sdsia
# Name of the repository, must be the name of the directory
$(repo)_NAME:=SDSIA
# Executable
$(repo)_EXENAME:=main
# Directory of the repository
$(repo)_DIR:=$(ROOT_DIR)/$($(repo)_NAME)
# Header of the shared .o
$(repo)_H:= \
	$(repo)_wget \
	$($(repo)_DIR)/$(repo).h
# List of header includes for the repository
$(repo)_INC_H:= \
	$($(repo)_H) \
	$(pberr_H) \
	$(gset_H) \
	$(pbjson_H) \
	$(genbrush_H)
# List of header includes for the executable
$(repo)_INC_H_EXE:= \
	$($(repo)_INC_H)
# List of directories from where include headers
$(repo)_INC_DIR:= \
	-I$($(repo)_DIR) \
	$(pberr_INC_DIR) \
	$(gset_INC_DIR) \
	$(pbjson_INC_DIR) \
	$(genbrush_INC_DIR)
# List of object dependencies for the repo
$(repo)_DEP_O:= \
	$(repo).o \
	$(pberr_DEP_O) \
	$(gset_DEP_O) \
	$(pbjson_DEP_O) \
	$(genbrush_DEP_O)
# List of other dependencies for the repo
$(repo)_DEP:= \
	$(ROOT_DIR)/PBMake/Makefile.inc \
	./Makefile
# List of object dependencies for the executable
$(repo)_EXE_DEP:= \
	$($(repo)_DEP_O)
# List of other arguments for this repository
$(repo)_BUILD_ARG:= 
$(repo)_LINK_ARG:=-lm
# Shared .o
$(repo).o: \
		$($(repo)_DIR)/$(repo).c \
		$($(repo)_DIR)/$(repo)-inline.c \
		$($(repo)_INC_H) \
		$($(repo)_DEP)
	$(COMPILER) $(BUILD_ARG) $($(basename $@)_INC_DIR) -c $($(basename $@)_DIR)/$(basename $@).c

