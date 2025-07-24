#include <stdio.h>
#include <string.h>
void readstr(char str[100]);
void readsearchstr(char pat[100]);
void readreplacestr(char replace[100]);
void matching(char mainstr[100], char pat[100], char replace[100]);
void main() {
    char mainstr[100], pat[100], replace[100];
    readstr(mainstr);
    readsearchstr(pat);
    readreplacestr(replace);
    matching(mainstr, pat, replace);
}
void readstr(char str[100]) {
    printf("\nEnter a string:\n");
    gets(str);
}
void readsearchstr(char pat[100]) {
    printf("Enter a search string:\n");
    gets(pat);
}
void readreplacestr(char replace[100]) {
    printf("\nEnter a replace string:\n");
    gets(replace);
}
void matching(char mainstr[100], char pat[100], char replace[100]) {
    char ans[100], *pos;
    int i = 0;
    pos = strstr(mainstr, pat);
    if (pos == NULL)     {
        printf("Search string is not present\n");
        return;
    }
    while (pos != NULL)     {
        strncpy(&ans[i], mainstr, pos - mainstr);
        i += pos - mainstr;
        strcpy(&ans[i], replace);
        i += strlen(replace);
        mainstr = pos + strlen(pat);
        pos = strstr(mainstr, pat);
    }
    strcpy(&ans[i], mainstr);
    printf("The resultant string is %s\n", ans);
}
