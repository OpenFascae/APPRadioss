#include "FITKMaterialPlasTab.h"

namespace Radioss
{
   
    const FITKMaterialPlasTabData& FITKMaterialPlasTab::getMaterialDataReadOnly() const
    {
        return m_data;
    }

    FITKMaterialPlasTabData& FITKMaterialPlasTab::getMaterialData()
    {
        return m_data;
    }
}
