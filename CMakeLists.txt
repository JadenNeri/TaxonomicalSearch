cmake_minimum_required(VERSION 3.30)
project(Project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project2
    .idea/.gitignore
    .idea/editor.xml
    .idea/modules.xml
    .idea/Project2.iml
    .idea/vcs.xml
    .idea/workspace.xml
    README.md
    src/main.cpp
    src/main.h
    src/Entry.cpp
    src/Entry.h
        src/Parser.cpp
        src/Parser.h
        src/traversals.cpp
        src/traversals.h
        src/TaxonTrie.cpp
)
