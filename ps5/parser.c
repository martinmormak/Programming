#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "parser.h"

struct parser* create_parser()
{
    struct parser* parser=calloc(1,sizeof(struct parser));
    create_container(parser->commands,COMMAND,create_command("KONIEC", "Príkaz ukončí rozohratú hru. Nastaví príslušný stav hry.", "(KONIEC)", 1));
    //printf("%s",parser->commands->command->name);
    create_container(parser->commands,COMMAND,create_command("QUIT", "Príkaz ukončí rozohratú hru. Nastaví príslušný stav hry.", "(QUIT)", 1));
    create_container(parser->commands,COMMAND,create_command("EXIT", "Príkaz ukončí rozohratú hru. Nastaví príslušný stav hry.", "(EXIT)", 1));
    create_container(parser->commands,COMMAND,create_command("SEVER", "Presun do miestnosti nachádzajúcej sa na sever od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(SEVER)", 1));
    create_container(parser->commands,COMMAND,create_command("S", "Presun do miestnosti nachádzajúcej sa na sever od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(S)", 1));
    create_container(parser->commands,COMMAND,create_command("JUH", "Presun do miestnosti nachádzajúcej sa na juh od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(JUH)", 1));
    create_container(parser->commands,COMMAND,create_command("J", "Presun do miestnosti nachádzajúcej sa na juh od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(J)", 1));
    create_container(parser->commands,COMMAND,create_command("VYCHOD", "Presun do miestnosti nachádzajúcej sa na východ od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(VYCHOD)", 1));
    create_container(parser->commands,COMMAND,create_command("V", "Presun do miestnosti nachádzajúcej sa na východ od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(V)", 1));
    create_container(parser->commands,COMMAND,create_command("ZAPAD", "Presun do miestnosti nachádzajúcej sa na západ od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(ZAPAD)", 1));
    create_container(parser->commands,COMMAND,create_command("Z", "Presun do miestnosti nachádzajúcej sa na západ od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(Z)", 1));
    create_container(parser->commands,COMMAND,create_command("ROZHLIADNI SA", "Príkaz vypíše aktuálne informácie o miestnosti, v ktorej sa hráč práve nachádza.", "(ROZHLIADNI SA)", 1));
    create_container(parser->commands,COMMAND,create_command("PRIKAZY", "Príkaz vypíše na obrazovku zoznam všetkých príkazov, ktorĂ© hra poskytuje.", "(PRIKAZY)", 1));
    create_container(parser->commands,COMMAND,create_command("HELP", "Príkaz vypíše na obrazovku zoznam všetkých príkazov, ktorĂ© hra poskytuje.", "(HELP)", 1));
    create_container(parser->commands,COMMAND,create_command("POMOC", "Príkaz vypíše na obrazovku zoznam všetkých príkazov, ktorĂ© hra poskytuje.", "(POMOC)", 1));
    create_container(parser->commands,COMMAND,create_command("VERZIA", "Príkaz zobrazí číslo verzie hry, ľubovoľný sprievodný text a meno a priezvisko autora s kontaktom (e-mailová adresa, webová stránka).", "(VERZIA)", 1));
    create_container(parser->commands,COMMAND,create_command("RESTART", "Znovu spustí hru od začiatku. Zmení stav hry na požadovaný.", "(RESTART)", 1));
    create_container(parser->commands,COMMAND,create_command("O HRE", "Príkaz zobrazí krátky text, ktorý poslúži ako úvod do príbehu. Ako dobrý začiatok sa javí známy text: Kde bolo tam bolo, â€¦", "(O HRE)", 1));
    create_container(parser->commands,COMMAND,create_command("ABOUT", "Príkaz zobrazí krátky text, ktorý poslúži ako úvod do príbehu. Ako dobrý začiatok sa javí známy text: Kde bolo tam bolo, â€¦", "(ABOUT)", 1));
    create_container(parser->commands,COMMAND,create_command("VEZMI", "Vloží predmet z miestnosti do batohu. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš vziaĹĄ.).", "(VEZMI)", 1));
    create_container(parser->commands,COMMAND,create_command("POLOZ", "	Položí predmet z batohu do miestnosti. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš položiĹĄ.)", "(POLOZ)", 1));
    create_container(parser->commands,COMMAND,create_command("INVENTAR", "Zobrazí obsah hráčovho batohu.", "(INVENTAR)", 1));
    create_container(parser->commands,COMMAND,create_command("I", "Zobrazí obsah hráčovho batohu.", "(I)", 1));
    create_container(parser->commands,COMMAND,create_command("POUZI", "Použije predmet z batohu alebo miestnosti. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš použiĹĄ.).", "(POUZI)", 1));
    create_container(parser->commands,COMMAND,create_command("PRESKUMAJ", "Vypíše opis predmetu, ktorý sa musí nachádzaĹĄ v miestnosti alebo batohu. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný alebo sa nenájde v batohu alebo v miestnosti, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš preskúmaĹĄ.).", "(PRESKUMAJ)", 1));
    create_container(parser->commands,COMMAND,create_command("NAHRAJ", "Príkaz zabezpečí nahratie uloženej pozície hry z disku. Voliteľným parametrom je cesta k súboru.", "(NAHRAJ)", 1));
    create_container(parser->commands,COMMAND,create_command("LOAD", "Príkaz zabezpečí nahratie uloženej pozície hry z disku. Voliteľným parametrom je cesta k súboru.", "(LOAD)", 1));
    create_container(parser->commands,COMMAND,create_command("ULOZ", "Príkaz uloží stav rozohratej hry na disk. Voliteľným parametrom je cesta k súboru.", "(ULOZ)", 1));
    create_container(parser->commands,COMMAND,create_command("SAVE", "Príkaz uloží stav rozohratej hry na disk. Voliteľným parametrom je cesta k súboru.", "(SAVE)", 1));
    parser->history=NULL;
    return parser;
}

struct parser* destroy_parser(struct parser* parser)
{
    if(parser!=NULL)
    {
        if(parser->history!=NULL)
        {
            destroy_containers(parser->history);
        }
        if(parser->commands!=NULL)
        {
            destroy_containers(parser->commands);
        }
        free(parser);
    }
    return NULL;
}

struct command* parse_input(struct parser* parser, char* input)
{
    char* inpu=(char*)calloc(1,strlen(input)+1);
    memcpy(inpu,input,strlen(input));
    for(int i=0;i<strlen(input);i++)
    {
        inpu[i]=(char)toupper(input[i]);
    }
    //printf("%s\n",inpu);
    int a=0;
    while(inpu[a]==' ')
    {
        a++;
    }
    char bfr='a';
    char* buf=(char*)calloc(1,strlen(inpu)+1);
    for(a=a;a<strlen(inpu);a++)
    {
        if(bfr==' '&&inpu[a]==' ')
        {}
        else
        {
            buf[strlen(buf)]=inpu[a];
            buf[strlen(buf)]='\0';
        }
        bfr=inpu[a];
    }
    a=(int)strlen(buf)-1;
    while(buf[a]==' ')
    {
        a--;
    }
    buf[a+1]='\0';
    //printf("%s\n",buf);
    struct container* container=parser->commands;
    //memcpy(container,parser->commands,sizeof(struct container));
    while(parser->commands!=NULL)
    {
        printf("ahoj\n");
        //regmatch_t groups[container->command->nmatch];
        //int result = regexec(&container->command->preg, buf, 0, NULL, 0);
        //printf("%d/n",(char)container->command->preg);
        if(regexec(&container->command->preg,buf,0,NULL,0)!=REG_NOMATCH)
        {
            free(inpu);
            free(buf);
            //printf("%s/n",buf);
            return container->command;
        }
        container=container->next;
    }
    free(inpu);
    free(buf);
    return NULL;
}
