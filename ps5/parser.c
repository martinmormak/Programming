#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "parser.h"

struct parser* create_parser()
{
    struct parser* parser=calloc(1,sizeof(struct parser));
    create_container(parser->commands,COMMAND,create_command("KONIEC", "PrĂ­kaz ukonÄŤĂ­ rozohratĂş hru. NastavĂ­ prĂ­sluĹˇnĂ˝ stav hry.", "(KONIEC)", 1));
    create_container(parser->commands,COMMAND,create_command("QUIT", "PrĂ­kaz ukonÄŤĂ­ rozohratĂş hru. NastavĂ­ prĂ­sluĹˇnĂ˝ stav hry.", "(QUIT)", 1));
    create_container(parser->commands,COMMAND,create_command("EXIT", "PrĂ­kaz ukonÄŤĂ­ rozohratĂş hru. NastavĂ­ prĂ­sluĹˇnĂ˝ stav hry.", "(EXIT)", 1));
    create_container(parser->commands,COMMAND,create_command("SEVER", "Presun do miestnosti nachĂˇdzajĂşcej sa na sever od aktuĂˇlnej. ZmenĂ­ referenciu aktuĂˇlnej miestnosti.", "(SEVER)", 1));
    create_container(parser->commands,COMMAND,create_command("S", "Presun do miestnosti nachĂˇdzajĂşcej sa na sever od aktuĂˇlnej. ZmenĂ­ referenciu aktuĂˇlnej miestnosti.", "(S)", 1));
    create_container(parser->commands,COMMAND,create_command("JUH", "Presun do miestnosti nachĂˇdzajĂşcej sa na juh od aktuĂˇlnej. ZmenĂ­ referenciu aktuĂˇlnej miestnosti.", "(JUH)", 1));
    create_container(parser->commands,COMMAND,create_command("J", "Presun do miestnosti nachĂˇdzajĂşcej sa na juh od aktuĂˇlnej. ZmenĂ­ referenciu aktuĂˇlnej miestnosti.", "(J)", 1));
    create_container(parser->commands,COMMAND,create_command("VYCHOD", "Presun do miestnosti nachĂˇdzajĂşcej sa na vĂ˝chod od aktuĂˇlnej. ZmenĂ­ referenciu aktuĂˇlnej miestnosti.", "(VYCHOD)", 1));
    create_container(parser->commands,COMMAND,create_command("V", "Presun do miestnosti nachĂˇdzajĂşcej sa na vĂ˝chod od aktuĂˇlnej. ZmenĂ­ referenciu aktuĂˇlnej miestnosti.", "(V)", 1));
    create_container(parser->commands,COMMAND,create_command("ZAPAD", "Presun do miestnosti nachĂˇdzajĂşcej sa na zĂˇpad od aktuĂˇlnej. ZmenĂ­ referenciu aktuĂˇlnej miestnosti.", "(ZAPAD)", 1));
    create_container(parser->commands,COMMAND,create_command("Z", "Presun do miestnosti nachĂˇdzajĂşcej sa na zĂˇpad od aktuĂˇlnej. ZmenĂ­ referenciu aktuĂˇlnej miestnosti.", "(Z)", 1));
    create_container(parser->commands,COMMAND,create_command("ROZHLIADNI SA", "PrĂ­kaz vypĂ­Ĺˇe aktuĂˇlne informĂˇcie o miestnosti, v ktorej sa hrĂˇÄŤ prĂˇve nachĂˇdza.", "(ROZHLIADNI SA)", 1));
    create_container(parser->commands,COMMAND,create_command("PRIKAZY", "PrĂ­kaz vypĂ­Ĺˇe na obrazovku zoznam vĹˇetkĂ˝ch prĂ­kazov, ktorĂ© hra poskytuje.", "(PRIKAZY)", 1));
    create_container(parser->commands,COMMAND,create_command("HELP", "PrĂ­kaz vypĂ­Ĺˇe na obrazovku zoznam vĹˇetkĂ˝ch prĂ­kazov, ktorĂ© hra poskytuje.", "(HELP)", 1));
    create_container(parser->commands,COMMAND,create_command("POMOC", "PrĂ­kaz vypĂ­Ĺˇe na obrazovku zoznam vĹˇetkĂ˝ch prĂ­kazov, ktorĂ© hra poskytuje.", "(POMOC)", 1));
    create_container(parser->commands,COMMAND,create_command("VERZIA", "PrĂ­kaz zobrazĂ­ ÄŤĂ­slo verzie hry, ÄľubovoÄľnĂ˝ sprievodnĂ˝ text a meno a priezvisko autora s kontaktom (e-mailovĂˇ adresa, webovĂˇ strĂˇnka).", "(VERZIA)", 1));
    create_container(parser->commands,COMMAND,create_command("RESTART", "Znovu spustĂ­ hru od zaÄŤiatku. ZmenĂ­ stav hry na poĹľadovanĂ˝.", "(RESTART)", 1));
    create_container(parser->commands,COMMAND,create_command("O HRE", "PrĂ­kaz zobrazĂ­ krĂˇtky text, ktorĂ˝ poslĂşĹľi ako Ăşvod do prĂ­behu. Ako dobrĂ˝ zaÄŤiatok sa javĂ­ znĂˇmy text: Kde bolo tam bolo, â€¦", "(O HRE)", 1));
    create_container(parser->commands,COMMAND,create_command("ABOUT", "PrĂ­kaz zobrazĂ­ krĂˇtky text, ktorĂ˝ poslĂşĹľi ako Ăşvod do prĂ­behu. Ako dobrĂ˝ zaÄŤiatok sa javĂ­ znĂˇmy text: Kde bolo tam bolo, â€¦", "(ABOUT)", 1));
    create_container(parser->commands,COMMAND,create_command("VEZMI", "VloĹľĂ­ predmet z miestnosti do batohu. PrĂ­kaz mĂˇ jeden povinnĂ˝ parameter, ktorĂ˝m je nĂˇzov predmetu. Ak predmet nebude zadanĂ˝, program vypĂ­Ĺˇe na obrazovku vhodnĂş hlĂˇĹˇku (napr. Neviem, ÄŤo chceĹˇ vziaĹĄ.).", "(VEZMI)", 1));
    create_container(parser->commands,COMMAND,create_command("POLOZ", "	PoloĹľĂ­ predmet z batohu do miestnosti. PrĂ­kaz mĂˇ jeden povinnĂ˝ parameter, ktorĂ˝m je nĂˇzov predmetu. Ak predmet nebude zadanĂ˝, program vypĂ­Ĺˇe na obrazovku vhodnĂş hlĂˇĹˇku (napr. Neviem, ÄŤo chceĹˇ poloĹľiĹĄ.)", "(POLOZ)", 1));
    create_container(parser->commands,COMMAND,create_command("INVENTAR", "ZobrazĂ­ obsah hrĂˇÄŤovho batohu.", "(INVENTAR)", 1));
    create_container(parser->commands,COMMAND,create_command("I", "ZobrazĂ­ obsah hrĂˇÄŤovho batohu.", "(I)", 1));
    create_container(parser->commands,COMMAND,create_command("POUZI", "PouĹľije predmet z batohu alebo miestnosti. PrĂ­kaz mĂˇ jeden povinnĂ˝ parameter, ktorĂ˝m je nĂˇzov predmetu. Ak predmet nebude zadanĂ˝, program vypĂ­Ĺˇe na obrazovku vhodnĂş hlĂˇĹˇku (napr. Neviem, ÄŤo chceĹˇ pouĹľiĹĄ.).", "(POUZI)", 1));
    create_container(parser->commands,COMMAND,create_command("PRESKUMAJ", "VypĂ­Ĺˇe opis predmetu, ktorĂ˝ sa musĂ­ nachĂˇdzaĹĄ v miestnosti alebo batohu. PrĂ­kaz mĂˇ jeden povinnĂ˝ parameter, ktorĂ˝m je nĂˇzov predmetu. Ak predmet nebude zadanĂ˝ alebo sa nenĂˇjde v batohu alebo v miestnosti, program vypĂ­Ĺˇe na obrazovku vhodnĂş hlĂˇĹˇku (napr. Neviem, ÄŤo chceĹˇ preskĂşmaĹĄ.).", "(PRESKUMAJ)", 1));
    create_container(parser->commands,COMMAND,create_command("NAHRAJ", "PrĂ­kaz zabezpeÄŤĂ­ nahratie uloĹľenej pozĂ­cie hry z disku. VoliteÄľnĂ˝m parametrom je cesta k sĂşboru.", "(NAHRAJ)", 1));
    create_container(parser->commands,COMMAND,create_command("LOAD", "PrĂ­kaz zabezpeÄŤĂ­ nahratie uloĹľenej pozĂ­cie hry z disku. VoliteÄľnĂ˝m parametrom je cesta k sĂşboru.", "(LOAD)", 1));
    create_container(parser->commands,COMMAND,create_command("ULOZ", "PrĂ­kaz uloĹľĂ­ stav rozohratej hry na disk. VoliteÄľnĂ˝m parametrom je cesta k sĂşboru.", "(ULOZ)", 1));
    create_container(parser->commands,COMMAND,create_command("SAVE", "PrĂ­kaz uloĹľĂ­ stav rozohratej hry na disk. VoliteÄľnĂ˝m parametrom je cesta k sĂşboru.", "(SAVE)", 1));
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
    while(container!=NULL)
    {
        //regmatch_t groups[container->command->nmatch];
        int result = regexec(&container->command->preg, buf, 0, NULL, 0);
        if(result!=REG_NOMATCH)
        {
            free(inpu);
            free(buf);
            return container->command;
        }
        container=container->next;
    }
    free(inpu);
    free(buf);
    return NULL;
}
