/**********************************************************************
 * @file   OperatorsInterfaceAPI.h
 * @brief  接口声明
 * @author BaGuijun (baguijun@163.com)
 * @date   2024-12-18
 *********************************************************************/
#ifndef _OperatorsInterfaceAPI_H_
#define _OperatorsInterfaceAPI_H_

#include <QtCore/QtGlobal>

#ifdef OperatorsInterface_API
#define OperatorsInterfaceAPI Q_DECL_EXPORT
#else
#define OperatorsInterfaceAPI Q_DECL_IMPORT
#endif

#endif
