#include "OperGraphEvent3D.h"

#include "GraphDataProvider/GraphProviderManager.h"
#include "GraphDataProvider/GraphModelProvider.h"
#include "GraphDataProvider/GraphMarkProvider.h"
#include "GraphDataVTKAdaptor/GraphVTKObject3D.h"
#include "GUIFrame/MainWindow.h"
#include "GUIFrame/CentralWidget.h"
#include "GUIWidget/GraphArea.h"
#include "GUIWidget/GraphMdiArea.h"
#include "GUIWidget/PostGraphWidget.h"

#include "FITK_Kernel/FITKCore/FITKDataRepo.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "FITK_Component/FITKRenderWindowVTK/FITKGraph3DWindowVTK.h"
#include "FITK_Component/FITKRenderWindowVTK/FITKGraphRender.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossNodesParts.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossMeshModel.h"
#include "FITK_Component/FITKRadiossData/FITKAbstractRWall.h"
#include "FITK_Component/FITKRadiossData/FITKGravity.h"
#include "FITK_Component/FITKRadiossData/FITKInitialField.h"
#include "FITK_Component/FITKRadiossData/FITKAbstractBCS.h"
#include "FITK_Component/FITKRadiossData/FITKAbstractInteraction.h"
#include "FITK_Component/FITKRadiossData/FITKAbstractConnection.h"
#include "FITK_Component/FITKRadiossData/FITKAbstractProbe.h"
#include "FITK_Interface/FITKInterfaceGeometry/FITKAbsGeoCommand.h"
#include "FITK_Interface/FITKInterfaceModel/FITKElementList.h"
#include "FITK_Interface/FITKInterfaceModel/FITKModelSet.h"
#include "FITK_Interface/FITKInterfaceModel/FITKMeshSurface.h"
namespace GUIOper {
    void OperGraphEvent3D::render()
    {
        GUI::GraphArea* graphWidget = getGraphWidget(GUI::GraphAreaType::GATPre);
        if (graphWidget) {
            graphWidget->reRender();
        }

        graphWidget = getGraphWidget(GUI::GraphAreaType::GATPost);
        if (graphWidget) {
            graphWidget->reRender();
        }
    }

    void OperGraphEvent3D::fitView()
    {
        GUI::GraphArea* graphWidget = getGraphWidget(GUI::GraphAreaType::GATPre);
        if (graphWidget) {
            graphWidget->fitView();
        }

        graphWidget = getGraphWidget(GUI::GraphAreaType::GATPost);
        if (graphWidget) {
            graphWidget->fitView();
        }
    }

    GUI::GraphArea* OperGraphEvent3D::getGraphWidget(GUI::GraphAreaType type)
    {
        // 获取主窗口。
        GUI::MainWindow* mainWindow = FITKAPP->getGlobalData()->getMainWindowT<GUI::MainWindow>();
        if (!mainWindow) {
            return nullptr;
        }

        // 获取中心区域
        GUI::CentralWidget* centralWidget = mainWindow->getCentralWidget();
        if (!centralWidget) {
            return nullptr;
        }

        GUI::GraphMdiArea* graphArea = centralWidget->getGraphMidArea();
        if (!graphArea) {
            return nullptr;
        }
        return graphArea->getFirstGraphArea(type);
    }

    GUI::GraphArea* OperGraphEvent3D::createGraphWidget(GUI::GraphAreaType type)
    {
        // 获取主窗口。
        GUI::MainWindow* mainWindow = FITKAPP->getGlobalData()->getMainWindowT<GUI::MainWindow>();
        if (!mainWindow) {
            return nullptr;
        }
        // 获取中心区域
        GUI::CentralWidget* centralWidget = mainWindow->getCentralWidget();
        if (!centralWidget) {
            return nullptr;
        }
        GUI::GraphMdiArea* graphArea = centralWidget->getGraphMidArea();
        if (!graphArea) {
            return nullptr;
        }
        int id = graphArea->addSubWidget(new GUI::PostGraphWidget(centralWidget), "post");
        centralWidget->addPostWidgetId(id);
        
        return graphArea->getGraphAreaByID(id);
       
    }

    QList<GUI::GraphArea*> OperGraphEvent3D::getAllGraphWidget(GUI::GraphAreaType type)
    { 
        QList<GUI::GraphArea*> graphWidgets;
        // 获取主窗口。
        GUI::MainWindow* mainWindow = FITKAPP->getGlobalData()->getMainWindowT<GUI::MainWindow>();
        if (!mainWindow) {
            return graphWidgets;
        }
        // 获取中心区域
        GUI::CentralWidget* centralWidget = mainWindow->getCentralWidget();
        if (!centralWidget) {
            return graphWidgets;
        }
        GUI::GraphMdiArea* graphArea = centralWidget->getGraphMidArea();
        if (!graphArea) {
            return graphWidgets;
        }
        return graphArea->getAllGraphArea(type);
    }

    void OperGraphEvent3D::addGraphObjectToWidget(Exchange::GraphVTKObject3D* obj, GUI::GraphArea* graphWidget, bool fitView)
    {
        if (!obj || !graphWidget)
        {
            return;
        }

        // 添加可视化对象。
        obj->removeFromGraphWidget();
        graphWidget->addObject(obj->getRenderLayer(), obj, false);
        obj->setRenderer(graphWidget->getRenderWindow()->getRenderer(obj->getRenderLayer())->getRenderer());


        //刷新窗口
        if (fitView) {
            graphWidget->fitView();
        }
        else {
            graphWidget->reRender();
        }
    }

    void OperGraphEvent3D::addGraphHightlightObjectToWidget(Exchange::GraphVTKObject3D * obj, GUI::GraphArea * graphWidget)
    {
        if (obj == nullptr || graphWidget == nullptr) return;
        //添加可视化对象
        obj->removeFromGraphWidget();

        //获得附加可视化对象链表
        QList<Exchange::GraphVTKObject3D*> addinObjs = obj->getAddinGraphObjs();
        for (Exchange::GraphVTKObject3D* addinObj : addinObjs)
        {
            addinObj->removeFromGraphWidget();
        }
        //获取图层
        int layer = obj->getRenderLayer();
        graphWidget->addObject(layer, obj, false);
        //添加至高亮图层
        for(Exchange::GraphVTKObject3D* addinObj : addinObjs)
        {
            int layer = addinObj->getRenderLayer();
            graphWidget->addObject(layer, addinObj, false);
        }
       
        //刷新窗口
        graphWidget->reRender();
    }

    QList<Exchange::GraphVTKObject3D*> OperGraphEvent3D::getGraphObjectsByDataId(int dataObjId, QVariant otherInfo)
    {
        QList<Exchange::GraphVTKObject3D*> objs;

        // 获取可视化窗口。
        GUI::GraphArea* graphWidget = getGraphWidget(GUI::GraphAreaType::GATPre);
        if (!graphWidget) {
            return objs;
        }

        // 获取模型与符号可视化对象管理器。
        GraphData::GraphModelProvider* modelProvider = GraphData::GraphProviderManager::getInstance()->getModelProvider(graphWidget->getRenderWindow());
        GraphData::GraphMarkProvider* markProvider = GraphData::GraphProviderManager::getInstance()->getMarkProvider(graphWidget->getRenderWindow());
        if (!modelProvider || !markProvider) {
            return objs;
        }
        // 检查是否为几何命令对象
        Interface::FITKAbsGeoCommand* geoCommand = Core::FITKDataRepo::getInstance()->getTDataByID<Interface::FITKAbsGeoCommand>(dataObjId);
        if (geoCommand) {
            // 直接使用几何命令ID获取可视化对象
            Exchange::GraphVTKObject3D* obj = modelProvider->getModelGraphObject(dataObjId);
            if (obj) {
                objs.append(obj);
            }
        }
        //检查是否为part对象
        Radioss::FITKRadiossPart* part = Core::FITKDataRepo::getInstance()->getTDataByID<Radioss::FITKRadiossPart>(dataObjId);
        if (part) {
            objs << modelProvider->getPartGraphObject(dataObjId);
        }
        //检查是否为刚体墙对象
        Radioss::FITKAbstractRWall* rwall = Core::FITKDataRepo::getInstance()->getTDataByID<Radioss::FITKAbstractRWall>(dataObjId);
        if (rwall) {
            objs << modelProvider->getRWallGraphObject(dataObjId);
        }
        //检查是否为重力载荷对象
        Radioss::FITKGravity* gravity = Core::FITKDataRepo::getInstance()->getTDataByID<Radioss::FITKGravity>(dataObjId);
        if (gravity) {
            objs << modelProvider->getGravityGraphObject(dataObjId);
            //检查重力载荷内是否有集合
            /*Interface::FITKModelSet* set = Core::FITKDataRepo::getInstance()->getTDataByID <Interface::FITKModelSet>(gravity->getNodeGroupID());
            if(set)
            {
                if (!otherInfo.isValid()) {
                    otherInfo = -1;
                }
                objs << modelProvider->getGraphObjSetOrSurface(set->getDataObjectID(),otherInfo.toInt());
            };*/
        }
        //判断是不是初始化场
        Radioss::FITKAbstractInitialField* initField = Core::FITKDataRepo::getInstance()->getTDataByID<Radioss::FITKAbstractInitialField>(dataObjId);
        if(initField) {
            objs << modelProvider->getFiledGraphObject(dataObjId);
        }
        //判断是不是边界条件
        Radioss::FITKAbstractBCS* bc = Core::FITKDataRepo::getInstance()->getTDataByID<Radioss::FITKAbstractBCS>(dataObjId);
        if (bc) {
            objs << modelProvider->getBCSGraphObject(dataObjId);
        }
        //判断是不是相互作用
        Radioss::FITKAbstractInteraction* interaction = Core::FITKDataRepo::getInstance()->getTDataByID<Radioss::FITKAbstractInteraction>(dataObjId);
        if (interaction) {
            objs << modelProvider->getInteractionGraphObject(dataObjId);
        }
        //判断是不是连接
        Radioss::FITKAbstractConnection* connection = Core::FITKDataRepo::getInstance()->getTDataByID<Radioss::FITKAbstractConnection>(dataObjId);
        if (connection) {
            objs << modelProvider->getConnectionGraphObject(dataObjId);
        }
        //判断是不是探针
        Radioss::FITKAbstractProbe* probe = Core::FITKDataRepo::getInstance()->getTDataByID<Radioss::FITKAbstractProbe>(dataObjId);
        if (probe)
        {
            objs << modelProvider->getProbeGraphObject(dataObjId);
        }
        //判断是否是集合或表面
        Interface::FITKModelSet* modelSet = Core::FITKDataRepo::getInstance()->getTDataByID<Interface::FITKModelSet>(dataObjId);
        Interface::FITKMeshSurface* surface = FITKDATAREPO->getTDataByID<Interface::FITKMeshSurface>(dataObjId);
        if (modelSet || surface && objs.isEmpty())
        {

            //第一位为instance数据ID，可以为-1。
            if (!otherInfo.isValid()) {
                otherInfo = -1;
            }

            objs << modelProvider->getGraphObjSetOrSurface(dataObjId, otherInfo.toInt());
        }
        return objs;
    }
    
    QList<Exchange::GraphVTKObject3D*> OperGraphEvent3D::getPartGeoGraphObjectsByDataId(int dataObjId)
    {
        QList<Exchange::GraphVTKObject3D*> objs;
        //获取可视化窗口
        GUI::GraphArea* graphWidget = getGraphWidget(GUI::GraphAreaType::GATPre);
        if (!graphWidget) return objs;

        //获取模型与符号可视化对象管理器
        GraphData::GraphModelProvider* modelProvider = GraphData::GraphProviderManager::getInstance()->getModelProvider(graphWidget->getRenderWindow());
        if (modelProvider == nullptr) return objs;

        Interface::FITKAbsGeoCommand* geoCommand = Core::FITKDataRepo::getInstance()->getTDataByID<Interface::FITKAbsGeoCommand>(dataObjId);
        if (geoCommand) {
            objs << modelProvider->getModelGraphObject(dataObjId);
        }

        //检查是否为part对象
        Radioss::FITKRadiossPart* part = Core::FITKDataRepo::getInstance()->getTDataByID<Radioss::FITKRadiossPart>(dataObjId);
        if (part) {
            objs << modelProvider->getPartGraphObject(dataObjId);
        }
        return objs;
    }

    QList<Exchange::GraphVTKObject3D*> OperGraphEvent3D::getAllGraphObject()
    {
        QList<Exchange::GraphVTKObject3D*> objs = {};
        // 获取可视化窗口。
        GUI::GraphArea* graphWidget = getGraphWidget(GUI::GraphAreaType::GATPre);
        if (!graphWidget) {
            return objs;
        }

        // 获取模型与符号可视化对象管理器。
        GraphData::GraphModelProvider* modelProvider = GraphData::GraphProviderManager::getInstance()->getModelProvider(graphWidget->getRenderWindow());
        GraphData::GraphMarkProvider* markProvider = GraphData::GraphProviderManager::getInstance()->getMarkProvider(graphWidget->getRenderWindow());
        if (modelProvider == nullptr || markProvider == nullptr) {
            return objs;
        }

        objs.append(modelProvider->getAllGraphObjects());
        return objs;
    }

    QList<Exchange::GraphVTKObject3D*> OperGraphEvent3D::getAllGeoGraphObject()
    {
        QList<Exchange::GraphVTKObject3D*> objs = {};
        // 获取可视化窗口。
        GUI::GraphArea* graphWidget = getGraphWidget(GUI::GraphAreaType::GATPre);
        if (!graphWidget) {
            return objs;
        }

        // 获取模型与符号可视化对象管理器。
        GraphData::GraphModelProvider* modelProvider = GraphData::GraphProviderManager::getInstance()->getModelProvider(graphWidget->getRenderWindow());
        GraphData::GraphMarkProvider* markProvider = GraphData::GraphProviderManager::getInstance()->getMarkProvider(graphWidget->getRenderWindow());
        if (modelProvider == nullptr || markProvider == nullptr) {
            return objs;
        }
        objs.append(modelProvider->getAllGeoGraphObjects());
        return objs;
    }

    QList<Exchange::GraphVTKObject3D*> OperGraphEvent3D::getAllMeshGraphObject()
    {
        QList<Exchange::GraphVTKObject3D*> objs = {};
        // 获取可视化窗口。
        GUI::GraphArea* graphWidget = getGraphWidget(GUI::GraphAreaType::GATPre);
        if (!graphWidget) {
            return objs;
        }

        // 获取模型与符号可视化对象管理器。
        GraphData::GraphModelProvider* modelProvider = GraphData::GraphProviderManager::getInstance()->getModelProvider(graphWidget->getRenderWindow());
        GraphData::GraphMarkProvider* markProvider = GraphData::GraphProviderManager::getInstance()->getMarkProvider(graphWidget->getRenderWindow());
        if (modelProvider == nullptr || markProvider == nullptr) {
            return objs;
        }
        objs.append(modelProvider->getAllMeshGraphObjects());
        return objs;
    }
    

    void OperGraphEvent3D::updateGraphRecursively(int dataObjId, int refLayer, bool recDown)
    {
        // 检查数据ID。
        Interface::FITKAbsGeoCommand* cmd = FITKDATAREPO->getTDataByID<Interface::FITKAbsGeoCommand>(dataObjId);
        if (!cmd) {
            return;
        }

        // 更新可视化对象。
        updateGraph(dataObjId);

        // 更新引用数据对象。
        if (refLayer != 0)
        {
            int subLayer = refLayer == -1 ? -1 : refLayer - 1;

            if (recDown)
            {
                int nRefedCmd = cmd->getReferencedCmdCount();
                for (int i = 0; i < nRefedCmd; i++)
                {
                    Interface::FITKAbsGeoCommand* cmdRef = cmd->getReferencedCmdByIndex(i);
                    if (!cmdRef)
                    {
                        continue;
                    }

                    // 递归更新。
                    updateGraphRecursively(cmdRef->getDataObjectID(), subLayer, recDown);
                }
            }
            else
            {
                int nRefCmd = cmd->getReferenceCmdCount();
                for (int i = 0; i < nRefCmd; i++)
                {
                    Interface::FITKAbsGeoCommand* cmdRef = cmd->getReferenceCmdByIndex(i);
                    if (!cmdRef)
                    {
                        continue;
                    }

                    // 递归更新。
                    updateGraphRecursively(cmdRef->getDataObjectID(), subLayer, recDown);
                }
            }
        }
    }


}


