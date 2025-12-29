/**********************************************************************
 * @file   FITKRadiossAdaptorInitialFieldAxis.h
 * @brief  初始角速度读写适配器
 * @author wangning (2185896382@qq.com)
 * @date   2025-11-07
 *********************************************************************/
#ifndef __FITKRADIOSSADAPTORINITIALFIELDAXIS_H__
#define __FITKRADIOSSADAPTORINITIALFIELDAXIS_H__
#include "FITKRadiossRadIOAPI.h"
#include "FITKRadiossAbstractAdaptor.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKInitialFieldAxis;
    /**
     * @brief  初始角速度读写适配器
     * @author wangning (2185896382@qq.com)
     * @date   2025-11-07
     */
    class FITKRadiossRadIOAPI FITKRadiossAdaptorInitialFieldAxis : public FITKRadiossAbstractAdaptor
    {
    public:
        explicit FITKRadiossAdaptorInitialFieldAxis() = default;
        ~FITKRadiossAdaptorInitialFieldAxis() = default;
        /**
         * @brief
         * @return   QString
         * @author wangning (2185896382@qq.com)
         * @date   2025-11-07
         */
        QString getAdaptorClass() override;
        /**
         * @brief    适配器读取
         * @return   bool
         * @author wangning (2185896382@qq.com)
         * @date   2025-11-07
         */
        bool adaptR() override;
        /**
         * @brief    适配器写出
         * @return   bool
         * @author wangning (2185896382@qq.com)
         * @date   2025-11-07
         */
        bool adaptW() override;

    private:
        /**
         * @brief    读取数据
         * @param[i] gravity
         * @return   bool
         * @author wangning (2185896382@qq.com)
         * @date   2025-11-07
         */
        bool readInivel(FITKInitialFieldAxis* inivel);
        /**
         * @brief    读取参数
         * @param[i] lines
         * @return   void
         * @author wangning (2185896382@qq.com)
         * @date   2025-11-07
         */
        void readParam(const QStringList& lines, FITKInitialFieldAxis* inivel);
    };
    /**
     * @brief  注册适配器
     * @author wangning (2185896382@qq.com)
     * @date   2025-11-07
     */
    Register2FITKIOAdaptorFactory(rad, Radioss::FITKInitialFieldAxis, FITKRadiossAdaptorInitialFieldAxis);
    RegRadiossRadAdaptor(/INIVEL/AXIS, FITKRadiossAdaptorInitialFieldAxis);
}
#endif //!__FITKRADIOSSADAPTORINITIALFIELDTRA_H__
