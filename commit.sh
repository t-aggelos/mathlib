#!/bin/bash
# simple quick script to up a version and commit every time i want to push

git add .
git commit -m "$1"
./up_version.sh
git push origin main