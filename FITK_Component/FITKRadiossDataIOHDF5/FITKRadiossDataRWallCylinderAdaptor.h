/**********************************************************************
 * @file   FITKRadiossDataRWallCylinderAdaptor.h
 * @brief  Radioss圆柱刚性墙数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-10-09
 *********************************************************************/
#ifndef FITKRadiossDataRWallCylinderAdaptor_H
#define FITKRadiossDataRWallCylinderAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKRWallCylinder;
}
namespace Interface
{
    /**
     * @brief  Radioss圆柱刚性墙数据适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-10-09
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataRWallCylinderAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataRWallCylinderAdaptor() = default;
        ~FITKRadiossDataRWallCylinderAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  圆柱刚性墙数据适配器
         * @author guqingtao (15598887859@163.com)
         * @date   2025-10-09
         */
        Radioss::FITKRWallCylinder* _wallCylinderData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKRWallCylinder, FITKRadiossDataRWallCylinderAdaptor)
}

#endif 

