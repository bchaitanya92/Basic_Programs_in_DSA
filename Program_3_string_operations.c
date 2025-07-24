#include<stdio.h>
void readstr(void);
void readsearchstr(void);
void readreplacestr(void);
void matching(char str[100]);
char mainstr[100],pat[100],replace[100],ans[100];

void main()
{

    readstr();
    readsearchstr();
    readreplacestr();
    matching(mainstr);
}


// Function to read the main string from the user
void readstr() 
{
    printf("\n Enter a string:\n");
    gets(mainstr); // Gets the input string and stores it in the mainstr variable
}

// Function to read the search string from the user
void readsearchstr() 
{
    printf("Enter a search string:\n");
    gets(pat); // Gets the input search string and stores it in the pat variable
}

// Function to read the replacement string from the user
void readreplacestr() 
{
    printf("\n Enter a replace string:\n");
    gets(replace); // Gets the input replacement string and stores it in the replace variable
}

// Function to perform string matching and replace the occurrences of the search string with the replacement string
void matching(char mainstr[100]) 
{
    char ans[100]; // Buffer to store the modified string
    int i = 0, j = 0, c = 0, m = 0, k = 0, flag = 0; // Initialize counters and flags

    // Iterate through the main string
    while (mainstr[c] != '\0') 
    {
        // Check if the current character of the main string matches the current character of the search string
        if (mainstr[m] == pat[i]) 
        {
            // Increment the indices of both strings
            i++;
            m++;

            // If the entire search string has been matched
            if (pat[i] == '\0') 
            {
                // Replace the search string with the replacement string
                for (k = 0; replace[k] != '\0'; k++, j++) 
                {
                    ans[j] = replace[k];
                }

                // Reset the indices for the next search string match
                i = 0;
                c = m;

                // Set the flag to indicate a match
                flag = 1;
            }
        } 
        else 
        {
            // Copy the current character of the main string to the answer string
            ans[j] = mainstr[c];
            j++;
            c++;
            m = c; // Reset the index for the next search string match
            i = 0; // Reset the index for the next search string match
        }
    }

    // Terminate the answer string
    ans[j] = '\0';

    // Check if the search string was found
    if (flag == 0) 
    {
        printf("Search string is not present\n");
    }

    // Display the modified string
    printf("The resultant string is %s\n", ans);
}