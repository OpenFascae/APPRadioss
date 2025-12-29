#include "OperGmshSettings.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "OperatorsInterface/GraphEventOperator.h"

#include "FITK_Component/FITKGmshExeDriver/GUIGmshSettings.h"
#include <QWidget>

bool ModelOper::OperGmshSettings::execGUI(){
    ////获取动作名称
    //QString actionName = _emitter->objectName();
    //QWidget* mw = FITKAPP->getGlobalData()->getMainWindow();
    //if (!mw) return false;
    //if (actionName == "actionGmshSettings")
    //{
    //    GUI::GUIGmshSettings* dialog = new GUI::GUIGmshSettings(this,mw);
    //    dialog->show();
    //}
    return false;
}

bool ModelOper::OperGmshSettings::execProfession()
{


    return true;
}
