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

add_executable(clone-graph "leetcode/graph/clone-graph.cpp")

add_executable(course-schedule "leetcode/graph/course-schedule.cpp")

add_executable(course-schedule-ii "leetcode/graph/course-schedule-ii.cpp")

add_executable(minimum-height-trees "leetcode/graph/minimum-height-trees.cpp")

add_executable(longest-increasing-path-in-a-matrix "leetcode/graph/longest-increasing-path-in-a-matrix.cpp")

add_executable(reconstruct-itinerary "leetcode/graph/reconstruct-itinerary.cpp")

add_executable(evaluate-division "leetcode/graph/evaluate-division.cpp")

add_executable(number-of-provinces "leetcode/graph/number-of-provinces.cpp")

add_executable(redundant-connection "leetcode/graph/redundant-connection.cpp")

add_executable(redundant-connection-ii "leetcode/graph/redundant-connection-ii.cpp")

add_executable(network-delay-time "leetcode/graph/network-delay-time.cpp")

add_executable(cracking-the-safe "leetcode/graph/cracking-the-safe.cpp")

add_executable(couples-holding-hands "leetcode/graph/couples-holding-hands.cpp")

add_executable(is-graph-bipartite "leetcode/graph/is-graph-bipartite.cpp")

add_executable(cheapest-flights-within-k-stops "leetcode/graph/cheapest-flights-within-k-stops.cpp")

add_executable(all-paths-from-source-to-target "leetcode/graph/all-paths-from-source-to-target.cpp")

add_executable(find-eventual-safe-states "leetcode/graph/find-eventual-safe-states.cpp")

add_executable(sum-of-distances-in-tree "leetcode/graph/sum-of-distances-in-tree.cpp")

add_executable(shortest-path-visiting-all-nodes "leetcode/graph/shortest-path-visiting-all-nodes.cpp")

add_executable(possible-bipartition "leetcode/graph/possible-bipartition.cpp")

add_executable(cat-and-mouse "leetcode/graph/cat-and-mouse.cpp")

add_executable(most-stones-removed-with-same-row-or-column "leetcode/graph/most-stones-removed-with-same-row-or-column.cpp")

add_executable(regions-cut-by-slashes "leetcode/graph/regions-cut-by-slashes.cpp")

add_executable(satisfiability-of-equality-equations "leetcode/graph/satisfiability-of-equality-equations.cpp")

add_executable(loud-and-rich "leetcode/graph/loud-and-rich.cpp")

add_executable(find-the-town-judge "leetcode/graph/find-the-town-judge.cpp")

add_executable(flower-planting-with-no-adjacent "leetcode/graph/flower-planting-with-no-adjacent.cpp")

add_executable(shortest-path-with-alternating-colors "leetcode/graph/shortest-path-with-alternating-colors.cpp")

add_executable(number-of-operations-to-make-network-connected "leetcode/graph/number-of-operations-to-make-network-connected.cpp")

add_executable(find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance "leetcode/graph/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance.cpp")

add_executable(validate-binary-tree-nodes "leetcode/graph/validate-binary-tree-nodes.cpp")

add_executable(course-schedule-iv "leetcode/graph/course-schedule-iv.cpp")

add_executable(reorder-routes-to-make-all-paths-lead-to-the-city-zero "leetcode/graph/reorder-routes-to-make-all-paths-lead-to-the-city-zero.cpp")

add_executable(path-with-maximum-probability "leetcode/graph/path-with-maximum-probability.cpp")



add_executable(longest-substring-without-repeating-characters "leetcode/string/longest-substring-without-repeating-characters.cpp")

add_executable(longest-palindromic-substring "leetcode/string/longest-palindromic-substring.cpp")

add_executable(zigzag-conversion "leetcode/string/zigzag-conversion.cpp")

add_executable(string-to-integer-atoi "leetcode/string/string-to-integer-atoi.cpp")

add_executable(integer-to-roman "leetcode/string/integer-to-roman.cpp")

add_executable(roman-to-integer "leetcode/string/roman-to-integer.cpp")

add_executable(longest-common-prefix "leetcode/string/longest-common-prefix.cpp")

add_executable(letter-combinations-of-a-phone-number "leetcode/string/letter-combinations-of-a-phone-number.cpp")

add_executable(valid-parentheses "leetcode/string/valid-parentheses.cpp")
# TODO: 如有需要，请添加测试并安装目标。
