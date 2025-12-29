/**********************************************************************
 * @file   FITKRadiossDataGravityAdaptor.h
 * @brief  重力场数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-10-09
 *********************************************************************/
#ifndef FITKRadiossDataGravityAdaptor_H
#define FITKRadiossDataGravityAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKGravity;
}
namespace Interface
{
    /**
     * @brief  重力场数据适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-10-09
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataGravityAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataGravityAdaptor() = default;
        ~FITKRadiossDataGravityAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  重力场数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-10-09
         */
        Radioss::FITKGravity* _gravityData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKGravity, FITKRadiossDataGravityAdaptor)
}

#endif 

