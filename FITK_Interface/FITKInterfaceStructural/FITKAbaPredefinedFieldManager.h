/**
 * 
 * @file   FITKAbaPredefinedFieldManager.h
 * @brief  预定义场管理器
 * @author LiJin (1003680421@qq.com)
 * @date   2024-05-10
 * 
 */
#ifndef FITKABAPREDEFINEDFIELDMANAGER_H
#define FITKABAPREDEFINEDFIELDMANAGER_H
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"
#include "FITK_Kernel/FITKCore/FITKAbstractDataObject.h"
#include "FITKInterfaceStructuralAPI.h"
#include "FITKAbaAbstractPredefinedField.h"


namespace Interface {
    /**
     * @brief  预定义场管理器
     * @author LiJin (1003680421@qq.com)
     * @date   2024-05-10
     */
    class FITKInterfaceStructuralAPI FITKAbaPredefinedFieldManager: public Core::FITKAbstractDataManager<FITKAbaAbstractPredefinedField>,
                                                                 public Core::FITKAbstractNDataObject
    {
    public:
        FITKAbaPredefinedFieldManager() = default;
        ~FITKAbaPredefinedFieldManager() = default;
    };
}


#endif // FITKABAPREDEFINEDFIELDMANAGER_H
