#include <ansi.h>
inherit NPC;
mapping *combat_action = ({
        ([      "action":              "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIY+"伏魔訣"+NOR+""+CYN+"】"+NOR+"一道金光閃過$n的$l!",

                "attact_type":  "sou",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
        ([      "action":               "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+MAG+"天罡\訣"+NOR+""+CYN+"】"+NOR+"一道紫光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
        ([      "action":               "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIR+"破邪訣"+NOR+""+CYN+"】"+NOR+"一道紅光閃過$n的$l!",

                "attact_type":  "sou",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIC+"凍妖訣"+NOR+""+CYN+"】"+NOR+"一道藍光閃過$n的$l!",
                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIM+"詠日訣"+NOR+""+CYN+"】"+NOR+"一道橙光閃過$n 的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+GRN+"劍氣訣"+NOR+""+CYN+"】"+NOR+"一道綠光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIW+"滅殺訣"+NOR+""+CYN+"】"+NOR+"一道白光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+WHT+"四傲訣"+NOR+""+CYN+"】"+NOR+"一道灰光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+YEL+"地土訣"+NOR+""+CYN+"】"+NOR+"一道褐光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
});

void create()
{
        set_name(MAG"奇倪獸"NOR,({"chini"}) );
        set("long",@LONG
這是傳說中的神獸奇倪獸，據說它原來是鎮守十萬大山地區的天
帥，但在漫長的日子中不幸被一枚
不斷發出寒氣的奇怪指環所誘
惑，最後在滅骨峰上蛻變成現在的奇倪獸....但是這個傳說背後似
乎還有一個見不得人黑幕存在...
LONG
);
        set("title",HIR"「十萬神獸」"NOR);
        set("age",1200+random(50));
        set("level",60);
        set("gender","雄性");
 set("attitude", "peaceful");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "奇倪獸忽然被一股火光所包圍，痛苦的大吼一聲.....。\n",
        }));
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾部","雙翼" }) );
        set("verbs", ({ "bite", "claw" }) );
      set("Merits/bar",9);
      set("Merits/sou",9);
      set("str",155);
      set("int",50);
          set("addition_armor",100);

    set("Merits/wit",9);
        set("addition_damage",50);
      set("no_busy",1);
        add("apply/hit",50);
        setup();
        set("actions", (: call_other, __FILE__, "query_action" :));
    carry_object(__DIR__"eq/chini_wrist")->wear();
    carry_object(__DIR__"eq/chini_boots")->wear();
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void die()
{
        object ob;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",

           HIW"\n【十萬大山】"+HIW"十萬生死印在各路俠士的協助下, 再度將奇倪獸元靈逐回天界!\n\n"+NOR,users());
            ob->add("popularity",5); //聲望
        ::die();
        return;
}

int accept_object(object who,object ob)
{
           int i;
                object obj,me,g;
                obj=this_object();
                me=this_player();
                if(ob->id("ice stone"))
                {
            message_vision("奇倪獸忽然一陣怪異的抖動....! \n",who);
       set("Merits/bar",7);
        set("Merits/wit",7);
      set("Merits/sou",7);
        set("addition_damage",50);
      set("no_busy",1);
        add("apply/hit",50);
        set("level",60);
         message_vision(HIC"一陣藍光閃過, 你的身邊忽然多了一個發光的靈體! \n"NOR,who);
       message("world:world1:vision",
           MAG"\n【十萬大山】"+HIR"寒嶽重新進入奇倪獸元靈，十萬神獸全體甦醒！！\n\n"+NOR,users());
       g=new(__DIR__"maigu.c");
        g->move("/open/world1/faceoff/sky/ten38.c");
       g=new(__DIR__"wo.c");
        g->move("/open/world1/faceoff/sky/ten50.c");
        for(i=0;i<=5;i++)
        {
                       g=new(__DIR__"ghost.c");
                g->move("/open/world1/faceoff/sky/ten9");
                       g=new(__DIR__"ghost.c");
                g->move("/open/world1/faceoff/sky/ten25");
                       g=new(__DIR__"ghost.c");
                g->move("/open/world1/faceoff/sky/ten44");

        }
  for(i=0;i<=2;i++)
        {
                       g=new(__DIR__"ghost2.c");
                g->move("/open/world1/faceoff/sky/ten2");
                       g=new(__DIR__"ghost2.c");
                g->move("/open/world1/faceoff/sky/ten7");
                       g=new(__DIR__"ghost2.c");
                g->move("/open/world1/faceoff/sky/ten4");

        }

            destruct(ob);
            return 1;
                }
     else
          {
         message_vision("奇倪獸大吼一聲，將"+ob->query("name")+"徹底摧毀! \n",who);
            command("kill "+who->query("id")+"");
            destruct(ob);
            return 1; 
          }

}
