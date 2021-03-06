inherit NPC;

void create()
{
        set_name("老虎", ({ "tiger" }) );
        set("long", "一隻相當凶猛的老虎。\n");
        set("race", "野獸");
        set("gender","雄性");   // 1999.2.28 增加此註解
        set("age", 12);
        set("level",5);
        
        set("str", 20);
        set("dex", 12);

        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) ); //受攻部位
        set("verbs", ({ "bite", "claw" }) );
         set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "老虎仰天狂吼~~吼~~~~。\n",
                "老虎不懷好意的打量你。\n",
                "老虎在你身邊繞來繞去。\n",
                "老虎很狠的咬了你一口，把你咬的哇哇大叫。\n" }) );
                
        set_temp("apply/damage", 15);   //附加傷害力
        set_temp("apply/hit", 20);      //附加命中率
        set_temp("apply/armor", 5);     //附加防禦力 

        setup();
}



