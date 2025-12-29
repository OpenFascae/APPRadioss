/**********************************************************************
 * @file   FITKRadiossDataTimeHistorySPHCELAdaptor.h
 * @brief  输出请求时间历程SPH粒子适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-11-11
 *********************************************************************/
#ifndef FITKRadiossDataTimeHistorySPHCELAdaptor_H
#define FITKRadiossDataTimeHistorySPHCELAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKTimeHistorySPHCEL;
}
namespace Interface
{
    /**
     * @brief  输出请求时间历程SPH粒子适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-11-11
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataTimeHistorySPHCELAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataTimeHistorySPHCELAdaptor() = default;
        ~FITKRadiossDataTimeHistorySPHCELAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  输出请求时间历程SPH粒子数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-11-11
         */
        Radioss::FITKTimeHistorySPHCEL* _data{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKTimeHistorySPHCEL, FITKRadiossDataTimeHistorySPHCELAdaptor)
}

#endif 

