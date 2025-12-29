/**********************************************************************
 * @file   FITKRadiossDataMaterialPlasBritAdaptor.h
 * @brief  脆性失效材料适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-10-30
 *********************************************************************/
#ifndef FITKRadiossDataMaterialPlasBritAdaptor_H
#define FITKRadiossDataMaterialPlasBritAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKMaterialPlasBrit;
}
namespace Interface
{
    /**
     * @brief  脆性失效材料适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-10-30
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataMaterialPlasBritAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataMaterialPlasBritAdaptor() = default;
        ~FITKRadiossDataMaterialPlasBritAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  脆性失效材料数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-10-30
         */
        Radioss::FITKMaterialPlasBrit* _data{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKMaterialPlasBrit, FITKRadiossDataMaterialPlasBritAdaptor)
}

#endif 

