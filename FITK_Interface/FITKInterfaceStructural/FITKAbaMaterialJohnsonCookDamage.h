#ifndef FITKABAMATERIALJOHNSONCOOKDAMAGE_H
#define FITKABAMATERIALJOHNSONCOOKDAMAGE_H
#include "FITKAbaMaterialBehavior.h"


namespace Interface {

class FITKInterfaceStructuralAPI FITKAbaMaterialJohnsonCookDamage: public FITKAbaMaterialBehavior
{
public:
    FITKAbaMaterialJohnsonCookDamage() = default;
    FITKAbaMaterialBehaviorEnum::FITKAbaMaterialBehaviorType getMaterialBehaviorType() override;
    /**
         * @brief  获取属性行为类名
         * @param[in]  void
         * @return 属性行为类名
         * @author libaojun
         * @date   2025-08-08
         */
        virtual QString getBehaviorClassName() override {
            return "Interface::FITKAbaMaterialJohnsonCookDamage";
        }
    double getD1() const;
    void setD1(double newD1);
    double getD2() const;
    void setD2(double newD2);
    double getD3() const;
    void setD3(double newD3);
    double getD4() const;
    void setD4(double newD4);
    double getD5() const;
    void setD5(double newD5);
    double getMeltingTemperature() const;
    void setMeltingTemperature(double newMeltingTemperature);
    double getTransitionTemperature() const;
    void setTransitionTemperature(double newTransitionTemperature);
    double getReferenceStrainRate() const;
    void setReferenceStrainRate(double newReferenceStrainRate);

private:
    double m_d1{0.0};
    double m_d2{0.0};
    double m_d3{0.0};
    double m_d4{0.0};
    double m_d5{0.0};
    double m_meltingTemperature{0.0};
    double m_transitionTemperature{0.0};
    double m_referenceStrainRate{0.0};
};
}
#endif // FITKABAMATERIALJOHNSONCOOKDAMAGE_H
