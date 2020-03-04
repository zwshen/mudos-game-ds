#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIR "赤血屍妖" NOR, ({"devil-ree"}) );
  set("long","這隻妖怪看起來一身血紅，十分的兇惡，它也是這附近\n"
  "的角頭老大，沒事還是不要惹到它比較。\n");
set("attitude", "aggressive");
set("level",25);
set_skill("dodge",60);
set_skill("unarmed",60);
setup();
carry_object(__DIR__"obj/pearl");
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
HIC"\n  公孫勝以飛快的速度回報:"HIW"\n\n\t上古魔獄－戰國皇陵被"+ob
->name(1)+"打開了。凡間將陷入一片死寂。\n\n"+NOR
        ,users());
        ob->add("popularity",0); //聲望
        ::die();
        //destruct(this_object());
        return;
}

