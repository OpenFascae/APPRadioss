#ifndef _OperatorImportRad_H_
#define _OperatorImportRad_H_


#include "FITK_Kernel/FITKCore/FITKActionOperator.h"
#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"

namespace ModelOper
{
    class FITKOperatorImportRad : public Core::FITKActionOperator
    {
        Q_OBJECT
    public:
        explicit FITKOperatorImportRad() = default;
        virtual ~FITKOperatorImportRad() = default;
 /**
          * @brief 执行界面操作
          * @return true     执行成功
          * @return false     执行失败
          * @author liuzhonghua (liuzhonghuaszch@163.com)
          * @date   2024-11-21
          */
         virtual bool execGUI() override;
         /**
          * @brief 执行读入操作
          * @return true     执行成功
          * @return false     执行失败
          * @author liuzhonghua (liuzhonghuaszch@163.com)
          * @date   2024-11-21
          */
         virtual bool execProfession() override;
 
    private slots:
        /**
         * @brief 读取线程结束执行该槽函数
         * @author LiBaojun (libaojunqd@foxmail.com)
         * @date 2024-03-26
         */
        void ioThreadFinishedSlot();
 
    };
    
    // 按钮注册相关操作
    Register2FITKOperatorRepo(actionImportRad, FITKOperatorImportRad);
}

#endif