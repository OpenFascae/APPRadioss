/**********************************************************************
 * @file   FITKRadiossDataGeomPartAdaptor.h
 * @brief  Radioss几何部件适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-11-26
 *********************************************************************/
#ifndef FITKRadiossDataGeomPartAdaptor_H
#define FITKRadiossDataGeomPartAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKRadiossGeomPart;
}
namespace Interface
{
    /**
     * @brief  Radioss几何部件适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-11-11
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataGeomPartAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataGeomPartAdaptor() = default;
        ~FITKRadiossDataGeomPartAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  Radioss几何部件数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-11-11
         */
        Radioss::FITKRadiossGeomPart* _data{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKRadiossGeomPart, FITKRadiossDataGeomPartAdaptor)
}

#endif 

