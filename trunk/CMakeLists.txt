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