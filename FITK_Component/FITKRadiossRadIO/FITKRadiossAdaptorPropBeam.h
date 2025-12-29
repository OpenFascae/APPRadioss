/**********************************************************************
 * @file   FITKRadiossAdaptorPropBeam.h
 * @brief  梁属性读取适配器
 * @author wangning (2185896382@qq.com)
 * @date   2025-10-24
 *********************************************************************/
#ifndef __FITKRadiossAdaptorPropBeam_H__
#define __FITKRadiossAdaptorPropBeam_H__
#include "FITKRadiossRadIOAPI.h"
#include "FITKRadiossAbstractAdaptor.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKPropBeam;
    /**
     * @brief  梁属性读取适配器
     * @author wangning (2185896382@qq.com)
     * @date   2025-10-24
     */
    class FITKRadiossRadIOAPI FITKRadiossAdaptorPropBeam : public FITKRadiossAbstractAdaptor
    {
    public:
        explicit FITKRadiossAdaptorPropBeam() = default;
        ~FITKRadiossAdaptorPropBeam() = default;
        /**
         * @brief
         * @return   QString
         * @author wangning (2185896382@qq.com)
         * @date   2025-09-15
         */
        QString getAdaptorClass() override;
        /**
         * @brief    适配器读取
         * @return   bool
         * @author wangning (2185896382@qq.com)
         * @date   2025-09-15
         */
        bool adaptR() override;
        /**
         * @brief    适配器写出
         * @return   bool
         * @author wangning (2185896382@qq.com)
         * @date   2025-09-15
         */
        bool adaptW() override;

    private:
        /**
         * @brief    读取属性信息
         * @return   bool
         * @author wangning (2185896382@qq.com)
         * @date   2025-09-15
         */
        bool readPropBeam(FITKPropBeam* beam);
        /**
         * @brief    读取参数
         * @return   void
         * @author wangning (2185896382@qq.com)
         * @date   2025-09-15
         */
        void readParam(const QStringList& lines,Radioss::FITKPropBeam* beam);

    };
    /**
     * @brief  注册适配器
     * @author wangning (2185896382@qq.com)
     * @date   2025-09-15
     */
    Register2FITKIOAdaptorFactory(rad, Radioss::FITKPropBeam, FITKRadiossAdaptorPropBeam);
    RegRadiossRadAdaptor(/PROP/TYPE13, FITKRadiossAdaptorPropBeam);
    RegRadiossRadAdaptor(/PROP/BEAM, FITKRadiossAdaptorPropBeam, 0);

}
#endif //!__FITKRADIOSSADAPTORPROPSHELL_H__
