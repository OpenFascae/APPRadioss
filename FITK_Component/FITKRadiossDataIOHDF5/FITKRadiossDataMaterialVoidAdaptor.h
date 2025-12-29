/**********************************************************************
 * @file   FITKRadiossDataMaterialVoidAdaptor.h
 * @brief  空材料数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-29
 *********************************************************************/
#ifndef FITKRadiossDataMaterialVoidAdaptor_H
#define FITKRadiossDataMaterialVoidAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKMaterialVoid;
}
namespace Interface
{
    /**
     * @brief  空材料数据适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-29
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataMaterialVoidAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataMaterialVoidAdaptor() = default;
        ~FITKRadiossDataMaterialVoidAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  空材料数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-29
         */
        Radioss::FITKMaterialVoid* _voidData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKMaterialVoid, FITKRadiossDataMaterialVoidAdaptor)
}

#endif 

