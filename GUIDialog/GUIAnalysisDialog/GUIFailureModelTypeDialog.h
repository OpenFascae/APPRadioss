/**********************************************************************
 * @file   GUIFailureModelTypeDialog.h
 * @brief  失效模型类型选择对话框声明
 * @author liuzhonghua (liuzhonghuaszch@163.com)
 * @date   2025-11-10
 *********************************************************************/
#ifndef _GUIFailureModelTypeDialog_H
#define _GUIFailureModelTypeDialog_H

#include <QDialog>
#include "GUIAnalysisDialogAPI.h"

namespace Ui
{
    class GUIFailureModelTypeDialog;
}
namespace GUI
{
    /**
     * @brief  失效模型类型选择对话框声明
     * @author liuzhonghua (liuzhonghuaszch@163.com)
     * @date   2025-11-10
     */
    class GUIAnalysisDialogAPI GUIFailureModelTypeDialog : public QDialog
    {
        Q_OBJECT
    public:
        explicit GUIFailureModelTypeDialog(QWidget* parent = nullptr);
        ~GUIFailureModelTypeDialog();

        /**
         * @brief    获取创建类型
         * @return   int
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-11-10
         */
        int selectedFailureModelType() const;
        /**
         * @brief    获取名称
         * @return   QString
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-11-10
         */
        QString getFailureModelName();

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

    private:
        Ui::GUIFailureModelTypeDialog* _ui{};
    };
}

#endif
