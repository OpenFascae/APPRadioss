/**********************************************************************
 * @file   GUIContactMultiUsageImpactDialog.h
 * @brief  接触多用途冲击界面窗口类
 * @author liuzhonghua (liuzhonghuaszch@163.com)
 * @date   2025-11-03
 *********************************************************************/
#ifndef _GUICONTACTMULTIUSAGEIMPACTDIALOG_H
#define _GUICONTACTMULTIUSAGEIMPACTDIALOG_H

#include "GUIAnalysisDialogAPI.h"
#include "FITK_Kernel/FITKCore/FITKAbstractGUIDialog.h"

namespace Ui
{
    class GUIContactMultiUsageImpactDialog;
}

namespace Core
{
    class FITKActionOperator;
}

namespace Radioss
{
    class FITKInteractionManager;
    class FITKInteractionMultiUsageImpact;
}

namespace GUI
{
    /**
     * @brief  接触绑定界面窗口类
     * @author liuzhonghua (liuzhonghuaszch@163.com)
     * @date   2025-09-08
     */
    class GUIAnalysisDialogAPI GUIContactMultiUsageImpactDialog : public Core::FITKDialog
    {
        Q_OBJECT
    public:

        GUIContactMultiUsageImpactDialog(Core::FITKActionOperator* oper, QWidget* parent = nullptr);
        GUIContactMultiUsageImpactDialog(Radioss::FITKInteractionMultiUsageImpact* multiUsageImpact, Core::FITKActionOperator* oper, QWidget* parent = nullptr);
        ~GUIContactMultiUsageImpactDialog();
       
    private:
        /**
         * @brief    初始化
         * @author   guqingtao (15598887859@163.com)
         * @date   2025-09-08
         */
        void init();
        /**
         * @brief    初始化界面窗口
         * @return   void
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-09-26
         */
        void initWidget();

        /**
         * @brief    获取相互作用管理器
         * @return   Interface::FITKInteractionManager *
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-09-26
         */
        Radioss::FITKInteractionManager* getInteractionManager();
        /**
         * @brief    创建数据
         * @return   bool
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-09-26
         */
        bool createObjData();
        /**
         * @brief    修改数据
         * @return   bool
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-09-26
         */
        bool editObjData();
        /**
         * @brief    从界面获取数据接口
         * @return   void
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-09-26
         */
        void getDataFormWidget();

    private slots:
        /**
         * @brief ok button clicked slot
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date 2024-10-23
         */
        void on_pushButton_OK_clicked();
        /**
         * @brief cencel button clicked slot
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date 2024-10-23
         */
        void on_pushButton_Cancel_clicked();
        /**
         * @brief    GapCurvature comboBox currentTextChanged slot
         * @param[i] text 
         * @return   void
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-11-04
         */
        void on_comboBox_GapCurvature_currentTextChanged(const QString & text);
        /**
         * @brief    LocalCurvature comboBox currentTextChanged slot
         * @param[i] text 
         * @return   void
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-11-04
         */
        void on_comboBox_LocalCurvature_currentTextChanged(const QString & text);
        /**
         * @brief    HeatContact comboBox currentTextChanged slot
         * @param[i] text 
         * @return   void
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-11-04
         */
        void on_comboBox_HeatContact_currentTextChanged(const QString & text);
        /**
         * @brief    Ifric comboBox currentTextChanged slot
         * @param[i] text 
         * @return   void
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-11-04
         */
        void on_comboBox_Ifric_currentTextChanged(const QString & text);

    protected:
        /**
         * @brief    关闭槽
         * @return   void
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2024-11-07
         */
        virtual void accept() override;

        /**
         * @brief    关闭槽
         * @return   void
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2024-11-07
         */
        virtual void reject() override;

    private:
        /**
         * @brief  ui
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-09-08
         */
        Ui::GUIContactMultiUsageImpactDialog* _ui{};
        /**
         * @brief  操作器
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-09-25
         */
        Core::FITKActionOperator* _oper{};
        /**
         * @brief  数据
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-09-26
         */
        Radioss::FITKInteractionMultiUsageImpact* _obj{};
        /**
         * @brief  是否创建
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-09-26
         */
        bool _isCreate = false;
    };

}

#endif
