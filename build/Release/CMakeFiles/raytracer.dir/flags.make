# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# compile CXX with /usr/bin/c++
CXX_FLAGS =     -std=c++11 -fmax-errors=5

CXX_DEFINES = -DvtkRenderingContext2D_AUTOINIT="1(vtkRenderingContextOpenGL)" -DvtkRenderingCore_AUTOINIT="3(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingOpenGL)" -DvtkRenderingVolume_AUTOINIT="1(vtkRenderingVolumeOpenGL)"

CXX_INCLUDES = -I/home/groberts/Projects/C-Bed/src/../includes -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Charts/Core -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Common/Color -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Common/DataModel -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Common/Math -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Common/Core -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Utilities/KWSys -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Common/Misc -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Common/System -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Common/Transforms -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Infovis/Core -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Extraction -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Common/ExecutionModel -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Core -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/General -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Common/ComputationalGeometry -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Statistics -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Imaging/Fourier -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Imaging/Core -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/alglib -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/Context2D -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/Core -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Geometry -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Sources -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/FreeType -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/freetype -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/zlib -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/ftgl/src -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/ftgl -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Utilities/DICOMParser -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Domains/Chemistry -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/XML -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/Geometry -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/Core -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/XMLParser -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/expat -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/AMR -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Parallel/Core -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/Legacy -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Utilities/HashSource -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/FlowPaths -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Generic -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Hybrid -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Imaging/Sources -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/HyperTree -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Imaging -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Imaging/General -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Modeling -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Parallel -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/ParallelImaging -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Programmable -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/SMP -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Selection -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Texture -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Filters/Verdict -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/verdict -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Geovis/Core -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Infovis/Layout -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Imaging/Hybrid -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/Image -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Utilities/MetaIO/vtkmetaio -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Utilities/MetaIO -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/jpeg -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/png -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/tiff -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Interaction/Style -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Interaction/Widgets -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/Annotation -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Imaging/Color -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/Volume -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Views/Core -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/libproj4/vtklibproj4 -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/libproj4 -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/AMR -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/hdf5/vtkhdf5 -isystem /home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/hdf5/vtkhdf5/hl/src -isystem /home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/hdf5/vtkhdf5/src -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/hdf5 -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/EnSight -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/Exodus -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/exodusII -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/netcdf/vtknetcdf/include -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/netcdf/vtknetcdf -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/netcdf -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/Export -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/GL2PS -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/ContextOpenGL -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/OpenGL -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Utilities/ParseOGLExt -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Utilities/EncodeString -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/gl2ps -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/Label -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/Import -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/Infovis -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/libxml2/vtklibxml2 -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/libxml2 -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/LSDyna -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/MINC -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/Movie -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/oggtheora -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/NetCDF -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/PLY -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/Parallel -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/jsoncpp -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/ParallelXML -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/SQL -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/ThirdParty/sqlite -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/IO/Video -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Imaging/Math -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Imaging/Morphological -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Imaging/Statistics -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Imaging/Stencil -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Interaction/Image -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/Image -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/LIC -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/LOD -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Rendering/VolumeOpenGL -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Views/Context2D -I/home/groberts/Projects/RayTracer2.0/VTK-6.3.0/Views/Infovis 

