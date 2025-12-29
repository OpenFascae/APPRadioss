/**********************************************************************
 * @file   OperImportVTK.h
 * @brief  VTK文件导入操作器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-08
 *********************************************************************/
#ifndef __OPERINMPORTVTK_H__
#define __OPERINMPORTVTK_H__

#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"
#include "FITK_Kernel/FITKCore/FITKActionOperator.h"

#include <QString>

namespace Interface
{
    class FITKAbstractStructuralPostVTK;
}

namespace OperModel
{
    /**
     * @brief  VTK文件导入操作器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-08
     */
    class OperImportVTK : public Core::FITKActionOperator
    {
        Q_OBJECT
    public:
        /**
         * @brief  构造函数
         * @author guqingtao (15598887859@163.com)
         * @date   2025-09-08
         */
        explicit OperImportVTK() = default;
        /**
         * @brief    构造函数
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-08
         */
        ~OperImportVTK() = default;
        /**
         * @brief    UI逻辑
         * @return   bool
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-08
         */
        bool execGUI() override;
        /**
         * @brief    业务逻辑
         * @return   bool
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-08
         */
        bool execProfession() override;

    private:
    };

    Register2FITKOperatorRepo(actionImportVTKResult, OperImportVTK);
}




#endif // !__MODELOPERATORS_INMPORT_INP_H__
