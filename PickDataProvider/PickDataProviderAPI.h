/**********************************************************************
 * @file   PickDataProviderAPI.h
 * @brief  接口
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-08-05
 *********************************************************************/
#ifndef __PICKDATAPROVIDERAPI_H__
#define __PICKDATAPROVIDERAPI_H__

#include <QtCore/QtGlobal>

#ifdef PickDataProvider_API
#define PickDataProviderAPI Q_DECL_EXPORT
#else
#define PickDataProviderAPI Q_DECL_IMPORT
#endif

#endif // __PICKDATAPROVIDERAPI_H__
