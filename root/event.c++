#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TObject.h>
#include <TClonesArray.h>
#include <random>

#include "Event.h"

const size_t size = 5000;
const size_t num_particles=2000;

int main() {

    TFile f("out.evt", "recreate");
    //f.SetCompressionLevel(0);
    TTree tree("tree", "tree");
    Event event;
    tree.Branch("Events", &event);
    
    double x = 0;

    for (int i=0; i<size; i++) {
        std::vector<Particle> arr;
        event.particles.clear();
        for (size_t i=0; i<num_particles; i++) {
            event.particles.emplace_back(TLorentzVector(x++, x++, x++, x++),
                                         TVector3(x++, x++, x++),
                                         std::vector<long long int>({1, 2, 3, 4, 5}));
        }
        tree.Fill();
    }

    tree.Write();
    f.Close();
}

