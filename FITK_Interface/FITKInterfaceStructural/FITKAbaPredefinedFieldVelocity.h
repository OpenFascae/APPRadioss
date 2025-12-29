/**
 * 
 * @file   FITKAbaPredefinedFieldVelocity.h
 * @brief  预定义速度场
 * @author LiJin (1003680421@qq.com)
 * @date   2024-06-18
 * 
 */
#ifndef FITKABAPREDEFINEDFIELDVELOCITY_H
#define FITKABAPREDEFINEDFIELDVELOCITY_H
#include "FITKAbaAbstractPredefinedField.h"
#include <array>


namespace Interface {


class FITKInterfaceStructuralAPI FITKAbaPredefinedFieldVelocity: public Interface::FITKAbaAbstractPredefinedField
{
    FITKCLASS(Interface, FITKAbaPredefinedFieldVelocity)
public:
    enum VelocityDefinition
    {
        TranslationalOnly,
        RotationalOnly,
        TranslationalAndRotational
    };
    Q_ENUM(VelocityDefinition);
public:
    FITKAbaPredefinedFieldVelocity() = default;
    ~FITKAbaPredefinedFieldVelocity() = default;
    FITKAbaPredefinedFiledType getPreDefinedType() const override;
    bool isModifiedInStep(int stepId) const override ;
    void activeStateChanged() override;
    bool isValidInStep(int stepId) override;
    bool isValidInCreatedStep() override;
    FITKAbaStepEnum::StateInStep getStateInStep(int stepId) override;
    VelocityDefinition getDefinition() const;
    void setDefinition(VelocityDefinition define);
    double getV1() const;
    void setV1(double v1);
    double getV2() const;
    void setV2(double v2);
    double getV3() const;
    void setV3(double v3);
    double getAngularVelocity() const;
    void setAngularVelocity(double av);
    std::array<double, 3> getAxisPoint1() const;
    void setAxisPoint1(const std::array<double, 3>& point1);
    std::array<double, 3> getAxisPoint2() const;
    void setAxisPoint2(const std::array<double, 3>& point2);
private:
    VelocityDefinition m_definition{VelocityDefinition::TranslationalOnly};
    double m_V1{0.0};
    double m_V2{0.0};
    double m_V3{0.0};
    double m_angularVelocity{0.0};
    std::array<double, 3> m_axisPoint1{0.0,0.0,0.0};
    std::array<double, 3> m_axisPoint2{0.0,0.0,0.0};
};
}
#endif // FITKABAPREDEFINEDFIELDVELOCITY_H
