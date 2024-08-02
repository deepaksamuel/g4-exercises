#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TPad.h"
#include "stdio.h"
#include <iostream>
using namespace std;
void analysis()
{
    TFile *fileO  = new TFile("build/output.root");
    TTree *treeO  = (TTree*) fileO->Get("simple");
    
    // TFile *fileC  = new TFile("build/output_420_C_0.1_8.root");
    // TTree *treeC  = (TTree*) fileC->Get("simple");
    
    Double_t w = 600;
    Double_t h = 600;
    auto c = new TCanvas("c", "c", w, h);
    // c->Divide(2,2);
    // c->cd(1);
    treeO->Draw("180/3.14*acos((posz)/sqrt(posx**2+posy**2+(posz)**2))>>h1(25)","tot_E>180");

    // fileO  = new TFile("build/output_In.root");
    // treeO  = (TTree*) fileO->Get("simple");
    // treeO->Draw("180/3.14*acos((posz)/sqrt(posx**2+posy**2+(posz)**2))>>h2(25)","tot_E>148","SAME");
    

    // treeC->Draw("acos((posz)/sqrt(posx**2+posy**2+(posz)**2))>>h1(1000)");
    
    // c->cd(2);
    // tree->Draw("tot_E");

    gPad->Modified(); gPad->Update(); 
    cout<<"processing complete"<<endl;

}
