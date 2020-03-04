#include <ansi.h>
#include "/u/a/anfernee/anfernee.h"
inherit GUILDMASTER;    // Ä~©Ó GUILDMASTER ¨Ã¤£»Ý­n¦AÄ~©Ó NPC

void create()
{
        set_name("·s¤â¾É®v", ({"master"}) );
    set("gender", "¨k©Ê");
    set("combat_exp", 100000);
    set("long",
    "¥L¬O½Ñ¦ì·s¤âªº«ü¾É±Ð®v¡A´£¨Ñ°ò¥»ªº§Þ¥©°V½m\n"
    "§A¥i¥H¨Ï¥Î"HIY"list"NOR"¨Ó¬Ý¬Ý¦³¤°»ò§Þ¥©¥i¥H´£¨Ñ¾Ç²ß¡C\n");
        set("no_join", 1);
        set("level", 200);
        set("age", 50);
        set_skill("blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set("guild_skills", ([  // // Ãø«×, µ¥¯Å1¥i¾Çªº¤W­­, ¤W­­
        "dodge":({30,5,40}),
        "blade":({50,5,35}),
        "sword":({50,5,35}),
        "parry":({30,5,40}),
        "unarmed":({40,5,40}),
        ]) );
        set("chat_chance", 5);
/*  set("chat_msg", ({
    "·s¤â¾É®v½w½wªº¹D:"HIC"Åwªï¦U¦ì®ÉªÅ®È¦æªÌ¦b³o¸Ì¾Ç²ß¡C"NOR"\n",
        "·s¤â¾É®v½w½wªº¦b©Ð¶¡¸ÌºCºCªº¨«µÛ¡C\n",
    }) ); */
        set("inquiry/master", "§Ú´N¬O·s¤â¾É®v\n");
        setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "·s¤â¾É®v¹D:"HIC"Åwªï¦U¦ì®ÉªÅ®È¦æªÌ¦b¦¹¾Ç²ß°ò¥»ªº§;
                        break;
                case 1:
                        break;
               }
}
