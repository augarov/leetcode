#!/bin/bash

CMD=${LEETCODE_CLI:-leetcode}

TARGET_PATH=$(realpath "$1")
if [ -f "${TARGET_PATH}" ]; then
    STATS_FILE="${TARGET_PATH}"
else
    echo "Invalid target path: ${TARGET_PATH}" >&2
    exit 1
fi

NL=$'\n'

function extract_progress() {
    local data=$1
    echo "${data}" | grep -oE "${2}\s+[0-9]+/[0-9]+" | awk '{ print $2 }'
}

function make_progress_badge() {
    local label=$1
    local color=$2
    local progress=$3
    local curr=$(echo ${progress} | awk -F'/' '{print $1}')
    local total=$(echo ${progress} | awk -F'/' '{print $2}')
    echo "![${label} ${progress}](https://progress-bar.xyz/${curr}?title=${label}%20&scale=${total}&suffix=%20%2F%20${total}&progress_color=4B9E46&color=000000&progress_number_color=${color}&width=200)"
}

function badges_by_category() {
    if [[ $# -lt 1 ]]; then
        local category="all"
        echo "Fetching totals..." >&2
        local data=$(${CMD} stats)
    else
        local category="$1"
        echo "Fetching stats for '$category'..." >&2
        local data=$(${CMD} stats -t ${category})
    fi

    if [ $? -ne 0 ]; then
        echo "Failed to fetch" >&2
        exit 1
    fi

    local easy_progress=$(extract_progress "${data}" "Easy")
    echo "${category}-easy: ${easy_progress}" >&2
    local easy_badge=$(make_progress_badge "easy" "21FF0A" $easy_progress)

    local medium_progress=$(extract_progress "${data}" "Medium")
    echo "${category}-medium: ${medium_progress}" >&2
    local medium_badge=$(make_progress_badge "medium" "F3F70B" $medium_progress)

    local hard_progress=$(extract_progress "${data}" "Hard")
    echo "${category}-hard: ${hard_progress}" >&2
    local hard_badge=$(make_progress_badge "hard" "FC4047" $hard_progress)

    echo -e "${easy_badge}${NL}${medium_badge}${NL}${hard_badge}"
}

total_badges=$(badges_by_category)
array_badges=$(badges_by_category "array")
string_badges=$(badges_by_category "string")
linked_list_badges=$(badges_by_category "linked-list")
hashmap_badges=$(badges_by_category "hash-table")
tree_badges=$(badges_by_category "tree")
heap_badges=$(badges_by_category "heap")
dp_badges=$(badges_by_category "dynamic-programming")

echo "Generating ${STATS_FILE}" >&2

cat << EOF > ${STATS_FILE}
# Hi, it's me having fun with LeetCode
## Statistics
### Total
${total_badges}
### By Category
#### Array
${array_badges}
#### String
${string_badges}
#### Linked List
${linked_list_badges}
#### Hash Table
${hashmap_badges}
#### Tree
${tree_badges}
#### Heap
${heap_badges}
#### Dynamic Programming
${dp_badges}
EOF

exit $?
