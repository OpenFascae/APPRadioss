/**********************************************************************
 * @file   FITKRadiossDataMaterialPlasJohnsAdaptor.h
 * @brief  PlasJohns材料数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-29
 *********************************************************************/
#ifndef FITKRadiossDataMaterialPlasJohnsAdaptor_H
#define FITKRadiossDataMaterialPlasJohnsAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKMaterialPlasJohns;
}
namespace Interface
{
    /**
     * @brief  PlasJohns材料数据
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-29
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataMaterialPlasJohnsAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataMaterialPlasJohnsAdaptor() = default;
        ~FITKRadiossDataMaterialPlasJohnsAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  PlasJohns材料数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-29
         */
        Radioss::FITKMaterialPlasJohns* _plasJohnsData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKMaterialPlasJohns, FITKRadiossDataMaterialPlasJohnsAdaptor)
}

#endif 

