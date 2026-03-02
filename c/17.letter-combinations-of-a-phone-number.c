/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static const char *digit_to_letters[8] = {
    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void helper(int i_path, char *digits, char *path, int n, char **result, int *result_count) {
    if (i_path == n) {
        result[*result_count] = (char*)malloc((n+1) * sizeof(char));
        strcpy(result[*result_count], path);
        printf("%s\n", result[*result_count]);
        (*result_count)++;
        return;
    }

    char dig = digits[i_path];
    const char *letters = digit_to_letters[dig - '2'];
    for (int i = 0; i < strlen(letters); i++) {
        path[i_path] = letters[i];
        helper(i_path+1, digits, path, n, result, result_count);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int n = strlen(digits);
    int max_comb = 1;
    for (int i = 0; digits[i] != '\0'; i++) {
        if (digits[i] == '7' || digits[i] == '9') 
            max_comb *= 4;
        else
            max_comb *= 3;
    }
    int result_count = 0;
    char **result = (char**)malloc(max_comb * sizeof(char*));
    char *path = (char*)malloc((n+1) * sizeof(char));
    path[n] = '\0';

    helper(0, digits, path, n, result, &result_count);

    free(path);
    *returnSize = result_count;
    return result;
}
