/**********************************************************************
 * @file   OperatorsGUIAPI.h
 * @brief  接口
 * @author BaGuijun (baguijun@163.com)
 * @date   2024-12-18
 *********************************************************************/
#ifndef _OperatorsGUIAPI_H_
#define _OperatorsGUIAPI_H_

#include <QtCore/QtGlobal>

#include <QDebug>

#if defined(OperatorsGUI_API)
#define OperatorsGUIAPI Q_DECL_EXPORT
#else
#define OperatorsGUIAPI Q_DECL_IMPORT
#endif

#endif
