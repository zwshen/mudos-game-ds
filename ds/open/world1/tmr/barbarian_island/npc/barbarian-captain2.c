#include <npc.h>
#include <ansi.h>
#include "barbarian_base.c"

void create()
{
        set_name("野蠻人", ({ "barbarian captain","barbarian","captain" }) );
        set("long",@long
在你眼前是一個非常兇狠的野蠻人首領，他正用著佈滿血絲的雙眼盯
著你，嘴裡喃喃自語著你聽不懂的話語，似乎他對你充滿敵意。
long
);
        set_race("human");
        set("title","大首領");
        set("age", 45);
        set_skill("twohanded blunt",90);        // 雙握棒法
        set_skill("parry",80);
        set_skill("dodge",80);
        setup();
        set_level(30);
        carry_object(__DIR__"obj/monster_pants")->wear();
        carry_object(__DIR__"obj/tiger-fur-armor")->wear();
        carry_object(__DIR__"obj/monster-waist")->wear();
        carry_object(__DIR__"obj/big-blunt")->wield();
}

void exchange(object player,object ob)
{
        object item;
        destruct(ob);
        message_vision(CYN "$N三兩口就把整隻烤鴨吃得精光了。\n" NOR,this_object() );
        message_vision(CYN "$N從懷中拿出一枚戒指送給了$n。\n" NOR,this_object(),player );
        command("smile");
        item=new(__DIR__"obj/jade-ring");
        item->move(player);
}


int accept_object(object me, object ob)
{
        object item;
       if(      !ob->id("_OBJ_ID_DUCK_")
                || is_fighting()
                || me->query_learn("finger-guessing fist") 
                || objectp( item=present("_OBJ_ID_JADE_RING_",me) ) )
           {
              do_chat((: command, "shake" :));
              return 0;
       }
       command("jump");
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}



