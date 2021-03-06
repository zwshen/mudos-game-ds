//不放飛劍

#include <ansi.h>
inherit NPC; 
void create()
{
        set_name(HIC"天疾"NOR,({"master sky-wind","sky","master","wind"}));
        set("long" ,@LONG  

      =====================================
        list    列出可學的技能與法術列表
        train   訓練技能
        join    加入工會
        advance 升級或增加屬性
      =====================================
LONG);
        set("nickname", "天疾門之玄外老人" );
        set("attitude", "friendly"); 
        set("age", 80);
        set("gender","男性");
        set("combat_exp", 450000);
        set("level", 60);
        set("title",HIR"神  技"NOR);
        set("max_ap",20000); 
        set("max_hp",16505);
        set("max_mp",20000);
        set("class1","疾風門"); 
        set("class2","天疾門"); 
        set("flurrydodge",1);
        set_temp("apply/armor",200);
        set_skill("fogseven",100);
        set_temp("sorgitimes",20);
        set_skill("unarmed", 100);
        set_skill("sword",100);
        set_skill("moon_force",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("sorgi_sword",100); 
        set_skill("sevenstar-sword",100); 
        set_skill("star-sword",100);
        set_skill("sorsin-force",100);     
        map_skill("sword","star-sword");
        map_skill("dodge","fogseven");
        set("guild_gifts",({ 3,5,5,7}));  
//      工會導師可以教授的技能列表
        set("guild_skills",([
  "sorsin-force" : ({ 175,4,85 }), 
]));

        set("no_check_class",1);
        set("adv_class",2);
        set("chat_chance",8);
        set_temp("class_wind/power",400);
        set("chat_msg", ({
  "天疾輕輕揮舞著手中的劍，慢慢提腿，劍氣快，出招慢。\n", 
  (:command("smile"):),
  (:command("exert moon_force recover"):), 
  (:command("exert moon_force recover"):),
}));
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
  (:command,"exert star-sword tian":),
  (:command,"exert star-sowrd nine":),
  (:command,"exert star-sword penuma-sword":),
  (:command,"exert sorsin-force":),
  (:command("exert moon_force moon-arc"):),
}));

        setup();
        carry_object("/u/j/jangshow/sword")->wield();
       // carry_object(__DIR__"eq/sandal")->wear();
}  
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        if(!query("no_join") || query("no_join")!=1)
        add_action("do_guild_join","join");
        if(!query("no_advance"))
        add_action("do_advance","advance");
}
int do_skill_list(string arg)
{
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); // 避免列出檢查職業的訊息
        write("\n");
        return 1;
}
int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        GUILDMASTER->do_skill_train(ob,me,arg);
        return 1;
}   
 
//現在卡死在join這..要想一個quest來補.. ><" 
int do_guild_join(string arg)
{
        object ob, me;
        int i;
        ob = this_object();
        me = this_player();  
        if(!arg=""||arg!="天疾門")
             return notify_fail("可以 join 天疾門 。\n")        if(me->query("level") < 50)
             return notify_fail("你的等級還不夠。\n")
        if(!me->query("class1")=="疾風門")
             return notify_fail("你不是疾風門的。\n")
        if(me->query("exp") < 10000000)
             return notify_fail("你的經驗值不夠。\n")
        if(me->query("popularity") < 2000)
             return notify_fail("你的聲望不夠。\n")  
        {
        message_vision(HIC"恭喜"+me->name()+"加入 天疾門 。\n",me)
        me->set("class2","天疾門");
        me->receive_damage("exp",10000000);
        me->receive_damage("popularity",2000);
        }
        return 1;
}   
string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     // 將 rank 分為六個層次

        if( me->query("gender") == "女性" )
        {
                switch( lv )
                {
                        case 0: rank = HIC"天疾門之門下弟子"NOR; break;
                        case 1: rank = HIG"天疾門之爐火純青"NOR; break;
                        default: rank = HIY"天疾門之橫掃千軍"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = HIC"天疾門之門下弟子"NOR; break;
                        case 1: rank = HIY"天疾門之爐火純青"NOR; break;
                        default: rank = HIM"天疾門之橫掃千軍"NOR;
                }
        }
        return rank;
}
void die()
{
   object ob,obj;
   obj=new(__DIR__"/obj/money/coin");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
    HIC"\n\t      【天疾門的玄外老人】"+HIW"被"+HIR"【"+ob->name()+"給殺掉了】\n\n"+NOR,users());
        ob->add("popularity",10);   
        ob->set("guild_rank",HIC"參透"HIY"天宇日理"HIC"萬機"NOR);
        ::die();
        return;
}


