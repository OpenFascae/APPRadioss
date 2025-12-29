#include "FITKAbstractConnection.h"

namespace Radioss
{
    FITKAbstractConnection::~FITKAbstractConnection()
    {}
 

    FITKAbstractConnection::ConnectionType FITKAbstractConnection::getType() const
    {
        return Connection_Unknown;
    }

}