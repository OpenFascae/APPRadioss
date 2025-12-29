/**
 * 
 * @file   FITKAbaProfileRectangular.h
 * @brief  矩形截面形状
 * @author LiJin (1003680421@qq.com)
 * @date   2024-04-28
 * 
 */
#ifndef FITKABAPROFILERECTANGULAR_H
#define FITKABAPROFILERECTANGULAR_H
#include "FITKInterfaceStructuralAPI.h"
#include "FITKAbaProfile.h"


namespace Interface {
    /**
     * @brief  矩形截面形状类
     * @author LiJin (1003680421@qq.com)
     * @date   2024-04-28
     */
    class FITKInterfaceStructuralAPI FITKAbaProfileRectangular: public FITKAbaProfile
    {
        FITKCLASS(Interface, FITKAbaProfileRectangular)
    public:
        /**
         * @brief  获取截面形状类型
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        FITKAbaProfileShape getShape() const override;
        /**
         * @brief  数据拷贝
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        bool copy(Core::FITKAbstractDataObject* obj) override;
        /**
         * @brief  获取宽度A
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        double getA() const;
        /**
         * @brief  设置宽度A
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        void setA(double value);
        /**
         * @brief  获取高度B
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        double getB() const;
        /**
         * @brief  设置高度B
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        void setB(double value);
    private:
        /**
         * @brief  宽度
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        double m_a{0.0};
        /**
         * @brief  高度
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        double m_b{0.0};
    };

}

#endif // FITKABAPROFILERECTANGULAR_H
