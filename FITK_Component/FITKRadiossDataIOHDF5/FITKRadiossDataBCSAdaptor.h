/**********************************************************************
 * @file   FITKRadiossDataBCSAdaptor.h
 * @brief  边界条件适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-11-10
 *********************************************************************/
#ifndef FITKRadiossDataBCSAdaptor_H
#define FITKRadiossDataBCSAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKRadiossBCS;
}
namespace Interface
{
    /**
     * @brief  边界条件适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-11-10
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataBCSAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataBCSAdaptor() = default;
        ~FITKRadiossDataBCSAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  边界条件数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-11-10
         */
        Radioss::FITKRadiossBCS* _data{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKRadiossBCS, FITKRadiossDataBCSAdaptor)
}

#endif 

