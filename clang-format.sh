#!/usr/bin/env bash
find ./UnitA -type f \( -iname \*.cpp -o -iname \*.h \) | xargs clang-format -style=llvm -i
find ./utility -type f \( -iname \*.cpp -o -iname \*.h \)| xargs clang-format -style=llvm -i