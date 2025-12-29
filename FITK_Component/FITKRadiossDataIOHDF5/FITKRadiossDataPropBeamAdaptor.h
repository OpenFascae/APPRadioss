/**********************************************************************
 * @file   FITKRadiossDataPropBeamAdaptor.h
 * @brief  梁单元属性数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-11-10
 *********************************************************************/
#ifndef FITKRadiossDataPropBeamAdaptor_H
#define FITKRadiossDataPropBeamAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKPropBeam;
}
namespace Interface
{
    /**
     * @brief  梁单元属性数据适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-11-10
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataPropBeamAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataPropBeamAdaptor() = default;
        ~FITKRadiossDataPropBeamAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;

    private:
        /**
         * @brief  梁单元属性数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-11-10
         */
        Radioss::FITKPropBeam* _data{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKPropBeam, FITKRadiossDataPropBeamAdaptor)
}

#endif 

