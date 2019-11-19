#include <TCanvas.h>
#include <TH1I.h>
#include "TH1D.h"
#include "TFile.h"
#include "TTree.h"
#include "TGraph.h"

void cabo_8ns(){
        
    TFile *file = new TFile("cabo1.root","RECREATE");
    TTree *tree = new TTree("mree","data from txt file");
    
    tree->ReadFile("cabo_8ns.txt","t1/D:t2/D",' ');
        
    double t1, t2;

    TH1I *h_dt = new TH1I("Cabo de 8 #etas", "Cabo de 8 #etas", 15,0,15.);
    
        
    tree->SetBranchAddress("t1", &t1);
    tree->SetBranchAddress("t2", &t2);
      
    auto n = tree->GetEntries();
    
    for (auto i = 0; i != n; ++i){
        tree->GetEntry(i);
        h_dt->Fill(t2-t1);
        cout << t2-t1 << endl;
        
    }
    TCanvas *t1c = new TCanvas("tempo","Tempo",400,500);
    cout << h_dt->GetMean() << ' ' << h_dt->GetStdDev() << endl;
    h_dt->Draw();
   
}

void cabo_16ns(){
        
    TFile *file = new TFile("cabo2.root","RECREATE");
    TTree *tree = new TTree("mree","data from txt file");
    
    tree->ReadFile("cabo_16ns.txt","t1/D:t2/D",' ');
        
    double t1, t2;

    TH1I *h_dt = new TH1I("Cabo de 16 #etas", "Cabo de 16 #etas", 8,12.5, 20.5);
    	
        
    tree->SetBranchAddress("t1", &t1);
    tree->SetBranchAddress("t2", &t2);
      
    auto n = tree->GetEntries();
    
    for (auto i = 0; i != n; ++i){
        tree->GetEntry(i);
        h_dt->Fill(t2-t1);
        cout << t2-t1 << endl;
        
    }
    TCanvas *t1c = new TCanvas("tempo","Tempo",400,500);
    cout << h_dt->GetMean() << ' ' << h_dt->GetStdDev() << endl;
    h_dt->Draw();
   
}


