/**********************************************************************
 * @file   FITKRadiossDataSurfaceAdaptor.h
 * @brief  Radioss表面数据适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-29
 *********************************************************************/
#ifndef FITKRadiossDataSurfaceAdaptor_H
#define FITKRadiossDataSurfaceAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKRadiossSurfaceSeg;
}
namespace Interface
{
    /**
     * @brief  Radioss表面数据适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-29
     */
    class FITKRadiossDataIOHDF5API FITKRadiossDataSurfaceAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossDataSurfaceAdaptor() = default;
        ~FITKRadiossDataSurfaceAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:
        bool getDataSetDim(H5::Group& h5group, std::string name, int& n, int& m);
    private:
        /**
         * @brief  表面数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-29
         */
        Radioss::FITKRadiossSurfaceSeg* _surfaceData{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKRadiossSurfaceSeg, FITKRadiossDataSurfaceAdaptor)
}

#endif 

