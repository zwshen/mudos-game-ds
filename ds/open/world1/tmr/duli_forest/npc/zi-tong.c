#include <npc.h>
#include <ansi.h>
#include <skill.h>

inherit F_VILLAGER;

void create()
{
        set_name("鄭子通", ({ "zheng zi tong","zi","tong","zheng", }) );
                set("long",@long
    鄭子通是有名的擊劍術高手，他自創的「擊劍術」實而不華，招招都
是大開大闔，強健而簡潔有力，最適合力量強而難學花招的人使用。鄭子
通長的瘦瘦高高，留著一頭半長抵肩的頭髮，穿著一身勁裝，背著一把長
劍，細薄而長的嘴角總不時留著一絲笑意，給人城府頗深的感覺。
long
);
        set_race("strength");
        set("age", 35);
        set_stat_maximum("gin", 400);
        set_stat_maximum("hp", 300);
        set_stat_maximum("nina", 100);
                set_attr("str",25);
                set_attr("cor",20);
                set_attr("strength",40);
                set_skill("parry",80);
                set_skill("dodge",80);
        set_skill("sword",80);
                set_skill("attack sword",80);
                map_skill("sword","attack sword");

        set("title","擊劍術高手");
        setup();
		set_level(10);
        do_heal();
    	carry_object(__DIR__"obj/white-sword")->wield();
}

int accept_fight(object ob)
{
        return 0;
}

/* Quest:可學到 「擊劍術」 劍法 */
void relay_say(object ob, string arg)
{
        if( ob->query_learn("attack sword")  )      return;
            if( strsrch(arg,"擊劍術")!=-1 )
                {
                         if( ob->query_attr("str") < 15 ) {
                message_vision(CYN"鄭子通上下打量了$N幾眼，冷笑道：「憑你手無縛雞之力的樣子，怎麼能學得我的絕技呢。」\n"NOR,ob);
                                return ;
                        }
           /* 學習技能點數不夠     */
                        if(ob->query("skills_point")+1 >  SKILL_MAX_POINT ) {
                    message_vision(CYN"鄭子通搖了搖頭說道：「你雜學過廣，我這點微未小技就不勞你費心學了。」\n"NOR,ob);
                                return;
                        }
            message_vision(CYN"鄭子通上下打量了$N幾眼，喜道：「瞧你身強力壯，如果你真想要學的話，我不妨可以傳授你幾招。」\n"NOR,ob);
                        ob->set_temp("duli_forest/zheng-zi-tong",1);
                        return ;
                }
                if( arg=="不想"
                        && ob->query_temp("duli_forest/zheng-zi-tong") )
                {
		        message_vision(CYN"鄭子通搖搖手說道：「你不想學，就別再來煩我了。」\n"NOR,ob);
                        ob->delete_temp("duli_forest/zheng-zi-tong");
                        return ;
                }

                if( arg=="想"
                        && ob->query_temp("duli_forest/zheng-zi-tong") )
                {
            message_vision(CYN"鄭子通說道：「那敢情好，你瞧仔細了吧。」\n"NOR,ob);
            message_vision(CYN"鄭子通拿起手中長劍，比劃了數招，$N凝神記住每招每式。\n"NOR,ob);
                        ob->add("skills_point",1);
            tell_object(ob,HIG"(你的技能學習點數花掉一點。)\n" NOR);
                        ob->improve_skill("attack sword",100);
                        ob->delete_temp("duli_forest/zheng-zi-tong");
                        return ;
                }
        
}
