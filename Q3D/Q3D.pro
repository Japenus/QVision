QT += core gui 3dcore 3dextras 3dinput 3drender

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    q3d.cpp \
    main.cpp \
    cameracontrol.cpp \

HEADERS += \
    q3d.h \
    global.h \
    cameracontrol.h \

# LIBS += -LD:/0penCASCADE7.7.0/opencascade-7.7.0/win64/vc14/Lib -LTKIGES -TKMath -LTKIGES -LTKBin -lTKBinLLTKBinXCAF -LTKBO -LTKBOOL \
# -LTKBReD -LTKCAF -lTKCDF -lTKernel -lTKG2d -lTKG3d -lTKGeomAlgo -lTKGeomBaseLTKHLR -LTKLCAE -lTKMath -lTkMesh -lTkMeshvs -lTkopenGl \
# -lTKPrim -lTKService -lTKshHealing -lTKTopALgoLTKXSDRAW -LTKV3d-LTKVCAF -LTKXCAF -LTKXml-lTKXmlL -lTKXmLXCAF -lTKXSBase -LTKSTEP
