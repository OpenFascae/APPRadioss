#include "FITKAbstractGeoHDF5Adaptor.h"
#include "FITK_Kernel/FITKCore/FITKLibInfo.h"

FITKLIBINFOREGISTER(FITKInterfaceGeoIOHDF5, FITKINTERFACEGEOIOHDF5VERSION);

namespace Interface
{
	FITKAbstractGeoHDF5Adaptor::~FITKAbstractGeoHDF5Adaptor()
	{}

    void FITKAbstractGeoHDF5Adaptor::setReader(IO::FITKAbstractHDF5Reader* reader)
    {
        _reader = reader;
    }

    void FITKAbstractGeoHDF5Adaptor::setWriter(IO::FITKAbstractHDF5Writer* writer)
    {
        _writer = writer;
    }
    void FITKAbstractGeoHDF5Adaptor::setH5Group(H5::Group *g)
    {
        _h5Group = g;
    }
}
