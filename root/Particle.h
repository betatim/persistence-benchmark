
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TClonesArray.h>

#include <iostream>
#include <vector>

class Particle: public TObject {

typedef long long int int64;

public:
    Particle():
    mom(TLorentzVector(0., 0., 0., 0.)),
    pos(TVector3(0., 0., 0.)),
    childrenIdx(std::vector<int64>())
    {
    }

    Particle(TLorentzVector mom, TVector3 pos, std::vector<int64> idx) :
    mom(mom),
    pos(pos),
    childrenIdx(idx)
    {
    }

    ClassDef(Particle, 1);

    TVector3 pos;
    TLorentzVector mom;
    std::vector<int64> childrenIdx;

};
