#include "OperGmshSettings.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "GUIDialog/GUIPostDialog/GUISolverSettingDialog.h"

#include "OperatorsInterface/GraphEventOperator.h"
#include "OperSolverSettings.h"


namespace ModelOper
{
    bool OperSolverSettings::execGUI()
    {
        GUI::GUISolverSettingDialog* dialog = new GUI::GUISolverSettingDialog(this, FITKAPP->getGlobalData()->getMainWindow());
        dialog->show();
        return false;
    }
    bool OperSolverSettings::execProfession()
    {
        return true;
    }
}
