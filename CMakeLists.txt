cmake_minimum_required(VERSION 3.18)
project(project)

set(CMAKE_CXX_STANDARD 11)

add_executable(project main.cpp ReadProgram.cpp ReadProgram.h LexicalAnalyzer.h LexicalAnalyzer.cpp GrammaticalAnalyzer.h GrammaticalAnalyzer.cpp FinalParser.h FinalParser.cpp quadraple.cpp quadraple.h SymTable.cpp SymTable.h Sym.cpp Sym.h MiddleVal.cpp MiddleVal.h)