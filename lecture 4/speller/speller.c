// Implements a spell-checker

#include <ctype.h>
#include <stdio.h>
#ifdef __unix__
#include <sys/resource.h>
#include <sys/time.h>
#endif

#include "dictionary.h"

// Undefine any definitions
#undef calculate
#undef getrusage

// Default dictionary
#define DICTIONARY "dictionaries/large"

// Prototype
#ifdef __unix__
double calculate(const struct rusage *b, const struct rusage *a);
#endif

int main(int argc, char *argv[])
{
    // Check for correct number of args
    if (argc != 2 && argc != 3)
    {
        printf("Usage: speller [dictionary] text\n");
        return 1;
    }

#ifdef __unix__
    // Structures for timing data
    struct rusage before, after;

    // Benchmarks
    double time_load = 0.0, time_check = 0.0, time_size = 0.0, time_unload = 0.0;
#endif

    // Determine dictionary to use
    char *dictionary = (argc == 3) ? argv[1] : DICTIONARY;

    // Load dictionary
#ifdef __unix__
    getrusage(RUSAGE_SELF, &before);
#endif
    bool loaded = load(dictionary);
#ifdef __unix__
    getrusage(RUSAGE_SELF, &after);

    // Calculate time to load dictionary
    time_load = calculate(&before, &after);
#endif

    // Exit if dictionary not loaded
    if (!loaded)
    {
        printf("Could not load %s.\n", dictionary);
        return 1;
    }

    // Try to open text
    char *text = (argc == 3) ? argv[2] : argv[1];
    FILE *file = fopen(text, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", text);
        unload();
        return 1;
    }

    // Prepare to report misspellings
    printf("\nMISSPELLED WORDS\n\n");

    // Prepare to spell-check
    int index = 0, misspellings = 0, words = 0;
    char word[LENGTH + 1];

    // Spell-check each word in text
    for (int c = fgetc(file); c != EOF; c = fgetc(file))
    {
        // Allow only alphabetical characters and apostrophes
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            // Append character to word
            word[index] = c;
            index++;

            // Ignore alphabetical strings too long to be words
            if (index > LENGTH)
            {
                // Consume remainder of alphabetical string
                while ((c = fgetc(file)) != EOF && isalpha(c));

                // Prepare for new word
                index = 0;
            }
        }

        // Ignore words with numbers (like MS Word can)
        else if (isdigit(c))
        {
            // Consume remainder of alphanumeric string
            while ((c = fgetc(file)) != EOF && isalnum(c));

            // Prepare for new word
            index = 0;
        }

        // We must have found a whole word
        else if (index > 0)
        {
            // Terminate current word
            word[index] = '\0';

            // Update counter
            words++;

            // Check word's spelling
#ifdef __unix__
            getrusage(RUSAGE_SELF, &before);
#endif
            bool misspelled = !check(word);
#ifdef __unix__
            getrusage(RUSAGE_SELF, &after);

            // Update benchmark
            time_check += calculate(&before, &after);
#endif

            // Print word if misspelled
            if (misspelled)
            {
                printf("%s\n", word);
                misspellings++;
            }

            // Prepare for next word
            index = 0;
        }
    }

    // Check whether there was an error
    if (ferror(file))
    {
        fclose(file);
        printf("Error reading %s.\n", text);
        unload();
        return 1;
    }

    // Close text
    fclose(file);

    // Determine dictionary's size
#ifdef __unix__
    getrusage(RUSAGE_SELF, &before);
#endif
    unsigned int n = size();
#ifdef __unix__
    getrusage(RUSAGE_SELF, &after);

    // Calculate time to determine dictionary's size
    time_size = calculate(&before, &after);
#endif

    // Unload dictionary
#ifdef __unix__
    getrusage(RUSAGE_SELF, &before);
#endif
    bool unloaded = unload();
#ifdef __unix__
    getrusage(RUSAGE_SELF, &after);

    // Calculate time to unload dictionary
    time_unload = calculate(&before,
