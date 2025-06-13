#!/bin/bash

set -e

if [[ "$1" == "build" ]]; then
  cmake -G Ninja -S . -B target-build
  cmake --build target-build -- -k 0 -j"$(nproc)" | tee build.log

  if [[ "${PIPESTATUS[0]}" -ne 0 ]]; then
    echo "The following builds have failed:"
    grep FAILED build.log
    exit 1
  fi

elif [[ "$1" == "clean" ]]; then
  echo "Cleaning build directory..."
  rm -rf build build.log

else
  echo "Usage: $0 {build|clean}"
  exit 1
fi
