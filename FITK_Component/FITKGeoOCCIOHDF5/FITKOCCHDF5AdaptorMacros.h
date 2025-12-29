#ifndef __FITKOCC_HDF5ADAPTOR_MACROS_H__
#define __FITKOCC_HDF5ADAPTOR_MACROS_H__

/**
 * @brief Macro to define a class that is an adaptor for HDF5 IO of OCC shapes. 
 * @aurhor: libaojun
 * @date: 2025-04-28
 */
#define FITKOCCAdaptorDec(ClassName, AbstractClass)  \
    class FITKGEOOCCIOHDF5API ClassName : public AbstractClass, \
        public FITKOCCShapeHDF5IOHelper \
    { \
    public: \
        explicit ClassName() = default; \
        virtual ~ClassName() = default; \
    protected: \
        virtual bool writeShape(H5::Group & g) override; \
        virtual bool readShape() override; \
    }; 

/**
 * @brief Macro to implement the class that is an adaptor for HDF5 IO of OCC shapes. 
 *  @aurhor: libaojun
 * @date: 2025-04-28
 */
#define FITKOCCAdaptorDef(ClassName) \
    bool ClassName::writeShape(H5::Group & g) \
    { \
        Interface::FITKAbsGeoCommand* command = this->getDataObjectAs<Interface::FITKAbsGeoCommand>(); \
        if(command == nullptr) return false; \
        OCC::FITKAbstractOCCModel* model =  dynamic_cast <OCC::FITKAbstractOCCModel*>(command->getShapeAgent()); \
        if(model == nullptr && _writer == nullptr) return false;   \
        return OCC::FITKOCCShapeHDF5IOHelper::writeShape(model, _writer, g); \
    } \
    bool ClassName::readShape() \
    { \
        Interface::FITKAbsGeoCommand* command = this->getDataObjectAs<Interface::FITKAbsGeoCommand>(); \
        if (command == nullptr) return false; \
        return OCC::FITKOCCShapeHDF5IOHelper::readShape(command, _reader, *_h5Group); \
    }



#endif