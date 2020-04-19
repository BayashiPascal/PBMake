# Build mode
# 0: development (max safety, no optimisation)
# 1: release (min safety, optimisation)
# 2: fast and furious (no safety, optimisation)
BUILD_MODE=1
# Override the build mode in repositories' folder
export BUILD_MODE

# 0: monolith version, the GBSurface is rendered toward a TGA image
# 1: GTK version, the GBSurface is rendered toward a TGA image or 
#    a GtkWidget
BUILDWITHGRAPHICLIB=0

default: all

LIST_REPOS=\
	PBErr \
	GSet \
	GTree \
	PBJson \
	PBMath \
	BCurve \
	Shapoid \
	PBPhys \
	Grad \
	KnapSack \
	ELORank \
	GenAlg \
	NeuraNet \
	FracNoise \
	GenBrush \
	MiniFrame \
	PixelToPosEstimator \
	PBDataAnalysis \
	PBCExtension \
	PBFileSys \
	SDSIA \
	GDataSet \
	ResPublish \
	PBImgAnalysis \
	TheSquid \
	NNSquidTrainer \
	CBo \
	Cryptic \
	GradAutomaton \
	

all: 
	for repo in $(LIST_REPOS); do if [ -d ../$$repo ]; then make -C ../$$repo all; fi; done;

allDev: 
	for repo in $(LIST_REPOS); do if [ -d ../$$repo ]; then make -C ../$$repo all BUILD_MODE=0 BUILDWITHGRAPHICLIB=0; fi; done;

allRelease: 
	for repo in $(LIST_REPOS); do if [ -d ../$$repo ]; then make -C ../$$repo all BUILD_MODE=1 BUILDWITHGRAPHICLIB=0; fi; done;

allDevGtk: 
	for repo in $(LIST_REPOS); do if [ -d ../$$repo ]; then make -C ../$$repo all BUILD_MODE=0 BUILDWITHGRAPHICLIB=1; fi; done;

allReleaseGtk: 
	for repo in $(LIST_REPOS); do if [ -d ../$$repo ]; then make -C ../$$repo all BUILD_MODE=1 BUILDWITHGRAPHICLIB=1; fi; done;

clean:
	for repo in $(LIST_REPOS); do if [ -d ../$$repo ]; then make -C ../$$repo clean; fi; done;

LIST_OBJ=\
	../PBErr/pberr.o \
	../GSet/gset.o \
	../GTree/gtree.o \
	../PBJson/pbjson.o \
	../PBMath/pbmath.o \
	../BCurve/bcurve.o \
	../Shapoid/shapoid.o \
	../PBPhys/pbphys.o \
	../Grad/grad.o \
	../KnapSack/knapsack.o \
	../ELORank/elorank.o \
	../GenAlg/genalg.o \
	../NeuraNet/neuranet.o \
	../FracNoise/fracnoise.o \
	../GenBrush/genbrush.o \
	../MiniFrame/miniframe.o \
	../PBDataAnalysis/pbdataanalysis.o \
	../PBCExtension/pbcextension.o \
	../PBFileSys/pbfilesys.o \
	../GDataSet/gdataset.o \
	../ResPublish/respublish.o \
	../PBImgAnalysis/pbimganalysis.o \
	../TheSquid/thesquid.o \
	../CBo/cbo.o \
	../Cryptic/cryptic.o \
	../GradAutomaton/gradautomaton.o \
	

LIST_INCLUDE=\
	../PBErr/pberr.h \
	../GSet/gset.h \
	../GSet/gset-inline.c \
	../GTree/gtree.h \
	../GTree/gtree-inline.c \
	../PBJson/pbjson.h \
	../PBJson/pbjson-inline.c \
	../PBMath/pbmath.h \
	../PBMath/pbmath-inline.c \
	../BCurve/bcurve.h \
	../BCurve/bcurve-inline.c \
	../Shapoid/shapoid.h \
	../Shapoid/shapoid-inline.c \
	../PBPhys/pbphys.h \
	../PBPhys/pbphys-inline.c \
	../Grad/grad.h \
	../Grad/grad-inline.c \
	../KnapSack/knapsack.h \
	../ELORank/elorank.h \
	../ELORank/elorank-inline.c \
	../GenAlg/genalg.h \
	../GenAlg/genalg-inline.c \
	../NeuraNet/neuranet.h \
	../NeuraNet/neuranet-inline.c \
	../FracNoise/fracnoise.h \
	../FracNoise/fracnoise-inline.c \
	../GenBrush/genbrush.h \
	../GenBrush/genbrush-inline.c \
	../GenBrush/genbrush-GTK.h \
	../GenBrush/genbrush-inline-GTK.c \
	../MiniFrame/miniframe.h \
	../MiniFrame/miniframe-inline.c \
	../PBDataAnalysis/pbdataanalysis.h \
	../PBDataAnalysis/pbdataanalysis-inline.c \
	../PBCExtension/pbcextension.h \
	../PBFileSys/pbfilesys.h \
	../PBFileSys/pbfilesys-inline.c \
	../GDataSet/gdataset.h \
	../GDataSet/gdataset-inline.c \
	../ResPublish/respublish.h \
	../ResPublish/respublish-inline.c \
	../PBImgAnalysis/pbimganalysis.h \
	../PBImgAnalysis/pbimganalysis-inline.c \
	../TheSquid/thesquid.h \
	../TheSquid/thesquid-inline.c \
	../CBo/cbo.h \
	../Cryptic/cryptic.h \
	../Cryptic/cryptic-inline.c \
	../GradAutomaton/gradautomaton.h \
	../GradAutomaton/gradautomaton-inline.c \
	

libAll: libDev libRelease libDevGtk libReleaseGtk

libDev:
	make allDev; rm -f Lib/libpbdev.a; ar -r Lib/libpbdev.a $(LIST_OBJ); rm -f Include/*; cp $(LIST_INCLUDE) Include/

libRelease:
	make allRelease; rm -f Lib/libpbrelease.a; ar -r Lib/libpbrelease.a $(LIST_OBJ); rm -f Include/*; cp $(LIST_INCLUDE) Include/

libDevGtk:
	make allDevGtk; rm -f Lib/libpbdevgtk.a; ar -r Lib/libpbdevgtk.a $(LIST_OBJ); rm -f Include/*; cp $(LIST_INCLUDE) Include/

libReleaseGtk:
	make allReleaseGtk; rm -f Lib/libpbreleasegtk.a; ar -r Lib/libpbreleasegtk.a $(LIST_OBJ); rm -f Include/*; cp $(LIST_INCLUDE) Include/
