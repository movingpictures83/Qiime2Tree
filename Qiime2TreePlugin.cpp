#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "Qiime2TreePlugin.h"

void Qiime2TreePlugin::input(std::string file) {
 inputfile = file;
}

void Qiime2TreePlugin::run() {
   
}

void Qiime2TreePlugin::output(std::string file) { 
   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";
   command += "qiime phylogeny align-to-tree-mafft-fasttree --i-sequences "+inputfile+" --o-alignment "+file+"_aligned_seqs.qza --o-masked-alignment "+file+"_aligned_masked.qza --o-tree "+file+"_unrooted.qza --o-rooted-tree "+file+"_rooted.qza; ";

//qiime tools import \
  --type 'SampleData[PairedEndSequencesWithQuality]' \
  --input-path AlphaFinal1.manifest \
  --output-path AlphaFinal1-paired-end-demux.qza \
  --input-format PairedEndFastqManifestPhred33V2
 //std::cout << command << std::endl;
   command += "conda deactivate; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;


 system(command.c_str());
}

PluginProxy<Qiime2TreePlugin> Qiime2TreePluginProxy = PluginProxy<Qiime2TreePlugin>("Qiime2Tree", PluginManager::getInstance());
