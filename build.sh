#!/bin/bash

BUILD_DIR="build"

# Step 1: Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
    echo "Created build directory: $BUILD_DIR"
else
    echo "'$BUILD_DIR' directory already exists."
fi

# Step 2: Check if we want to clean the build
if [ "$1" == "clean" ]; then
    echo "Cleaning up..."
    rm -rf "$BUILD_DIR"  # Remove the build directory and its contents
    echo "Clean complete."
    exit 0
fi

# Start timing the build process
start_time=$(date +%s)

# Step 3: Get a list of all .c files in the current directory
SOURCES=$(ls "src/"*.c)

# Step 4: Create an empty list for object files
OBJECTS=""

# Step 5: Compile each .c file into a .o file and move to the build directory
for SOURCE in $SOURCES; do
    OBJECT="${SOURCE##*/}"  # Get the file name (without path)
    OBJECT="${OBJECT%.c}.o"  # Replace .c with .o
    gcc -I../libs -c "$SOURCE" -o "$BUILD_DIR/$OBJECT"  # Compile the source file into the build directory
    
    # Check for errors during compilation
    if [ $? -ne 0 ]; then
        echo "Error compiling $SOURCE"
        exit 1  # Exit with an error code if the compilation fails
    fi

    OBJECTS="$OBJECTS $BUILD_DIR/$OBJECT"  # Add the object file to the list
done

# Step 6: Link the object files into the final executable (shared library or executable) in the build directory
# Create the shared library libmathlib.so
gcc $OBJECTS -o "$BUILD_DIR/libmathlib.so" -fPIC -shared -lm

# Check if linking the object files succeeded
if [ $? -ne 0 ]; then
    echo "Error linking object files into libmathlib.so"
    exit 1  # Exit with an error code if the linking fails
fi

# Step 7: Optionally, clean up object files (but leave the shared library in the build directory)
rm $OBJECTS

# End timing the build process
end_time=$(date +%s)
elapsed_time=$((end_time - start_time))

# Print the build completion time
echo "Build completed. Executable 'libmathlib.so' created in the '$BUILD_DIR' directory."
echo "Total build time: $elapsed_time seconds."
