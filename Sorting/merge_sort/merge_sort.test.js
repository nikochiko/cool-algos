// Test case of merge sort function.
const merge_sort_test = require("./merge_sort.js");

const input = [5345, 55, 3423, 5346, 33];
const sorted = merge_sort_test.mergeSort(input);
console.log("Merge sort", sorted);
