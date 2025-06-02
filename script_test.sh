#!/bin/bash

MAP_DIR="assets/invalid_maps"
EXEC="./cub3d"
LOG_DIR="valgrind_logs"

mkdir -p "$LOG_DIR"

echo "🔍 Running memory leak checks with Valgrind..."
echo "---------------------------------------------"

for file in "$MAP_DIR"/*.cub; do
    map_name=$(basename "$file")
    log_file="$LOG_DIR/${map_name%.cub}.log"
    
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
        "$EXEC" "$file" > /dev/null 2> "$log_file"

    def_lost=$(grep "definitely lost:" "$log_file" | awk '{print $4}' | tr -d ',')
    ind_lost=$(grep "indirectly lost:" "$log_file" | awk '{print $4}' | tr -d ',')

    if [ "$def_lost" -ne 0 ] || [ "$ind_lost" -ne 0 ]; then
        echo "❌ $map_name -> Memory leaks detected! Check $log_file"
    else
        echo "✅ $map_name -> No memory leaks"
    fi
done

echo "---------------------------------------------"
echo "✅ Leak check completed."
