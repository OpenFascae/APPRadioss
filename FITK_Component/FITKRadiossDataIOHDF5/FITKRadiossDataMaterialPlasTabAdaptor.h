/**********************************************************************
 * @file   FITKRadiossDataMaterialPlasTabAdaptor.h
 * @brief  PlasTab材料数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-29
 *********************************************************************/
#ifndef FITKRadiossDataMaterialPlasTabAdaptor_H
#define FITKRadiossDataMaterialPlasTabAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKMaterialPlasTab;
}
namespace Interface
{
    /**
     * @brief  PlasTab材料数据
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-29
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataMaterialPlasTabAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataMaterialPlasTabAdaptor() = default;
        ~FITKRadiossDataMaterialPlasTabAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  PlasTab材料数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-29
         */
        Radioss::FITKMaterialPlasTab* _plasTabData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKMaterialPlasTab, FITKRadiossDataMaterialPlasTabAdaptor)
}

#endif 

