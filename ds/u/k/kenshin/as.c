#include <ansi.h>

inherit ITEM;
void create()
{
    set_name("[0;1;33m¤[1mÑ[1m¨[1mÏ[1;36mµ[1mo[1mÁ[1mn[1;37m¾[1m¹[0m",({"angel's say","say","angel"}));
    setup();
}
void init()
{
    add_action("do_cc","cc");
} 
int do_cc(string arg)
{ 
        object me = this_player();
        if( !arg || arg=="" ) return notify_fail("§A­n¼g¤°»ò¡S\n"); 
        {
        tell_object(users(),
        HIC"¡i"HIY"³B©ó"HIR"Àø¶Ë´Á¤¤"HIC"¡jÂÅªºØp(Kenshin):"NOR" "+arg+"\n"NOR); 
        }
    return 1;
}
 int query_autoload() { return 1; }

