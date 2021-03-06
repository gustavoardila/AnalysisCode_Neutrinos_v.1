# C++ Compiler
CXX=g++

# Name of the main file and the target file
MAINFILE=PhenoAnalyzer.cc
MAINFILE_PARALLEL=PhenoAnalyzerParallel.cc
#MAINFILE=PhenoAnalyzer.cc
TARGETFILE=PhenoAnalyzer
TARGETFILE_PARALLEL=PhenoAnalyzerParallel
HEADERS==PhenoAnalyzer.h
OTHERFILES=ROOTFunctions.h DelphesFunctions.h #mt2_bisect.h  # Other files
#SOURCEFILES=mt2_bisect.cpp #mt2bl_bisect.cpp mt2w_bisect.cpp 

# Directory where HepMC is installed
HEPMCDIR=/usr/local/HEP/MG5_aMC_v2_6_3_2/HEPTools/hepmc/
HEPMCLIB=$(HEPMCDIR)/lib
HEPMCINC=$(HEPMCDIR)/include/

# Root flags and libs
ROOTCFLAGS=$(shell root-config --cflags)
ROOTLIBS=$(shell root-config --libs)  
ROOTGLIBS=$(shell root-config --glibs)  

# Directory of Exrootanalysis
EXROOTDIR=/usr/local/HEP/ExRootAnalysis
EXROOTLIB=$(EXROOTDIR)/lib
EXROOTINC=$(EXROOTDIR)/ExRootAnalysis


# Directory of Delphes
DELPHESDIR=/usr/local/HEP/Delphes-3.4.1
DELPHESLIB=${DELPHESDIR}
DELPHESINC=${DELPHESDIR}

all: 
	@echo " Usage: write one of the next possibilities:"
	@echo "	make compile    			To compile without Root nor HepMC"
	@echo "	make compile_ROOT			To compile with Root and without HepMC"
	@echo "	make compile_HepMC    			To compile without Root and with HepMC"
	@echo "	make compile_ROOT_HepMC    		To compile with Root and HepMC"
	@echo "	make compile_ROOT_Delphes		To compile with Root and Delphes"
	@echo " To edit make parameters type vi Makefile"


# To compile without Root nor HepMC
compile: $(MAINFILE) $(OTHERFILES)
	$(CXX) -o $(TARGETFILE) $(MAINFILE) $(SOURCEFILES)

# To compile with Root and without HepMC
compile_ROOT: $(MAINFILE) $(OTHERFILES)
	$(CXX) -o $(TARGETFILE) $(MAINFILE) $(SOURCEFILES)`root-config --cflags` \
          -I$(EXROOTINC) \
          -L$(EXROOTLIB) -lExRootAnalysis -L$(ROOTPHYLIB) -lPhysics

# To compile without Root and with HepMC
compile_HepMC: $(MAINFILE) $(OTHERFILES)
	$(CXX) -o $(TARGETFILE) $(MAINFILE) $(SOURCEFILES)\
	 -I$(HEPMCINC) \
	 -L$(HEPMCLIB) -lHepMC

# To compile with Root and HepMC
compile_ROOT_HepMC: $(MAINFILE) $(OTHERFILES)
	$(CXX) -o $(TARGETFILE) $(MAINFILE) $(SOURCEFILES) `root-config --cflags --glibs` \
         -I$(HEPMCINC) -I$(EXROOTINC) \
         -L$(HEPMCLIB) -lHepMC -L$(EXROOTLIB) -lExRootAnalysis -L$(ROOTLIB) -lPhysics

# To compile with Root and Delphes
compile_ROOT_Delphes: $(MAINFILE) $(OTHERFILES)
	$(CXX) -o $(TARGETFILE) $(MAINFILE) $(SOURCEFILES) -Wall $(ROOTCFLAGS) 	\
	-I$(DELPHESINC) -I$(EXROOTINC)	\
	-L$(DELPHESLIB) -lDelphes -L$(EXROOTLIB) -lExRootAnalysis $(ROOTLIBS)

compile_ROOT_Delphes_joinHistos:  joinHistos.cc $(OTHERFILES)
	$(CXX) -o joinHistos joinHistos.cc $(SOURCEFILES) -Wall $(ROOTCFLAGS) 	\
	-I$(DELPHESINC) -I$(EXROOTINC)	\
	-L$(DELPHESLIB) -lDelphes -L$(EXROOTLIB) -lExRootAnalysis $(ROOTLIBS)

compile_ROOT_Delphes_stackHistos:  stackHistos.cc $(OTHERFILES)
	$(CXX) -o stackHistos stackHistos.cc $(SOURCEFILES) -Wall $(ROOTCFLAGS) 	\
	-I$(DELPHESINC) -I$(EXROOTINC)	\
	-L$(DELPHESLIB) -lDelphes -L$(EXROOTLIB) -lExRootAnalysis $(ROOTLIBS)

compile_ROOT_Delphes_joinSignalHistos:  joinSignalHistos.cc $(OTHERFILES)
	$(CXX) -o joinSignalHistos joinSignalHistos.cc $(SOURCEFILES) -Wall $(ROOTCFLAGS) \
	-I$(DELPHESINC) -I$(EXROOTINC)  \
	-L$(DELPHESLIB) -lDelphes -L$(EXROOTLIB) -lExRootAnalysis $(ROOTLIBS)

compile_ROOT_Delphes_joinBGHistos:  joinBGHistos.cc $(OTHERFILES)
	 $(CXX) -o joinBGHistos joinBGHistos.cc $(SOURCEFILES) -Wall $(ROOTCFLAGS)   \
	-I$(DELPHESINC) -I$(EXROOTINC)  \
	-L$(DELPHESLIB) -lDelphes -L$(EXROOTLIB) -lExRootAnalysis $(ROOTLIBS)

compile_ROOT_Delphes_join2Histos:  join2histos.cc $(OTHERFILES)
	$(CXX) -o join2histos join2histos.cc $(SOURCEFILES) -Wall $(ROOTCFLAGS) 	\
	-I$(DELPHESINC) -I$(EXROOTINC)	\
	-L$(DELPHESLIB) -lDelphes -L$(EXROOTLIB) -lExRootAnalysis $(ROOTLIBS)

compile_ROOT_Delphes_Test: Test.cc $(OTHERFILES)
	$(CXX) -o Test Test.cc $(SOURCEFILES) -Wall $(ROOTCFLAGS) 	\
	-I$(DELPHESINC) -I$(EXROOTINC)	\
	-L$(DELPHESLIB) -lDelphes -L$(EXROOTLIB) -lExRootAnalysis $(ROOTLIBS)

# To compile with Root and Delphes in parallel mode
compile_ROOT_Delphes_parallel: $(MAINFILE) $(OTHERFILES)
	$(CXX) -fopenmp -o $(TARGETFILE_PARALLEL) $(MAINFILE_PARALLEL) $(SOURCEFILES) -Wall $(ROOTCFLAGS) 	\
	-I$(DELPHESINC) -I$(EXROOTINC)	\
	-L$(DELPHESLIB) -lDelphes -L$(EXROOTLIB) -lExRootAnalysis $(ROOTLIBS)
