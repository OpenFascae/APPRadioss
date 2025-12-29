/**
 * 
 * @file   FITKAbaConnectorAssignmentManager.h
 * @brief  连接器截面赋予管理器
 * @author LiJin (1003680421@qq.com)
 * @date   2024-06-20
 * 
 */
#ifndef FITKABACONNECTORASSIGNMENTMANAGER_H
#define FITKABACONNECTORASSIGNMENTMANAGER_H
#include "FITKAbaConnectorAssignment.h"
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"
#include "FITK_Kernel/FITKCore/FITKAbstractDataObject.h"

namespace Interface {

class FITKInterfaceStructuralAPI FITKAbaConnectorAssignmentManager: public Core::FITKAbstractDataManager<FITKAbaConnectorAssignment>,
                                                                     public Core::FITKAbstractDataObject
{
public:
    FITKAbaConnectorAssignmentManager() = default;
    ~FITKAbaConnectorAssignmentManager() = default;
};
}
#endif // FITKABACONNECTORASSIGNMENTMANAGER_H
