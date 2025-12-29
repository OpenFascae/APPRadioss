#include "FITKMaterialHydro.h"

namespace Radioss
{
   
    const FITKMaterialHydroData& FITKMaterialHydro::getMaterialDataReadOnly() const
    {
        return m_data;
    }

    FITKMaterialHydroData& FITKMaterialHydro::getMaterialData()
    {
        return m_data;
    }

    void FITKMaterialHydro::setEOSID(int id)
    {
        _eosID = id;
    }

    int FITKMaterialHydro::getEOSID()
    {
        return _eosID;
    }
}
