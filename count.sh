#!/bin/bash

# Directory to be searched
DIRECTORY="."

# Extensions of code files to be searched (add more as needed)
EXTENSIONS=("py" "cpp" "c" "hpp" "cc" "h")

# Initialize file and line count
FILE_COUNT=0
LINE_COUNT=0

# Function to count lines in a file
count_lines() {
    local file="$1"
    local lines=$(wc -l < "$file")
    echo "$lines"
}

# Main loop to go through files
for ext in "${EXTENSIONS[@]}"; do
    while IFS= read -r -d '' file; do
        FILE_COUNT=$((FILE_COUNT + 1))
        LINE_COUNT=$((LINE_COUNT + $(count_lines "$file")))
    done < <(find "$DIRECTORY" -name "*.$ext" -print0)
done

# Output results
echo "Number of code files: $FILE_COUNT"
echo "Total lines of code: $LINE_COUNT"
