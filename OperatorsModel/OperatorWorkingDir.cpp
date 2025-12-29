#include "OperatorWorkingDir.h"
#include "FITK_Component/FITKWidget/FITKWorkingDirDialog.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"

bool GUIOper::OperatorWorkingDir::execGUI()
{
    //主界面
    AppFrame::FITKGlobalData* g = FITKAPP->getGlobalData();
    if (g == nullptr) return false;
    //弹出对话框
    Comp::FITKWorkingDirDialog d(g->getMainWindow());
    return d.exec() == QDialog::Accepted;
}
