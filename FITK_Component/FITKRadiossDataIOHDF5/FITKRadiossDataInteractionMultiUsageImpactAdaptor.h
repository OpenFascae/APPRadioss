/**********************************************************************
 * @file   FITKRadiossDataInteractionMultiUsageImpactAdaptor.h
 * @brief  多用途冲击适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-11-03
 *********************************************************************/
#ifndef FITKRadiossDataInteractionMultiUsageImpactAdaptor_H
#define FITKRadiossDataInteractionMultiUsageImpactAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKInteractionMultiUsageImpact;
}
namespace Interface
{
    /**
     * @brief  多用途冲击适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-11-03
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataInteractionMultiUsageImpactAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataInteractionMultiUsageImpactAdaptor() = default;
        ~FITKRadiossDataInteractionMultiUsageImpactAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  多用途冲击数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-11-03
         */
        Radioss::FITKInteractionMultiUsageImpact* _data{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKInteractionMultiUsageImpact, FITKRadiossDataInteractionMultiUsageImpactAdaptor)
}

#endif 

