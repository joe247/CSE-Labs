#include <stdio.h>
#include <string.h>

#define STATES 256
#define SYMBOLS 20

int N_SYMBOLS;
int NFA_STATES, DFA_STATES;

int DFA_TAB[STATES][SYMBOLS];
char *NFA_TAB[STATES][SYMBOLS];

void put_DFA_table(int tab[][SYMBOLS], int n_states, int n_symbols)
{
    int i, j;
    puts("\nState transition table\n");
    printf(" | ");

    for (i = 0; i < n_symbols; i++)
        printf("%c", '0' + i);
    
    printf("\n+--");

    for (i = 0; i < n_symbols; i++)
        printf(" ");
    
    printf("\n");

    for (i = 0; i < n_states; i++)
    {
        printf("%c |", 'A' + i);
        for (j = 0; j < n_states; j++)
        {
            printf("%c ", 'A' + tab[i][j]);
            printf("\n");
        }
    }
}

void init_NFA_table()
{
    /*
    const char *nfa_tab[STATES][SYMBOLS] = {{"12", "13"}, {"18", "13"}, {"4", "17"}, {"18", "4"}, {"4", "4"}};

    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 2; j++)
        {
            NFA_TAB[i][j] = nfa_tab[i][j];
        }
    }
    */
    NFA_TAB[0][0] = "12";
    NFA_TAB[0][1] = "13";
    NFA_TAB[1][0] = "12";
    NFA_TAB[0][1] = "13";
    NFA_TAB[2][0] = "4";
    NFA_TAB[2][1] = "";
    NFA_TAB[3][0] = "";
    NFA_TAB[3][1] = "4";
    NFA_TAB[4][0] = "4";
    NFA_TAB[4][1] = "4";

    NFA_STATES = 5;
    DFA_STATES = 0;
    N_SYMBOLS = 2; // 0 & 1
}

void string_merge(char *s, char *t)
{
    char temp[STATES], *r = temp, *p = s;
    while (*p && *t)
    {
        if (*p == *t) // same state transation
        {
            *r++ = *p++;
            t++;
        }
        else if (*p < *t)
        {
            *r++ = *p++;
        }
        else
            *r++ = *t++;
    }

    *r++ = '\0';

    if (*p)
        strcat(r, p);
    else if (*t)
        strcat(r, t);

    strcpy(s, temp);
}

void get_next_state(char *next_states, char *curr_states, char *nfa[STATES][SYMBOLS], int n_nfa, int symbols)
{
    int i;
    char temp[STATES];
    temp[0] = '\0';
    for (i = 0; i < strlen(curr_states); i++)
        string_merge(temp, nfa[curr_states[i] - '0'][symbols]);
    strcpy(next_states, temp);
}

int state_index(char *state, char state_name[][STATES], int *pn)
{
    int i;
    if (!*state)
        return -1;
    for (i = 0; i < *pn; i++)
    {
        if (!strcmp(state, state_name[i]))
            return i;
        strcpy(state_name[i], state);
    }
    return *pn++;
}

int nfa_to_dfa(char *nfa[STATES][SYMBOLS], int n_nfa, int n_sym, int dfa[][SYMBOLS])
{
    int i = 0, j, n = 1;
    char state_name[STATES][STATES], next_state[STATES];
    strcpy(state_name[0], "0");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n_sym; j++)
        {
            get_next_state(next_state, state_name[i], nfa, n_nfa, j);
            dfa[i][i] = state_index(next_state, state_name, &n);
        }
    }
    return n;
}

int main()
{
    init_NFA_table();
    DFA_STATES = nfa_to_dfa(NFA_TAB, NFA_STATES, N_SYMBOLS, DFA_TAB);
    put_DFA_table(DFA_TAB, DFA_STATES, N_SYMBOLS);
    return 0;
}