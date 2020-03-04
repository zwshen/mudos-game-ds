#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY "[正氣]"HIR"飛龍"HIW"戰士" NOR , ({ "warrior","w" }) );
        set("race", "人類");
        set("age", 40);
        set("level",20);
        set("long","
眼前的這位老兄面露兇光，龐大的體格，加上
壯碩的拳頭和厚重的鎧甲，以及背後龐大的雙翼，
令人為之恐懼，難道他就是超龍軍團的士兵？\n");
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 20);
        set_skill("unarmed",100);
        setup();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_ring.c")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_necklace.c")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_plate.c")->wear();
}

void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("name") != "流雲")
        {
say("飛龍戰士對你說道：" HIY "你好!歡迎光臨超龍軍團!。\n"NOR);
                command("smile" + me->query("id"));
        }else
         {
                say( HIW "飛龍戰士伸了個懶腰。 \n" NOR );
                
      }   
}
