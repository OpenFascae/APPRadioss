/**
 * 
 * @file   FITKAbaBoundaryConditionVolocity.h
 * @brief  速度、角速度边界条件，遵循与位移、旋转边界条件相同的接口
 * @author LiJin (1003680421@qq.com)
 * @date   2024-07-08
 * 
 */
#ifndef FITKABABOUNDARYCONDITIONVELOCITY_H
#define FITKABABOUNDARYCONDITIONVELOCITY_H
#include "FITKAbaBoundaryConditionDisplacement.h"


namespace Interface {
class FITKInterfaceStructuralAPI FITKAbaBoundaryConditionVelocity: public FITKAbaBoundaryConditionDisplacement
    {
        FITKCLASS(Interface, FITKAbaBoundaryConditionVelocity)
    public:
        FITKAbaBoundaryConditionType getBoundaryConditionType() const override;
    };
}


#endif // FITKABABOUNDARYCONDITIONVELOCITY_H
