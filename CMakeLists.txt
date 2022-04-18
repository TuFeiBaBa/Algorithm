# CMakeList.txt: Algorithm 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithm")

# 将源代码添加到此项目的可执行文件。
add_executable (Algorithm "Algorithm.cpp" "Algorithm.h")

add_executable(push-dominoes "leetcode/push-dominoes.cpp")

add_executable(base-7 "leetcode/base-7.cpp")

add_executable(plates-between-candles "leetcode/plates-between-candles.cpp")

add_executable(minimum-index-sum-of-two-lists "leetcode/minimum-index-sum-of-two-lists.cpp")

add_executable(the-time-when-the-network-becomes-idle "leetcode/the-time-when-the-network-becomes-idle.cpp")

add_executable(k-th-smallest-in-lexicographical-order "leetcode/k-th-smallest-in-lexicographical-order.cpp")

add_executable(find-missing-observations "leetcode/find-missing-observations.cpp")

add_executable(remove-colored-pieces-if-both-neighbors-are-the-same-color "leetcode/remove-colored-pieces-if-both-neighbors-are-the-same-color.cpp")

add_executable(binary-number-with-alternating-bits "leetcode/binary-number-with-alternating-bits.cpp")

add_executable(maximize-the-confusion-of-an-exam "leetcode/maximize-the-confusion-of-an-exam.cpp")

add_executable(array-of-doubled-pairs "leetcode/array-of-doubled-pairs.cpp")

add_executable(rotate-string "leetcode/rotate-string.cpp")

add_executable(insert-delete-getrandom-o1 "leetcode/insert-delete-getrandom-o1.cpp")

add_executable(find-servers-that-handled-most-number-of-requests "leetcode/find-servers-that-handled-most-number-of-requests.cpp")

add_executable(clone-graph "leetcode/clone-graph.cpp")
# TODO: 如有需要，请添加测试并安装目标。
