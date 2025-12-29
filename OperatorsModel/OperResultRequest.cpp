#include "OperResultRequest.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "GUIDialog/GUIPostDialog/GUIRadiossResultRequestDialog.h"

namespace ModelOper
{
    bool OperResultRequest::execGUI()
    {
        GUI::GUIRadiossResultRequestDialog* dialog = new GUI::GUIRadiossResultRequestDialog(this, FITKAPP->getGlobalData()->getMainWindow());
        dialog->show();
        return false;
    }
    bool OperResultRequest::execProfession()
    {
        return true;
    }
}
