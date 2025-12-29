/**********************************************************************
 * @file   FITKRadiossDataInitialFieldTraAdaptor.h
 * @brief  初始值数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-30
 *********************************************************************/
#ifndef FITKRadiossDataInitialFieldTraAdaptor_H
#define FITKRadiossDataInitialFieldTraAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKInitialFieldTra;
}
namespace Interface
{
    /**
     * @brief  初始值数据适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-30
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataInitialFieldTraAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataInitialFieldTraAdaptor() = default;
        ~FITKRadiossDataInitialFieldTraAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  初始值数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-30
         */
        Radioss::FITKInitialFieldTra* _traData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKInitialFieldTra, FITKRadiossDataInitialFieldTraAdaptor)
}

#endif 

