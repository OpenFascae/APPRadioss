 
#ifndef _FITKRadiossRadIOAPI_API_H_
#define _FITKRadiossRadIOAPI_API_H_

#include <QtCore/QtGlobal>


#if defined(FITKRadiossRadIO_API)
#define FITKRadiossRadIOAPI Q_DECL_EXPORT
#else
#define FITKRadiossRadIOAPI Q_DECL_IMPORT
#endif

#endif
