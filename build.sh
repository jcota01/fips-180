#!/bin/bash
echo "Running pre-build..."

echo "Remove Testing directory..."
rm -rf Testing

echo "Build project..."
cmake --preset default
cmake --build --preset default