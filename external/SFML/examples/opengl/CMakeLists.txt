
set(SRCROOT ${PROJECT_SOURCE_DIR}/examples/opengl)

# all source files
set(SRC ${SRCROOT}/OpenGL.cpp)

if (SFML_OS_IOS)
    set(resources
            resources/background.jpg
            resources/tuffy.ttf)
    set_source_files_properties(${RESOURCES} PROPERTIES MACOSX_PACKAGE_LOCATION resources)
endif()

# define the opengl target
sfml_add_example(opengl GUI_APP
                 SOURCES ${SRC}
                 BUNDLE_RESOURCES ${RESOURCES}
                 DEPENDS sfml-graphics
                 RESOURCES_DIR resources)

# external dependency headers
target_include_directories(opengl SYSTEM PRIVATE ${PROJECT_SOURCE_DIR}/examples/opengl)