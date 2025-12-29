/**
 * 
 * @file   FITKAbaConnectorBehavior.h
 * @brief  连接器截面行为基类
 * @author LiJin (1003680421@qq.com)
 * @date   2024-06-20
 * 
 */
#ifndef FITKABACONNECTORBEHAVIOR_H
#define FITKABACONNECTORBEHAVIOR_H
#include "FITKInterfaceStructuralAPI.h"
#include <QObject>


namespace Interface {

class FITKInterfaceStructuralAPI FITKAbaConnectorBehaviorEnum : public QObject
{
    Q_OBJECT
public:
    enum ConnectorBehaviorType
    {
        Elasticity,
        Plasticity,
        Damping,
        Stop,
        Lock,
    };
    Q_ENUM(ConnectorBehaviorType)

    enum Definition
    {
        Linear,
        Nonlinear,
        Rigid
    };
    Q_ENUM(Definition)

    enum Coupling
    {
        Uncoupled,
        Coupled,
        CoupledOnPosition,
        CoupledOnMotion
    };
    Q_ENUM(Coupling)

    enum LockType
    {
        All,
        Specify
    };
    Q_ENUM(LockType)

    enum LockSpecify
    {
        None,
        U1,
        U2,
        U3,
        UR1,
        UR2,
        UR3
    };
    Q_ENUM(LockSpecify)

    enum PlacticityIsoTropicHardeningDefinition
    {
        Tabular,
        ExponentialLaw
    };
    Q_ENUM(PlacticityIsoTropicHardeningDefinition)
};

class FITKInterfaceStructuralAPI FITKAbaConnectorBehavior
{
public:
    FITKAbaConnectorBehavior();
    virtual ~FITKAbaConnectorBehavior();
    virtual FITKAbaConnectorBehaviorEnum::ConnectorBehaviorType getBehaviorType() const = 0;
};
}


#endif // FITKABACONNECTORBEHAVIOR_H
