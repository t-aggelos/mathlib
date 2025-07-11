#!/bin/bash

# We use a custom semver system, where:
# Each major is 15 minor, and each minor is 15 patches
# This is done because I don't want to bother really,
# thinking about major features and minor features.
MATHLIB_VERSION_PATCH=$((MATHLIB_VERSION_PATCH + 1))
if (( patch >= 15 )); then
    MATHLIB_VERSION_PATCH=0
    MATHLIB_VERSION_MINOR=$((MATHLIB_VERSION_MINOR + 1))
    if ((minor >= 15)); then 
        MATHLIB_VERSION_MINOR=0
        MATHLIB_VERSION_MAJOR=$((MATHLIB_VERSION_MAJOR + 1))
    fi
fi

# Save updated version back to file
echo "MATHLIB_VERSION_MAJOR=$MATHLIB_VERSION_MAJOR" > "$MATHLIB_VERSION_FILE"
echo "MATHLIB_VERSION_MINOR=$MATHLIB_VERSION_MINOR" >> "$MATHLIB_VERSION_FILE"
echo "MATHLIB_VERSION_PATCH=$MATHLIB_VERSION_PATCH" >> "$MATHLIB_VERSION_FILE"
