#include "OperLicense.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"

bool GUIOper::OperLicense::execGUI()
{
    //显示版权信息
    FITKAPP->showCopyrightDlg();

    return false;
}