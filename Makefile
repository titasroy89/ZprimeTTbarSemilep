LIBRARY := SUHH2ZprimeSemiLeptonic
#USERLDFLAGS := -lSUHH2core -lSUHH2common -lGenVector -lTMVA
# enable par creation; this is necessary for all packages containing AnalysisModules
# to be loaded from by AnalysisModuleRunner.
HAPDFINC=$(shell scram tool tag lhapdf INCLUDE)
LHAPDFLIB=$(shell scram tool tag LHAPDF LIBDIR)
LWTNNLIB= $(shell scram tool tag lwtnn LIBDIR)
LWTNNINC= $(shell scram tool tag lwtnn INCLUDE)
TFLOWLIB= $(shell scram tool tag tensorflow LIBDIR)
TFLOWINC= $(shell scram tool tag tensorflow INCLUDE)
PBUFLIB= $(shell scram tool tag protobuf LIBDIR)
PBUFINC= $(shell scram tool tag protobuf INCLUDE)
EigenINC= $(shell scram tool tag Eigen INCLUDE)
USERCXXFLAGS := -I${LHAPDFINC} -I${LWTNNINC} -I/cvmfs/cms.cern.ch/${SCRAM_ARCH}/cms/cmssw/${CMSSW_VERSION}/src -I${TFLOWINC} -I${PBUFINC} -I${EigenINC}
#USERLDFLAGS := -lSUHH2core -lSUHH2common -lTMVA -lGenVector -lSUHH2JetMETObjects -L${LHAPDFLIB} -L${LWTNNLIB} -lLHAPDF -llwtnn -L/cvmfs/cms.cern.ch/${SCRAM_ARCH}/cms/cmssw/${CMSSW_VERSION}/lib/${SCRAM_ARCH} -lPhysicsToolsTensorFlow -L${TFLOWLIB} -ltensorflow_framework -ltensorflow_cc -ltensorflow -L${PBUFLIB}
USERLDFLAGS := -lSUHH2core -lSUHH2common -lTMVA -lGenVector -lSUHH2JetMETObjects -L${LHAPDFLIB} -L${LWTNNLIB} -lLHAPDF -llwtnn -L/cvmfs/cms.cern.ch/${SCRAM_ARCH}/cms/cmssw/${CMSSW_VERSION}/lib/${SCRAM_ARCH} -lPhysicsToolsTensorFlow -L${TFLOWLIB} -ltensorflow_framework -L${PBUFLIB}
# enable par creation; this is necessary for all packages containing AnalysisModules
# # to be loaded from by AnalysisModuleRunner.
# PAR := 1
#
PAR := 1
include ../Makefile.common
