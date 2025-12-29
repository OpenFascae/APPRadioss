#include "GlobalDataFactory.h" 
#include "FITK_Interface/FITKInterfaceGeometry/FITKGeoCommandList.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossCase.h"
#include "FITK_Component/FITKRadiossData/FITKRadiossPostData.h"


Core::FITKAbstractDataObject *GlobalDataFactory::createMeshData()
{
    return nullptr;
}

Core::FITKAbstractDataObject* GlobalDataFactory::createGeoData()
{
    // 创建几何数据
    return new Interface::FITKGeoCommandList;
}

Core::FITKAbstractDataObject *GlobalDataFactory::createPhysicsData()
{
    return  new Radioss::FITKRadiossCase;
}

Core::FITKAbstractDataObject *GlobalDataFactory::createPostData()
{
    // 创建后处理数据
    return  new Radioss::FITKRadiossPostData;
}

QHash<int, Core::FITKAbstractDataObject *> GlobalDataFactory::createOtherData()
{
    // 不创建其他数据
    return QHash<int, Core::FITKAbstractDataObject *>();
}
