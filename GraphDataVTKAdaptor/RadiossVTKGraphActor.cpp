#include "RadiossVTKGraphActor.h"

#include <vtkObjectFactory.h>

#include <vtkUnstructuredGrid.h>
#include <vtkAlgorithmOutput.h>
#include <vtkDataSetMapper.h>
#include <vtkProperty.h>
#include <vtkTexture.h>
#include <vtkRenderer.h>
#include <vtkInformation.h>
#include <vtkTransform.h>
#include <vtkCellData.h>

RadiossVTKGraphActor* RadiossVTKGraphActor::New()
{
    // Return the instance.
    return new RadiossVTKGraphActor;
}

void RadiossVTKGraphActor::SetMapper(vtkMapper* mapper)
{
    m_mapper = mapper;

    this->Device->SetMapper(mapper);
    vtkActor::SetMapper(mapper);
}

void RadiossVTKGraphActor::setRelativeCoincidentTopologyPolygonOffsetParameters(double val, double units)
{
    if (m_mapper)
    {
        m_mapper->SetRelativeCoincidentTopologyPolygonOffsetParameters(val, units);
    }
}

RadiossVTKGraphActor::RadiossVTKGraphActor() :
    FITKActorClipTool(this)
{
    // Create a mapper and set to the actor.
    this->Device = vtkActor::New();
    m_mapper = vtkDataSetMapper::New();
    this->SetMapper(m_mapper);
}

RadiossVTKGraphActor::~RadiossVTKGraphActor()
{
    // Delete the mapper created by self.
    if (m_mapper)
    {
        m_mapper->Delete();
        m_mapper = nullptr;
    }

    m_mapper = nullptr;

    // Delete the actor device.
    if (Device)
    {
        Device->Delete();
        Device = nullptr;
    }

    m_graphObj = nullptr;
}

void RadiossVTKGraphActor::deepCopy(RadiossVTKGraphActor* source)
{
    if (!m_mapper || !source)
    {
        return;
    }

    // Copy properties.
    this->ShallowCopy(source);

    // Copy mapper properties.
    m_mapper->ShallowCopy(m_mapper);

    // Copy data.
    vtkUnstructuredGrid* grid = vtkUnstructuredGrid::New();
    grid->DeepCopy(source->getInputDataObject());
    setInputDataObject(grid);
}

void RadiossVTKGraphActor::setAutoRemoveNormals(bool flag)
{
    m_autoRemoveNormals = flag;

    // Try to remove the normals.
    if (m_autoRemoveNormals)
    {
        removeCellNormals();
    }
}

void RadiossVTKGraphActor::removeCellNormals()
{
    // Check the mapper.
    if (!m_mapper)
    {
        return;
    }

    // Check the input data.
    vtkDataSet* dataset = m_mapper->GetInput();
    if (!dataset)
    {
        return;
    }

    // Check the cell data.
    vtkCellData* cellData = dataset->GetCellData();
    if (!cellData)
    {
        return;
    }

    // Get the normals array.
    vtkDataArray* normals = cellData->GetNormals();
    if (!normals)
    {
        return;
    }

    cellData->SetNormals(nullptr);
    normals->Delete();

    update();
}

void RadiossVTKGraphActor::setColor(QColor color)
{
    if (!color.isValid())
    {
        return;
    }

    setFrontFaceColor(color);
    setBackFaceColor(color);
}

void RadiossVTKGraphActor::setFrontFaceColor(QColor color)
{
    if (!color.isValid())
    {
        return;
    }

    m_frontFaceColor = color;

    // Initialize front face property.
    vtkProperty* prop = this->GetProperty();
    if (!prop)
    {
        prop = vtkProperty::New();
        this->SetProperty(prop);
    }

    prop->SetColor(color.redF(), color.greenF(), color.blueF());
}

void RadiossVTKGraphActor::setBackFaceColor(QColor color)
{
    if (!color.isValid())
    {
        return;
    }

    m_backFaceColor = color;

    if (!m_enableBackFace)
    {
        return;
    }

    // Initialize back face property.
    vtkProperty* prop = this->GetBackfaceProperty();
    if (!prop)
    {
        prop = vtkProperty::New();
        this->SetBackfaceProperty(prop);
    }

    prop->SetColor(color.redF(), color.greenF(), color.blueF());
}

void RadiossVTKGraphActor::setEnableBackFaceColor(bool isOn)
{
    if (isOn)
    {
        setBackFaceColor(m_backFaceColor);
    }
    else
    {
        vtkProperty* prop = this->GetBackfaceProperty();
        if (!prop)
        {
            prop = vtkProperty::New();
            this->SetBackfaceProperty(prop);
        }

        prop->SetColor(m_frontFaceColor.redF(), m_frontFaceColor.greenF(), m_frontFaceColor.blueF());
    }

    m_enableBackFace = isOn;
}

void RadiossVTKGraphActor::setGraphObject(Comp::FITKGraphObjectVTK* obj)
{
    m_graphObj = obj;
}

Comp::FITKGraphObjectVTK* RadiossVTKGraphActor::getGraphObject()
{
    return m_graphObj;
}
void RadiossVTKGraphActor::setActorType(ActorType type)
{
    m_actorType = type;
}
ActorType RadiossVTKGraphActor::getActorType()
{
    return m_actorType;
}
void RadiossVTKGraphActor::setDataType(DataType type)
{
    m_dataType = type;
}

DataType RadiossVTKGraphActor::getDataType()
{
    return m_dataType;
}

vtkDataObject* RadiossVTKGraphActor::getInputDataObject(int port, int connection)
{
    // If mapper is empty, return.
    if (!m_mapper)
    {
        return nullptr;
    }

    return m_mapper->GetInputDataObject(port, connection);
}

vtkDataSet* RadiossVTKGraphActor::getInputAsDataSet()
{
    if (!m_mapper)
    {
        return nullptr;
    }

    return m_mapper->GetInputAsDataSet();
}

void RadiossVTKGraphActor::setScalarVisibility(bool isOn)
{
    // If mapper is empty, return.
    if (!m_mapper)
    {
        return;
    }

    m_mapper->SetScalarVisibility(isOn);
}

void RadiossVTKGraphActor::setScalarModeToDefault()
{
    // If mapper is empty, return.
    if (!m_mapper)
    {
        return;
    }

    m_mapper->SetScalarModeToDefault();
}

void RadiossVTKGraphActor::setScalarModeToUsePointData()
{
    // If mapper is empty, return.
    if (!m_mapper)
    {
        return;
    }

    m_mapper->SetScalarModeToUsePointData();
}

void RadiossVTKGraphActor::setScalarModeToUseCellData()
{
    // If mapper is empty, return.
    if (!m_mapper)
    {
        return;
    }

    m_mapper->SetScalarModeToUseCellData();
}

void RadiossVTKGraphActor::setScalarModeToUsePointFieldData()
{
    // If mapper is empty, return.
    if (!m_mapper)
    {
        return;
    }

    m_mapper->SetScalarModeToUsePointFieldData();
}

void RadiossVTKGraphActor::setScalarModeToUseCellFieldData()
{
    // If mapper is empty, return.
    if (!m_mapper)
    {
        return;
    }

    m_mapper->SetScalarModeToUseCellFieldData();
}

void RadiossVTKGraphActor::selectScalarArray(QString name)
{
    // If mapper is empty, return.
    if (!m_mapper)
    {
        return;
    }

    m_mapper->SelectColorArray(name.toUtf8().data());
}

void RadiossVTKGraphActor::update()
{
    // If mapper is empty, return.
    if (!m_mapper)
    {
        return;
    }

    // Update the actor's mapper.
    m_mapper->Update();
}

// Override from vtkActor
//@{
void RadiossVTKGraphActor::ReleaseGraphicsResources(vtkWindow* window)
{
    // Override release resources function.
    this->Device->ReleaseGraphicsResources(window);
    this->Superclass::ReleaseGraphicsResources(window);
}

int RadiossVTKGraphActor::RenderOpaqueGeometry(vtkViewport* viewport)
{
    this->Device->SetProperty(this->GetProperty());
    this->Device->SetBackfaceProperty(this->BackfaceProperty);

    // Copy property keys.
    if (this->GetPropertyKeys())
    {
        this->Device->SetPropertyKeys(this->GetPropertyKeys());
    }

    return this->Device->RenderOpaqueGeometry(viewport);
}

int RadiossVTKGraphActor::RenderTranslucentPolygonalGeometry(vtkViewport* viewport)
{
    this->Device->SetProperty(this->GetProperty());
    this->Device->SetBackfaceProperty(this->BackfaceProperty);

    // Copy property keys.
    if (this->GetPropertyKeys())
    {
        this->Device->SetPropertyKeys(this->GetPropertyKeys());
    }

    return this->Device->RenderTranslucentPolygonalGeometry(viewport);
}

void RadiossVTKGraphActor::ShallowCopy(vtkProp* prop)
{
    // Override shallow copy.
    // FITKAcousticsVTKGraphActor* f = FITKAcousticsVTKGraphActor::SafeDownCast(prop);
    this->vtkActor::ShallowCopy(prop);
}
//@}

// vtkStandardNewMacro(vtkActorEx);