# Build mode
# 0: development (max safety, no optimisation)
# 1: release (min safety, optimisation)
# 2: fast and furious (no safety, optimisation)
BUILD_MODE=1
# Override the build mode in repositories' folder
export BUILD_MODE

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
	

all: 
	for repo in $(LIST_REPOS); do if [ -d ../$$repo ]; then make -C ../$$repo all; fi; done;

clean:
	for repo in $(LIST_REPOS); do if [ -d ../$$repo ]; then make -C ../$$repo clean; fi; done;
