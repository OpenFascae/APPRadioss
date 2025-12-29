/**********************************************************************
 * @file   FITKRadiossDataResultRequestAdaptor.h
 * @brief  结果请求数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-10-14
 *********************************************************************/
#ifndef FITKRadiossDataResultRequestAdaptor_H
#define FITKRadiossDataResultRequestAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKRadiossResultRequest;
}
namespace Interface
{
    /**
     * @brief  结果请求数据适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-10-14
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataResultRequestAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataResultRequestAdaptor() = default;
        ~FITKRadiossDataResultRequestAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  结果请求数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-10-14
         */
        Radioss::FITKRadiossResultRequest* _resultRequest{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKRadiossResultRequest, FITKRadiossDataResultRequestAdaptor)
}

#endif 

