/**********************************************************************
 * @file   FITKRadiossDataProbeAccelerationAdaptor.h
 * @brief  探针加速度计适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-11-10
 *********************************************************************/
#ifndef FITKRadiossDataProbeAccelerationAdaptor_H
#define FITKRadiossDataProbeAccelerationAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKProbeAcceleration;
}
namespace Interface
{
    /**
     * @brief  探针 加速度计适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-11-10
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataProbeAccelerationAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataProbeAccelerationAdaptor() = default;
        ~FITKRadiossDataProbeAccelerationAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  探针 加速度计数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-11-10
         */
        Radioss::FITKProbeAcceleration* _data{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKProbeAcceleration, FITKRadiossDataProbeAccelerationAdaptor)
}

#endif 

