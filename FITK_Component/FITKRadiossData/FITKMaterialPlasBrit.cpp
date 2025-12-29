#include "FITKMaterialPlasBrit.h"

namespace Radioss
{
   
    const FITKMaterialPlasBritData& FITKMaterialPlasBrit::getMaterialDataReadOnly() const
    {
        return m_data;
    }

    FITKMaterialPlasBritData& FITKMaterialPlasBrit::getMaterialData()
    {
        return m_data;
    }
}
