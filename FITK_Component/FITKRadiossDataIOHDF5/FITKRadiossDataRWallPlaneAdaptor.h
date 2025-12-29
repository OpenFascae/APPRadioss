/**********************************************************************
 * @file   FITKRadiossDataRWallPlaneAdaptor.h
 * @brief  Radioss平面刚性墙数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-10-09
 *********************************************************************/
#ifndef FITKRadiossDataRWallPlaneAdaptor_H
#define FITKRadiossDataRWallPlaneAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKRWallPlane;
}
namespace Interface
{
    /**
     * @brief  Radioss平面刚性墙数据适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-10-09
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataRWallPlaneAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataRWallPlaneAdaptor() = default;
        ~FITKRadiossDataRWallPlaneAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  平面刚性墙数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-10-09
         */
        Radioss::FITKRWallPlane* _wallPlaneData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKRWallPlane, FITKRadiossDataRWallPlaneAdaptor)
}

#endif 

