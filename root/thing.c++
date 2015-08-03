#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TObject.h>
#include <TClonesArray.h>

#include "MyThing.h"

int root() {

    size_t size = 100000;
    TTree tree("tree", "tree");
    TClonesArray arr("MyThing", size);
    tree.Branch("allthethings", &arr, size, false);
    arr.BypassStreamer();
    for (int i=0; i<size; i++) {
        MyThing* thing = (MyThing*) arr.ConstructedAt(i);
        thing->SetThing(42.);
    }

    std::cout << "Saving..." << std::endl;
    TFile f("out.root", "recreate");
    tree.Write();
    f.Close();
}

int main() {
    root();
    return 0;
}

