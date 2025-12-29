#include "MessageTableWidget.h"

#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKComponents.h"  
#include "FITK_Component/FITKCompMessageWidget/FITKConsoleComponent.h"
#include "FITK_Kernel/FITKPython/FITKPythonInterface.h" 

namespace GUI
{
    MessageTabWidget::MessageTabWidget(QWidget * parent)
    {
        // 尝试从FITK应用程序中获取名为"MessageConsole"的组件，并将其添加到UI的tab_message标签页中
        auto conWidgetComp = FITKAPP->getComponents()->getComponentByName("MessageConsole");
        Comp::ConsoleComponent *conWidgetInter = dynamic_cast<Comp::ConsoleComponent *>(conWidgetComp);
        if (nullptr != conWidgetInter) 
        {
            this->addTab(conWidgetInter->getWidget(0), tr("Log"));
        }
        // python 窗口
        QWidget* pw = Python::FITKPythonInterface::getInstance()->getPyWidget();
        if (pw)
        {
            this->addTab(pw, tr("Python"));
        }

        this->setTabPosition(QTabWidget::South);
             
    }

    MessageTabWidget::~MessageTabWidget()
    {

    }
}

