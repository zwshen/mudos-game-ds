//Query online wizards
//by moto and nokia
#include <ansi.h>
inherit ITEM;
void create()
{


       set_name(HIW""BLK"線上WIZ偵測器"NOR, ({"wizlist machine", "machine"}));
        set_weight(1000);
        set("unit", "顆");
        set("long", @LONG偵測線上wiz
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("do_twiz","twiz");
}

int do_twiz()
{
        int i = 0, idle;
        object *user, wizard;
        string status;

        user=users();

        printf(HIB"────────────┘"HIY"Online Wizards List"HIB"└─────────────\n"NOR);

        foreach(wizard in user)
        {
                status = "";
                
                if(wizardp(wizard))
                {
                        i++;
                        idle = query_idle(wizard);
                        
                        if( in_input(wizard) )
                                status = HIM"(輸入當中) "NOR;
                        else if( in_edit(wizard) )
                                status += HIW"(執行當中) "NOR;
                        else if( idle > 60 )
                                status += sprintf(HIY"(發呆 %d 分鐘)"NOR, idle / 60);
                        else
                                status = "";
                                
                        printf("%2d. ", i);
                        printf("%s「%s」", wizard->query("guild_rank"), wizard->query("nickname"));
                        printf("%s(%s)", wizard->query("name"), wizard->query("id"));
                        if( status != "" )
                                printf(HIM"  立志加入"HIY"雕像工會"HIM"成員"NOR" %s\n", status);
                        else
                                printf("\n");
                }
        }

        printf(HIB"─────────────────────┐"HIW"Total %2d Wizards Online"HIB"┌──\n"NOR, i);

        return 1;
}

