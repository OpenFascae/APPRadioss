/**********************************************************************
 * @file   FITKRadiossAdaptorNonLinerCurve.h
 * @brief  非线性函数读取适配器
 * @author zhangjingx (hiter25@outlook.com)
 * @date   2025-07-15
 *********************************************************************/
#ifndef __FITKRADIOSSADAPTORNONLINERCURVE_H__
#define __FITKRADIOSSADAPTORNONLINERCURVE_H__
#include "FITKRadiossRadIOAPI.h"
#include "FITKRadiossAbstractAdaptor.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKNonLinerCurve;
    /**
     * @brief  非线性函数读取适配器
     * @author zhangjingx (hiter25@outlook.com)
     * @date   2025-07-11
     */
    class FITKRadiossRadIOAPI FITKRadiossAdaptorNonLinerCurve : public FITKRadiossAbstractAdaptor
    {
    public:
        explicit FITKRadiossAdaptorNonLinerCurve() = default;
        ~FITKRadiossAdaptorNonLinerCurve() = default;
        /**
         * @brief
         * @return   QString
         * @author   zhangjingx (hiter25@outlook.com)
         * @date     2025-07-08
         */
        QString getAdaptorClass() override;
        /**
         * @brief    适配器读取
         * @return   bool
         * @author   zhangjingx (hiter25@outlook.com)
         * @date     2025-07-08
         */
        bool adaptR() override;
        /**
         * @brief    适配器写出
         * @return   bool
         * @author   zhangjingx (hiter25@outlook.com)
         * @date     2025-07-08
         */
        bool adaptW() override;
    private:
        /**
         * @brief    读取非线性函数
         * @param[i] nonLinerCurve 
         * @return   bool
         * @author   zhangjingx (hiter25@outlook.com)
         * @date     2025-07-15
         */
        bool readFunct(FITKNonLinerCurve* nonLinerCurve);
    };
    /**
     * @brief  注册适配器
     * @author zhangjingx (hiter25@outlook.com)
     * @date   2025-07-09
     */
    Register2FITKIOAdaptorFactory(rad, Radioss::FITKNonLinerCurve, FITKRadiossAdaptorNonLinerCurve);
    RegRadiossRadAdaptor(/FUNCT, FITKRadiossAdaptorNonLinerCurve);
}
#endif //!__FITKRADIOSSADAPTORNONLINERCURVE_H__
