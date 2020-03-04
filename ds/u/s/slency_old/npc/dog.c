// dog.c
#include <ansi.h>

inherit NPC;

void create()
{
         set_name( YEL "思溪的雜種狗" NOR , ({ "slency's dog","dog" }) );
        set("race", "野獸");
        set("age", 1);
        set("long", "牠是思溪的雜種狗, 因為是雜種狗, 所以牠的脾氣不大好唷。\n");

        set("str", 20);
        set("cor", 26);

        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 8);
        set("chat_msg", ({

                "思溪的雜種狗用後腿抓了抓自己的耳朵。\n" }) );

        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);

        setup();
}

void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("name") != "思溪")
        {
say("思溪的雜種狗舔了舔你的腳說道：" HIW "HI!這位客人你好唷, 偶素思溪的雜種狗, 不要75偶唷。\n" NOR );
                command("bite" + me->query("id"));
        }else
         {
                say( HIG "思溪的雜種狗用鼻子聞了聞你的腳。 \n" NOR );
                say( HIG "思溪的雜種狗在思溪的腳邊挨挨擦擦的﹐想討東西吃。\n" NOR );
                say( HIG "思溪的雜種狗對著思溪搖了搖尾巴。\n" NOR );
      }   
}
