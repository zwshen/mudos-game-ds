inherit NPC;
#include <ansi.h>
void create()
{
        set_name("波修", ({ "master po", "master", "po" }) );
        set("title", "獵人公會副會長");
        set("gender", "男性");
//        set("class","hunter");
        set("age", 40);
        set("adv_class",1);
        set("class1","獵人");
        set("guild_gifts",({6,6,4,4 }));
        set("long",@long
一個留著長髮的男人，一雙銳利的眼神正看著你，在他面前，你直覺
得有一股迫人的壓力。他就是現任獵人公會的副會長，專門負責新收獵人
的工作，也藉著這次的任務，順道逛逛saint 城。
long
        );
        set("attitude", "peaceful");
        set("level",40);
        set("guild_skills",([
                "dodge" : ({150,2,30}),
                "parry" : ({150,2,30}),
                "block" : ({150,2,30}),
                "combat" : ({200,2,30}),
                "psychical" : ({100,2,5}),
        ])  );

        set("inquiry",([
        "念":"念是一個獵人最基本、也是最重要的技能。",
         "特殊能力":"共有攻擊系、防禦系、現化系、操作系、放出系、特質系六種。",
        "攻擊系":"是指能在一定時間內，加強本身的攻擊能力。",
        "防禦系":"是指能在一定時間內，加強本身的防禦能力。",
        "現化系":"是指能讓氣具體化的呈現。",
        "操作系":"是指能夠操作物品或生物。",
        "放出系":"是指以射出方式釋發氣。",
        "特質系":"特質系是種未分類的念，通常在獵人本身能力高時，才會顯現出來。",
        "學習":"通常念的特殊能力，我們公會只會教授有成就的獵人。",
        ]) );
        set_skill("unarmed", 90);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("block",80);
        set("no_check_class",1);
        setup();
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_apprentice","apprentice");
}

int do_apprentice()
{
        return 0;
}

int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_list(ob,me,arg);   
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        int i;
        object ob, me;

        ob = this_object();
        me = this_player();

        message_vision("$N想加入「"+ arg+ "」。\n",me); 
        if(me->query("class1")=="獵人")
                return notify_fail("你已經是一位獵人了。\n");
        if(!arg || arg!="獵人" )
                return notify_fail("這裡沒有這個公會。\n");
        if(me->query("adv_class") )
                return notify_fail("你已經加入公會或門派了。\n");

        if(!me->query_temp("join_hunter_ok") )
        {
        command("shake");
        command("say 想成為獵人，必須先通過獵人試驗。");
        }
        else {
        command("smile");
        command("say 恭喜通過獵人試驗，成為一個獵人了。");
        command("pat "+me->query("id") );
        command("say 等你稍有成就時，再來找我學習念的特殊能力吧。");
        me->delete_temp("join_hunter_ok");
        me->set("adv_class",1);
        me->set("class1","獵人");
        me->set("guild_rank","初級獵人");
        }               
        return 1;
}


int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(me->query("class1")=="獵人" )
                return GUILDMASTER->do_advance(ob,me,arg);
        else 
                return notify_fail("你並沒有加入獵人公會。\n");
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     // 將 rank 分為六個層次

        switch( lv )
        {
        case 0: rank = "初級獵人"; break;
        case 1: rank = "一星獵人"; break;
        case 2: rank = "二星獵人"; break;
        case 3: rank = "三星獵人"; break;
        }
        return rank;
}


