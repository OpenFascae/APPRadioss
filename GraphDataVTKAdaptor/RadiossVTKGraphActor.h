/*
 * Copyright (c) 2020-2026, Qingdao Digital Intelligent Ship & Ocean Technology Co., Ltd.
 * All rights reserved.
 *
 * This file is part of FastCAE and is distributed under the terms of the
 * BSD 3-Clause License. See the LICENSE file in the project root for details.
 */

/**********************************************************************
 * @file   RadiossVTKGraphActor.h
 * @brief  External vtkActor with some common functions.
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-07-23
 *********************************************************************/
#ifndef _RADIOSSVTKGRAPHACTOR_H__
#define _RADIOSSVTKGRAPHACTOR_H__

#include "GraphDataVTKAdaptorAPI.h"
#include "GraphVTKCommons.h"
#include "FITK_Interface/FITKVTKAlgorithm/FITKGraphActor.h"
#include "FITK_Interface/FITKVTKAlgorithm/FITKActorClipTool.h"

#include <vtkActor.h>
#include <vtkObjectFactory.h>
#include <vtkRenderingCoreModule.h>

#include <QColor>
namespace Comp
{
    class FITKGraphObjectVTK;
}
class vtkDataSetMapper;
class vtkAlgorithmOutput;
class vtkDataObject;

/**
 * @brief  Sub-class of vtkActor, add some new interfaces for setting input.
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-07-23
 */
class GraphDataVTKAdaptorAPI RadiossVTKGraphActor : public vtkActor, public FITKActorClipTool
{
public:
    vtkTypeMacro(RadiossVTKGraphActor, vtkActor);
    /**
     * @brief  VTK new
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-07-23
     */
    static RadiossVTKGraphActor* New();
    /**
     * @brief  Set the mapper.[override]
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-07-23
     */
    void SetMapper(vtkMapper* mapper) override;

    /**
     * @brief   Set the polygon offset.
     * @param   val: The value
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setRelativeCoincidentTopologyPolygonOffsetParameters(double val, double units = 1);

    /**
     * @brief   Deep copy.
     * @param   source: Source actor
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void deepCopy(RadiossVTKGraphActor* source);

    /**
     * @brief   Auto remove the cell's normals if the input data is not empty.( DO NOT USE FOR NOW !!! )
     * @param   flag: Whether to remove the normals
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setAutoRemoveNormals(bool flag);

    /**
     * @brief   Set both front and back face color.
     * @param   color: The color
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setColor(QColor color);

    /**
     * @brief   Set the front face color.
     * @param   color: The color
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setFrontFaceColor(QColor color);

    /**
     * @brief   Set the back face color.
     * @param   color: The color
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setBackFaceColor(QColor color);

    /**
     * @brief   Set enable the back face color.
     * @param   isOn: Enable or not
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setEnableBackFaceColor(bool isOn);

    /**
     * @brief   Set the data object.
     * @param   obj: Data object
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setGraphObject(Comp::FITKGraphObjectVTK* obj);

    /**
     * @brief   Get the data object.
     * @return  Data object
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    Comp::FITKGraphObjectVTK* getGraphObject();

    /**
     * @brief   Get the graph object as the given type.[template]
     * @return  The graph object.
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    template<class T>
    T* getGraphObjectAs()
    {
        return dynamic_cast<T*>(m_graphObj);
    }
    /**
     * @brief       Set the actor's data type.
     * @param[in]   type: Surface or edge or vertex
     * @author      ChengHaotian (yeguangbaozi@foxmail.com)
     * @date        2024-04-23
     */
    void setActorType(ActorType type);

    /**
     * @brief       Get the actor's data type.
     * @return      Is surface or edge or vertex
     * @author      ChengHaotian (yeguangbaozi@foxmail.com)
     * @date        2024-04-23
     */
    ActorType getActorType();
    /**
     * @brief   Set the actor's data type.
     * @param   type: Geometry or mesh or post
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setDataType(DataType type);

    /**
     * @brief   Get the actor's data type.
     * @return  Is geometry or mesh or post
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    DataType getDataType();
    /**
     * @brief   Get the input data object.
     * @param   port: Input port
     * @param   connection: Connection
     * @return  Input data
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    vtkDataObject* getInputDataObject(int port = 0, int connection = 0);
    /**
     * @brief   Get the input as the vtkDataSet.
     * @return  The data set
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    vtkDataSet* getInputAsDataSet();
    /**
     * @brief   Set if show the scalar.
     * @param   isOn: Is on
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setScalarVisibility(bool isOn);

    /**
     * @brief   Set the color with default color.
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setScalarModeToDefault();

    /**
     * @brief   Set the color with point scalar.
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setScalarModeToUsePointData();

    /**
     * @brief   Set the color with cell scalar.
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setScalarModeToUseCellData();

    /**
     * @brief   Set the color with point field scalar.
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setScalarModeToUsePointFieldData();

    /**
     * @brief   Set the color with cell field scalar.
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void setScalarModeToUseCellFieldData();

    /**
     * @brief   Select the array need to be the scalars.
     * @param   name
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void selectScalarArray(QString name);

    /**
     * @brief   Update the actor's mapper.
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void update();

protected:
    /**
     * @brief   Constructor.
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    RadiossVTKGraphActor();

    /**
     * @brief   Destructor.[virtual]
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    virtual ~RadiossVTKGraphActor();

    /**
     * @brief   Copy constructor.
     * @param   The object
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    RadiossVTKGraphActor(const RadiossVTKGraphActor&) = delete;

    /**
     * @brief   Operator overloading.
     * @param   The object
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void operator=(const RadiossVTKGraphActor&) = delete;

    /**
     * @brief   Remove the cell normals array.
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    void removeCellNormals();

protected:
    /**
     * @brief   VTK function override.
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
     //@{
     /**
      * @brief   Release any graphics resources that are being consumed by this actor.
      *          The parameter window could be used to determine which graphic
      *          resources to release.
      * @param   window: The vtk window
     * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date     2025-07-23
      */
    virtual void ReleaseGraphicsResources(vtkWindow* window) override;

    /**
     * @brief   For rendering opaque's actor.[override]
     * @param   viewport: The view port
     * @return  Is opaque render
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    int RenderOpaqueGeometry(vtkViewport* viewport) override;

    /**
     * @brief   For rendering opaque's actor.[override]
     * @param   viewport: The view port
     * @return  Is opaque render
     * @author  ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date    2025-07-23
     */
    int RenderTranslucentPolygonalGeometry(vtkViewport* viewport) override;
    //@}

    ///**
    // * @brief   Render function override.[virtual][override]
    // * @param   ren: The renderer
    // * @param   mapper: The actor's mapper
    // * @author  ZhouZhaoYi(zhouzhaoyi@diso.cn)
    // * @date    2025-07-23
    // */
    //virtual void Render(vtkRenderer* ren, vtkMapper* mapper) override;

    /**
     * @brief     Shallow copy.[override]
     * @param     prop: The source prop
    // * @author  ZhouZhaoYi(zhouzhaoyi@diso.cn)
    // * @date    2025-07-23
     */
    void ShallowCopy(vtkProp* prop) override;
    //@}

protected:
    // VTK function override need
    //@{
    /**
     * @brief     The actor device needed by vtkActor.
    // * @author  ZhouZhaoYi(zhouzhaoyi@diso.cn)
    // * @date    2025-07-23
     */
    vtkActor* Device{ nullptr };
    //@}

    /**
     * @brief     A mapper initialized in the constructor
    // * @author  ZhouZhaoYi(zhouzhaoyi@diso.cn)
    // * @date    2025-07-23
     */
    vtkMapper* m_mapper{ nullptr };

    /**
     * @brief     The data object
    // * @author  ZhouZhaoYi(zhouzhaoyi@diso.cn)
    // * @date    2025-07-23
     */
    Comp::FITKGraphObjectVTK* m_graphObj{ nullptr };

    /**
     * @brief     The data type of the actor.( Geometry, mesh or post. )
    // * @author  ZhouZhaoYi(zhouzhaoyi@diso.cn)
    // * @date    2025-07-23
     */
    DataType m_dataType = OtherData;

    /**
     * @brief     Is the back face render enabled.
    // * @author  ZhouZhaoYi(zhouzhaoyi@diso.cn)
    // * @date    2025-07-23
     */
    bool m_enableBackFace = true;

    /**
     * @brief     The color of the front face.
    // * @author  ZhouZhaoYi(zhouzhaoyi@diso.cn)
    // * @date    2025-07-23
     */
    QColor m_frontFaceColor = QColor(255, 255, 255);

    /**
     * @brief     The color of the back face.
    // * @author  ZhouZhaoYi(zhouzhaoyi@diso.cn)
    // * @date    2025-07-23
     */
    QColor m_backFaceColor = QColor();

    /**
     * @brief     Remove the input data's normals.( For input data only )( DO NOT USE FOR NOW !!! )
    // * @author  ZhouZhaoYi(zhouzhaoyi@diso.cn)
    // * @date    2025-07-23
     */
    bool m_autoRemoveNormals = false;
    /**
     * @brief  The data type of the actor.( Surface, edge or vertex. )
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-08-21
     */
    ActorType m_actorType = OtherActor;
};

#endif // !_RADIOSSVTKGRAPHACTOR_H__



