/**
 * 
 * @file   FITKAbaProfileManager.h
 * @brief  梁截面形状管理器
 * @author LiJin (1003680421@qq.com)
 * @date   2024-03-27
 * 
 */
#ifndef FITKABAPROFILEMANAGER_H
#define FITKABAPROFILEMANAGER_H
#include "FITKInterfaceStructuralAPI.h"
#include "FITK_Kernel/FITKCore/FITKAbstractNDataObject.h"
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"
#include "FITKAbaProfile.h"


namespace Interface {
    /**
     * @brief  梁截面形状管理器
     * @author LiJin (1003680421@qq.com)
     * @date   2024-03-27
     */
    class FITKAbaProfileManager: public Core::FITKAbstractDataObject
    , public Core::FITKAbstractDataManager<FITKAbaProfile>
    {
    public:
        /**
         * @brief  构造函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        FITKAbaProfileManager() = default;
        /**
         * @brief  析构函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        ~FITKAbaProfileManager() = default;
    };

}

#endif // FITKABAPROFILEMANAGER_H
