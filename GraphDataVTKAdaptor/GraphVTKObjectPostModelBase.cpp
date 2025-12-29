#include "GraphVTKObjectPostModelBase.h"

#include "FITK_Interface/FITKVTKAlgorithm/FITKGraphActor.h"

#include <vtkMapper.h>
#include <vtkDataSet.h>
#include <vtkDataArray.h>
#include <vtkDataSetAttributes.h>
#include <vtkCellData.h>
#include <vtkPointData.h>
namespace Exchange
{
    GraphVTKObjectPostModelBase::GraphVTKObjectPostModelBase(Core::FITKAbstractDataObject* dataObj) :
        GraphVTKObject3DPostBase(dataObj)
    {

    }

    GraphVTKObjectPostModelBase::~GraphVTKObjectPostModelBase()
    {

    }
}