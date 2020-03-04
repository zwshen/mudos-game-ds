#include <ansi.h>
inherit NPC;
void create()
{
        set_name("秦始皇", ({ "ghost shu huang chin","chin" }) );
        set("level",65);
set("long","在你眼前的是頂頂大名的一代梟雄秦始皇，為了一統天下不惜為被天理開起時空
，勢必要創造一個死的世界。\n");
;
        set("age",300);
        set("evil",99);
     set("title",MAG "梟雄"NOR);
        set("gender","男性");
        set("attitude","killer");
        set_skill("staff",100);
        setup();
        carry_object("/u/k/king/area/npc/wp/stafff")->wield();
        carry_object("/u/k/king/area/npc/eq/devil-armor")->wear();
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",
HIC"\n  秦假先以飛快的速度回報:"HIW"\n\n\t一代梟雄－秦始皇死在"+ob
->name(1)+"的手中了，又被封印到五道天環之中。\n\n"+NOR
        ,users());
        ob->add("popularity",1); //聲望
     message_vision( "$N"+HIR "臨死前，用盡內力將自己的魔心鎮碎" NOR ,this_object()
);
        ::die();
        //destruct(this_object());
        return;
}

