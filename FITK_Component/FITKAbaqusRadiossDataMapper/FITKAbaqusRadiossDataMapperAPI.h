 
#ifndef _FITKAbaqusRadiossDataMapper_API_API_H_
#define _FITKAbaqusRadiossDataMapper_API_API_H_

#include <QtCore/QtGlobal>


#if defined(FITKAbaqusRadiossDataMapper_API)
#define FITKAbaqusRadiossDataMapperAPI Q_DECL_EXPORT
#else
#define FITKAbaqusRadiossDataMapperAPI Q_DECL_IMPORT
#endif

#ifndef FITKAbaqusRadiossDataMapperVersion
#define FITKAbaqusRadiossDataMapperVersion "0.1.1"
#endif

#endif
