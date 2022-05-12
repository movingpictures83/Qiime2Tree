#ifndef QIIME2TREEPLUGIN_H
#define QIIME2TREEPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class Qiime2TreePlugin : public Plugin
{
public: 
 std::string toString() {return "Qiime2Tree";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;

};

#endif
