/* hing.c write by -Acme-
   update by -Acme-
*/

#include <ansi.h>
inherit NPC;
void create()
{
    set_name("朱中慶", ({ "chu chung hing", "hing", "__GUARD__" }) );
    set("level", 35);
    set("race","人類");
    set("gender","男性");
    set("age",45);
    set("title",HIY"按察使"NOR);
    set_skill("parry", 80);
    set_skill("sword", 80);
    set_skill("dodge", 80);
    set("long","他是天城掌管刑獄的最高長官，身材壯碩，看來武藝不弱。\n");
    setup();
    carry_object(__DIR__"eq/armor")->wear();
    carry_object(__DIR__"eq/boots")->wear();
    carry_object(__DIR__"wp/sword")->wield();
}
void init()
{
    ::init();
    if(!this_object()->visible(this_player())) return;
    call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
    if(ob->query_temp("SKYCITY/jail") >0 || ob->query_tmp("SKYCITY/hatred") > 0 ) {
        command("say 惡賊！納命來！！");
        this_object()->kill_ob(ob);
    }
}

void die()
{
    object ob;

    if( !ob = query_temp("last_damage_from") ) ob = this_player(1);

    if( !ob ) {
        ::die();
        return;
    }

    if( !ob->query_temp("SKYCITY/jail") ) {
        ob->add_temp("SKYCITY/jail",1);
        message_vision(HIC"縣老爺"HIR"大喝：可惡的"+ob->name(1)+"，吃了熊心豹\子膽！？膽敢劫獄！？\n"NOR,ob);
        message_vision(HIC"縣老爺"HIR"大喝：眾將聽令，見"+ob->name(1)+"者，殺∼無∼赦∼∼！！\n"NOR,ob);
    } else ob->add_temp("SKYCITY/jail",1);

    ::die();
    return;
}
