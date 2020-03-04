#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name(HIW "µL¬Û©àªáªøÀ@" NOR,({"wu-xiang flower dagger","dagger"}) );
        set("long",@LONG
    [0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [0m[0;1;36m¡[1mX[1m¢[1mw[1mù[1mù[1mù[1mû[0m                            
    [0;1m [1m [1m [1m [0m[0;1m¢[1mb[1m¢[1mb[1m¢[1mc[1m¢[1mc[1m¢[1mc[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1m¢[1md[1;36;47mx[1;40m¢[1m­[1;37m¢[1mc[1m¢[1mb[1m¢[1mb[0m                     
    [30;46m¢i¢h¢g¢f¢f¢e¢e¢e¢e¢e¢e¢e¢e¢e¢e¢e¢e¢e¢e¢e¢e¢e¢e[36;47mx[40m¢¬[30;47m¢f¢g¢g[0m                     
    [0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m¡[1mX[1m¢[1mw[1mù[1mù[1mù[1mý[0m         

LONG
);
         set_weight(2500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","§â");
                set("value",5000);
        }
             set("weapon_prop/sou",1);
             set("weapon_prop/dex",2);
             set("limit_level",30);
             set("limit_dex",30);
        init_dagger(35);
        setup();        
}

