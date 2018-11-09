# This is a small example how the crab api can easily be used to create something like multi crab.
# It has some additional features like also creating the xml files for you.
# For it to work you need inputDatasets & requestNames apart from the classical part
#
# Make sure to have a unique directory where your joboutput is saved, otherwise the script gets confused and you too!!
#
# Usage ./CrabConfig ConfigFile [options]
#
# Take care here to make the request names *nice*
#
# autocomplete_Datasets(ListOfDatasets) works also for several entries with *
#
from DasQuery import autocomplete_Datasets

inputDatasets = [ '/RSGluonToTT_M-3500_TuneCP5_13TeV-pythia8/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM',
'/RSGluonToTT_M-2500_TuneCP5_13TeV-pythia8/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM']
#inputDatasets = autocomplete_Datasets(inputDatasets)

tags_to_remove = ['_TuneCUETP8M1_13TeV-madgraphMLM-pythia8', '_TuneCP5_13TeV-pythia8']

requestNames = []
for x in inputDatasets:
    name = x.split('/')[1]
    for tag in tags_to_remove:
        if tag in name: modified_name =name.replace(tag,'')
    requestNames.append(modified_name)


# ===============================================================================
# Classical part of crab, after resolving the * it uses in the example below just the first entry
#

from CRABClient.UserUtilities import config, getUsernameFromSiteDB


config = config()
config.General.workArea = 'crab_Signals'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/nfs/dust/cms/user/reimersa/CMSSW_9_4_1/src/UHH2/core/python/ntuplewriter.py'
config.JobType.outputFiles = ["Ntuple.root"]
config.JobType.maxMemoryMB = 2500

config.Data.inputDBS = 'global'
config.Data.splitting = 'EventAwareLumiBased'
config.Data.unitsPerJob = 7500
config.Data.outLFNDirBase = '/store/user/%s/NTuplesRun2/2017/MC/ZprimeSignals/' % (getUsernameFromSiteDB())
config.Data.publication = False
config.JobType.sendExternalFolder = True
#config.Data.allowNonValidInputDataset = True
#config.Data.publishDataName = 'CRAB3_tutorial_May2015_MC_analysis'

config.Site.storageSite = 'T2_DE_DESY'

config.General.requestName = requestNames[0]
config.Data.inputDataset = inputDatasets[0]
