/**********************************************************************
 * @file   FITKRadiossDataSubSetAdaptor.h
 * @brief  Radioss子集数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-29
 *********************************************************************/
#ifndef FITKRadiossDataSubSetAdaptor_H
#define FITKRadiossDataSubSetAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKRadiossSubSet;
}
namespace Interface
{
    /**
     * @brief  Radioss子集数据适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-29
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataSubSetAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataSubSetAdaptor() = default;
        ~FITKRadiossDataSubSetAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  子集数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-29
         */
        Radioss::FITKRadiossSubSet* _subSetData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKRadiossSubSet, FITKRadiossDataSubSetAdaptor)
}

#endif 

