///**********************************************************************
// * @file   FITKRadiossDataMaterialFailBiquadAdaptor.h
// * @brief  BIQUAD失效材料适配器
// * @author guqingtao (15598887859@163.com)
// * @date   2025-11-10
// *********************************************************************/
//#ifndef FITKRadiossDataMaterialFailBiquadAdaptor_H
//#define FITKRadiossDataMaterialFailBiquadAdaptor_H
//
//#include "FITKRadiossDataHDF5Adaptor.h"
//#include "FITKRadiossDataIOHDF5API.h"
//#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"
//
//namespace Radioss
//{
//    class FITKMaterialFailBiquad;
//}
//namespace Interface
//{
//    /**
//     * @brief  BIQUAD失效材料适配器
//     * @author guqingtao (15598887859@163.com)
//     * @date   2025-11-10
//     */
//    class FITKRadiossDataIOHDF5API FITKRadiossDataMaterialFailBiquadAdaptor : public FITKRadiossDataHDF5Adaptor
//    {
//    public:
//        explicit FITKRadiossDataMaterialFailBiquadAdaptor() = default;
//        ~FITKRadiossDataMaterialFailBiquadAdaptor() = default;
//
//        virtual bool adaptR() override;
//        virtual bool adaptW() override;
//    private:
//
//    private:
//        /**
//         * @brief  BIQUAD失效材料
//         * @author guqingtao (15598887859@163.com)
//         * @date   2025-11-10
//         */
//        Radioss::FITKMaterialFailBiquad* _data{};
//    };
//    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKMaterialFailBiquad, FITKRadiossDataMaterialFailBiquadAdaptor)
//}
//
//#endif 
//
