/**********************************************************************
 * @file   FITKRadiossDataNodeAdaptor.h
 * @brief  节点数据HDF5适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-29
 *********************************************************************/
#ifndef FITKRadiossDataNodeAdaptor_H
#define FITKRadiossDataNodeAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKRadiossNodes;
}
namespace Interface
{
    /**
     * @brief  节点数据HDF5适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-29
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataNodeAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataNodeAdaptor() = default;
        ~FITKRadiossDataNodeAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  Node数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-29
         */
        Radioss::FITKRadiossNodes* _nodeData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKRadiossNodes, FITKRadiossDataNodeAdaptor)
}

#endif 

