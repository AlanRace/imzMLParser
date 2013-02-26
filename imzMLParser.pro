TEMPLATE = lib
CONFIG += staticlib
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    UserParam.cpp \
    TargetList.cpp \
    Target.cpp \
    SpectrumList.cpp \
    Spectrum.cpp \
    SourceFileRefList.cpp \
    SourceFileList.cpp \
    SourceFile.cpp \
    Source.cpp \
    SoftwareList.cpp \
    Software.cpp \
    SelectedIonList.cpp \
    SelectedIon.cpp \
    ScanWindowList.cpp \
    ScanSettingsList.cpp \
    ScanSettings.cpp \
    ScanList.cpp \
    Scan.cpp \
    SampleList.cpp \
    Run.cpp \
    ReferenceableParamGroupList.cpp \
    ReferenceableParamGroup.cpp \
    ProductList.cpp \
    Product.cpp \
    ProcessingMethod.cpp \
    PrecursorList.cpp \
    Precursor.cpp \
    OBOTerm.cpp \
    OBO.cpp \
    MzMLContent.cpp \
    InstrumentConfigurationList.cpp \
    InstrumentConfiguration.cpp \
    ImzMLHandler.cpp \
    ImzMLFile.cpp \
    FileDescription.cpp \
    FileContent.cpp \
    Detector.cpp \
    DataProcessingList.cpp \
    DataProcessing.cpp \
    CVParam.cpp \
    CVList.cpp \
    CV.cpp \
    ComponentList.cpp \
    ChromatogramList.cpp \
    BinaryDataArrayList.cpp \
    BinaryDataArray.cpp \
    Binary.cpp \
    Analyser.cpp \
    Activation.cpp

HEADERS += \
    UserParam.h \
    TargetList.h \
    Target.h \
    SpectrumList.h \
    Spectrum.h \
    SourceFileRefList.h \
    SourceFileList.h \
    SourceFile.h \
    Source.h \
    SoftwareList.h \
    Software.h \
    SelectedIonList.h \
    SelectedIon.h \
    ScanWindowList.h \
    ScanWindow.h \
    ScanSettingsList.h \
    ScanSettings.h \
    ScanList.h \
    Scan.h \
    SampleList.h \
    Sample.h \
    Run.h \
    ReferenceableParamGroupList.h \
    ReferenceableParamGroup.h \
    ProductList.h \
    Product.h \
    ProcessingMethod.h \
    PrecursorList.h \
    Precursor.h \
    OBOTerm.h \
    OBO.h \
    MzMLContent.h \
    InstrumentConfigurationList.h \
    InstrumentConfiguration.h \
    ImzMLHandler.h \
    ImzMLFile.h \
    ImzMLCV.h \
    FileDescription.h \
    FileContent.h \
    Detector.h \
    DataProcessingList.h \
    DataProcessing.h \
    CVParam.h \
    CVList.h \
    CV.h \
    Contact.h \
    ComponentList.h \
    ChromatogramList.h \
    Chromatogram.h \
    BinaryDataArrayList.h \
    BinaryDataArray.h \
    Binary.h \
    Analyser.h \
    Activation.h \
    helpers/convert.h \
    helpers/trim.h

OTHER_FILES += \
    imzMLParser.pro.user

unix: INCLUDEPATH += /usr/local/xerces/include/
unix: LIBS += -L/usr/local/xerces/lib/
unix|win32: LIBS += -lxerces-c
