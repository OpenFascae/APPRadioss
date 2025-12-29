/**
 *
 * @file FITKAdaptorAPI.h
 * @brief 声明接口
 * @author fulipeng (flipengqd@yeah.net)
 * @date 2024-03-07
 *
 */

#ifndef _FITKABAQUSDATA_API_H_
#define _FITKABAQUSDATA_API_H_

#include <QtCore/QtGlobal>


#if defined(FITKAbaqusData_API)
#define FITKAbaqusDataAPI Q_DECL_EXPORT
#else
#define FITKAbaqusDataAPI Q_DECL_IMPORT
#endif


#ifndef FITKAbaqusDataVersion
#define FITKAbaqusDataVersion "1.1.0"
#endif

#endif
