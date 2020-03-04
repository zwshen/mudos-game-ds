#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("[0;1;35m·[1mL[1m¯[1mº[1;37mº[1më[1mÆ[1mF[0m", ({ "smile elf","smile","elf" }) );
        set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","
³o¬O¤@¨ãºë¥©ªº¤â¤u«½«½¡A·í§A¥J²Ó§âª±ªº®É­Ô¡A
¦ü¥GÄ±±o¦o¥¿¦b¹ï§A·L¯ºµÛ¡C"HIC"[2003¦~¤C¤i¬ö©À«½«½]
\n"NOR);
                set("unit", "°¦");
                set("material", "gold");
                set("no_sell",1);
               //set("no_drop",1);
               //set("no_auc",1);
               //set("no_get",1);
              // set("no_give",1);   
                set("value",4800);
        }
              setup();
}
int query_autoload() { return 1; }

