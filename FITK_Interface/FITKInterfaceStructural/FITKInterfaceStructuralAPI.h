/**
 *
 * @file FITKInterfaceStructuralAPI.h
 * @brief  声明位接口
 * @author LiBaojun (libaojunqd@foxmail.com)
 * @date 2024-03-30
 *
 */
#ifndef _FITKINTERFACESTRUCTURAL_API_H_
#define _FITKINTERFACESTRUCTURAL_API_H_

#include <QtCore/QtGlobal>


#if defined(FITKInterfaceStructural_API)
#define FITKInterfaceStructuralAPI Q_DECL_EXPORT
#else
#define FITKInterfaceStructuralAPI Q_DECL_IMPORT
#endif

#ifndef FITKInterfaceStructuralVersion
#define FITKInterfaceStructuralVersion "1.0.0"
#endif

#endif
