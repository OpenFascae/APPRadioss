/**********************************************************************
 * @file   FITKRadiossDataPropSolidAdaptor.h
 * @brief  Radioss实体单元属性数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-30
 *********************************************************************/
#ifndef FITKRadiossDataPropSolidAdaptor_H
#define FITKRadiossDataPropSolidAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKPropSolid;
}
namespace Interface
{
    /**
     * @brief  Radioss实体单元属性数据适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-30
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataPropSolidAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataPropSolidAdaptor() = default;
        ~FITKRadiossDataPropSolidAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  实体单元属性数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-30
         */
        Radioss::FITKPropSolid* _solidData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKPropSolid, FITKRadiossDataPropSolidAdaptor)
}

#endif 

