#ifndef FITK_OCC_SHAPE_HDF5_IO_HELPER_H_
#define FITK_OCC_SHAPE_HDF5_IO_HELPER_H_

namespace H5
{
    class Group;
}

namespace IO
{
    class FITKAbstractHDF5Reader;
    class FITKAbstractHDF5Writer;
}
namespace Interface
{
    class FITKAbsGeoCommand;
}
namespace OCC
{
    class FITKAbstractOCCModel;

    class FITKOCCShapeHDF5IOHelper
    {
    public:
        FITKOCCShapeHDF5IOHelper() = default;
        virtual ~FITKOCCShapeHDF5IOHelper() = default;
        /**
         * @brief    写出虚拓扑形状
         * @param[i] model 
         * @param[i] writer 
         * @param[i] g 
         * @return   bool
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-04-28
         */
        bool writeShape(OCC::FITKAbstractOCCModel* model, IO::FITKAbstractHDF5Writer* writer, H5::Group &g);
        /**
         * @brief    读取虚拓扑形状
         * @param[i] command 
         * @param[i] reader 
         * @param[i] g 
         * @return   bool
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-04-28
         */
        bool readShape(Interface::FITKAbsGeoCommand* command, IO::FITKAbstractHDF5Reader* reader,H5::Group &g);



    };
} // namespace OCC

#endif // FITK_OCC_SHAPE_HDF5_IO_HELPER_H_
