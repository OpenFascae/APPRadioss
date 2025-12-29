 
#ifndef _FITKIBASTRAN_BDFIO_API_H_
#define _FITKIBASTRAN_BDFIO_API_H_

#include <QtCore/QtGlobal>


#if defined(FITKNastranBDFIO_API)
#define FITKNastranBDFIOAPI Q_DECL_EXPORT
#else
#define FITKNastranBDFIOAPI Q_DECL_IMPORT
#endif

#ifndef FITKNastranBDFIOVersion 
#define FITKNastranBDFIOVersion "1.0.1"
#endif

#endif
