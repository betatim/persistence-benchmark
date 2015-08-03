#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TObject.h>
#include <TClonesArray.h>
#include <random>

#include "MyThing.h"

int main() {

    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(0, 1);

    size_t size = 20000000;
    TFile f("/dev/null", "recreate");
    f.SetCompressionLevel(0);
    TTree tree("tree", "tree");
    TClonesArray arr("MyThing", size);
    tree.Branch("allthethings", &arr, size, false);
    //arr.BypassStreamer();
    for (int i=0; i<size; i++) {
        MyThing* thing = (MyThing*) arr.ConstructedAt(i);
        thing->SetThing(dist(e2));
    }
    tree.Fill();

    tree.Write();
    f.Close();
}

