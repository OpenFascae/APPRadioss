/**
 *
 * @file OperatorsNonLinerCurve.h
 * @brief 曲线操作器接口
 * @author wangning (2185896382@qq.com)
 * @date 2025-08-20
 *
 */
#ifndef __OperatorsNonLinerCurve_H__
#define __OperatorsNonLinerCurve_H__

#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"
#include "FITK_Kernel/FITKCore/FITKActionOperator.h"

namespace OperModel
{
    /**
     * @brief 曲线操作器
     * @author wangning (2185896382@qq.com)
     * @date 2025-08-20
     */
    class OperatorsNonLinerCurve :public Core::FITKActionOperator
    {
        Q_OBJECT
    public:
        explicit OperatorsNonLinerCurve() = default;
        virtual ~OperatorsNonLinerCurve() = default;

        virtual bool execGUI();

        virtual bool execProfession();
    };

    // 按钮注册相关操作
    Register2FITKOperatorRepo(actionCurveCreate, OperatorsNonLinerCurve);
    Register2FITKOperatorRepo(actionCurveEdit, OperatorsNonLinerCurve);
}

#endif
