#!/bin/bash

CMD=${LEETCODE_CLI:-leetcode}

TARGET_PATH=$(realpath "$1")
if [ -f "${TARGET_PATH}" ]; then
    STATS_FILE="${TARGET_PATH}"
else
    echo "Invalid target path: ${TARGET_PATH}"
    exit 1
fi

echo "Fetching stats..."
data=$(${CMD} stats)

if [ $? -ne 0 ]; then
    echo "Failed to fetch"
    exit 1
fi


function extract_progress() {
    echo "${data}" | grep -oE "${1}\s+[0-9]+/[0-9]+" | awk '{ print $2 }'
}

function make_progress_badge() {
    local label=$1
    local color=$2
    local progress=$3
    local curr=$(echo ${progress} | awk -F'/' '{print $1}')
    local total=$(echo ${progress} | awk -F'/' '{print $2}')
    echo "![${label} ${progress}](https://progress-bar.xyz/${curr}?title=${label}%20&scale=${total}&suffix=%20%2F%20${total}&progress_color=4B9E46&color=000000&progress_number_color=${color}&width=200)"
}

easy_progress=$(extract_progress "Easy")
echo "Easy progress: ${easy_progress}"
easy_badge=$(make_progress_badge "easy" "21FF0A" $easy_progress)

medium_progress=$(extract_progress "Medium")
echo "Medium progress: ${medium_progress}"
medium_badge=$(make_progress_badge "medium" "F3F70B" $medium_progress)

hard_progress=$(extract_progress "Hard")
echo "Hard progress: ${hard_progress}"
hard_badge=$(make_progress_badge "hard" "FC4047" $hard_progress)

echo "Generatin ${STATS_FILE}"

cat << EOF > ${STATS_FILE}
# Hi, it's me having fun with LeetCode
### Statistics
${easy_badge}
${medium_badge}
${hard_badge}
EOF

exit $?
