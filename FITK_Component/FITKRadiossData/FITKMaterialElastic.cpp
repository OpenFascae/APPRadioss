#include "FITKMaterialElastic.h"

namespace Radioss
{
    double FITKMaterialVoid::getDensity() const
    {
        return m_density;
    }

    void FITKMaterialVoid::setDensity(double density)
    {
        m_density = density;
    }

    double FITKMaterialVoid::getYoungsModulus() const
    {
        return m_youngsModulus;
    }

    void FITKMaterialVoid::setYoungsModulus(double modulus)
    {
        m_youngsModulus = modulus;
    }

    double FITKMaterialVoid::getPoissonsRatio() const
    {
        return m_poissonsRatio;
    }

    void FITKMaterialVoid::setPoissonsRatio(double ratio)
    {
        m_poissonsRatio = ratio;
    }
}
