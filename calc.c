#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

int main(void)
{
    /* Screen initialisieren. malloc */
    initscr();
    

    /* refresh damit Bildschirminhalt = Memory-Inhalt */
    refresh();
    
    /* Render Screen */
    /*
        1 - num1 und num2 nicht gesetzt
        2 - num1 gesetzt
    */
    char numSet = '1';
    char operation = '+';
    int num1, num2;
    char c;
    char *buffer = (char*)malloc(255);
    while(1)
    {
        /* Zahlen einlesen */
        printw("Type first Number");        
        
        while(1)
        {
            c = getch();
            if ( c >= '0' && c <= '9')
            {
                sprintf(buffer, "%s%c",buffer,c);
            }
            else if ( c == 0xA && numSet == '2' )
            {
                clear();
                int solution;
                if (operation == '+')
                {
                    solution = num1 + atoi(buffer);
                }
                else
                {
                    solution = num1 - atoi(buffer);
                }
                printw("%d", solution);
            }
            else if (c == 0x2B )
            {
                if (numSet == '1')
                {
                    numSet = '2';
                    num1 = atoi(buffer);
                    strcpy(buffer,"");
                }
            }
            else if (c == 0x2D )
            {
                if (numSet == '1')
                {
                    numSet = '2';
                    operation = '-';
                    num1 = atoi(buffer);
                    strcpy(buffer,"");
                }
            }
 
            /* parseCharacter(c); */
        }
        /* Operation auswählen */
        /* Zahlen einlesen */
        /* Bestätigen */
        /* Ausgabe Ergebnis */
        /* Optionen Beenden oder refresh */
    }
    
    clear();
    printw("%d", c);
    refresh();
    getch();
    endwin();
    return 0;
}
