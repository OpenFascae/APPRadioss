#include "OperatorCreateSolution.h"
#include "GUIDialog/GUIAnalysisDialog/GUICreateSolutionDialog.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossCase.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossSolution.h"
#include "OperatorsInterface/TreeEventOperator.h"
#include "GUIFrame/MainWindow.h"
#include "GUIWidget/ControlPanel.h"
#include "GUIWidget/TreeWidgetSolution.h"

bool ModelOper::OperatorCreateSolution::execGUI()
{
    GUI::GUICreateSolutionDialog dlg;
    if (dlg.exec() != QDialog::Accepted)return false;
    QString name = dlg.getSolutionName();
    Radioss::FITKRadiossCase* caseObj = FITKAPP->getGlobalData()->
        getPhysicsData<Radioss::FITKRadiossCase>();
    if (!caseObj) return false;
    auto matMgr = caseObj->getSolutionManager();
    if(!matMgr) return false;

    Radioss::FITKRadiossSolution* solution = new Radioss::FITKRadiossSolution;
    solution->setDataObjectName(name);
    matMgr->appendDataObj(solution);

    return true;
}

bool ModelOper::OperatorCreateSolution::execProfession()
{
    //更新树的操作
    GUI::MainWindow* mainWindow = GUI::MainWindow::GetMainWindowFromFramework();
    if (!mainWindow) return false;
    GUI::ControlPanel* controlPanel = mainWindow->getControlPanel();
    if (!controlPanel) return false;
    GUI::TreeWidgetSolution* TreeWidgetSolution = controlPanel->getSolutionTree();
    if (!TreeWidgetSolution) return false;
    TreeWidgetSolution->updateTreeWidget();

    return false;
}
