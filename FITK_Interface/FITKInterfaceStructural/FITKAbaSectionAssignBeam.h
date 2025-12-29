/**
 * 
 * @file   FITKAbaSectionAssignBeam.h
 * @brief  Beam类型的截面属性赋予
 * @author LiJin (1003680421@qq.com)
 * @date   2024-04-28
 * 
 */
#ifndef FITKABASECTIONASSIGNBEAM_H
#define FITKABASECTIONASSIGNBEAM_H
#include "FITKInterfaceStructuralAPI.h"
#include "FITKAbaAbastractSectionAssign.h"


namespace Interface {
    /**
     * @brief  Beam类型截面属性赋予
     * @author LiJin (1003680421@qq.com)
     * @date   2024-04-28
     */
    class FITKInterfaceStructuralAPI FITKAbaSectionAssignBeam: public FITKAbaAbastractSectionAssign
    {
        FITKCLASS(Interface, FITKAbaSectionAssignBeam)
    public:
        /**
         * @brief  构造函数
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        FITKAbaSectionAssignBeam() = default;
        /**
         * @brief  析构函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        ~FITKAbaSectionAssignBeam() = default;
        /**
         * @brief  获取截面属性赋予类型
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        FITKAbaSectionAssignType getSectionAssignType() const override;
    };
}


#endif // FITKABASECTIONASSIGNBEAM_H
