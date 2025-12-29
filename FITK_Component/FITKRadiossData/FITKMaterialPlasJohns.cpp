#include "FITKMaterialPlasJohns.h"

namespace Radioss
{


    void FITKMaterialPlasJohns::setType( FITKMaterialPlasJohns::MaterialPlasJohnsType type)
    {
        // 设置Johnson-Cook材料模型的类型
        m_type = type;
    }

    FITKMaterialPlasJohns::MaterialPlasJohnsType FITKMaterialPlasJohns::getType() const
    {
        return m_type;
    }
    const FITKMaterialPlasJohnsData &FITKMaterialPlasJohns::getMaterialDataReadOnly() const
    {
        return m_data;
    }
    FITKMaterialPlasJohnsData &FITKMaterialPlasJohns::getMaterialData()
    {
        return m_data;
    }
}
