#include "FITKStruIsosurfPostData.h"
#include "FITKStruPost3DManager.h"
#include "FITKAbstractStruPostVTK.h"

#include "FITK_Kernel/FITKAppFramework/FITKAppFramework.h"
#include "FITK_Kernel/FITKAppFramework/FITKGlobalData.h"

#include "FITK_Component/FITKAbaqusData/FITKAbaqusData.h"
#include "FITK_Component/FITKAbaqusData/FITKAbaqusPostData.h"

#include <vtkContourFilter.h>
#include <vtkSmartPointer.h>
#include <vtkDataSetMapper.h>
#include <vtkDataSet.h>
#include <vtkPointData.h>
#include <vtkLookupTable.h>
#include <vtkTrivialProducer.h>



// DATA
namespace Interface {
    FITKStruIsosurfPostData::FITKStruIsosurfPostData()
    {

    }

    FITKStruIsosurfPostData::~FITKStruIsosurfPostData() {
        if (_producer) {
            _producer->Delete();
            _producer = nullptr;
        }
    }

    void FITKStruIsosurfPostData::setFileName(const QString fileName) {
        _fileName = fileName;
    }

    QString FITKStruIsosurfPostData::getFileName() {
        return _fileName;
    }

    void FITKStruIsosurfPostData::setType(const VariableLocation type) {
        _fileType = type;
    }

    VariableLocation FITKStruIsosurfPostData::getType() {
        return _fileType;
    }

    void FITKStruIsosurfPostData::setInput(vtkDataSet* inp)
    {
        _inp = inp;
    }

    void FITKStruIsosurfPostData::setValue(QList < double > value) {
        _values = value;
    }

    QList<double> FITKStruIsosurfPostData::getValue() {
        return _values;
    }

    vtkDataSet* FITKStruIsosurfPostData::getOutput() {
        return _inp;
    }

    vtkAlgorithmOutput* FITKStruIsosurfPostData::getOutputAlgorithm() {
        if (_contourFilter == nullptr) {
            return nullptr;
        }
        return _contourFilter->GetOutputPort();
    }

    StruPostType FITKStruIsosurfPostData::getPostStructualType() {
        return StruPostType::SPTDynamicExplict;
    }

    void FITKStruIsosurfPostData::setModelID(int modelId) {
        _modelID = modelId;
    }

    int FITKStruIsosurfPostData::getModelID() {
        return _modelID;
    }

    void FITKStruIsosurfPostData::update() {
        
    }
}

// DATA MANAGER

namespace Interface {
    FITKStruIsoPostDataManager::FITKStruIsoPostDataManager(FITKAbstractStructuralPostVTK* absPost) : _postObj(absPost) {

    }

    void FITKStruIsoPostDataManager::appendDataObj(Core::FITKAbstractDataObject* item) {
        FITKStruIsosurfPostData* v = dynamic_cast<FITKStruIsosurfPostData*>(item);
        if (v == nullptr || _postObj == nullptr) {
            return;
        }
        auto def = _postObj->getOutput();
        if (def == nullptr) {
            return;
        }
        v->setModelID(_postObj->getDataObjectID());
        v->setInput(def);
        Core::FITKAbstractDataManager<FITKStruIsosurfPostData>::appendDataObj(item);
    }

    void FITKStruIsoPostDataManager::insertDataObj(int idx, Core::FITKAbstractDataObject* item) {
        FITKStruIsosurfPostData* v = dynamic_cast<FITKStruIsosurfPostData*>(item);
        if (v == nullptr || _postObj == nullptr) {
            return;
        }
        auto def = _postObj->getOutput();
        if (def == nullptr) {
            return;
        }
        v->setModelID(_postObj->getDataObjectID());
        v->setInput(def);
        Core::FITKAbstractDataManager<FITKStruIsosurfPostData>::insertDataObj(idx, item);
    }
}
