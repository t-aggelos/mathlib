#!/bin/bash
set -e

# Root bin directory
MATHLIB_BIN_DIR="./bin"

#
# Version control
#
MATHLIB_VERSION_FILE="./version.properties"
if [[ -f "$MATHLIB_VERSION_FILE" ]]; then
    source "$MATHLIB_VERSION_FILE"
else
    MATHLIB_VERSION_MAJOR=0
    MATHLIB_VERSION_MINOR=0
    MATHLIB_VERSION_PATCH=0
fi

echo "[INFO] 🔁 Building version: $MATHLIB_VERSION_MAJOR.$MATHLIB_VERSION_MINOR.$MATHLIB_VERSION_PATCH"

build_assembly() {
    MATHLIB_CURRENT_ASSEMBLY="$1"
    
    cd "$MATHLIB_CURRENT_ASSEMBLY" || {
        echo "[ERROR]: Failed to enter directory: $MATHLIB_CURRENT_ASSEMBLY"
        exit 1
    }

    # export output 
    export "$1"

    # SOURCE is not POSIX-compliant (!), use "." instead
    . "./build.sh"

    ERROR_LEVEL=$?
    if [ "$ERROR_LEVEL" -ne 0 ]; then
        echo "[ERROR]: $1 build failed with code $ERROR_LEVEL"
        exit "$ERROR_LEVEL"
    else
        echo "[SUCCESS]: $1 built successfully."
    fi

    # fail guard and navigate back to root
    cd - >/dev/null || exit 1
}

#
# Build for library
#
MATHLIB_SRC_DIR="./src"
MATHLIB_INCLUDE_DIR="./include"
build_assembly src

#
# Build for testbed
#
MATHLIB_SRC_DIR="./testbed/src"
MATHLIB_INCLUDE_DIR="./testbed/include"
build_assembly testbed

