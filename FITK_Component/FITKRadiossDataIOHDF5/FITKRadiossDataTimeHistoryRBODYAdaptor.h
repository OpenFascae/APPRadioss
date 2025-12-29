/**********************************************************************
 * @file   FITKRadiossDataTimeHistoryRBODYAdaptor.h
 * @brief  输出请求时间历程刚体适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-11-11
 *********************************************************************/
#ifndef FITKRadiossDataTimeHistoryRBODYAdaptor_H
#define FITKRadiossDataTimeHistoryRBODYAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKTimeHistoryRBODY;
}
namespace Interface
{
    /**
     * @brief  输出请求时间历程刚体适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-11-11
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataTimeHistoryRBODYAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataTimeHistoryRBODYAdaptor() = default;
        ~FITKRadiossDataTimeHistoryRBODYAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  输出请求时间历程刚体数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-11-11
         */
        Radioss::FITKTimeHistoryRBODY* _data{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKTimeHistoryRBODY, FITKRadiossDataTimeHistoryRBODYAdaptor)
}

#endif 

