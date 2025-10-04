#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Delimiter used between length and string content
#define DELIMITER '#'

// Function to encode a list of strings
char* encode(char** strs, int num_strs) {
    if (num_strs == 0) {
        return strdup(""); // Return empty string for empty list
    }

    size_t total_len = 0;
    for (int i = 0; i < num_strs; i++) {
        int len = strlen(strs[i]);
        // Calculate length of length string (e.g., "123" has length 3)
        int len_str_len = snprintf(NULL, 0, "%d", len); 
        total_len += len_str_len + 1 + len; // length_str + DELIMITER + actual_string
    }

    char* encoded_str = (char*)malloc(total_len + 1);
    if (encoded_str == NULL) {
        perror("Failed to allocate memory for encoded string");
        exit(EXIT_FAILURE);
    }
    encoded_str[0] = '\0'; // Initialize as empty string

    for (int i = 0; i < num_strs; i++) {
        int len = strlen(strs[i]);
        char len_str[20]; // Buffer for length string
        sprintf(len_str, "%d", len);
        strcat(encoded_str, len_str);
        strcat(encoded_str, "#");
        strcat(encoded_str, strs[i]);
    }
    return encoded_str;
}

// Function to decode a single string back into a list of strings
char** decode(char* s, int* num_decoded_strs) {
    if (s == NULL || strlen(s) == 0) {
        *num_decoded_strs = 0;
        return NULL;
    }

    char** decoded_strs = NULL;
    *num_decoded_strs = 0;
    int current_pos = 0;
    int capacity = 2; // Initial capacity for decoded_strs array

    decoded_strs = (char**)malloc(capacity * sizeof(char*));
    if (decoded_strs == NULL) {
        perror("Failed to allocate memory for decoded strings");
        exit(EXIT_FAILURE);
    }

    while (s[current_pos] != '\0') {
        char len_buffer[20];
        int len_buffer_idx = 0;
        while (s[current_pos] != DELIMITER && s[current_pos] != '\0') {
            len_buffer[len_buffer_idx++] = s[current_pos++];
        }
        len_buffer[len_buffer_idx] = '\0';
        current_pos++; // Move past the delimiter

        int str_len = atoi(len_buffer);

        char* decoded_str = (char*)malloc(str_len + 1);
        if (decoded_str == NULL) {
            perror("Failed to allocate memory for decoded string");
            exit(EXIT_FAILURE);
        }
        strncpy(decoded_str, s + current_pos, str_len);
        decoded_str[str_len] = '\0';
        current_pos += str_len;

        // Resize array if needed
        if (*num_decoded_strs == capacity) {
            capacity *= 2;
            decoded_strs = (char**)realloc(decoded_strs, capacity * sizeof(char*));
            if (decoded_strs == NULL) {
                perror("Failed to reallocate memory for decoded strings");
                exit(EXIT_FAILURE);
            }
        }
        decoded_strs[(*num_decoded_strs)++] = decoded_str;
    }
    return decoded_strs;
}

// Helper function to free memory allocated by decode
void free_decoded_strings(char** strs, int num_strs) {
    if (strs == NULL) return;
    for (int i = 0; i < num_strs; i++) {
        free(strs[i]);
    }
    free(strs);
}

// Example usage
int main() {
    char* original_strs[] = {"hello", "world", "longstringwithnumbers123"};
    int num_original_strs = sizeof(original_strs) / sizeof(original_strs[0]);

    char* encoded = encode(original_strs, num_original_strs);
    printf("Encoded: %s\n", encoded);

    int num_decoded_strs;
    char** decoded = decode(encoded, &num_decoded_strs);

    printf("Decoded:\n");
    for (int i = 0; i < num_decoded_strs; i++) {
        printf("- %s\n", decoded[i]);
    }

    free(encoded);
    free_decoded_strings(decoded, num_decoded_strs);

    return 0;
}
