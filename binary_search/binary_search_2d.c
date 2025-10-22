/*

Search in a Sorted matrix

*/


/**
 * Binary Search Once 
 * Time: O(log(n × m)) 
 * Space: O(1)
 */
int binary_search_matrix1(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];

    int left = 0;
    int right = rows * cols - 1;

    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        int r = mid / cols;
        int c = mid % cols;
        int mid_value = matrix[r][c];

        if (mid_value == target) {
            return 1;
        } else if (mid_value < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}


/**
 * Binary Search Once 
 * Time: O(log(n) + log(m)) 
 * Space: O(1)
 */
int binary_search_matrix2(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];

    /* Binary Search to find the correct row */
    int top = 0;
    int bottom = rows - 1;
    int row = -1;

    /* Binary Search to find the correct row */
    while (top <= bottom) {
        int mid_row = top + ((bottom - top) >> 1);
        if (target >= matrix[mid_row][0] && target <= matrix[mid_row][cols - 1]) {
            row = mid_row;
            break;
        } else if (target < matrix[mid_row][0]) {
            bottom = mid_row - 1;
        } else {
            top = mid_row + 1;
        }
    }

    if (row == -1) {
        return 0;
    }

    /* Binary Search within the identified row */
    int left = 0;
    int right = cols - 1;

    while (left <= right) {
        int mid_col = left + ((right - left) >> 1);
        int mid_value = matrix[row][mid_col];

        if (mid_value == target) {
            return 1;
        } else if (mid_value < target) {
            left = mid_col + 1;
        } else {
            right = mid_col - 1;
        }
    }

    return 0;
}