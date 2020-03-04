#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIY"¥ú¤§¤l"NOR,({"son of light","son","light","master"}));
        set("gender", "¨k©Ê"); 
        set("title",HIW"Àsªº¶Ç¤H"NOR);        set("long",@LONG
        list    ¦C¥X¥i¾Çªº§Þ¯à»Pªk³N¦Cªí
        train   °V½m§Þ¯à
        learn   ¾Ç²ßªk³N
        join    ¥[¤J¤u·|
        advance ¤É¯Å©Î¼W¥[ÄÝ©Ê

LONG
        );
        set("level",45);                
        set("age",53);                  

        set("adv_class",2);             
        set("class1","dragon");           Ù
        set("guild_skills",([   
                "dodge":({32,2,105}),   ú
                "blade":({30,2,90}),    
        ]) );

        set("guild_spells",([           
                "killingdragon-yet-blade":({60,2,30}),
        ]) );

        set("guild_gifts",({10,5,-3,8}));

        setup();

        add_money("coin",1000);
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_spell_train","learn");
        if(!query("no_join") || query("no_join")!=1)
                add_action("do_guild_join","join");
        if(!query("no_advance"))
                add_action("do_advance","advance");
}

int do_spell_train(string arg)
{
        GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
        return 1;
}

int do_skill_list(string arg)
{
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); 
        write("\n");
        GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
        this_player()->delete("no_check_class");
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

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
                case 0: break;
                case -1: command("say ª±®a¤w¸g¥[¤J¨ä¥Lªù¬£¡C");break;
                case -2: command("say ª±®a¤w¸g¥[¤J¤F»P¾É®v¦P¯Å©Î§ó°ª¯Åªº²ÕÂ´¡C");break;
                case -3: command("say ª±®a¥Ø«eªº²ÕÂ´¨Ã¤£¾A¦X¥[¤J¥»²ÕÂ´¡C");break;
                case -4: command("say ª±®aµ¥¯Å¤£°÷¡C");break;
                case -5: command("say ª±®aªº termstr ¨Ã¨S¦³¤j©ó termnum ­È¡C");break;
                case -6: command("say ª±®aªº termstr ¨Ã¨S¦³µ¥©ó termnum ­È¡C");break;
                case -7: command("say ª±®aªº termstr ¨Ã¨S¦³¤p©ó termnum ­È¡C");break;
                case -8: command("say ª±®a¿é¤Jªº²ÕÂ´¿ù»~©Î¨S¦³¿é¤J­n¥[¤Jªº²ÕÂ´¦W¡C");break;
                default: command("say ª±®a¥[¤J¤F¯«¤Mªù¡C");
        }
        
        return 1;
}

int do_advance(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        GUILDMASTER->do_advance(ob,me,arg);
        return 1;
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/4;     
        if( me->query("gender") == "¨k©Ê" )
        {
                switch( lv )
                {
                        case 0: rank = HIW"¯«¤M¤Jªù¤p¤p¤M«È"NOR; break;
                        case 1: rank = HIG"¯«¤M¤JªùÄl¤õ¯Â«C"NOR; break; 
                        case 2: rank = HIB"¯«¤M¤Jªù¸U¤Ò²ö¼Ä"NOR; break;                        default: rank = HIY"¯«"HIR"·´ ¤Ñ  ·À ¦a"HIY"¤M"NOR;
                }
        }
        return rank;
}


