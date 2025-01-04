#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <mode> <path>"
    exit 1
fi

MODE="$1"
TARGET_PATH=$(realpath "$2")

CMD=${LEETCODE_CLI:-leetcode}

if [ -f "${TARGET_PATH}" ]; then
    SOLUTION="${TARGET_PATH}"
elif [ -d "${TARGET_PATH}" ]; then
    SOLUTION="${TARGET_PATH}/solution.cpp"
    if [ ! -f "${SOLUTION}" ]; then
        echo "Solution not found: ${SOLUTION}"
        exit 1
    fi
else
    echo "Invalid target path: ${TARGET_PATH}"
    exit 1
fi

case "${MODE}" in
    test)
        echo "Testing solution ${SOLUTION}..."

        base_dir=$(dirname "${SOLUTION}")
        testsuite="${base_dir}/tests.txt"
        if [ -f "${testsuite}" ]; then
            echo "Using tests ${testsuite}"
            cat ${testsuite} | ${CMD} test ${SOLUTION} -i
        else
            echo "Using default tests"
            ${CMD} test ${SOLUTION}
        fi


        exit $?
        ;;
    *)
        echo "Invalid mode: ${MODE}"
        exit 1
        ;;
esac