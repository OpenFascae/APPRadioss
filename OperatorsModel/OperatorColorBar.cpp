#include "OperatorColorBar.h"
#include "GUIDialog/GUIPostDialog/GUIColorBarDialog.h"
#include "OperatorsInterface/GraphEventOperator.h"

bool ModelOper::OperatorColorBar::execGUI()
{
    EventOper::GraphEventOperator* graphOper = Core::FITKOperatorRepo::getInstance()
        ->getOperatorT<EventOper::GraphEventOperator>("GraphPostProcess");
    if (!graphOper)return false;

    GUI::GUIColorBarDialog dlg(graphOper);
    dlg.exec();
    return false;
}

bool ModelOper::OperatorColorBar::execProfession()
{
    return false;
}
