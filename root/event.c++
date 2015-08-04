#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TObject.h>
#include <TClonesArray.h>
#include <random>

#include "Event.h"

const size_t size = 1000;
const size_t num_particles=2000;

int main() {

    TFile f("out.root", "recreate");
    f.SetCompressionLevel(0);
    TTree tree("tree", "tree");
    Event event;
    tree.Branch("Events", &event);
    
    double x = 0;

    for (int i=0; i<size; i++) {
        TClonesArray arr("Particle", num_particles);
        for (size_t i=0; i<num_particles; i++) {
            auto part = static_cast<Particle*>(arr.ConstructedAt(i));
            part->pos = TVector3(x++, x++, x++);
            part->mom = TLorentzVector(x++, x++, x++, x++);
            part->childrenIdx.push_back(1);
            part->childrenIdx.push_back(2);
            part->childrenIdx.push_back(3);
            part->childrenIdx.push_back(4);
            part->childrenIdx.push_back(5);
        }
        event.particles = arr;
        tree.Fill();
    }

    tree.Write();
    f.Close();
}

