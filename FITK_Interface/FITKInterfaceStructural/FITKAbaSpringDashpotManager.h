/**
 * 
 * @file   FITKAbaSpringDashpotManager.h
 * @brief  弹簧阻尼管理器
 * @author LiJin (1003680421@qq.com)
 * @date   2024-06-19
 * 
 */
#ifndef FITKABASPRINGDASHPOTMANAGER_H
#define FITKABASPRINGDASHPOTMANAGER_H
#include "FITKAbaAbstractSpringDashpot.h"
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"
#include "FITK_Kernel/FITKCore/FITKAbstractDataObject.h"


namespace Interface {

    class FITKAbaSpringDashpotManager: public Core::FITKAbstractDataObject,
        public Core::FITKAbstractDataManager<FITKAbaAbstractSpringDashpot>
    {
    public:
        FITKAbaSpringDashpotManager() = default;
        ~FITKAbaSpringDashpotManager() = default;
    };
}
#endif // FITKABASPRINGDASHPOTMANAGER_H
