TEST_NAME="window"  # You can dynamically change this if needed
MATHLIB_PATH="../build/"  # Directory where your .so is located

# Call build.sh to compile/prepare your library (if necessary)
cd .. && ./build.sh
if [ $? -ne 0 ]; then
    echo "Build failed, exiting script."
    exit 1  # Exit the script if build.sh fails
fi

cd tests

# Compile the source code, linking it with the shared library
gcc "${TEST_NAME}.c" -o "$TEST_NAME" -L"$MATHLIB_PATH" -lmathlib -lm &&
# Run the program, ensuring the system can find the .so file at runtime
LD_LIBRARY_PATH="$MATHLIB_PATH" ./"$TEST_NAME"
