/**********************************************************************
 * @file   GUIRigidWallPlaneDialog.h
 * @brief  刚性平面墙对话框
 * @author guqingtao (15598887859@163.com)
 * @date   2025-08-26
 *********************************************************************/
#ifndef _GUIRigidWallPlaneDialog_H
#define _GUIRigidWallPlaneDialog_H

#include "GUIAnalysisDialogAPI.h"
#include "GUIRigidWallDialog.h"

namespace GUI
{
    /**
     * @brief  刚性平面墙对话框
     * @author guqingtao (15598887859@163.com)
     * @date   2025-08-26
     */
    class GUIAnalysisDialogAPI GUIRigidWallPlaneDialog : public GUIRigidWallDialog
    {
        Q_OBJECT;
    public:

        explicit GUIRigidWallPlaneDialog(Radioss::FITKAbstractRWall* obj, Core::FITKActionOperator* oper,QWidget* parent = nullptr);
        virtual ~GUIRigidWallPlaneDialog() = default;
    protected:
        /**
         * @brief    初始化数据
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-26
         */
        void init() override;
        /**
         * @brief    检查
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-26
         */
        virtual bool ckeckData()override;
        /**
         * @brief    从界面获取数据
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-26
         */
        void getDataFormWidget() override;

    };
}

#endif
