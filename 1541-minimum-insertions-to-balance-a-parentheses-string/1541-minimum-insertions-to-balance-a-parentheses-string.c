
int minInsertions(const char *s) {
    int need = 0;
    int insertions = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            // Ensure the required closing parentheses remain in pairs
            if (need % 2 != 0) {
                insertions++;
                need--;
            }

            // Each opening parenthesis requires two closing parentheses
            need += 2;
        } else {
            // Use one required closing parenthesis
            need--;

            // If there is no matching opening parenthesis, insert one
            if (need < 0) {
                insertions++;
                need = 1;
            }
        }
    }

    // Insert any remaining required closing parentheses
    return insertions + need;
}

