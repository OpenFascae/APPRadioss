/**********************************************************************
 * @file   FITKRadiossDataInteractionTiedAdaptor.h
 * @brief  动力学绑定数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-30
 *********************************************************************/
#ifndef FITKRadiossDataInteractionTiedAdaptor_H
#define FITKRadiossDataInteractionTiedAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKInteractionKinematicTied;
}
namespace Interface
{
    /**
     * @brief  动力学绑定数据适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-30
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataInteractionTiedAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataInteractionTiedAdaptor() = default;
        ~FITKRadiossDataInteractionTiedAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  动力学绑定数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-30
         */
        Radioss::FITKInteractionKinematicTied* _tiedData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKInteractionKinematicTied, FITKRadiossDataInteractionTiedAdaptor)
}

#endif 

