/**********************************************************************
 * @file   GUIMaterialTypeDialog.h
 * @brief  材料类型选择对话框声明
 * @author wangning (2185896382@qq.com)
 * @date   2025-05-23
 *********************************************************************/
#ifndef _GUIMaterialTypeDialog_H
#define _GUIMaterialTypeDialog_H

#include <QDialog>
#include "GUIAnalysisDialogAPI.h"

namespace Ui
{
    class GUIMaterialTypeDialog;
}

namespace GUI
{
    /**
     * @brief 材料类型选择对话框
     */
    class GUIAnalysisDialogAPI GUIMaterialTypeDialog : public QDialog
    {
        Q_OBJECT
    public:
        explicit GUIMaterialTypeDialog(QWidget* parent = nullptr);
        ~GUIMaterialTypeDialog();

        /**
         * @brief 获取用户选择的材料类型
         * @return 材料类型
         */
        int selectedMaterialType() const;
        /**
         * @brief    获取材料名称
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-26
         */
        QString getMaterialName();
    private slots:

        /**
        * @brief OK按钮信号
        * @return 
        */
        void on_pushButtonOK_clicked();
        /**
        * @brief cancle按钮信号
        * @return 
        */
        void on_pushButtonCancel_clicked();
        /**
         * @brief    切换材料类型
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-08-26
         */
        void on_comboBox_type_currentIndexChanged(int index);

    private:
        /**
         * @brief  ui
         * @author guqingtao (15598887859@163.com)
         * @date   2025-08-26
         */
        Ui::GUIMaterialTypeDialog* _ui{};
    };
}

#endif
