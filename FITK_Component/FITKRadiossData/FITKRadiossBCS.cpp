#include "FITKRadiossBCS.h"

namespace Radioss
{
    FITKAbstractBCS::BCSType FITKRadiossBCS::getBCSType() const
    {
        // 在派生类中重写以提供具体类型
        return FITKAbstractBCS::BCSType::BSSCyclic;
    }
    void FITKRadiossBCS::setFreedomFixed(int index, bool fixed)
    {
        if (index < 1 || index > 6) return; // 索引范围检查
        _freedomFixed[index - 1] = fixed; // 设置自由度固定状态
    }

    bool FITKRadiossBCS::isFreedomFixed(int index) const
    {
        if (index < 1 || index > 6) return false; // 索引范围检查
        return _freedomFixed[index - 1]; // 获取自由度固定状态
    }


    
    FITKAbstractBCS::BCSType FITKRadiossBCSCyclic::getBCSType() const
    {
        // 在派生类中重写以提供具体类型
        return FITKAbstractBCS::BCSType::BSSCyclic;
    }



    FITKAbstractBCS::BCSType FITKRadiossBCSLagMul::getBCSType() const
    {
        // 在派生类中重写以提供具体类型
        return FITKAbstractBCS::BCSType::BCSLAGMUL;
    }


} // namespace Radioss
