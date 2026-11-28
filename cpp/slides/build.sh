#!/bin/bash
# 构建 slides-cpp 下全部课件：md -> html
# 用法: ./build.sh [课件名]
set -e
cd "$(dirname "$0")"

if [ -n "$1" ]; then
  name="$1"
  dir=$(find . -maxdepth 2 -name "$name.md" -not -path './references/*' | head -1 | xargs dirname)
  if [ -z "$dir" ]; then
    echo "not found: $name.md"
    exit 1
  fi
  python3 genhtml.py "$name" "${dir#./}"
  exit 0
fi

for md in */*.md; do
  case "$md" in
    references/*|code/*) continue ;;
  esac
  dir=$(dirname "$md")
  name=$(basename "$md" .md)
  python3 genhtml.py "$name" "$dir"
done
