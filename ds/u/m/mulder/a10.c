#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIC"斯蘭街"NOR);
        set("long", "古老的街景，碩大的石磚，這條類似中古世紀歐洲的街道充滿著
古意盎然的模樣。兩排的櫻木開滿了茂盛的枝葉，地下舖著用櫻花做
的地毯，在樹底下有著幾對情侶在談情，也有家人一起來賞櫻的，一
幅美麗的圖案顯現在你的眼前。北面有著世界著名的武匠達加開的武
器屋。
");
        set("exits",([
        "east":__DIR__"a06",
//      "north":__DIR__"a11",
        ]));
        set("outdoor",1);
        set("objects",([
        __DIR__"npc/thief1":1,
        ]));
        set("light",1);
        setup();
}

void init()
{
        call_out("war_check",30);
}

void war_check()
{
        object ob;
        ob=this_object();
        remove_call_out("war_check"); //luky
        if(ob->query("war"))
        {
        ob->set("war",0);
message("world:world3:vision",
      HIR"              突然你看到天空出現大批飛船\n\n"NOR
      HIR"              細看之下原來是"HIB"貿易聯盟"NOR"的"HIB"戰艦\n\n"NOR
      HIR"          你發覺這些戰艦消失於"HIW"Naboo"HIR"城外的森林。\n\n"NOR
	,users());
        new(__DIR__"npc/battle.c")->move(__DIR__"a06");
        new(__DIR__"npc/battle.c")->move(__DIR__"a06");
       new(__DIR__"npc/battle.c")->move(__DIR__"a06");
        new(__DIR__"npc/battle.c")->move(__DIR__"a06");
       new(__DIR__"npc/battle.c")->move(__DIR__"a06");
        new(__DIR__"npc/battle.c")->move(__DIR__"a06");
        ob->set("WarStart",1);
        call_out("war_report",30);
	}
	else call_out("war_check",30);
}

void war_report()
{
        object obj,ob,where;
        remove_call_out("war_report"); //luky
        if( this_object()->query("time") > 1 )	// >1 為30秒的樣子.....
	{					//如果要更久就弄大的數字
		this_object()->set("time",0);
                this_object()->set("WarStart",0);

		for(int i=0;i<10;i++)	//這裡依照此war會招出多少mob而定
		{			//有幾隻mob出現,i就小於多少隻mob
		        ob=find_living("battle droid");
			if(ob)
				destruct(ob);
		}

message("world:world3:vision",
                HIM"               貿易聯盟撤退了\n\n"NOR
	,users());

		return;
	}

        if(this_object()->query("WarStart"))
        {
        	obj=find_living("battle droid");
        	where=environment(obj);
        	if(!where)
                {
message("world:world3:vision",
                	HIM"               貿易聯盟被大家同心協力打敗了\n\n"NOR
	,users());
               	this_object()->set("WarStart",0);
                }
                else
                {
                	this_object()->add("time",1);
                	call_out("war_report",30);
                }
        }
}

