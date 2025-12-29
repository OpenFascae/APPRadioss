/**********************************************************************
 * @file   GUIMaterialElasticDialog.h
 * @brief  弹性材料参数窗口
 * @author guqingtao (15598887859@163.com)
 * @date   2025-08-22
 *********************************************************************/
#ifndef _GUIMaterialElasticDialog_H
#define _GUIMaterialElasticDialog_H

#include "GUIMaterialPropDialog.h"

namespace GUI
{
    /**
     * @brief  弹性材料参数窗口
     * @author guqingtao (15598887859@163.com)
     * @date   2025-08-22
     */
    class GUIAnalysisDialogAPI GUIMaterialElasticDialog : public GUIMaterialPropDialog
    {
        Q_OBJECT;
    public:
        explicit GUIMaterialElasticDialog(Interface::FITKAbstractMaterial* obj,Core::FITKActionOperator* oper,QWidget* parent = nullptr);
        virtual~GUIMaterialElasticDialog() = default;

    protected:
        /**
         * @brief    初始化UI
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-22
         */
        void initUI();
        /**
         * @brief    初始化数据
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-22
         */
        void init() override;
        /**
         * @brief    检查
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-22
         */
        virtual bool ckeckData()override;
        /**
         * @brief    从界面获取数据
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-22
         */
        void getDataFormWidget() override;

    };
}

#endif
