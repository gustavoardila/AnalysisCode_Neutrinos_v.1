/*                             __
                           .--()°"."
 Author: Nathalia Cardona "|, . ,"
                           !_-(_\
*/

#include "PhenoAnalyzer.h"
#include "LeptonCounter.h"
#include "Cuts.h"
#include "Physics.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

void writeCsv(int count, string path, string cut)
{
  ofstream outfile;
  outfile.open("/home/n.cardonac/AnalysisCode_Neutrinos_v.1/PhenoAnalyzer/counts.csv", ios_base::app); // append instead of overwrite
  outfile << path << "," << cut << "," << count << "\n";
}

int main(int argc, char *argv[])
{
  cout << "Starting phenoanalyzer..." << endl;

  // Importing Delphes data
  TChain chain("Delphes");
  chain.Add(argv[1]);
  ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);

  // output file manager
  TFile *HistoOutputFile = new TFile(argv[2], "RECREATE");

  // directory to store the histograms
  TDirectory *noCutsDirectory = HistoOutputFile->mkdir("noCuts");

  // directory to store the histograms after the jets cuts
  TDirectory *jetsCutsDirectory = HistoOutputFile->mkdir("jetsCuts");

  // directory to store the histograms after the leptons cuts
  TDirectory *leptonsCutsDirectory = HistoOutputFile->mkdir("leptonsCuts");

  // get tree info
  vector<string> branches = {
      "Electron",
      "Muon",
      "Jet",
      "MissingET"};

  map<string, TClonesArray *> branchDict;

  // create a dictionary with the branches
  for (int i = 0; (unsigned)i < branches.size(); i++)
  {
    TClonesArray *branch = treeReader->UseBranch(branches[i].c_str());
    branchDict[branches[i]] = branch;
  }

  // boolean mask to avoid over computation
  vector<int> cutsArr;

  for (int i = 0; (unsigned)i < treeReader->GetEntries(); i++)
  {
    cutsArr.push_back(1);
  }
  
  int nEvents;

  // write number of events to csv
  nEvents = (int)treeReader->GetEntries();
  writeCsv(nEvents, string(argv[1]), "C0");

  // open output file
  HistoOutputFile->cd();

  // ---------------------------------No cuts--------------------------------------------

  noCutsDirectory->cd();
  cout << "No cuts" << endl;
  nEvents = ptEtaPhiMjjMt(treeReader, branchDict, cutsArr, noFilter);
  cout << "No cuts done." << endl;

  writeCsv(nEvents, string(argv[1]), "noCuts");

  // -----------------------------------Jets cuts-----------------------------------------

  jetsCutsDirectory->cd();
  cout << "Jets cuts" << endl;
  nEvents = ptEtaPhiMjjMt(treeReader, branchDict, cutsArr, jetsCuts);
  cout << "Jets cuts done." << endl;

  writeCsv(nEvents, string(argv[1]), "Cuts");

  // -----------------------------------Leptons cuts--------------------------------------

  leptonsCutsDirectory->cd();
  cout << "Leptons cuts" << endl;
  nEvents = ptEtaPhiMjjMt(treeReader, branchDict, cutsArr, leptonsCuts);
  cout << "Leptons cuts done." << endl;

  writeCsv(nEvents, string(argv[1]), "Leptons cuts");

  // ------------------------------------------------------------------------------------

  // close output file
  cout << "closing output file" << endl;
  HistoOutputFile->Close();

  cout << "DONE." << endl;
}
