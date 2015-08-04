
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TClonesArray.h>

#include <vector>

class Particle: public TObject {

public:
    Particle() {
        this->mom = TLorentzVector(0., 0., 0., 0.);
        this->pos = TVector3(0., 0., 0.);
        this->childrenIdx = std::vector<int>();
    }

    ClassDef(Particle, 1);

    TVector3 pos;
    TLorentzVector mom;
    std::vector<int> childrenIdx;

};
