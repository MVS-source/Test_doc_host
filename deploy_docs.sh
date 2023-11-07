#!/bin/bash

# Stops the script if a command fails
set -e

# Config
REPO="https://github.com/MVS-source/Test_doc_host.git"
TARGET_BRANCH="gh-pages"
BUILD_DIR="../B-CPP-500-LYN-5-1-rtype-bryan.zakka"  # The path should be to your build directory
CLONE_DIR="gh-pages-clone"
COMMIT_MESSAGE="Update documentation"

# Check if the build directory exists
if [ ! -d "$BUILD_DIR" ]; then
    echo "The build directory $BUILD_DIR does not exist."
    exit 1
fi

# Clone only the gh-pages branch
if [ ! -d "$CLONE_DIR" ]; then
    git clone --branch $TARGET_BRANCH $REPO $CLONE_DIR
else
    echo "Using existing '$CLONE_DIR' directory."
fi

# Create a 'doc' directory in the clone directory if it doesn't exist
mkdir -p $CLONE_DIR/docs

# Copy the Client, GameEngine, and Server directories
cp -ra $BUILD_DIR/Client $CLONE_DIR
cp -ra $BUILD_DIR/GameEngine $CLONE_DIR
cp -ra $BUILD_DIR/Server $CLONE_DIR
cp -ra $BUILD_DIR/Assets $CLONE_DIR

# Copy the Doxygen HTML directory to the 'docs' directory
cp -ra $BUILD_DIR/doxygen/html/* $CLONE_DIR/docs/

# Go into the clone directory
cd $CLONE_DIR

# Add all changes to git
git add --all .

# Check for changes; if nothing has changed, exit the script
if git diff --cached --quiet; then
    echo "No changes to the documentation to commit."
    exit 0
else
    echo "Changes detected, preparing to commit."
fi

# Configure git with your name and email
git config user.name "MVS-source"
git config user.email "victor-michael.smith@epitech.eu"

# Commit the changes
git commit -m "$COMMIT_MESSAGE"

# Push the changes to the gh-pages branch
git push origin $TARGET_BRANCH

# Confirmation message
echo "La documentation a été déployée."

# Cleanup: go back to the original directory and remove the clone directory
cd ..
rm -rf $CLONE_DIR
