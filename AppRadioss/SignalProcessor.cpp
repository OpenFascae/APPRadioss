#include "SignalProcessor.h"
#include "FITK_Kernel/FITKAppFramework/FITKMessage.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "GUIFrame/MainWindow.h"

void SignalProcessor::on_sendProgramDriverMessageSig(AppFrame::FITKAbstractProgramerDriver* driver, int messageType, const QString& message)
{
    //显示信息
    AppFrame::FITKMessageInfo(message);
}

void SignalProcessor::on_sendProcessSig(QObject* sender, int process)
{
    //获取主页面
    GUI::MainWindow* mw = FITKAPP->getGlobalData()->getMainWindowT<GUI::MainWindow>();
    if (mw == nullptr) return;
    //设置进度值
    mw->setProgressValue(process);
}

