#ifndef SCHAER_COS_MOUNTAIN_H
#define SCHAER_COS_MOUNTAIN_H

#include "crossableMountain.H"

namespace Foam
{

class schaerCosMountain final : public crossableMountain
{
    public:
    TypeName("schaerCos");
    schaerCosMountain(const dictionary& dict);
    dimensionedScalar heightAt(const point& p) const;
    dimensionedScalar start() const;
    dimensionedScalar end() const;
    dimensionedScalar timeToCross(const dimensionedScalar u0, const dimensionedScalar H) const;

    private:
    const dimensionedScalar h0;
    const dimensionedScalar a;
    const dimensionedScalar lambda;
    const dimensionedScalar xOffset;

    dimensionedScalar timeToCrossIntegralAt
    (
        const dimensionedScalar u0,
        const dimensionedScalar H,
        const dimensionedScalar x
    ) const;
};

}

#endif

