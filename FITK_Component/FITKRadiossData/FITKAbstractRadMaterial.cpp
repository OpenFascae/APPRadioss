#include "FITKAbstractRadMaterial.h"

namespace Radioss
{
    FITKAbstractRadMaterial::RadMatType FITKAbstractRadMaterial::getRadMatType()
    {
        return RadMatType();
    }
    void FITKAbstractRadMaterial::setFailID(int id)
    {
        _failID = id;
    }
    int FITKAbstractRadMaterial::getFailID()
    {
        return _failID;
    }
    void FITKAbstractRadMaterial::setFailState(bool state)
    {
        _isFail = state;
    }
    bool FITKAbstractRadMaterial::isFailState()
    {
        return _isFail;
    }
}