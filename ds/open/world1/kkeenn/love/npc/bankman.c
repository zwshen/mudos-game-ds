#include <ansi.h>
inherit NPC;
inherit BANKMAN;
inherit SSERVER;
void create()
{
        set_name("紫千紅",({ "purple thousand red","red"}));
        set("long", "一個身穿華麗服飾的苗窕女性，她是情城池的副城主，\n也同時是這間錢莊的主人。\n\n"
     "存款請打[deposit]\n提款請打[withdraw]\n查看餘額請打[balance]\n\n"
        );
        set("level",1);
        set("nickname",HIM"《情城池》"HIC"股東"NOR);
        set("title",HIC"情城池副城主"NOR);
        set("gender", "女性");
        set("race", "人類");
        set("no_kill",1);
        set("age", 40);
 setup();
}
void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}


