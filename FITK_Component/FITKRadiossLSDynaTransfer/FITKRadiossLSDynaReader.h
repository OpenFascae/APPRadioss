/**********************************************************************
 * @file   FITKRadiossLSDynaReader.h
 * @brief  LS-Dyna文件读取器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-07-01
 *********************************************************************/
#ifndef _FITKRadiossLSDynaReader_H_
#define _FITKRadiossLSDynaReader_H_

#include "FITK_Interface/FITKInterfaceIO/FITKAbstractTextReader.h"

namespace Radioss
{
    /**
     * @brief  Ls-Dyna文件读取器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-07-01
     */
    class FITKRadiossLSDynaReader : public Interface::FITKAbstractTextReader
    {
        Q_OBJECT
    public:
        explicit FITKRadiossLSDynaReader(bool & success);
        virtual ~FITKRadiossLSDynaReader() = default;
        /**
         * @brief 执行读取操作
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-07-01
         */
        virtual void run() override;
        /**
         * @brief 打印控制台消息
         * @param[i] level 打印级别 1 normal 2 warning 3error
         * @param[i] str 打印的信息
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-07-01
         */
        void consoleMessage(int level, const QString& str) override;

    private:
        /**
         * @brief  成功标记
         * @author guqingtao (15598887859@163.com)
         * @date   2025-07-01
         */
        bool & _success;
    };
}

#endif