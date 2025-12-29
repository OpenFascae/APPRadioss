#include "FITKAbstractProbe.h"

namespace Radioss
{
    FITKAbstractProbe::~FITKAbstractProbe()
    {}
 

    FITKAbstractProbe::ProbeType FITKAbstractProbe::getType() const
    {
        return Probe_Unknown;
    }

}