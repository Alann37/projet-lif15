cmake_minimum_required(VERSION 2.6)
PROJECT ( automate )
file(
    GLOB_RECURSE
    source_files
    src/*
)
set(EXECUTABLE_OUTPUT_PATH ../bin)
# Déclaration de l'exécutable
add_executable(
    automate 
    ${source_files}
)

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
add_custom_target(doc
${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)