#include "OperGraphSetting.h"

#include "GUIFrame/MainWindow.h"
#include "GUIDialog/GUIToolDialog/GUIGraphSettingDialog.h"
#include "OperatorsInterface/GraphEventOperator.h"

#include "FITK_Kernel/FITKAppFramework/FITKAppSettings.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"

#include <QAction>
namespace OperModel
{
    bool OperGraphSetting::execGUI()
    {

        GUI::MainWindow* mw = GUI::MainWindow::GetMainWindowFromFramework();
        if (mw == nullptr) return false;
        QString name = _emitter->objectName();
        if (name.isEmpty()) return false;
        //获取触发当前操作的action
        QAction* action = mw->findChild<QAction*>(name);
        if (action == nullptr) return false;
        AppFrame::FITKAppSettings* appSettings = FITKAPP->getAppSettings();
        if (appSettings == nullptr) return false;
        EventOper::GraphEventOperator* graphOper = FITKOPERREPO->getOperatorT<EventOper::GraphEventOperator>("GraphPreprocess");
        if (graphOper == nullptr) return false;
        if (name == "actionPointVisible")
        {
            //设置几何点的显示隐藏状态
            QVariant isEnable = appSettings->getVarient("GraphSetting/GeoPointVisible");
            if (!isEnable.isValid())
            {
                isEnable = true;
            }
            graphOper->setPointVisible(!isEnable.value<bool>(), false, false);
            if (!isEnable.value<bool>())
            {
                action->setIcon(QIcon(":/toolBar/visibleGeoPoint.png"));
                appSettings->setValue("GraphSetting/GeoPointVisible", true);
            }
            else {
                action->setIcon(QIcon(":/toolBar/no_visibleGeoPoint.png"));
                appSettings->setValue("GraphSetting/GeoPointVisible", false);
            }

        }
        else if (name == "actionLineVisible")
        {
            //设置几何线的显示隐藏状态
            QVariant isEnable = appSettings->getVarient("GraphSetting/GeoLineVisible");
            if(!isEnable.isValid())
            {
                isEnable = true;
            }
            graphOper->setLineVisible(!isEnable.value<bool>(), false, false);
            if (!isEnable.value<bool>())
            {
                action->setIcon(QIcon(":/toolBar/visibleGeoLine.png"));
                appSettings->setValue("GraphSetting/GeoLineVisible", true);
            }
            else {
                action->setIcon(QIcon(":/toolBar/no_visibleGeoLine.png"));
                appSettings->setValue("GraphSetting/GeoLineVisible", false);
            }

        }
        else if (name == "actionGeoVisible")
        {
            //设置几何的显示隐藏状态
            name = "Geo";
            QVariant isEnable = appSettings->getVarient("GraphSetting/GeoVisible");
            if (!isEnable.isValid())
            {
                isEnable = true;
            }
            graphOper->setAllModelVisible(!isEnable.value<bool>(), false, false);
            if (!isEnable.value<bool>())
            {
                action->setIcon(QIcon(":/toolBar/visibleGeo.png"));
                appSettings->setValue("GraphSetting/GeoVisible", true);
            }
            else {
                action->setIcon(QIcon(":/toolBar/no_visibleGeo.png"));
                appSettings->setValue("GraphSetting/GeoVisible", false);
            }

        }
        else if (name == "actionMeshPointVisible")
        {
            //设置网格点的显示隐藏状态
            name = "MeshPoint";
            QVariant isEnable = appSettings->getVarient("GraphSetting/MeshPointVisible");
            if(!isEnable.isValid())
            {
                isEnable = true;
            }
            graphOper->setPointVisible(!isEnable.value<bool>(), true, false);
            if (!isEnable.value<bool>())
            {
                action->setIcon(QIcon(":/toolBar/visibleMeshPoint.png"));
                appSettings->setValue("GraphSetting/MeshPointVisible", true);
            }
            else {
                action->setIcon(QIcon(":/toolBar/no_visibleMeshPoint.png"));
                appSettings->setValue("GraphSetting/MeshPointVisible", false);
            }
        }
        else if (name == "actionMeshLineVisible")
        {
            //设置网格线的显示隐藏状态
            name = "MeshLine";
            QVariant isEnable = appSettings->getVarient("GraphSetting/MeshLineVisible");
            if(!isEnable.isValid())
            {
                isEnable = true;
            }
            graphOper->setLineVisible(!isEnable.value<bool>(), true, false);
            if (!isEnable.value<bool>())
            {
                action->setIcon(QIcon(":/toolBar/visibleMeshLine.png"));
                appSettings->setValue("GraphSetting/MeshLineVisible", true);
            }
            else {
                action->setIcon(QIcon(":/toolBar/no_visibleMeshLine.png"));
                appSettings->setValue("GraphSetting/MeshLineVisible", false);
            }

        }
        else if (name == "actionPartVisible")
        {
            //设置Part的显示隐藏状态
            name = "Part";
            QVariant isEnable = appSettings->getVarient("GraphSetting/PartVisible");
            if (!isEnable.isValid())
            {
                isEnable = true;
            }
            graphOper->setAllModelVisible(!isEnable.value<bool>(), true, false);
            if (!isEnable.value<bool>())
            {
                action->setIcon(QIcon(":/toolBar/visiblePart.png"));
                appSettings->setValue("GraphSetting/PartVisible", true);
            }
            else {
                action->setIcon(QIcon(":/toolBar/no_visiblePart.png"));
                appSettings->setValue("GraphSetting/PartVisible", false);
            }

        }
        else if (name == "actionGraphSetting")
        {
            GUI::GUIGraphSettingDialog* dialog = new GUI::GUIGraphSettingDialog(this, mw);
            if (dialog == nullptr) return false;
            dialog->show();
        }
        
        return true;
    }
    bool OperGraphSetting::execProfession()
    {
        return true;
    }

}
