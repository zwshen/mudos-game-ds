#include <ansi.h>
inherit NPC;

void create()
{
        set_name("活體四十級八極門", ({"bagiman","man1"}) );
        set("long", "你可以打他看看....還蠻耐打的\n");
        set("title",HIW"全身裝備"NOR);
        set("race", "人類");
        set("age", 50);
        set("level", 40);

        set("str",70);
        set("dex",40);
        set("con",64);
        set("int",25); 
        set("combat_exp",10000);
        set("chat_chance",20);
        set("chat_msg",({
         (:command("say 我說保管箱ㄚ...你現在在想什麼??"):),
         (:command("say 唉...真無聊..."):),
         (:command("exert bagi_fist"):),
         (:command("exert bagi_fist"):),
        }) );

      set_skill("unarmed",100);
      set_skill("combat",100);
      set_skill("bagi_fist",100);
      set_skill("horse-steps",100);
      set_skill("bagi_force",100);
      set_skill("force",100);
      set_skill("dodge",70);
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                (:command("exert bagi_fist"):),
                (:command("exert bagi_force power_up"):),
         }) );

      setup();

      carry_object("/open/world1/eq/bc_cloak")->wear();
      carry_object("/open/world1/eq/bs_hands")->wear();
      carry_object("/open/world1/eq/bt_neck")->wear();
      carry_object("/open/world1/eq/gs_waist")->wear();
      carry_object("/open/world1/eq/mb_wing")->wear();
      carry_object("/open/world1/eq/mf_armor")->wear();
      carry_object("/open/world1/eq/sl_mask")->wear();
      carry_object("/open/world1/tmr/ghost-forest/npc/eq/randombite-finger")->wear();
      carry_object("/open/world1/tmr/ghost-forest/npc/eq/gold_helmet")->wear();
      carry_object("/open/world1/wilfred/sand/npc/eq/eq7")->wear();
      carry_object("/open/world1/wilfred/sand/npc/eq/eq9")->wear();
      carry_object("/open/world1/eq/water_boots")->wear();
      carry_object("/open/world1/eq/viper_cloth")->wear();
      carry_object("/open/world1/tmr/area/npc/wp/dab-aqua-claw2")->wield();


}
int talk_action()
{
command("know ");
command("emote 露出了無奈的眼神。");
command("say 天天挨打，有時真不想做了。");
command("say 真的，連一點福利也沒有...");
command("stare");
command("shrug");
command("sigh");
command("say 這就是我的宿命吧...");
return 1;
}

