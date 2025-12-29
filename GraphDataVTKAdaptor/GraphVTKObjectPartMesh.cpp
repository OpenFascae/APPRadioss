/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

#include "GraphVTKObjectPartMesh.h"
#include "RadiossVTKGraphActor.h"
#include "GraphDataSetCompomentManager.h"
#include "GraphVTKObjectHighlighting.h"
#include "GraphDataVTKPartSetManager.h"

#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"
#include "FITK_Kernel/FITKAppFramework/FITKAppSettings.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossNodesParts.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossMeshModel.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossCase.h"
#include "FITK_Interface/FITKInterfaceModel/FITKAbstractElement.h"
#include "FITK_Interface/FITKInterfaceModel/FITKUnstructuredMesh.h"
#include "FITK_Interface/FITKInterfaceMesh/FITKMeshFeatureVTK.h"
#include "FITK_Interface/FITKVTKAlgorithm/FITKSurfaceFilter.h"
#include "FITK_Interface/FITKVTKAlgorithm/FITKHighOrderCellFilter.h"
#include "FITK_Interface/FITKVTKAlgorithm/FITKShellFeatureEdges.h"
#include "FITK_Kernel/FITKCore/FITKVec3D.h"

#include <QVector>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkCellData.h>
#include <vtkProperty.h>
#include <vtkUnsignedCharArray.h>
#include <vtkPointData.h>
#include <vtkThreshold.h>
#include <vtkDataSetAlgorithm.h>
#include <vtkMapper.h>
namespace Exchange {
    GraphVTKObjectPartMesh::GraphVTKObjectPartMesh(Radioss::FITKRadiossPart* dataObj) :
        GraphVTKObjectModelBase(dataObj)
    {
        if (dataObj == nullptr) return;
        initActor();
        generateGraph(dataObj);
        updateGraphProperty();
    }
    GraphVTKObjectPartMesh::~GraphVTKObjectPartMesh()
    {
    }
    void GraphVTKObjectPartMesh::generateGraph(Radioss::FITKRadiossPart* part)
    {
        PartMeshDataVTK* partData{ nullptr };
        int partID = part->getDataObjectID();
        bool isTrue = GraphDataVTKPartSetManager::getInstance()->getPartMeshData(partID, partData);
        if (!isTrue || partData == nullptr) return;

        // Create thresholds.
        vtkThreshold* threshold{ nullptr };

        if (partData->_meshFeature)
        {
            FITKSurfaceFilter* surfaceFilter = partData->_meshFeature->getSurfaceFilter();
            FITKShellFeatureEdges* featureEdges = partData->_meshFeature->getFeatureEdgeFilter();
            if (surfaceFilter == nullptr) return;

            // Save the model filter.
            _modelFilter = surfaceFilter;
            _modelEdgeFilter = featureEdges;

            // Generate actors and set the port of surface filter( or high order cell filter ).
            threshold = createOrphanMeshThreshold(1, partData->_filterSurface->GetOutputPort());
            _faceActor->setInputConnection(threshold->GetOutputPort());
            addActor(_faceActor);

            if (_lineActor)
            {
                _lineActor->setInputConnection(threshold->GetOutputPort());
                addActor(_lineActor);
            }

            if (m_graphObjHighlight)
            {
                m_graphObjHighlight->setModelInputConnection(surfaceFilter->GetOutputPort());
            }

            threshold = createOrphanMeshThreshold(0, partData->_filterSurfVert->GetOutputPort());
            _surfPointActor->setInputConnection(threshold->GetOutputPort());
            addActor(_surfPointActor);

            threshold = createOrphanMeshThreshold(0, partData->_filterVertex->GetOutputPort());
            _pointActor->setInputConnection(threshold->GetOutputPort());
            addActor(_pointActor);
        }
        else
        {
            vtkUnstructuredGrid* grid = vtkUnstructuredGrid::SafeDownCast(partData->_meshData);
            _pointActor->setInputDataObject(grid);
            addActor(_pointActor);
            if (m_graphObjHighlight)
            {
                m_graphObjHighlight->setModelInputDataObject(partData->_meshData);
                m_graphObjHighlight->setActorType(ActorType::VertexActor);
                m_graphObjHighlight->setVertexSize(5);
            }
        }
    }
    void GraphVTKObjectPartMesh::initActor()
    {
        Radioss::FITKRadiossPart* part = dynamic_cast<Radioss::FITKRadiossPart*>(_dataObj);
        if (part == nullptr) return;
        QColor color = part->getColor();
        this->setRenderLayer(0);

        _pointActor = RadiossVTKGraphActor::New();
        _pointActor->setActorType(ActorType::VertexActor); //点类型
        _pointActor->SetPickable(false);
        _pointActor->setGraphObject(this);
        _pointActor->SetVisibility(true);
        _pointActor->GetProperty()->SetPointSize(5);
        _pointActor->GetProperty()->SetOpacity(1);
        _pointActor->setRelativeCoincidentTopologyPolygonOffsetParameters(GraphVTKCommons::_mesh3DGraphOffset);

        _lineActor = RadiossVTKGraphActor::New();
        _lineActor->setActorType(ActorType::EdgeActor); //线类型
        _lineActor->SetPickable(false);
        _lineActor->setGraphObject(this);
        _lineActor->setColor(Qt::black);
        _lineActor->GetProperty()->SetRepresentation(1); //线模式
        _lineActor->setRelativeCoincidentTopologyPolygonOffsetParameters(GraphVTKCommons::_mesh3DGraphOffset + 1);

        _faceActor = RadiossVTKGraphActor::New();
        _faceActor->setActorType(ActorType::SurfaceActor); //面类型
        _faceActor->SetPickable(false);
        _faceActor->setGraphObject(this);
        _faceActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
        _faceActor->GetProperty()->SetOpacity(1);
        _faceActor->setRelativeCoincidentTopologyPolygonOffsetParameters(GraphVTKCommons::_mesh3DGraphOffset);
        setLightPropertiesForSurface(_faceActor);

        _surfPointActor = RadiossVTKGraphActor::New();
        _surfPointActor->setActorType(ActorType::VertexActor); //表面点类型
        _surfPointActor->SetPickable(false);
        _surfPointActor->setGraphObject(this);
        _surfPointActor->SetVisibility(false);
        _surfPointActor->GetProperty()->SetPointSize(5);
        _surfPointActor->GetProperty()->SetOpacity(1);
        _surfPointActor->setRelativeCoincidentTopologyPolygonOffsetParameters(GraphVTKCommons::_mesh3DGraphOffset);
    }

    bool GraphVTKObjectPartMesh::updateGraphData(bool forceUpdate)
    {
        Radioss::FITKRadiossPart* part = dynamic_cast<Radioss::FITKRadiossPart*>(_dataObj);
        if (part == nullptr) return false;
        PartMeshDataVTK* partData{ nullptr };
        bool isTrue = GraphDataVTKPartSetManager::getInstance()->getPartMeshData(part->getDataObjectID(), partData, forceUpdate);
        if (!partData || !isTrue) return false;

        if (_faceActor)
            _faceActor->update();
        if(_lineActor)
            _lineActor->update();
        if(_pointActor)
            _pointActor->update();
        return true;
    }
    void GraphVTKObjectPartMesh::updateGraphProperty()
    {
        AppFrame::FITKAppSettings* settings = FITKAPP->getAppSettings();
        if (!settings) return;
        QVariant meshLineWidth = settings->getVarient("GraphSetting/MeshLineWidth");
        if (!meshLineWidth.isValid())
            meshLineWidth = 1;
        QVariant meshPointSize = settings->getVarient("GraphSetting/MeshPointSize");
        if (!meshPointSize.isValid())
            meshPointSize = 5;
        QVariant meshPointColor = settings->getVarient("GraphSetting/MeshPointColor");
        if (!meshPointColor.isValid())
            meshPointColor = QColor(255, 255, 255);
        QVariant meshLineColor = settings->getVarient("GraphSetting/MeshLineColor");
        if (!meshLineColor.isValid())
            meshLineColor = QColor(0, 0, 0);
        updateLineWidth(meshLineWidth.value<double>());
        updatePointSize(meshPointSize.value<double>());
        updateSubColor(meshPointColor.value<QColor>(), 0);
        updateSubColor(meshLineColor.value<QColor>(), 1);
    }

    void GraphVTKObjectPartMesh::update(bool forceUpdate)
    {
        //更新可见
        updateVisibility();

        if (forceUpdate == false)
        {
            return;
        }
        updateGraphData(forceUpdate);
        generateGraph(dynamic_cast<Radioss::FITKRadiossPart*>(_dataObj));
    }
    void GraphVTKObjectPartMesh::updateVisibility()
    {
        //获取运行时设置
        AppFrame::FITKAppSettings* runSetting = FITKAPP->getAppSettings();

        //获取点显示状态
        QVariant pointVisible = true;
        QVariant lineVisible = true;
        QVariant partVisible = true;
        partVisible = runSetting->getVarient("GraphSetting/PartVisible");
        if (!partVisible.isValid())
            partVisible = true;
        lineVisible = runSetting->getVarient("GraphSetting/MeshLineVisible");
        if (!lineVisible.isValid())
            lineVisible = true;
        pointVisible = runSetting->getVarient("GraphSetting/MeshPointVisible");
        if (!pointVisible.isValid())
            pointVisible = true;

        if (_faceActor)
            _faceActor->SetVisibility(partVisible.value<bool>());
        if (_lineActor)
            _lineActor->SetVisibility(lineVisible.value<bool>());
        if (_pointActor)
            _pointActor->SetVisibility(pointVisible.value<bool>());
    }
    void GraphVTKObjectPartMesh::updateSubColor(QColor color, QVariant otherPar)
    {
        if (otherPar.isValid()) {
            int element = otherPar.toInt();
            switch (element) {
            case 0:
                if (_pointActor)
                    _pointActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
                break;
            case 1:
                if (_lineActor)
                    _lineActor->GetProperty()->SetEdgeColor(color.redF(), color.greenF(), color.blueF());
                break;
            default:
                break;
            }
        }
    }
    void GraphVTKObjectPartMesh::updateModelColor(QColor color)
    {
        // 检查对象是否有效
        Radioss::FITKRadiossPart* part = dynamic_cast<Radioss::FITKRadiossPart*>(_dataObj);
        if (part == nullptr) return;
        part->setColor(color);
        // 更新单元演员颜色
        if (_faceActor != nullptr) {
            _faceActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
            _faceActor->GetProperty()->SetOpacity(color.alphaF());
        }
    }
    void GraphVTKObjectPartMesh::updatePointSize(int size)
    {
        if (_pointActor)
            _pointActor->GetProperty()->SetPointSize(size);
    }
    void GraphVTKObjectPartMesh::updateLineWidth(int width)
    {
        if (_lineActor)
            _lineActor->GetProperty()->SetLineWidth(width);
    }
    void GraphVTKObjectPartMesh::setVisible(bool visibility)
    {

        if (visibility == false)
        {
            if (_faceActor)
                _faceActor->SetVisibility(visibility);
            if (_lineActor)
                _lineActor->SetVisibility(visibility);
            if (_pointActor)
                _pointActor->SetVisibility(visibility);
        }
        else
        {
            updateVisibility();
        }
        _isVisible = visibility;
    }
    void GraphVTKObjectPartMesh::setCellVisible(bool visibility)
    {
        if (!_isVisible) return;

        if (_faceActor) {
            _faceActor->SetVisibility(visibility);
        }
    }
    void GraphVTKObjectPartMesh::setPointVisibility(bool visibility)
    {
        if (!_isVisible) return;

        if (_pointActor) {
            _pointActor->SetVisibility(visibility);
        }
    }
    void GraphVTKObjectPartMesh::setLineVisibility(bool visibility)
    {
        if (!_isVisible) return;

        if (_lineActor) {
            _lineActor->SetVisibility(visibility);
        }
    }
    void GraphVTKObjectPartMesh::setPickMode(GraphVTKCommons::ShapePickMode mode)
    {
        auto setActorPickable = [=](RadiossVTKGraphActor* fActor, bool isOn) {
            if (fActor) {
                fActor->SetPickable(isOn);
            }
            };

        switch (mode) {
        case GraphVTKCommons::PickMeshVertex:
            setActorPickable(_pointActor, true);
            setActorPickable(_faceActor, false);
            setActorPickable(_surfPointActor, false);
            break;
        case GraphVTKCommons::PickMeshCell:
            setActorPickable(_pointActor, false);
            setActorPickable(_faceActor, true);
            setActorPickable(_surfPointActor, false);
            break;
        case GraphVTKCommons::PickMeshCellSurf:
            setActorPickable(_pointActor, false);
            setActorPickable(_faceActor, true);
            setActorPickable(_surfPointActor, false);
            break;
        case GraphVTKCommons::PickMeshVertexSurf:
            setActorPickable(_pointActor, false);
            setActorPickable(_faceActor, false);
            setActorPickable(_surfPointActor, true);
            _surfPointActor->SetVisibility(true);
            break;
        default:
            setActorPickable(_pointActor, false);
            setActorPickable(_faceActor, false);
            setActorPickable(_surfPointActor, false);
            _surfPointActor->SetVisibility(false);
            break;
        }

        //记录拾取类型
        GraphVTKObject3D::setPickMode(mode);
    }
    int GraphVTKObjectPartMesh::getShapeIdByVTKCellId(int vtkCellId, GraphVTKCommons::ShapePickMode pickType, QVariant otherInfo)
    {
        int shapeID = -1;
        Radioss::FITKRadiossPart* part = dynamic_cast<Radioss::FITKRadiossPart*>(_dataObj);
        if (part == nullptr) return false;
        PartMeshDataVTK* partData{ nullptr };
        bool isTrue = GraphDataVTKPartSetManager::getInstance()->getPartMeshData(part->getDataObjectID(), partData);
        if (!partData || !isTrue) return false;

        switch (pickType)
        {
        case GraphVTKCommons::PickMeshVertex: {
            vtkIntArray* idsArray = vtkIntArray::SafeDownCast(partData->_meshData->GetPointData()
                ->GetArray(VTKID_BY_NODEID_ARRAY_NAME));
            shapeID = idsArray->GetValue(vtkCellId);
            break;
        }
        case GraphVTKCommons::PickMeshCell: {
            FITKSurfaceFilter* surfaceFilter = partData->_meshFeature->getSurfaceFilter();
            vtkIntArray* idsArray = vtkIntArray::SafeDownCast(partData->_meshData->GetCellData()
                ->GetArray(VTKID_BY_NODEID_ARRAY_NAME));
            int orgCellIndex = -1;
            int faceIndex = -1;
            surfaceFilter->getSurfaceCellInfo(vtkCellId, orgCellIndex, faceIndex);
            shapeID = idsArray->GetValue(orgCellIndex);
            break;
        }
        case GraphVTKCommons::PickMeshVertexSurf: {
            FITKSurfaceFilter* surfaceFilter = partData->_meshFeature->getSurfaceFilter();
            vtkIntArray* idsArray = vtkIntArray::SafeDownCast(partData->_meshData->GetPointData()
                ->GetArray(VTKID_BY_NODEID_ARRAY_NAME));
            int orgPointIndex = surfaceFilter->getOriginPointIdBySurfacePointId(vtkCellId);

            shapeID = idsArray->GetValue(orgPointIndex);
            break;
        }
        }

        return shapeID;
    }
    const QVector<int> GraphVTKObjectPartMesh::getVTKCellIdsByShapeId(int shapeId, GraphVTKCommons::ShapePickMode pickType, QVariant otherInfo)
    {
        QVector<int> vtkIds;
        Radioss::FITKRadiossPart* part = dynamic_cast<Radioss::FITKRadiossPart*>(_dataObj);
        if (part == nullptr) return vtkIds;
        PartMeshDataVTK* partData{ nullptr };
        bool isTrue = GraphDataVTKPartSetManager::getInstance()->getPartMeshData(part->getDataObjectID(), partData);
        if (!partData || !isTrue) return vtkIds;

        switch (pickType)
        {
        case GraphVTKCommons::PickMeshVertex: 
        case GraphVTKCommons::PickMeshVertexSurf: {
            vtkIntArray* idsArray = vtkIntArray::SafeDownCast(partData->_meshData->GetPointData()
                ->GetArray(NODEID_BY_VTKID_ARRAY_NAME));
            int vtkid = idsArray->GetValue(shapeId);
            vtkIds.append(vtkid);
            break;
        }
        }
        return vtkIds;
    }
    bool GraphVTKObjectPartMesh::getVisibility()
    {
        Radioss::FITKRadiossPart* part = dynamic_cast<Radioss::FITKRadiossPart*>(_dataObj);
        if (part == nullptr) {
            return false;
        }

        return this->Superclass::getVisibility();
    }
}
